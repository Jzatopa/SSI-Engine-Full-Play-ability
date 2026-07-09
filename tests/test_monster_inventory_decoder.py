from scripts.decode_monster_inventory import decode


def test_monster_inventory_decoder_preserves_executable_block_boundary() -> None:
    report = decode()
    assert report["item0_template_count"] == 91
    assert report["mon0itm_block_count"] == 42
    assert report["record_layout"] == {
        "record_size": 62,
        "unresolved_prefix_size": 46,
        "item_payload_offset": 46,
        "item_payload_size": 16,
        "all_blocks_divisible": True,
    }
    assert report["summary"] == {
        "record_count": 143,
        "exact_item0_match_count": 18,
        "blocks_with_exact_matches": 13,
        "stable_field_item0_match_count": 64,
        "newly_recovered_mutable_match_count": 46,
        "saved_stf_file_count": 5,
        "saved_stf_record_count": 27,
        "saved_exact_item0_match_count": 15,
    }
    assert all(
        match["offset"] == match["record_index"] * 62 + 46
        for block in report["blocks"]
        for match in block["exact_item0_matches"]
    )
    block52 = next(block for block in report["blocks"] if block["monster_id"] == 52)
    assert block52["exact_item0_matches"] == [
        {
            "offset": 232,
            "record_index": 3,
            "template_index": 39,
            "itemptr": 3,
            "raw_hex": "03 00 03 13 01 00 20 00 04 00 00 c8 00 00 00 00",
        }
    ]
    assert "equipped flag" in report["boundary"]
    saved = {entry["name"]: entry for entry in report["saved_stf_files"]}
    assert {name: entry["record_count"] for name, entry in saved.items()} == {
        "CHRDATA1.STF": 16, "CHRDATA2.STF": 5, "CHRDATA3.STF": 2,
        "CHRDATA4.STF": 2, "CHRDATA5.STF": 2,
    }
    first = saved["CHRDATA1.STF"]["records"][0]
    assert first["itemptr"] == 20
    assert first["template_comparison"]["nearest_template_indices"] == [19]
    assert first["template_comparison"]["unique_nearest_differences"] == [
        {"payload_offset": 6, "template_value": 32, "saved_value": 160}
    ]
    assert first["template_comparison"]["stable_field_template_index"] == 19
    assert first["template_comparison"]["equipped"] is True
    assert first["template_comparison"]["quantity"] == 0
