/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:19d4
 * Ghidra name: FUN_1cc0_19d4
 * Linear address: 0x1E5D4
 * Body addresses: 27
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __stdcall16far FUN_1cc0_19d4(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined1 in_CF;
  
  uVar1 = FUN_1cc0_1a04();
  if ((!(bool)in_CF) && (uVar1 = in_CX, *(int *)(unaff_DI + 4) != 1)) {
    uVar1 = FUN_1cc0_0a2d();
  }
  return uVar1;
}


