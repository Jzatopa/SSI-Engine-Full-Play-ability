/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c6a:025b
 * Ghidra name: FUN_1c6a_025b
 * Linear address: 0x1C8FB
 * Body addresses: 13
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

ulong __cdecl16near FUN_1c6a_025b(void)

{
  uint in_AX;
  uint uVar1;
  
  uVar1 = in_AX << 4 | in_AX >> 0xc;
  return CONCAT22(uVar1,uVar1) & 0xffff0;
}


