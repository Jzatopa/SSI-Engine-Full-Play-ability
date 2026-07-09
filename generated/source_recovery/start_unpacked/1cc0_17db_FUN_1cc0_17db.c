/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:17db
 * Ghidra name: FUN_1cc0_17db
 * Linear address: 0x1E3DB
 * Body addresses: 49
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __stdcall16far FUN_1cc0_17db(int *param_1,byte *param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  bVar5 = false;
  uVar2 = (uint)*param_2;
  pbVar4 = (byte *)param_2;
  while ((pbVar4 = pbVar4 + 1, uVar2 != 0 && (bVar5 = *pbVar4 < 0x20, *pbVar4 == 0x20))) {
    uVar2 = uVar2 - 1;
  }
  uVar1 = FUN_1cc0_16f8();
  if ((bVar5) || (iVar3 = 0, uVar2 != 0)) {
    iVar3 = (int)pbVar4 - (int)(byte *)param_2;
    uVar1 = 0;
  }
  *param_1 = iVar3;
  return uVar1;
}


