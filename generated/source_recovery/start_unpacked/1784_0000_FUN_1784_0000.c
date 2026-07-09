/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1784:0000
 * Ghidra name: FUN_1784_0000
 * Linear address: 0x17840
 * Body addresses: 38
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1784_0000(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x50d0 == '\x02') {
    FUN_1784_0053();
  }
  if (*(char *)0x50d0 == '\0') {
    FUN_19e3_00a9();
  }
  FUN_19e3_0000(param_1);
  return;
}


