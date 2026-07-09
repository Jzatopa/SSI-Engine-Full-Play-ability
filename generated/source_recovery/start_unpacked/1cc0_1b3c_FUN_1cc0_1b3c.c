/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1b3c
 * Ghidra name: FUN_1cc0_1b3c
 * Linear address: 0x1E73C
 * Body addresses: 50
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1cc0_1b3c(void)

{
  undefined2 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  int in_DX;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x3dca;
  uVar4 = (uint)*(byte *)0x80;
  pbVar2 = (byte *)0x81;
  do {
    for (; (pbVar3 = pbVar2, uVar4 != 0 && (*pbVar2 < 0x21)); pbVar2 = pbVar2 + 1) {
      uVar4 = uVar4 - 1;
    }
    for (; (uVar4 != 0 && (0x20 < *pbVar3)); pbVar3 = pbVar3 + 1) {
      uVar4 = uVar4 - 1;
    }
  } while ((pbVar3 != pbVar2) && (in_DX = in_DX + -1, pbVar2 = pbVar3, in_DX != 0));
  return;
}


