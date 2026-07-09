from __future__ import annotations

from matrix_cubed.formats.save import parse_who_record


TST2_WHO = bytes.fromhex(
    "04545354320000000000000000000000110e0d0e0f0d0f110e0d0e0f0d0f0c0c"
    "0c0b0b0e0b0b0001010700e8030000409c00002b01000c321800000200010002"
    "00000000001f0000000000000000000000000000000000000019000000000000"
    "0000000000000019000000000000000014000000000000000000460000000055"
    "0a280a0a320a0a0a000000000000005500000000000000000000000000000028"
    "000000000000000000000000000000000000000000000000200a000000000000"
    "00000000000102030405060708090a0b0c0d0e0f010100002c32300000010002"
    "0001001f000c00000000000000000000000000000000000800fa560000000000"
    "000000"
)


def test_parse_live_created_who_record() -> None:
    record = parse_who_record(TST2_WHO)

    assert record.name == "TST2"
    assert record.ability_scores == {
        "str": 17,
        "dex": 14,
        "con": 13,
        "int": 14,
        "wis": 15,
        "cha": 13,
        "tech": 15,
    }
    assert record.current_ability_scores == record.ability_scores
    assert record.race_id == 1
    assert record.race == "terran"
    assert record.gender_id == 0
    assert record.gender == "male"
    assert record.career_id == 1
    assert record.career == "rocket_jock"
    assert record.level == 7
    assert record.credits == 1000
    assert record.experience == 40000
    assert record.age == 24
    assert record.hit_points_candidate == 31


def test_parse_who_record_rejects_wrong_size() -> None:
    try:
        parse_who_record(b"short")
    except ValueError as exc:
        assert "259-byte" in str(exc)
    else:
        raise AssertionError("short .WHO data was accepted")


def test_known_enum_candidates_from_controlled_samples() -> None:
    female = bytearray(TST2_WHO)
    female[0x26] = 1
    assert parse_who_record(bytes(female)).gender == "female"

    martian = bytearray(TST2_WHO)
    martian[0x27] = 2
    assert parse_who_record(bytes(martian)).race == "martian"

    medic = bytearray(TST2_WHO)
    medic[0x28] = 2
    assert parse_who_record(bytes(medic)).career == "medic"
