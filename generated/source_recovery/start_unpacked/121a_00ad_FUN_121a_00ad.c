/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:00ad
 * Ghidra name: FUN_121a_00ad
 * Linear address: 0x1224D
 * Body addresses: 48
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_121a_00ad(undefined1 param_1)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x44c6 = *(undefined1 *)0x44c7;
  *(undefined1 *)0x44ad = 0;
  *(undefined1 *)0x44ac = param_1;
  FUN_1c3e_000b(0x44ac);
  *(undefined1 *)0x44c7 = param_1;
  return;
}


