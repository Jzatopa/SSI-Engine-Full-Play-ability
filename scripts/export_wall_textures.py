#!/usr/bin/env python3
"""Assemble Matrix Cubed WALLDEF wall-view textures from extracted 8x8 tiles."""

from __future__ import annotations

import argparse
from pathlib import Path

from PIL import Image


IDX_OFFSET = [0, 2, 6, 10, 22, 38, 54, 110, 132, 154]
COL_COUNT = [1, 1, 1, 3, 2, 2, 7, 2, 2, 1]
ROW_COUNT = [2, 4, 4, 4, 8, 8, 8, 11, 11, 2]
WALL_SLICE_SIZE = 156
TRANSPARENCY_COLORS = {(255, 82, 255), (255, 85, 255), (170, 0, 170)}


def sbyte(value: int) -> int:
    return value - 256 if value >= 128 else value


def dax_decompress(raw_size: int, compressed: bytes) -> bytes:
    out = bytearray(raw_size)
    inp = 0
    outp = 0
    while inp < len(compressed) and outp < raw_size:
        run = sbyte(compressed[inp])
        if run >= 0:
            n = run + 1
            chunk = compressed[inp + 1 : inp + 1 + n]
            out[outp : outp + len(chunk)] = chunk
            inp += run + 2
            outp += len(chunk)
        else:
            n = -run
            if inp + 1 >= len(compressed):
                break
            end = min(outp + n, raw_size)
            out[outp:end] = bytes([compressed[inp + 1]]) * (end - outp)
            inp += 2
            outp = end
    return bytes(out)


def read_dax(path: Path) -> dict[int, bytes]:
    data = path.read_bytes()
    toc_len = int.from_bytes(data[:2], "little")
    data_offset = toc_len + 2
    blocks: dict[int, bytes] = {}
    for off in range(2, data_offset, 9):
        if off + 9 > len(data):
            break
        block_id = data[off]
        rel = int.from_bytes(data[off + 1 : off + 5], "little")
        raw_size = int.from_bytes(data[off + 5 : off + 7], "little")
        packed_size = int.from_bytes(data[off + 7 : off + 9], "little")
        packed = data[data_offset + rel : data_offset + rel + packed_size]
        if not packed:
            continue
        blocks[block_id] = packed if raw_size <= 0 else dax_decompress(raw_size, packed)
    return blocks


def load_tiles(tile_dir: Path, block_id: int) -> list[Image.Image]:
    tiles = []
    for tile_id in range(256):
        path = tile_dir / f"8X8D1_{block_id:03d}_{tile_id:03d}.png"
        if not path.exists():
            break
        tiles.append(apply_transparency(Image.open(path).convert("RGBA")))
    if not tiles:
        raise FileNotFoundError(f"no extracted 8X8D1 tiles found for block {block_id}")
    tiles[0] = transparent_tile()
    return tiles


def magenta_tile() -> Image.Image:
    return Image.new("RGBA", (8, 8), (255, 82, 255, 255))


def transparent_tile() -> Image.Image:
    return Image.new("RGBA", (8, 8), (0, 0, 0, 0))


def apply_transparency(image: Image.Image) -> Image.Image:
    pixels = image.load()
    for y in range(image.height):
        for x in range(image.width):
            r, g, b, a = pixels[x, y]
            if (r, g, b) in TRANSPARENCY_COLORS:
                pixels[x, y] = (r, g, b, 0)
    return image


def assemble_view(tile_ids: list[int], rows: int, cols: int, tiles: list[Image.Image]) -> Image.Image:
    image = Image.new("RGBA", (cols * 8, rows * 8), (0, 0, 0, 0))
    for row in range(rows):
        for col in range(cols):
            tile_id = tile_ids[row * cols + col]
            tile = tiles[tile_id] if 0 <= tile_id < len(tiles) else magenta_tile()
            image.alpha_composite(tile, (col * 8, row * 8))
    return image


def export_wallset(block_id: int, data: bytes, tile_dir: Path, out_dir: Path) -> int:
    tiles = load_tiles(tile_dir, block_id)
    count = 0
    wall_count = len(data) // WALL_SLICE_SIZE
    for wall_index in range(wall_count):
        base = wall_index * WALL_SLICE_SIZE
        wall_number = wall_index + 1
        for view_id, idx in enumerate(IDX_OFFSET):
            rows = ROW_COUNT[view_id]
            cols = COL_COUNT[view_id]
            tile_ids = []
            cursor = base + idx
            for _row in range(rows):
                for _col in range(cols):
                    tile_ids.append(data[cursor])
                    cursor += 1
            image = assemble_view(tile_ids, rows, cols, tiles)
            path = out_dir / f"walldef1_{block_id:03d}_wall_{wall_number:02d}_view_{view_id:02d}.png"
            image.save(path)
            count += 1
    return count


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("walldef_dax", type=Path)
    parser.add_argument("tile_dir", type=Path)
    parser.add_argument("out_dir", type=Path)
    args = parser.parse_args()

    args.out_dir.mkdir(parents=True, exist_ok=True)
    blocks = read_dax(args.walldef_dax)
    total = 0
    for block_id, data in sorted(blocks.items()):
        total += export_wallset(block_id, data, args.tile_dir, args.out_dir)
    print(f"exported {total} wall texture views from {len(blocks)} wallsets")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
