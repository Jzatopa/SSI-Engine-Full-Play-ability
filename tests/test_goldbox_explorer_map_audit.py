from __future__ import annotations

from scripts.audit_goldbox_explorer_maps import extract_matrix_map_names


def test_extract_matrix_map_names_reads_only_matrix_cubed_table(tmp_path) -> None:
    source = tmp_path / "GeoDaxFile.cs"
    source.write_text(
        """
        maps = new Dictionary<int, string>
            {
                {16, "Chicagorg"},
            };
        _mapNames.Add((int)FileHelper.GameList.CountdownToDoomsday, maps);

        maps = new Dictionary<int, string>
            {
                {1, "Luna Base"},
                {17, "Caloris Space Port"},
                {115, "Jupiter Aircar"}
            };
        _mapNames.Add((int)FileHelper.GameList.MatrixCubed, maps);
        """,
        encoding="utf-8",
    )

    names = extract_matrix_map_names(source)

    assert names == {
        1: "Luna Base",
        17: "Caloris Space Port",
        115: "Jupiter Aircar",
    }
