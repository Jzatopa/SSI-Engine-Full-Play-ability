/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0d49
 * Ghidra name: FUN_0000_0d49
 * Linear address: 0x00D49
 * Original GAME.OVR file offset: 3409
 * Body addresses: 41
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_0d49(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar1 = FUN_0000_06f8();
  *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP) = uVar1;
  if (*(byte *)0x76d6 < 0x80) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_06d5(0x6b,1);
  }
  func_0x00000707(0x6b,0x7818);
  return;
}


