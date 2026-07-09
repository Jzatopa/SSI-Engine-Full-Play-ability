# GAME.OVR Analysis

- Path: `/home/jzatopa/Downloads/Buck Rogers Matrix Cubed - Source/MATRIX/GAME.OVR`
- Bytes: `212529`
- SHA-256: `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`
- Magic: `FBOV`
- ASCII strings: `1007`
- Pascal-style string candidates: `724`
- ITEMS records: `39` records of 9 bytes

## Item Name Verdict

GAME.OVR contains item UI/debug fields, including namenum(1..3), but obvious item names are not present as plain ASCII/Pascal strings.

Plaintext item-name search found no obvious weapon/item nouns such as knife, pistol, rifle, laser, blaster, or shield. Keep runtime labels conservative (`Item N`) until the `namenum(1..3)` fields are mapped to their source table.

## Key Anchors

- `000000` `overlay_magic`: FBOV overlay marker — FBOV)>; WARNING: Insufficient Memory$Insufficient Memory. Exiting ProgramU
- `000393` `credits`: credits text starts — $CREATED BY:SSI SPECIAL PROJECTS TEAM; GAME DEVELOPMENT:; PROGRAMMING:
- `065336` `combat_start`: A battle begins... — A battle begins...U
- `099509` `character_creation`: Pick Race / Pick Gender / Pick Class — 	Pick Race; Select; Pick Gender
- `126462` `item0_loader`: ITEM0.dax loader/error strings — >8D	t; ITEM0; .dax
- `129547` `save_character`: Lose character / save prompts — "Can't save.  No room on this disk.; Lose character? ; Ok  Try another disk
- `134527` `load_game`: Load Which Game — load from:; Matrix Countdown; .dat
- `136472` `save_game`: Save Which Game — Save Which Game: ; A B C D E F G H I J; .dat"Can't save.  No room on this disk.
- `139303` `character_sheet_labels`: name/race/gender/thaco/career labels — )@*V*`*o*t*; name  :; race  :
- `143848` `item_debug_fields`: itemptr/namenum/plus/ready fields — Must be unreadiedU; itemptr:      ; namenum(1):   
- `145587` `gear_menu`: gear ready/trade/drop/sell menu —  has no gear.; Ready ;  Trade
- `117370` `shop_menu`: Buy Sell Ammo View Pool — Buy Sell Ammo View Pool ; Take Divvy ; ExitRAs you Leave the Shopkeeper says, "Excuse me but you have Left Some Money here."  *Do you want to go back and get your Money?%Thanks for the tip.  Have a nice day.U
- `178171` `ship_stats`: ship name/type/range labels — &;E ~; &;E ~; name:

## Densest String Clusters

- `176128-180223`: 51 strings
- `094208-098303`: 48 strings
- `090112-094207`: 47 strings
- `143360-147455`: 44 strings
- `028672-032767`: 41 strings
- `024576-028671`: 40 strings
- `147456-151551`: 39 strings
- `016384-020479`: 38 strings
- `000000-004095`: 36 strings
- `114688-118783`: 35 strings
- `188416-192511`: 31 strings
- `045056-049151`: 30 strings
