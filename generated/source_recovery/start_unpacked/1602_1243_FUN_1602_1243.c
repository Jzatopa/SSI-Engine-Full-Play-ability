/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:1243
 * Ghidra name: FUN_1602_1243
 * Linear address: 0x17263
 * Body addresses: 41
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_1602_1243(void)

{
  byte extraout_AH;
  byte extraout_AH_00;
  undefined2 unaff_DS;
  
  FUN_1836_03cf();
  FUN_1602_0bf4(0x1014,unaff_DS,CONCAT11(extraout_AH,0xf),(uint)extraout_AH << 8);
  FUN_1602_10c7(CONCAT11(extraout_AH_00,0x18),CONCAT11(extraout_AH_00,0x27),
                CONCAT11(extraout_AH_00,0x18),(uint)extraout_AH_00 << 8);
  return;
}


