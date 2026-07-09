/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:3e17
 * Ghidra name: FUN_121a_3e17
 * Linear address: 0x15FB7
 * Body addresses: 44
 * Calling convention: __stdcall16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void FUN_121a_3e17(undefined1 param_1,byte param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)((uint)param_2 * 0x140 + param_4);
  for (param_4 = (param_3 + 1) - param_4; param_4 != 0; param_4 = param_4 + -1) {
    puVar1 = puVar2;
    puVar2 = puVar2 + 1;
    *puVar1 = param_1;
  }
  return;
}


