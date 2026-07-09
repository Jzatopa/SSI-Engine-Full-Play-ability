/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0df7
 * Ghidra name: FUN_187b_0df7
 * Linear address: 0x195A7
 * Body addresses: 37
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_187b_0df7(void)

{
  code *pcVar1;
  
  _LAB_1099_001f_1 = 0xffff;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
                    /* WARNING: Call to offcut address within same function */
  func_0x000195c3(0x1000);
  return;
}


