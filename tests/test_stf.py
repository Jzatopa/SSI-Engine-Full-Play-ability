"""Tests for the evidence-backed .STF saved-inventory decoder."""

import pytest

from matrix_cubed.formats.stf import STF_RECORD_SIZE, parse_stf


def test_parse_stf_empty_inventory() -> None:
    assert parse_stf(b"").records == ()


def test_parse_stf_rejects_unaligned_data() -> None:
    with pytest.raises(ValueError, match="divisible by 62"):
        parse_stf(b"\x00" * 125)


def test_parse_stf_splits_62_byte_item_records_without_guessing_fields() -> None:
    first = bytes(range(STF_RECORD_SIZE))
    second = bytes((value + 62) & 0xFF for value in range(STF_RECORD_SIZE))
    inventory = parse_stf(first + second)
    assert len(inventory.records) == 2
    assert inventory.records[0].record_index == 0
    assert inventory.records[0].prefix == first[:46]
    assert inventory.records[0].item_payload == first[46:]
    assert inventory.records[0].itemptr == 46
    assert inventory.records[0].is_equipped is False
    assert inventory.records[0].quantity == 56
    assert inventory.records[1].prefix == second[:46]
    assert inventory.raw == first + second


def test_parse_stf_exposes_proven_equipped_bit_and_quantity_byte() -> None:
    raw = bytearray(STF_RECORD_SIZE)
    raw[46] = 20
    raw[46 + 6] = 0xA0
    raw[46 + 10] = 100
    item = parse_stf(bytes(raw)).records[0]
    assert item.itemptr == 20
    assert item.is_equipped is True
    assert item.quantity == 100
