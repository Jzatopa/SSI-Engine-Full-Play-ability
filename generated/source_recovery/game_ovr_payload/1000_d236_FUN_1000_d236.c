/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:d236
 * Ghidra name: FUN_1000_d236
 * Linear address: 0x1D236
 * Original GAME.OVR file offset: 119358
 * Body addresses: 326
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_1000_d236(void)

{
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 uVar1;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  undefined2 unaff_DS;
  int local_5;
  
  *(undefined1 *)0x8c33 = 0;
  *(undefined1 *)0x8c34 = 0;
  *(undefined1 *)0x8c22 = 0;
  *(undefined1 *)0x8c23 = 0;
  *(code *)FUN_0000_7638 = (code)0x41;
  *(undefined1 *)0x7639 = 9;
  *(undefined1 *)0x8c37 = 1;
  FUN_0000_e6d2(0);
  *(undefined1 *)0x7653 = 8;
  *(undefined2 *)0x4432 = 0x8000;
  *(undefined1 *)0x7816 = 0;
  *(undefined2 *)0x7640 = 0;
  *(undefined2 *)0x7642 = 0;
  *(undefined2 *)0x7644 = 0;
  *(undefined2 *)0x7646 = 0;
  FUN_0000_e6d2(0);
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2d2) = 0;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2d3) = 0;
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xe5) = 0;
  FUN_1000_cf61(CONCAT11(extraout_AH,1));
  uVar1 = FUN_1000_d677(CONCAT11(extraout_AH_00,*(undefined *)&DAT_0000_7716),
                        CONCAT11(extraout_AH_00,*(undefined *)&DAT_0000_7756));
  *(undefined2 *)0x4428 = uVar1;
  FUN_1000_cf61(1);
  uVar1 = FUN_1000_d677(CONCAT11(extraout_AH_01,*(undefined *)&DAT_0000_7716),
                        CONCAT11(extraout_AH_01,*(undefined *)&DAT_0000_7756));
  *(undefined2 *)0x442a = uVar1;
  FUN_1000_cf61(1);
  uVar1 = FUN_1000_d677(CONCAT11(extraout_AH_02,*(undefined *)&DAT_0000_7716),
                        CONCAT11(extraout_AH_02,*(undefined *)&DAT_0000_7756));
  *(undefined2 *)0x442c = uVar1;
  FUN_1000_cf61(1);
  uVar1 = FUN_1000_d677(CONCAT11(extraout_AH_03,*(undefined *)&DAT_0000_7716),
                        CONCAT11(extraout_AH_03,*(undefined *)&DAT_0000_7756));
  *(undefined2 *)0x442e = uVar1;
  FUN_1000_cf61(1);
  uVar1 = FUN_1000_d677(CONCAT11(extraout_AH_04,*(undefined *)&DAT_0000_7716),
                        CONCAT11(extraout_AH_04,*(undefined *)&DAT_0000_7756));
  *(undefined2 *)0x4430 = uVar1;
  if (*(char *)0x4441 == '\0') {
    for (local_5 = 1; *(undefined1 *)((int)*(undefined4 *)0x4418 + local_5 + 0xff) = 0,
        local_5 != 0x20; local_5 = local_5 + 1) {
    }
    for (local_5 = 0; *(undefined1 *)((int)*(undefined4 *)0x441c + local_5 + 0x379) = 0,
        local_5 != 9; local_5 = local_5 + 1) {
    }
  }
  return;
}


