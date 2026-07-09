/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1c54
 * Ghidra name: FUN_1cc0_1c54
 * Linear address: 0x1E854
 * Body addresses: 19
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

byte __stdcall16far FUN_1cc0_1c54(byte param_1)

{
  if ((0x60 < param_1) && (param_1 < 0x7b)) {
    param_1 = param_1 - 0x20;
  }
  return param_1;
}


