/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:10c7
 * Ghidra name: FUN_1602_10c7
 * Linear address: 0x170E7
 * Body addresses: 30
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far
FUN_1602_10c7(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined2 in_AX;
  byte bVar1;
  
  bVar1 = (byte)((uint)in_AX >> 8);
  FUN_1602_0e39((uint)bVar1 << 8,CONCAT11(bVar1,param_1),CONCAT11(bVar1,param_2),
                CONCAT11(bVar1,param_3),CONCAT11(bVar1,param_4));
  return;
}


