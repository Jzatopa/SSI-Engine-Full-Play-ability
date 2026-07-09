/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:026d
 * Ghidra name: FUN_187b_026d
 * Linear address: 0x18A1D
 * Body addresses: 47
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_026d(void)

{
  undefined2 unaff_DS;
  
  if (*(int *)0x9eda != 0 || *(int *)0x9edc != 0) {
    FUN_1cc0_0254(*(undefined2 *)0x9ed8,*(undefined2 *)0x9eda,*(undefined2 *)0x9edc);
    *(undefined2 *)0x9eda = 0;
    *(undefined2 *)0x9edc = 0;
    *(undefined2 *)0x9ede = 0;
    *(undefined2 *)0x9ee0 = 0;
  }
  return;
}


