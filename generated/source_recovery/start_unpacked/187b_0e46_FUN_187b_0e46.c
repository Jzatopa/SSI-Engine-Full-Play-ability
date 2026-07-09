/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0e46
 * Ghidra name: FUN_187b_0e46
 * Linear address: 0x195F6
 * Body addresses: 42
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_0e46(uint param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xd68d) {
    uVar1 = (undefined2)(((ulong)param_1 * 10000) / 0x20bd);
  }
  FUN_187b_0e1d(uVar1);
  return;
}


