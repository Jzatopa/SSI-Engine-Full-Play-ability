/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:00f5
 * Ghidra name: FUN_1602_00f5
 * Linear address: 0x16115
 * Body addresses: 47
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_00f5(byte param_1)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x44ad = 5;
  *(byte *)0x44ac = param_1;
  FUN_1c3e_000b(0x44ac);
  *(int *)0x44c0 = (uint)param_1 * 0x200 + -0x6000;
  return;
}


