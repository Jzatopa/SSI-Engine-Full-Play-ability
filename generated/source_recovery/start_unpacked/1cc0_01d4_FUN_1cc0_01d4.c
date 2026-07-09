/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:01d4
 * Ghidra name: FUN_1cc0_01d4
 * Linear address: 0x1CDD4
 * Body addresses: 11
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void FUN_1cc0_01d4(void)

{
  code *pcVar1;
  
  FUN_1cc0_01df();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}


