/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1099:009d
 * Ghidra name: FUN_1099_009d
 * Linear address: 0x10A2D
 * Body addresses: 20
 * Calling convention: __stdcall16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void FUN_1099_009d(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  return;
}


