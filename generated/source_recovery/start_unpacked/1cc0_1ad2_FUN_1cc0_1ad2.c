/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1ad2
 * Ghidra name: FUN_1cc0_1ad2
 * Linear address: 0x1E6D2
 * Body addresses: 20
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_1ad2(undefined1 param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)param_3;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    puVar1 = puVar2;
    puVar2 = puVar2 + 1;
    *puVar1 = param_1;
  }
  return;
}


