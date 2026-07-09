#!/usr/bin/env python3
"""Build a dialog/menu reference from decoded ECL listings and missing text hits."""

from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from dataclasses import asdict, dataclass
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))

from scripts.compare_goldbox_ecl_text import normalize
from scripts.contextualize_goldbox_ecl_text import (
    TextContext,
    contextualize_hits,
    load_listing_rows,
    load_substring_missing_hits,
)


DEFAULT_COMPARE_JSON = Path("generated") / "ecl_text_goldbox" / "ecl_text_compare.json"
DEFAULT_CONTEXT_JSON = Path("generated") / "ecl_text_goldbox" / "goldbox_ecl_text_context.json"
DEFAULT_LISTING_DIR = Path("generated") / "ecl1_disasm"
DEFAULT_EVENT_ATLAS = Path("generated") / "event_atlas" / "event_atlas.json"
DEFAULT_OUT_DIR = Path("generated") / "ecl_text_goldbox"
DEFAULT_DOC_PATH = Path("docs") / "ecl-dialog-trees-reference.md"

ROW_RE = re.compile(r"^0x(?P<address>[0-9A-Fa-f]{4})\s+0x(?P<opcode>[0-9A-Fa-f]{2})\s+(?P<body>.+)$")
ENTRY_RE = re.compile(r"^(?P<label>[A-Za-z_][A-Za-z0-9_]*)\s+0x(?P<address>[0-9A-Fa-f]{4})$")
TARGET_RE = re.compile(r"0x([0-9A-Fa-f]{4})")
MENU_BODY_RE = re.compile(r"MENU:\s*(.+)")
ON_GOTO_BODY_RE = re.compile(r"ON GOTO\s+(.+?)\s+of\s+\[([^\]]+)\]")
STRING_LITERAL_RE = re.compile(r"'([^']+)'|\"([^\"]+)\"")

CONTROL_WORDS = ("GOTO", "GOSUB", "MENU", "IF ", "RETURN", "EXIT", "NEWECL", "COMBAT")
TEXT_WORDS = ("PRINT", "MENU", "WHO")


@dataclass(frozen=True)
class Instruction:
    block_id: int
    address: int
    opcode: int
    body: str
    row: str


@dataclass(frozen=True)
class BranchRegion:
    block_id: int
    target: int
    end: int | None
    incoming: tuple[str, ...]
    instructions: tuple[Instruction, ...]


@dataclass(frozen=True)
class AttachedMissingText:
    block_id: int
    offset: int
    vm_address: int
    encoded_length: int
    text: str
    normalized_text: str
    unique_index: int
    attachment_kind: str
    owner_target: int | None
    owner_incoming: tuple[str, ...]
    owner_summary: str
    previous_row: str | None
    previous_distance: int | None
    next_row: str | None
    next_distance: int | None
    context_kind: str


def parse_menu_labels(instructions: list[Instruction] | tuple[Instruction, ...]) -> list[str]:
    labels: list[str] = []
    for instr in instructions:
        match = MENU_BODY_RE.search(instr.body)
        if not match:
            continue
        for single, double in STRING_LITERAL_RE.findall(match.group(1)):
            label = (single or double).strip()
            if label and label not in labels:
                labels.append(label)
    return labels


def parse_on_goto_targets(instructions: list[Instruction] | tuple[Instruction, ...]) -> list[dict[str, object]]:
    branches: list[dict[str, object]] = []
    for instr in instructions:
        match = ON_GOTO_BODY_RE.search(instr.body)
        if not match:
            continue
        targets: list[int] = []
        for value in match.group(2).split(","):
            value = value.strip()
            if not value:
                continue
            try:
                targets.append(int(value, 16))
            except ValueError:
                continue
        branches.append({"selector": match.group(1).strip(), "targets": targets, "row": instr.row})
    return branches


def extracted_text_rows(instructions: tuple[Instruction, ...]) -> list[dict[str, object]]:
    rows: list[dict[str, object]] = []
    for instr in instructions:
        if not any(word in instr.body for word in TEXT_WORDS):
            continue
        texts = [(single or double).strip() for single, double in STRING_LITERAL_RE.findall(instr.body)]
        rows.append(
            {
                "address": instr.address,
                "address_hex": f"0x{instr.address:04X}",
                "row": instr.row,
                "texts": [text for text in texts if text],
            }
        )
    return rows


def parse_listing(path: Path) -> tuple[int | None, list[tuple[str, int]], list[Instruction]]:
    block_match = re.search(r"ecl1_(\d+)\.ecl\.txt$", path.name)
    if not block_match:
        return None, [], []
    block_id = int(block_match.group(1))
    entries: list[tuple[str, int]] = []
    instructions: list[Instruction] = []
    for line in path.read_text(encoding="utf-8").splitlines():
        entry = ENTRY_RE.match(line)
        if entry:
            entries.append((entry.group("label"), int(entry.group("address"), 16)))
            continue
        row = ROW_RE.match(line)
        if row:
            instructions.append(
                Instruction(
                    block_id=block_id,
                    address=int(row.group("address"), 16),
                    opcode=int(row.group("opcode"), 16),
                    body=row.group("body"),
                    row=line,
                )
            )
    instructions.sort(key=lambda item: item.address)
    return block_id, entries, instructions


def load_listings(listing_dir: Path) -> tuple[dict[int, list[tuple[str, int]]], dict[int, list[Instruction]]]:
    entries_by_block: dict[int, list[tuple[str, int]]] = {}
    instructions_by_block: dict[int, list[Instruction]] = {}
    for path in sorted(listing_dir.glob("ecl1_*.ecl.txt")):
        block_id, entries, instructions = parse_listing(path)
        if block_id is None:
            continue
        entries_by_block[block_id] = entries
        instructions_by_block[block_id] = instructions
    return entries_by_block, instructions_by_block


def describe_referrer(instr: Instruction, target: int) -> str:
    body = instr.body
    if " of [" in body:
        targets = [int(value, 16) for value in TARGET_RE.findall(body.split(" of [", 1)[1])]
        if target in targets:
            return f"0x{instr.address:04X} {body.split(' of [', 1)[0]} choice {targets.index(target)}"
    return f"0x{instr.address:04X} {body}"


def branch_targets(
    entries_by_block: dict[int, list[tuple[str, int]]],
    instructions_by_block: dict[int, list[Instruction]],
) -> dict[int, dict[int, list[str]]]:
    by_block: dict[int, dict[int, list[str]]] = {}
    for block_id, entries in entries_by_block.items():
        for label, address in entries:
            by_block.setdefault(block_id, {}).setdefault(address, []).append(f"entry {label}")
    for block_id, instructions in instructions_by_block.items():
        for instr in instructions:
            if not any(word in instr.body for word in ("GOTO", "GOSUB")):
                continue
            for value in TARGET_RE.findall(instr.body):
                target = int(value, 16)
                by_block.setdefault(block_id, {}).setdefault(target, []).append(describe_referrer(instr, target))
    return by_block


def build_regions(
    entries_by_block: dict[int, list[tuple[str, int]]],
    instructions_by_block: dict[int, list[Instruction]],
) -> dict[int, list[BranchRegion]]:
    target_refs = branch_targets(entries_by_block, instructions_by_block)
    regions_by_block: dict[int, list[BranchRegion]] = {}
    for block_id, instructions in instructions_by_block.items():
        target_set = set(target_refs.get(block_id, {})) | {instr.address for instr in instructions if instr.opcode in (0x15, 0x2B, 0x25, 0x26, 0x29)}
        targets = sorted(target for target in target_set if any(instr.address >= target for instr in instructions))
        regions: list[BranchRegion] = []
        for index, target in enumerate(targets):
            end = targets[index + 1] if index + 1 < len(targets) else None
            contained = tuple(instr for instr in instructions if instr.address >= target and (end is None or instr.address < end))
            incoming = tuple(sorted(set(target_refs.get(block_id, {}).get(target, []))))
            regions.append(BranchRegion(block_id, target, end, incoming, contained))
        regions_by_block[block_id] = regions
    return regions_by_block


def region_for_address(regions: list[BranchRegion], address: int) -> BranchRegion | None:
    previous: BranchRegion | None = None
    for region in regions:
        if region.target > address:
            break
        previous = region
        if region.end is not None and address < region.end:
            return region
    return previous


def nearest_region_instruction(region: BranchRegion, address: int) -> Instruction | None:
    previous = [instr for instr in region.instructions if instr.address <= address]
    if previous:
        preferred = [
            instr
            for instr in previous
            if any(word in instr.body for word in TEXT_WORDS) or any(word in instr.body for word in CONTROL_WORDS)
        ]
        return (preferred or previous)[-1]
    following = [instr for instr in region.instructions if instr.address > address]
    return following[0] if following else None


def summarize_region(region: BranchRegion | None, address: int) -> str:
    if region is None:
        return "no decoded branch target region"
    nearest = nearest_region_instruction(region, address)
    if nearest is not None:
        return nearest.row
    text_rows = [instr.row for instr in region.instructions if any(word in instr.body for word in TEXT_WORDS)]
    if text_rows:
        return text_rows[0]
    if region.instructions:
        return region.instructions[0].row
    return f"branch target 0x{region.target:04X} has no decoded instructions"


def nearby_control(context: TextContext) -> str | None:
    candidates: list[tuple[int, str]] = []
    for row, distance in ((context.previous_row, context.previous_distance), (context.next_row, context.next_distance)):
        if row is None or distance is None:
            continue
        if any(word in row for word in CONTROL_WORDS):
            candidates.append((distance, row))
    if not candidates:
        return None
    candidates.sort(key=lambda item: item[0])
    return candidates[0][1]


def attachment_kind(context: TextContext, region: BranchRegion | None) -> str:
    for row in (context.previous_row, context.next_row):
        if row and context.text in row:
            if "MENU:" in row:
                return "decoded_menu_instruction"
            return "decoded_text_instruction"
    control = nearby_control(context)
    if control and "MENU" in control:
        return "near_menu_instruction"
    if region is not None:
        nearby_region_rows = [
            instr
            for instr in region.instructions
            if abs(instr.address - context.vm_address) <= 0x180
            and any(marker in instr.body for marker in ("MENU", "WHO", "INPUT"))
        ]
        if nearby_region_rows:
            return "prompt_or_menu_region"
    if region is not None:
        return "branch_target_region"
    return "loose_listing_context"


def attach_contexts(contexts: list[TextContext], regions_by_block: dict[int, list[BranchRegion]]) -> list[AttachedMissingText]:
    norms = sorted({normalize(context.text) for context in contexts})
    unique_index = {norm: index + 1 for index, norm in enumerate(norms)}
    attached = []
    for context in contexts:
        region = region_for_address(regions_by_block.get(context.block_id, []), context.vm_address)
        norm = normalize(context.text)
        attached.append(
            AttachedMissingText(
                block_id=context.block_id,
                offset=context.offset,
                vm_address=context.vm_address,
                encoded_length=context.encoded_length,
                text=context.text,
                normalized_text=norm,
                unique_index=unique_index[norm],
                attachment_kind=attachment_kind(context, region),
                owner_target=region.target if region else None,
                owner_incoming=region.incoming if region else (),
                owner_summary=summarize_region(region, context.vm_address),
                previous_row=context.previous_row,
                previous_distance=context.previous_distance,
                next_row=context.next_row,
                next_distance=context.next_distance,
                context_kind=context.context_kind,
            )
        )
    return attached


def load_event_atlas(path: Path) -> dict[int, dict[str, object]]:
    if not path.exists():
        return {}
    atlas = json.loads(path.read_text(encoding="utf-8"))
    return {int(item["ecl_block"]): item for item in atlas if item.get("ecl_block") is not None}


def build_dialog_conversations(
    attached: list[AttachedMissingText],
    regions_by_block: dict[int, list[BranchRegion]],
    event_atlas_by_ecl: dict[int, dict[str, object]],
) -> list[dict[str, object]]:
    """Compile atlas event targets plus ECL dialog references into compact rows.

    These rows are intentionally evidence-first. They make menu/choice regions
    easy for runtime tests to consume without claiming that every attached
    packed string is fully proven original dialog ownership.
    """

    attachments_by_owner: dict[tuple[int, int], list[AttachedMissingText]] = {}
    for item in attached:
        if item.owner_target is None:
            continue
        attachments_by_owner.setdefault((item.block_id, item.owner_target), []).append(item)

    conversations: list[dict[str, object]] = []
    for ecl_block, atlas in sorted(event_atlas_by_ecl.items()):
        regions_by_target = {region.target: region for region in regions_by_block.get(ecl_block, [])}
        events = atlas.get("events") if isinstance(atlas.get("events"), dict) else {}
        for event_id_text, event in sorted(events.items(), key=lambda pair: int(pair[0])):
            if not isinstance(event, dict) or event.get("target") is None:
                continue
            target = int(event["target"])
            region = regions_by_target.get(target) or region_for_address(regions_by_block.get(ecl_block, []), target)
            if region is None:
                continue
            owner_attachments = sorted(
                attachments_by_owner.get((ecl_block, region.target), []),
                key=lambda row: (row.vm_address, row.text),
            )
            menu_labels = parse_menu_labels(region.instructions)
            attached_choice_labels = [
                item.text.strip()
                for item in owner_attachments
                if item.context_kind == "short_choice_or_label" and item.text.strip()
            ]
            labels: list[str] = []
            label_sources: dict[str, str] = {}
            for label in menu_labels:
                if label not in labels:
                    labels.append(label)
                    label_sources[label] = "decoded_menu_instruction"
            for label in attached_choice_labels:
                if label not in labels:
                    labels.append(label)
                    label_sources[label] = "attached_missing_text"

            branches = parse_on_goto_targets(region.instructions)
            branch_targets = branches[0]["targets"] if branches else []
            choices = []
            for index, label in enumerate(labels):
                branch_target = branch_targets[index] if index < len(branch_targets) else None
                attachment = next((item for item in owner_attachments if item.text.strip() == label), None)
                choices.append(
                    {
                        "label": label,
                        "choice_index": index,
                        "branch_target": branch_target,
                        "branch_target_hex": f"0x{branch_target:04X}" if branch_target is not None else "",
                        "selector": str(branches[0]["selector"]) if branches else "",
                        "evidence": attachment.previous_row if attachment else (str(branches[0]["row"]) if branches else ""),
                        "source": label_sources.get(label, "unknown"),
                    }
                )
            if not choices and branches:
                for index, branch_target in enumerate(branch_targets):
                    choices.append(
                        {
                            "label": f"Choice {index + 1}",
                            "choice_index": index,
                            "branch_target": branch_target,
                            "branch_target_hex": f"0x{branch_target:04X}",
                            "selector": str(branches[0]["selector"]),
                            "evidence": str(branches[0]["row"]),
                            "source": "branch_target_without_label",
                        }
                    )
            if not choices:
                continue

            conversations.append(
                {
                    "geo_id": atlas.get("geo_id"),
                    "geo_name": atlas.get("name"),
                    "ecl_block": ecl_block,
                    "event_id": int(event_id_text),
                    "event_target": target,
                    "event_target_hex": f"0x{target:04X}",
                    "event_text": event.get("text", ""),
                    "dialog_target": region.target,
                    "dialog_target_hex": f"0x{region.target:04X}",
                    "incoming": list(region.incoming),
                    "prompt_rows": extracted_text_rows(region.instructions),
                    "choices": choices,
                    "attachment_count": len(owner_attachments),
                    "confidence": (
                        "menu_instruction"
                        if menu_labels
                        else "attached_missing_text_near_branch"
                        if attached_choice_labels
                        else "branch_targets_without_labels"
                    ),
                    "evidence_limit": "Choice labels are compiled from decoded MENU rows or nearby missing packed text attachments; attached text is not ownership proof by itself.",
                }
            )
    return conversations


def md_escape(value: str) -> str:
    return value.replace("|", "\\|")


def write_outputs(
    attached: list[AttachedMissingText],
    regions_by_block: dict[int, list[BranchRegion]],
    instructions_by_block: dict[int, list[Instruction]],
    event_atlas_by_ecl: dict[int, dict[str, object]],
    out_dir: Path,
    doc_path: Path,
) -> None:
    out_dir.mkdir(parents=True, exist_ok=True)
    doc_path.parent.mkdir(parents=True, exist_ok=True)

    by_kind: dict[str, int] = {}
    for item in attached:
        by_kind[item.attachment_kind] = by_kind.get(item.attachment_kind, 0) + 1
    unique_count = len({item.normalized_text for item in attached})
    conversations = build_dialog_conversations(attached, regions_by_block, event_atlas_by_ecl)

    payload = {
        "source": "Decoded ECL listings plus Gold Box whole-block text hits still missing after substring comparison",
        "evidence_limits": [
            "Missing text attachments identify nearby decoded ECL branch/menu regions; they are not runtime ownership proof by themselves.",
            "Address mapping follows the previous context pass: vm_address = 0x8000 + decoded ECL block offset.",
        ],
        "summary": {
            "attached_hit_count": len(attached),
            "unique_normalized_text_count": unique_count,
            "by_attachment_kind": dict(sorted(by_kind.items())),
            "dialog_conversation_count": len(conversations),
        },
        "dialog_conversations": conversations,
        "missing_text_attachments": [asdict(item) for item in attached],
        "branch_regions": {
            str(block_id): [
                {
                    "target": region.target,
                    "end": region.end,
                    "incoming": list(region.incoming),
                    "instructions": [asdict(instr) for instr in region.instructions],
                }
                for region in regions
            ]
            for block_id, regions in sorted(regions_by_block.items())
        },
    }
    (out_dir / "ecl_dialog_reference.json").write_text(json.dumps(payload, indent=2), encoding="utf-8")
    (out_dir / "ecl_dialog_conversations.json").write_text(json.dumps(conversations, indent=2), encoding="utf-8")

    with (out_dir / "ecl_missing_text_attachments.tsv").open("w", encoding="utf-8", newline="") as f:
        fieldnames = [
            "unique_index",
            "block_id",
            "offset",
            "vm_address",
            "text",
            "attachment_kind",
            "owner_target",
            "owner_summary",
            "owner_incoming",
        ]
        writer = csv.DictWriter(f, fieldnames=fieldnames, delimiter="\t")
        writer.writeheader()
        for item in attached:
            row = asdict(item)
            row["offset"] = f"0x{item.offset:04X}"
            row["vm_address"] = f"0x{item.vm_address:04X}"
            row["owner_target"] = "" if item.owner_target is None else f"0x{item.owner_target:04X}"
            row["owner_incoming"] = "; ".join(item.owner_incoming)
            writer.writerow({name: row[name] for name in fieldnames})

    with (out_dir / "ecl_dialog_conversations.tsv").open("w", encoding="utf-8", newline="") as f:
        fieldnames = [
            "geo_id",
            "geo_name",
            "ecl_block",
            "event_id",
            "event_target_hex",
            "dialog_target_hex",
            "choice_labels",
            "choice_targets",
            "confidence",
        ]
        writer = csv.DictWriter(f, fieldnames=fieldnames, delimiter="\t")
        writer.writeheader()
        for row in conversations:
            writer.writerow(
                {
                    "geo_id": row["geo_id"],
                    "geo_name": row["geo_name"],
                    "ecl_block": row["ecl_block"],
                    "event_id": row["event_id"],
                    "event_target_hex": row["event_target_hex"],
                    "dialog_target_hex": row["dialog_target_hex"],
                    "choice_labels": "; ".join(str(choice["label"]) for choice in row["choices"]),
                    "choice_targets": "; ".join(str(choice["branch_target_hex"]) for choice in row["choices"]),
                    "confidence": row["confidence"],
                }
            )

    attached_by_block: dict[int, list[AttachedMissingText]] = {}
    for item in attached:
        attached_by_block.setdefault(item.block_id, []).append(item)

    lines = [
        "# Matrix Cubed ECL Dialog Trees Reference",
        "",
        "This file is generated from decoded ECL listings plus the Gold Box whole-block text scan.",
        "It is a reference for dialog/menu reconstruction, not proof that every nearby packed string is owned by the displayed instruction.",
        "",
        "## Summary",
        "",
        f"- Missing Gold Box text hit rows attached: {len(attached)}",
        f"- Unique normalized still-missing strings: {unique_count}",
        f"- Compiled dialog conversation rows: {len(conversations)}",
        "- Address mapping: `vm_address = 0x8000 + decoded ECL block offset`",
    ]
    for kind, count in sorted(by_kind.items()):
        lines.append(f"- `{kind}`: {count}")
    lines.extend(
        [
            "",
            "## Compiled Dialog Conversations",
            "",
            "These compact rows are intended for runtime and capture validation. They retain confidence labels because nearby missing-text attachments are not proof of ownership by themselves.",
            "",
            "| GEO | Event | Target | Choices | Confidence |",
            "|---:|---:|---:|---|---|",
        ]
    )
    for row in conversations:
        labels = "; ".join(
            f"{choice['label']}{' -> ' + choice['branch_target_hex'] if choice['branch_target_hex'] else ''}"
            for choice in row["choices"]
        )
        lines.append(
            f"| {row['geo_id']} {md_escape(str(row['geo_name']))} | {row['event_id']} | {row['event_target_hex']} "
            f"| {md_escape(labels)} | {row['confidence']} |"
        )
    lines.extend(
        [
            "",
            "## Still-Missing Text Attachments",
            "",
            "| # | ECL | VM address | Text | Attachment | Owner target | Owner summary |",
            "|---:|---:|---:|---|---|---:|---|",
        ]
    )
    for item in sorted(attached, key=lambda row: (row.unique_index, row.block_id, row.vm_address)):
        target = "" if item.owner_target is None else f"0x{item.owner_target:04X}"
        lines.append(
            f"| {item.unique_index} | {item.block_id} | 0x{item.vm_address:04X} | {md_escape(item.text)} "
            f"| {item.attachment_kind} | {target} | {md_escape(item.owner_summary)} |"
        )

    lines.extend(["", "## Dialog Trees By ECL Block", ""])
    for block_id in sorted(instructions_by_block):
        instructions = instructions_by_block[block_id]
        if not instructions:
            continue
        block_missing = attached_by_block.get(block_id, [])
        has_dialog = any(any(word in instr.body for word in TEXT_WORDS) for instr in instructions)
        if not has_dialog and not block_missing:
            continue
        atlas = event_atlas_by_ecl.get(block_id)
        title = f"ECL {block_id}"
        if atlas:
            title += f" - GEO {atlas.get('geo_id')}: {atlas.get('name')}"
        lines.extend([f"### {title}", ""])
        if block_missing:
            lines.append("Attached still-missing strings:")
            for item in sorted(block_missing, key=lambda row: row.vm_address):
                target = "" if item.owner_target is None else f" owner 0x{item.owner_target:04X};"
                incoming = f" incoming: {'; '.join(item.owner_incoming)}" if item.owner_incoming else ""
                lines.append(f"- 0x{item.vm_address:04X}:{target} `{item.attachment_kind}` `{item.text}`.{incoming}")
            lines.append("")
        lines.append("| Target/Addr | Incoming / Instruction | Extracted text or menu |")
        lines.append("|---:|---|---|")
        for region in regions_by_block.get(block_id, []):
            text_instrs = [instr for instr in region.instructions if any(word in instr.body for word in TEXT_WORDS)]
            if not text_instrs and not any(item.owner_target == region.target for item in block_missing):
                continue
            incoming = "<br>".join(md_escape(value) for value in region.incoming) if region.incoming else ""
            for index, instr in enumerate(text_instrs[:12]):
                prefix = f"0x{region.target:04X}" if index == 0 else ""
                incoming_text = incoming if index == 0 else ""
                lines.append(f"| {prefix} | {incoming_text} | `{md_escape(instr.row)}` |")
        lines.append("")

    doc_path.write_text("\n".join(lines), encoding="utf-8")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--compare-json", type=Path, default=DEFAULT_COMPARE_JSON)
    parser.add_argument("--listing-dir", type=Path, default=DEFAULT_LISTING_DIR)
    parser.add_argument("--event-atlas", type=Path, default=DEFAULT_EVENT_ATLAS)
    parser.add_argument("--out-dir", type=Path, default=DEFAULT_OUT_DIR)
    parser.add_argument("--doc-path", type=Path, default=DEFAULT_DOC_PATH)
    args = parser.parse_args()

    hits = load_substring_missing_hits(args.compare_json)
    rows_by_block = load_listing_rows(args.listing_dir)
    contexts = contextualize_hits(hits, rows_by_block)
    entries_by_block, instructions_by_block = load_listings(args.listing_dir)
    regions_by_block = build_regions(entries_by_block, instructions_by_block)
    attached = attach_contexts(contexts, regions_by_block)
    write_outputs(attached, regions_by_block, instructions_by_block, load_event_atlas(args.event_atlas), args.out_dir, args.doc_path)
    print(
        "ECL dialog reference: "
        f"{len(attached)} missing text hit attachments, "
        f"{len({item.normalized_text for item in attached})} unique strings, "
        f"{len(instructions_by_block)} ECL listing blocks"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
