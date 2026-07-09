/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:0124
 * Ghidra name: FUN_1602_0124
 * Linear address: 0x16144
 * Body addresses: 23
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_0124(byte param_1)

{
  undefined2 unaff_DS;
  
  *(int *)0x44c2 = (uint)param_1 * 0x200 + -0x6000;
  return;
}


