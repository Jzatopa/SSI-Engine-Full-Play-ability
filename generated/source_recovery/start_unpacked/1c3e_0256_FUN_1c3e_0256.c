/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:0256
 * Ghidra name: FUN_1c3e_0256
 * Linear address: 0x1C636
 * Body addresses: 82
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1c3e_0256(void)

{
  int extraout_DX;
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  undefined2 uVar4;
  byte *in_stack_00000010;
  
  uVar4 = (undefined2)((ulong)in_stack_00000010 >> 0x10);
  pbVar3 = (byte *)in_stack_00000010;
  for (uVar1 = (uint)*in_stack_00000010;
      ((uVar1 != 0 && (pbVar3[uVar1] != 0x5c)) && (pbVar3[uVar1] != 0x3a)); uVar1 = uVar1 - 1) {
  }
  FUN_1c3e_02a8();
  iVar2 = 0;
  while ((iVar2 != extraout_DX && (pbVar3[iVar2 + 1] != 0x2e))) {
    iVar2 = iVar2 + 1;
  }
  FUN_1c3e_02a8();
  FUN_1c3e_02a8();
  return;
}


