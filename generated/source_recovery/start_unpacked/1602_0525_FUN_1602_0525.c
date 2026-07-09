/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:0525
 * Ghidra name: FUN_1602_0525
 * Linear address: 0x16545
 * Body addresses: 58
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_0525(int param_1)

{
  undefined2 unaff_SS;
  
  while ((*(byte *)(param_1 + -0x103) < *(byte *)(param_1 + -0x101) &&
         (*(char *)(param_1 + (uint)*(byte *)(param_1 + -0x103) + -0x100) == ' '))) {
    *(char *)(param_1 + -0x103) = *(char *)(param_1 + -0x103) + '\x01';
  }
  return;
}


