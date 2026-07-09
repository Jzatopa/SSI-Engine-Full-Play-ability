/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 178b:051b
 * Ghidra name: FUN_178b_051b
 * Linear address: 0x17DCB
 * Body addresses: 74
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __stdcall16far FUN_178b_051b(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_7f [43];
  char local_54 [82];
  
  FUN_1cc0_0adc(0x50,local_54,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_1c3e_0112(local_7f,unaff_SS,0,local_54,unaff_SS);
  if ((*(int *)0x9f48 == 0) && (local_54[0] != '\0')) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


