from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class DaxBlock:
    file_name: str
    block_id: int
    offset: int
    raw_size: int
    packed_size: int
    data: bytes


def _sbyte(value: int) -> int:
    return value - 256 if value >= 128 else value


def decompress(raw_size: int, compressed: bytes) -> bytes:
    out = bytearray(raw_size)
    inp = 0
    outp = 0
    while inp < len(compressed) and outp < raw_size:
        run = _sbyte(compressed[inp])
        if run >= 0:
            count = run + 1
            chunk = compressed[inp + 1 : inp + 1 + count]
            out[outp : outp + len(chunk)] = chunk
            inp += count + 1
            outp += len(chunk)
        else:
            count = -run
            if inp + 1 >= len(compressed):
                break
            end = min(outp + count, raw_size)
            out[outp:end] = bytes([compressed[inp + 1]]) * (end - outp)
            inp += 2
            outp = end
    return bytes(out)


def read_dax(path: Path) -> list[DaxBlock]:
    data = path.read_bytes()
    toc_len = int.from_bytes(data[:2], "little")
    data_offset = toc_len + 2
    blocks: list[DaxBlock] = []
    for off in range(2, data_offset, 9):
        if off + 9 > len(data):
            break
        block_id = data[off]
        rel = int.from_bytes(data[off + 1 : off + 5], "little")
        raw_size = int.from_bytes(data[off + 5 : off + 7], "little")
        packed_size = int.from_bytes(data[off + 7 : off + 9], "little")
        packed = data[data_offset + rel : data_offset + rel + packed_size]
        block = packed if raw_size <= 0 else decompress(raw_size, packed)
        blocks.append(DaxBlock(path.name, block_id, rel, raw_size, packed_size, block))
    return blocks
