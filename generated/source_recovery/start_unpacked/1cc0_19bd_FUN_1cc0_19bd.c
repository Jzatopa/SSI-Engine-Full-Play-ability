/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:19bd
 * Ghidra name: FUN_1cc0_19bd
 * Linear address: 0x1E5BD
 * Body addresses: 23
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_19bd(void)

{
  int unaff_DI;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  FUN_1cc0_1a04();
  if ((!(bool)in_CF) && (*(int *)(unaff_DI + 4) != 1)) {
    FUN_1cc0_0a2d();
  }
  return;
}


