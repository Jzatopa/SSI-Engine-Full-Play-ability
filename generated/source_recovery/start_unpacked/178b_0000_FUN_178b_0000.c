/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 178b:0000
 * Ghidra name: FUN_178b_0000
 * Linear address: 0x178B0
 * Body addresses: 32
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_178b_0000(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x50d0 == '\x01') {
    FUN_19e3_0000(*(undefined2 *)0x2328);
  }
  *(undefined1 *)0x50cf = *(undefined1 *)0x50d0;
  *(undefined1 *)0x50d0 = 0;
  return;
}


