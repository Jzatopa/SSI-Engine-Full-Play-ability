/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:04a2
 * Ghidra name: FUN_1cc0_04a2
 * Linear address: 0x1D0A2
 * Body addresses: 7
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __cdecl16far FUN_1cc0_04a2(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  LOCK();
  uVar1 = *(undefined2 *)0x3dce;
  *(undefined2 *)0x3dce = 0;
  UNLOCK();
  return uVar1;
}


