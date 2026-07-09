/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:029c
 * Ghidra name: FUN_187b_029c
 * Linear address: 0x18A4C
 * Body addresses: 39
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_029c(void)

{
  undefined2 unaff_DS;
  
  if (*(int *)0x9ee2 != 0 || *(int *)0x9ee4 != 0) {
    FUN_1cc0_0254(*(undefined2 *)0x9ee6,*(undefined2 *)0x9ee2,*(undefined2 *)0x9ee4);
    *(undefined2 *)0x9ee2 = 0;
    *(undefined2 *)0x9ee4 = 0;
  }
  return;
}


