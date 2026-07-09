/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1bdc:032f
 * Ghidra name: FUN_1bdc_032f
 * Linear address: 0x1C0EF
 * Body addresses: 43
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1bdc_032f(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  *(undefined2 *)(iVar1 + 2) = 0xd7b0;
  *(undefined2 *)(iVar1 + 4) = 0x80;
  *(int *)(iVar1 + 0xc) = iVar1 + 0x80;
  *(undefined2 *)(iVar1 + 0xe) = uVar2;
  *(undefined2 *)(iVar1 + 0x10) = 0x35a;
  *(undefined2 *)(iVar1 + 0x12) = 0x1bdc;
  *(undefined1 *)(iVar1 + 0x30) = 0;
  return;
}


