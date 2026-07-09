# Matrix Cubed Startup Input Map

Status: string-evidence map with marked inferred transitions
Scope: startup inputs from executable setup through Begin Adventuring

## Nodes

### Graphics Adapter Type (`graphics_adapter`)

- Kind: `setup_prompt`
- Evidence: START.EXE offset 5287: GRAPHICS ADAPTER TYPE: [1] EGA [2] Tandy [3] VGA

| Input | Result | Target |
| --- | --- | --- |
| `1` | EGA | `sound_type` |
| `2` | Tandy | `sound_type` |
| `3` | VGA | `sound_type` |

### Sound Type (`sound_type`)

- Kind: `setup_prompt`
- Evidence: START.EXE offsets 5444-5566: SOUND TYPE choices

| Input | Result | Target |
| --- | --- | --- |
| `1` | PC speaker | `alternate_input` |
| `2` | Sound Blaster | `alternate_input` |
| `3` | Adlib | `alternate_input` |
| `4` | Roland MT32 | `alternate_input` |
| `5` | Tandy 1000 | `alternate_input` |
| `6` | Silent | `alternate_input` |

### Alternate Input Type (`alternate_input`)

- Kind: `setup_prompt`
- Evidence: START.EXE offset 5566: ALTERNATE INPUT TYPE: [1] JOYSTICK [2] MOUSE [3] NEITHER

| Input | Result | Target |
| --- | --- | --- |
| `1` | Joystick (Calibration prompts follow if selected.) | `joystick_calibration` |
| `2` | Mouse | `save_path` |
| `3` | Neither | `save_path` |

### Joystick Calibration (`joystick_calibration`)

- Kind: `setup_prompt`
- Evidence: START.EXE offset 45461: upper-left calibration prompt
- Evidence: START.EXE offset 45461: lower-right calibration prompt
- Note: The exact abort/retry loop needs live DOS validation.

| Input | Result | Target |
| --- | --- | --- |
| `button 1` | Confirm upper-left | `joystick_calibration_lower` |
| `abort` | Could not read joystick | `alternate_input` |

### Joystick Calibration Lower Right (`joystick_calibration_lower`)

- Kind: `setup_prompt`
- Evidence: START.EXE offset 45461: Push JOYSTICK #1 to the extreme lower right position and press BUTTON #1.

| Input | Result | Target |
| --- | --- | --- |
| `button 1` | Confirm lower-right | `save_path` |

### Save Path (`save_path`)

- Kind: `setup_prompt`
- Evidence: START.EXE offsets 5639-5734: SAVE / PATH TO SAVE DATA / USING DEFAULT PATH / :\SAVE
- Evidence: START.EXE offset 5734: :\BUCK\SAVE

| Input | Result | Target |
| --- | --- | --- |
| `Enter` | Use default save path | `loading_overlay` |
| `text` | Type save path | `loading_overlay` |

### Loading (`loading_overlay`)

- Kind: `status`
- Evidence: START.EXE offset 29259: Loading...Please Wait

| Input | Result | Target |
| --- | --- | --- |
| `auto` | Continue when overlay loads | `title_sequence` |

### Title And Story Sequence (`title_sequence`)

- Kind: `presentation`
- Evidence: TITLE.DAX blocks 001-004
- Evidence: BIGPIC1.DAX blocks 112-117
- Evidence: START.EXE offset 60968: Press button or enter to continue
- Note: Exact timing and skip behavior still needs live DOS capture.

| Input | Result | Target |
| --- | --- | --- |
| `Enter` | Advance title/story screens | `startup_command_menu` |
| `button` | Advance title/story screens | `startup_command_menu` |
| `auto` | Timed screens may advance without input | `startup_command_menu` |

### Startup Command Menu (`startup_command_menu`)

- Kind: `menu`
- Evidence: START.EXE offsets 59986-60298: character, load/save, begin, and exit command labels
- Evidence: START.EXE offset 59934: Select Exit:
- Note: The earlier reconstruction used a compact inferred menu; this node is the stronger string-evidence map.

| Input | Result | Target |
| --- | --- | --- |
| `1` | Create New Character | `create_character` |
| `2` | Purge Character | `purge_character` |
| `3` | Modify Character | `modify_character` |
| `4` | Train Character | `train_character` |
| `5` | View Character | `view_character_pick` |
| `6` | Add Character to Team | `add_character` |
| `7` | Remove Character from Team | `remove_character` |
| `8` | Load Saved Game | `load_saved_game` |
| `9` | Save Current Game | `save_current_game` |
| `10` | Begin Adventuring | `game_start` |
| `11` | Exit to DOS | `exit_to_dos` |

### Create New Character (`create_character`)

- Kind: `character_flow`
- Evidence: START.EXE offset 59986: Create New Character
- Evidence: GAME.OVR offset 99509: Pick Race
- Evidence: GAME.OVR offset 99531: Pick Gender
- Evidence: GAME.OVR offset 99543: Pick Class
- Evidence: GAME.OVR offset 99554: Reroll stats?
- Evidence: GAME.OVR offset 99569: Character name:
- Evidence: GAME.OVR offset 99586: Save

| Input | Result | Target |
| --- | --- | --- |
| `select race` | Pick Race | `create_pick_gender` |
| `Exit` | Abort creation | `startup_command_menu` |

### Create Character: Pick Gender (`create_pick_gender`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 99531: Pick Gender

| Input | Result | Target |
| --- | --- | --- |
| `select gender` | Pick Gender | `create_pick_class` |
| `Exit` | Back | `startup_command_menu` |

### Create Character: Pick Class/Career (`create_pick_class`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 99543: Pick Class
- Evidence: START.EXE offsets 61712-61760: Rocket Jock, Medic, Warrior, Engineer, Rogue
- Evidence: START.EXE offsets 61812-61854: Martian, Venusian, Mercurian, Tinker, Desert Runner

| Input | Result | Target |
| --- | --- | --- |
| `select class` | Pick Class | `create_reroll_stats` |
| `Exit` | Back | `startup_command_menu` |

### Create Character: Reroll Stats (`create_reroll_stats`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 99554: Reroll stats?

| Input | Result | Target |
| --- | --- | --- |
| `Yes` | Reroll stats | `create_reroll_stats` |
| `No` | Keep stats | `create_name` |

### Create Character: Name (`create_name`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 99569: Character name:

| Input | Result | Target |
| --- | --- | --- |
| `text` | Enter character name | `create_skills` |

### Create Character: Skills (`create_skills`)

- Kind: `character_flow`
- Evidence: START.EXE offsets 62116-62242: skill category labels
- Evidence: GAME.OVR offsets 154711-154769: General skills, skill points, maximum per skill
- Evidence: GAME.OVR offsets 156204-156292: skill point and unspent-points checks

| Input | Result | Target |
| --- | --- | --- |
| `Add` | Add skill point | `create_skills` |
| `Subtract` | Subtract skill point | `create_skills` |
| `Keep` | Keep skill choices | `create_save` |
| `Exit` | Exit skill allocation (May prompt about unspent points.) | `create_save` |

### Create Character: Save (`create_save`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 99586: Save

| Input | Result | Target |
| --- | --- | --- |
| `Save` | Save character to CHARS.DAX | `startup_command_menu` |
| `Exit` | Return without saving | `startup_command_menu` |

### Purge Character (`purge_character`)

- Kind: `character_flow`
- Evidence: START.EXE offset 60015: Purge Character
- Evidence: GAME.OVR offset 129547: Lose character?
- Evidence: GAME.OVR offset 150247: Pick Character

| Input | Result | Target |
| --- | --- | --- |
| `Select` | Choose character to purge | `purge_confirm` |
| `Exit` | Return | `startup_command_menu` |

### Purge Character: Confirm (`purge_confirm`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 129547: Lose character?

| Input | Result | Target |
| --- | --- | --- |
| `Yes` | Delete character | `startup_command_menu` |
| `No` | Cancel | `startup_command_menu` |

### Modify Character (`modify_character`)

- Kind: `character_flow`
- Evidence: START.EXE offset 60038: Modify Character
- Evidence: GAME.OVR offset 102225: Modify:
- Evidence: GAME.OVR offset 102234: Add Subtract Keep Exit

| Input | Result | Target |
| --- | --- | --- |
| `Select` | Choose character to modify | `modify_skills` |
| `Exit` | Return | `startup_command_menu` |

### Modify Character: Skills (`modify_skills`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 102234: Add Subtract Keep Exit

| Input | Result | Target |
| --- | --- | --- |
| `Add` | Add point | `modify_skills` |
| `Subtract` | Subtract point | `modify_skills` |
| `Keep` | Save changes | `startup_command_menu` |
| `Exit` | Cancel or exit | `startup_command_menu` |

### Train Character (`train_character`)

- Kind: `character_flow`
- Evidence: START.EXE offset 60081: Train Character
- Evidence: GAME.OVR offset 109065: conscious/max-level checks
- Evidence: GAME.OVR offset 109186: Do you wish to train?

| Input | Result | Target |
| --- | --- | --- |
| `Select` | Choose character to train | `train_confirm` |
| `Exit` | Return | `startup_command_menu` |

### Train Character: Confirm (`train_confirm`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 109186: Do you wish to train?

| Input | Result | Target |
| --- | --- | --- |
| `Yes` | Train selected character | `startup_command_menu` |
| `No` | Cancel | `startup_command_menu` |

### View Character: Pick (`view_character_pick`)

- Kind: `character_flow`
- Evidence: START.EXE offset 60104: View Character
- Evidence: GAME.OVR offset 150247: Pick Character
- Evidence: GAME.OVR offset 150263: Select Exit

| Input | Result | Target |
| --- | --- | --- |
| `Select` | View selected character | `view_character_sheet` |
| `Exit` | Return | `startup_command_menu` |

### View Character: Sheet (`view_character_sheet`)

- Kind: `character_flow`
- Evidence: GAME.OVR offset 139315: name
- Evidence: GAME.OVR offset 139342: career
- Evidence: GAME.OVR offset 139446: career skills
- Evidence: GAME.OVR offset 143132: Skills
- Note: Exact sub-tabs need live capture or deeper disassembly.

| Input | Result | Target |
| --- | --- | --- |
| `View` | Cycle/details | `view_character_sheet` |
| `Exit` | Return | `startup_command_menu` |

### Add Character To Team (`add_character`)

- Kind: `character_flow`
- Evidence: START.EXE offset 60126: Add Character to Team
- Evidence: GAME.OVR offset 104505: Add a character:
- Evidence: GAME.OVR offset 104523: Add

| Input | Result | Target |
| --- | --- | --- |
| `Add` | Add selected roster character to active team | `startup_command_menu` |
| `Exit` | Return | `startup_command_menu` |

### Remove Character From Team (`remove_character`)

- Kind: `character_flow`
- Evidence: START.EXE offset 60156: Remove Character from Team
- Note: Exact confirmation text is not yet identified in strings.

| Input | Result | Target |
| --- | --- | --- |
| `Select` | Remove selected active team member | `startup_command_menu` |
| `Exit` | Return | `startup_command_menu` |

### Load Saved Game (`load_saved_game`)

- Kind: `save_flow`
- Evidence: START.EXE offset 60190: Load Saved Game
- Evidence: GAME.OVR offset 134527: Load Which Game:
- Evidence: GAME.OVR offset 127429: from saved game
- Evidence: GAME.OVR offset 128551: Is your save disk in drive

| Input | Result | Target |
| --- | --- | --- |
| `slot/name` | Choose saved game (Loaded game returns to command/menu or map depending save state.) | `startup_command_menu` |
| `Exit` | Cancel | `startup_command_menu` |

### Save Current Game (`save_current_game`)

- Kind: `save_flow`
- Evidence: START.EXE offset 60214: Save Current Game
- Evidence: START.EXE offset 29338: Saving...Please Wait
- Evidence: GAME.OVR offset 136472: Save Which Game:
- Evidence: GAME.OVR offset 129678: Overwrite Rename Abort save

| Input | Result | Target |
| --- | --- | --- |
| `slot/name` | Choose save target | `save_confirm` |
| `Exit` | Cancel | `startup_command_menu` |

### Save Current Game: Confirm (`save_confirm`)

- Kind: `save_flow`
- Evidence: GAME.OVR offset 129678: Overwrite Rename Abort save

| Input | Result | Target |
| --- | --- | --- |
| `Overwrite` | Overwrite existing save | `startup_command_menu` |
| `Rename` | Enter new file name | `save_current_game` |
| `Abort save` | Cancel | `startup_command_menu` |

### Exit To DOS (`exit_to_dos`)

- Kind: `exit_flow`
- Evidence: START.EXE offset 60298: Exit to DOS
- Evidence: GAME.OVR offset 98188: Game NOT saved. Quit anyway?

| Input | Result | Target |
| --- | --- | --- |
| `Yes` | Quit to DOS | `dos_exit` |
| `No` | Return | `startup_command_menu` |

### DOS Exit (`dos_exit`)

- Kind: `terminal`
- Evidence: Terminal state inferred from Exit to DOS.

Terminal node.

### Begin Adventuring / Game Starts (`game_start`)

- Kind: `terminal`
- Evidence: START.EXE offset 60239: Begin Adventuring
- Evidence: GAME.OVR offset 65336: A battle begins...
- Evidence: Existing runtime prototype starts at GEO 017 Caloris Space Port.
- Note: This is the requested boundary: startup input mapping stops once the adventuring runtime begins.

Terminal node.
