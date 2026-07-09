/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:00a2
 * Ghidra name: FUN_1c3e_00a2
 * Linear address: 0x1C482
 * Body addresses: 37
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1c3e_00a2(uint *param_1,uint *param_2,uint *param_3,uint *param_4)

{
  code *pcVar1;
  byte in_CL;
  byte in_CH;
  byte extraout_DL;
  byte extraout_DH;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  *param_1 = (uint)extraout_DL;
  *param_2 = (uint)extraout_DH;
  *param_3 = (uint)in_CL;
  *param_4 = (uint)in_CH;
  return;
}


