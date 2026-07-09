/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:01bf
 * Ghidra name: FUN_1cc0_01bf
 * Linear address: 0x1CDBF
 * Body addresses: 14
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __cdecl16near FUN_1cc0_01bf(void)

{
  uint in_AX;
  undefined2 uVar1;
  undefined1 uVar2;
  byte in_CL;
  
  uVar1 = CONCAT11((char)((in_AX & 0xff) % (uint)in_CL),(char)((in_AX & 0xff) / (uint)in_CL) + '0');
  FUN_1cc0_01e7(uVar1);
  uVar2 = (undefined1)((uint)uVar1 >> 8);
  return CONCAT11(uVar2,uVar2);
}


