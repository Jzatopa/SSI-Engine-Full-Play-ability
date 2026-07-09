/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 19e3:00a9
 * Ghidra name: FUN_19e3_00a9
 * Linear address: 0x19ED9
 * Body addresses: 43
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_19e3_00a9(void)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x50cd = *(undefined1 *)0x50cc;
  if (*(char *)0x50cc != '\0') {
    *(undefined1 *)0x50d0 = 1;
    FUN_19e3_1294();
    FUN_19e3_165a(0);
    FUN_19e3_16c6(0);
  }
  return;
}


