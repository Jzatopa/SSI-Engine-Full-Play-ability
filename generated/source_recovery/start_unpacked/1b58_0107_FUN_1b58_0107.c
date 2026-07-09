/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1b58:0107
 * Ghidra name: FUN_1b58_0107
 * Linear address: 0x1B687
 * Body addresses: 63
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1b58_0107(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x8d70 != '\0') {
    *(undefined2 *)0x44ac = 9;
    *(undefined2 *)0x44ae = param_3;
    *(undefined2 *)0x44b0 = param_2;
    *(undefined2 *)0x44bc = (int)((ulong)param_1 >> 0x10);
    *(undefined2 *)0x44b2 = (int)param_1;
    FUN_1c3e_000b(0x44ac);
  }
  return;
}


