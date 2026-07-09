/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:029c
 * Ghidra name: FUN_1cc0_029c
 * Linear address: 0x1CE9C
 * Body addresses: 53
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

int __cdecl16far FUN_1cc0_029c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1000_02b1();
  return (int)uVar1 + (int)((ulong)uVar1 >> 0x10) * 0x10;
}


