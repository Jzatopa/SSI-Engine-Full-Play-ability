/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1b58:0072
 * Ghidra name: FUN_1b58_0072
 * Linear address: 0x1B5F2
 * Body addresses: 87
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1b58_0072(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x8d70 != '\0') {
    *(undefined2 *)0x44ac = 3;
    FUN_1c3e_000b(0x44ac);
    *param_3 = *(undefined2 *)0x44ae;
    *param_2 = *(int *)0x44b0;
    if (*(char *)0x8d6e == '\0') {
      *param_2 = *param_2 / 2;
    }
    *param_1 = *(undefined2 *)0x44b2;
  }
  return;
}


