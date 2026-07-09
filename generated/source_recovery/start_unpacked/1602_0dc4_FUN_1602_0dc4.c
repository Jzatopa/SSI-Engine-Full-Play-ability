/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:0dc4
 * Ghidra name: FUN_1602_0dc4
 * Linear address: 0x16DE4
 * Body addresses: 90
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_0dc4(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  byte extraout_AH;
  byte extraout_AH_00;
  byte extraout_AH_01;
  undefined2 unaff_SS;
  undefined1 local_2b [41];
  
  FUN_1cc0_0adc(0x28,local_2b,unaff_SS,(int)param_3,(int)((ulong)param_3 >> 0x10));
  FUN_1602_03d1(CONCAT11(extraout_AH,0x28),(uint)extraout_AH << 8,CONCAT11(extraout_AH,0x18),
                (uint)extraout_AH << 8);
  FUN_1602_041a(local_2b,unaff_SS,CONCAT11(extraout_AH_00,param_1),CONCAT11(extraout_AH_00,param_2),
                CONCAT11(extraout_AH_00,0x18),(uint)extraout_AH_00 << 8);
  FUN_1602_0e1e();
  FUN_1602_03d1(CONCAT11(extraout_AH_01,0x28),(uint)extraout_AH_01 << 8,
                CONCAT11(extraout_AH_01,0x18),(uint)extraout_AH_01 << 8);
  return;
}


