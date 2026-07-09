/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1b58:00c9
 * Ghidra name: FUN_1b58_00c9
 * Linear address: 0x1B649
 * Body addresses: 62
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1b58_00c9(undefined2 param_1,int param_2)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x8d70 != '\0') {
    *(undefined2 *)0x44ac = 4;
    if (*(char *)0x8d6e == '\0') {
      param_2 = param_2 << 1;
    }
    *(int *)0x44b0 = param_2;
    *(undefined2 *)0x44b2 = param_1;
    FUN_1c3e_000b(0x44ac);
  }
  return;
}


