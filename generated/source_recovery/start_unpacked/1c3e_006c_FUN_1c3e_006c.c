/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:006c
 * Ghidra name: FUN_1c3e_006c
 * Linear address: 0x1C44C
 * Body addresses: 34
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1c3e_006c(uint *param_1,uint *param_2,uint *param_3,undefined2 *param_4)

{
  code *pcVar1;
  uint uVar2;
  undefined2 in_CX;
  byte extraout_DL;
  byte extraout_DH;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  *param_1 = uVar2 & 0xff;
  *param_2 = (uint)extraout_DL;
  *param_3 = (uint)extraout_DH;
  *param_4 = in_CX;
  return;
}


