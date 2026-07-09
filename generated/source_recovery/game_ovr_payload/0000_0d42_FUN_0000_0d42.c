/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0d42
 * Ghidra name: FUN_0000_0d42
 * Linear address: 0x00D42
 * Original GAME.OVR file offset: 3402
 * Body addresses: 6
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0d42(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar1 = (uint)*(byte *)0x7757;
  uVar2 = (uint)*(byte *)0x7717;
  uVar3 = FUN_0000_06f8();
  *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP) = uVar3;
  if (*(byte *)0x76d6 < 0x80) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_06d5(0x6b,1,uVar2,uVar1);
  }
  func_0x00000707(0x6b,0x7818);
  return;
}


