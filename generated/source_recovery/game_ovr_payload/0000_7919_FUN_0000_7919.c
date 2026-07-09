/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7919
 * Ghidra name: FUN_0000_7919
 * Linear address: 0x07919
 * Original GAME.OVR file offset: 31009
 * Body addresses: 22
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_7919(void)

{
  undefined2 uVar1;
  int unaff_BP;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  
  uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
  iVar2 = (int)*(undefined4 *)(unaff_BP + -4);
  uVar1 = *(undefined2 *)(iVar2 + 0x101);
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar2 + 0xff);
  *(undefined2 *)(unaff_BP + -2) = uVar1;
  if (*(int *)(unaff_BP + -4) == 0 && *(int *)(unaff_BP + -2) == 0) {
    FUN_0000_792f();
    return;
  }
  if (((undefined *)&DAT_0000_fffa)[*(int *)(unaff_BP + 6)] != '\0') {
    FUN_0000_792f();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) != '\x01') {
    FUN_0000_7919();
    return;
  }
  *(undefined1 *)(unaff_BP + -0x105) = 0;
  func_0x00001140();
  iVar2 = unaff_BP;
  func_0x00006e7f(0xec);
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x2fb4,0xec,unaff_BP + -0x116,unaff_SS,iVar2);
}


