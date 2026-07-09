/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:15ea
 * Ghidra name: FUN_1cc0_15ea
 * Linear address: 0x1E1EA
 * Body addresses: 22
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

uint __stdcall16far FUN_1cc0_15ea(uint param_1)

{
  uint uVar1;
  uint extraout_DX;
  
  FUN_1cc0_1639();
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = extraout_DX % param_1;
  }
  return uVar1;
}


