# Controlled Save Samples

Save directory: `/home/jzatopa/Downloads/matrix-cubed-liveplay/MATRIX/SAVE`
Baseline for byte diffs: `TST2`

## Characters

| Stem | Intent | Race | Gender | Career | Level | XP | HP Candidate |
| --- | --- | --- | --- | --- | ---: | ---: | ---: |
| CHRDATA1 | terran male medic career variant | terran (1) | male (0) | medic (2) | 7 | 48000 | 38 |
| GEN1 | terran female rocket_jock gender variant | terran (1) | female (1) | rocket_jock (1) | 7 | 40000 | 34 |
| RAC1 | martian male rocket_jock race variant | martian (2) | male (0) | rocket_jock (1) | 7 | 40000 | 43 |
| TST1 | terran male rocket_jock baseline | terran (1) | male (0) | rocket_jock (1) | 7 | 40000 | 31 |
| TST2 | terran male rocket_jock baseline | terran (1) | male (0) | rocket_jock (1) | 7 | 40000 | 31 |

## Confirmed Enum Offsets

- `0x26` `gender_id_candidate`: 0=male, 1=female. Evidence: TST1, TST2, RAC1, GEN1, CAR1.
- `0x27` `race_id_candidate`: 1=terran, 2=martian. Evidence: TST1, TST2, RAC1, GEN1, CAR1.
- `0x28` `career_id_candidate`: 1=rocket_jock, 2=medic. Evidence: TST1, TST2, RAC1, GEN1, CAR1.

## Diff Notes

Byte diffs are generated in the JSON artifact. Many differences are expected because stats, age, HP, and name vary between random character rolls.
