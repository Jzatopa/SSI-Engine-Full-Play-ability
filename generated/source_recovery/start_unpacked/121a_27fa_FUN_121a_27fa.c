/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:27fa
 * Ghidra name: FUN_121a_27fa
 * Linear address: 0x1499A
 * Body addresses: 68
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_121a_27fa(undefined4 param_1,int param_2,byte param_3)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x44c8 == '\x03') {
    FUN_1cc0_1aaf(param_2 * 3,(int)param_1 + (uint)param_3 * 3,(int)((ulong)param_1 >> 0x10),
                  (uint)param_3 * 3 + -0x6639,unaff_DS);
  }
  return;
}


