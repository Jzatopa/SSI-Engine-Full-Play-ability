"""Decoder for Buck Rogers Matrix Cubed saved inventory (``.STF``) files.

Local save files prove that STF is a variable-length array of 62-byte item
records. Each record has a 46-byte runtime/display prefix followed by a
16-byte ITEM0-shaped payload. Unresolved fields are exposed as raw bytes.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path

STF_RECORD_SIZE = 62
STF_ITEM_PAYLOAD_OFFSET = 46


@dataclass(frozen=True)
class SavedItemRecord:
    record_index: int
    prefix: bytes
    item_payload: bytes

    @property
    def itemptr(self) -> int:
        return self.item_payload[0]

    @property
    def is_equipped(self) -> bool:
        """Original GAME.OVR tests record offset 0x34 bit 0x80."""
        return bool(self.item_payload[6] & 0x80)

    @property
    def quantity(self) -> int:
        """Original GAME.OVR stacks/decrements record offset 0x38."""
        return self.item_payload[10]


@dataclass(frozen=True)
class SavedInventory:
    records: tuple[SavedItemRecord, ...]
    raw: bytes


def parse_stf(data: bytes) -> SavedInventory:
    if len(data) % STF_RECORD_SIZE:
        raise ValueError(f"expected .STF size divisible by {STF_RECORD_SIZE}, got {len(data)} bytes")
    records = []
    for index, offset in enumerate(range(0, len(data), STF_RECORD_SIZE)):
        raw = data[offset : offset + STF_RECORD_SIZE]
        records.append(SavedItemRecord(index, raw[:STF_ITEM_PAYLOAD_OFFSET], raw[STF_ITEM_PAYLOAD_OFFSET:]))
    return SavedInventory(tuple(records), data)


def read_stf(path: Path) -> SavedInventory:
    return parse_stf(path.read_bytes())
