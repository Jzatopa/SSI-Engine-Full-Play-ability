/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:8695
 * Ghidra name: FUN_0000_8695
 * Linear address: 0x08695
 * Original GAME.OVR file offset: 34461
 * Body addresses: 64
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_8695(void)

{
  char *pcVar1;
  undefined2 uVar2;
  int unaff_BP;
  int unaff_SI;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  
  pcVar1 = (char *)(unaff_SI + 0x3d);
  *pcVar1 = *pcVar1 + '\x01';
  bVar5 = *pcVar1 == '\0';
  FUN_0000_d977();
  if (!bVar5) {
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
    *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
  }
  uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
  iVar3 = (int)*(undefined4 *)(unaff_BP + -4);
  uVar2 = *(undefined2 *)(iVar3 + 0x101);
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar3 + 0xff);
  *(undefined2 *)(unaff_BP + -2) = uVar2;
  FUN_0000_8691();
  return;
}


