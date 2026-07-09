/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:180c
 * Ghidra name: FUN_1cc0_180c
 * Linear address: 0x1E40C
 * Body addresses: 46
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_180c(byte *param_1,undefined2 *param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)param_2 >> 0x10);
  pbVar5 = (byte *)param_1;
  pbVar6 = (byte *)((undefined2 *)param_2 + 1);
  *param_2 = 0;
  pbVar6[0] = 0xb0;
  pbVar6[1] = 0xd7;
  for (iVar3 = 0x16; pbVar6 = pbVar6 + 2, iVar3 != 0; iVar3 = iVar3 + -1) {
    pbVar6[0] = 0;
    pbVar6[1] = 0;
  }
  bVar2 = *param_1;
  if (0x4f < bVar2) {
    bVar2 = 0x4f;
  }
  for (uVar4 = (uint)bVar2; pbVar5 = pbVar5 + 1, uVar4 != 0; uVar4 = uVar4 - 1) {
    pbVar1 = pbVar6;
    pbVar6 = pbVar6 + 1;
    *pbVar1 = *pbVar5;
  }
  *pbVar6 = 0;
  return;
}


