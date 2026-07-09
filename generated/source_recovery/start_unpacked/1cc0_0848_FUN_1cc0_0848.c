/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0848
 * Ghidra name: FUN_1cc0_0848
 * Linear address: 0x1D448
 * Body addresses: 36
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_0848(undefined4 param_1)

{
  undefined2 in_BX;
  undefined1 in_ZF;
  
  FUN_1cc0_07b6();
  if ((bool)in_ZF) {
    FUN_1cc0_07da();
    FUN_1cc0_07da();
  }
  *(undefined2 *)((int)param_1 + 8) = in_BX;
  FUN_1cc0_0879();
  return;
}


