/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:01b3
 * Ghidra name: FUN_1cc0_01b3
 * Linear address: 0x1CDB3
 * Body addresses: 12
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __cdecl16near FUN_1cc0_01b3(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  
  FUN_1cc0_01bf();
  uVar1 = FUN_1cc0_01bf();
  uVar1 = CONCAT11((char)((uint)uVar1 >> 8),(char)uVar1 + '0');
  FUN_1cc0_01e7(uVar1);
  uVar2 = (undefined1)((uint)uVar1 >> 8);
  return CONCAT11(uVar2,uVar2);
}


