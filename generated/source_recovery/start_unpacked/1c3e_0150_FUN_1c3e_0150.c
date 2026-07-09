/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:0150
 * Ghidra name: FUN_1c3e_0150
 * Linear address: 0x1C530
 * Body addresses: 26
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1c3e_0150(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  FUN_1c3e_016a();
  return;
}


