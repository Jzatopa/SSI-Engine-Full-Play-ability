/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:005e
 * Ghidra name: FUN_121a_005e
 * Linear address: 0x121FE
 * Body addresses: 79
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __stdcall16far FUN_121a_005e(undefined4 param_1,byte param_2)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_b [8];
  undefined1 local_3;
  
  FUN_1cc0_09f6(8,local_b,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  if (*(char *)0x8dc6 == '\0') {
    local_3 = *(undefined1 *)(*(byte *)(param_2 + 0x9cc7) + 0x9dc7);
  }
  else {
    local_3 = *(undefined1 *)(param_2 + 0x9dd7);
  }
  return local_3;
}


