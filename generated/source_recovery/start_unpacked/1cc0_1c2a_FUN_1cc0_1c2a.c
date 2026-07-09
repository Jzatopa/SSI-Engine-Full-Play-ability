/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1c2a
 * Ghidra name: FUN_1cc0_1c2a
 * Linear address: 0x1E82A
 * Body addresses: 27
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1cc0_1c2a(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  int unaff_BP;
  byte *pbVar5;
  byte *pbVar6;
  undefined2 unaff_SS;
  int iVar4;
  
  pbVar2 = (byte *)*(undefined4 *)(unaff_BP + 6);
  pbVar5 = (byte *)pbVar2;
  pbVar6 = (byte *)(unaff_BP + -0x80);
  bVar3 = *pbVar2;
  if (0x7e < bVar3) {
    bVar3 = 0x7f;
  }
  for (iVar4 = (int)(char)bVar3; pbVar5 = pbVar5 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    pbVar1 = pbVar6;
    pbVar6 = pbVar6 + 1;
    *pbVar1 = *pbVar5;
  }
  *pbVar6 = 0;
  return;
}


