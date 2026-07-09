/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0b1a
 * Ghidra name: FUN_0000_0b1a
 * Linear address: 0x00B1A
 * Original GAME.OVR file offset: 2850
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0b1a(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  ((undefined *)&DAT_0000_7756)[in_BX + unaff_SI] =
       ((undefined *)&DAT_0000_7756)[in_BX + unaff_SI] + (char)((uint)in_AX >> 8);
  uVar1 = FUN_0000_06f8();
  *(undefined2 *)0x4432 = uVar1;
  return;
}


