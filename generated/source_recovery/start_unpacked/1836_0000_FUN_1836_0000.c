/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1836:0000
 * Ghidra name: FUN_1836_0000
 * Linear address: 0x18360
 * Body addresses: 95
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_1836_0000(void)

{
  undefined2 unaff_DS;
  
  FUN_1b58_0051();
  FUN_1b58_0146();
  if (*(char *)0x50d0 == '\x02') {
    FUN_187b_02c3();
  }
  else if (*(char *)0x50d0 == '\x01') {
    FUN_19e3_0000(*(undefined2 *)0x2328);
  }
  *(undefined1 *)0x44ad = 0;
  *(undefined1 *)0x44ac = *(undefined1 *)0x44c6;
  FUN_1c3e_000b(0x44ac);
  if (*(char *)0x4440 != '\0') {
    FUN_1cc0_05bf(0x8c4e,unaff_DS);
  }
  FUN_1cc0_00e9();
  return;
}


