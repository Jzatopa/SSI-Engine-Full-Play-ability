/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:03d1
 * Ghidra name: FUN_1602_03d1
 * Linear address: 0x163F1
 * Body addresses: 73
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_03d1(undefined1 param_1,undefined1 param_2,byte param_3,byte param_4)

{
  undefined1 extraout_AH;
  
  FUN_1b58_0051();
  if ((param_4 < 0x28) && (param_3 < 0x19)) {
    FUN_1602_0263(CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,0x20),CONCAT11(extraout_AH,param_1),
                  CONCAT11(extraout_AH,param_2),CONCAT11(extraout_AH,param_2),
                  CONCAT11(extraout_AH,param_3),CONCAT11(extraout_AH,param_4));
    FUN_1b58_0030();
  }
  return;
}


