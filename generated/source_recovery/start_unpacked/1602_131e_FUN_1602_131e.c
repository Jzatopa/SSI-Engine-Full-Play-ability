/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:131e
 * Ghidra name: FUN_1602_131e
 * Linear address: 0x1733E
 * Body addresses: 60
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_131e(undefined1 param_1,undefined4 param_2)

{
  undefined2 unaff_SS;
  undefined1 local_102 [256];
  
  FUN_1cc0_1790(0xff,local_102,unaff_SS,0,param_1,0);
  FUN_1cc0_0adc(0xff,(int)param_2,(int)((ulong)param_2 >> 0x10),local_102,unaff_SS);
  return;
}


