/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:0ece
 * Ghidra name: FUN_121a_0ece
 * Linear address: 0x1306E
 * Body addresses: 49
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

char __stdcall16far FUN_121a_0ece(byte param_1)

{
  return param_1 * '\x10' + (param_1 >> 4);
}


