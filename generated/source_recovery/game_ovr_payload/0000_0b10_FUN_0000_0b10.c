/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0b10
 * Ghidra name: FUN_0000_0b10
 * Linear address: 0x00B10
 * Original GAME.OVR file offset: 2840
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0b10(void)

{
  undefined1 extraout_AH;
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = 1;
  func_0x000006da();
  uVar1 = FUN_0000_06f8(0x6b,CONCAT11(extraout_AH,*(undefined *)&DAT_0000_7716),
                        CONCAT11(extraout_AH,*(undefined *)&DAT_0000_7756),uVar1);
  *(undefined2 *)0x4432 = uVar1;
  return;
}


