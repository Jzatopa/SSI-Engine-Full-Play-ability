/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:0dbc
 * Ghidra name: FUN_121a_0dbc
 * Linear address: 0x12F5C
 * Body addresses: 133
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

char __stdcall16far FUN_121a_0dbc(byte param_1)

{
  return (param_1 * -0x80 + (param_1 & 2) * ' ' + (param_1 & 4) * '\b' + (param_1 & 8) * '\x02' +
          ((param_1 & 0x10) >> 1) + ((param_1 & 0x20) >> 3) + ((param_1 & 0x40) >> 5)) -
         ((char)param_1 >> 7);
}


