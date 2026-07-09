/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:3e43
 * Ghidra name: FUN_121a_3e43
 * Linear address: 0x15FE3
 * Body addresses: 47
 * Calling convention: __stdcall16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void FUN_121a_3e43(undefined1 param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_4 * 0x140 + param_2);
  param_4 = (param_3 + 1) - param_4;
  do {
    *puVar1 = param_1;
    puVar1 = puVar1 + 0x140;
    param_4 = param_4 + -1;
  } while (param_4 != 0);
  return;
}


