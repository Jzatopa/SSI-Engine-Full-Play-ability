/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10ec:01db
 * Ghidra name: FUN_10ec_01db
 * Linear address: 0x1109B
 * Body addresses: 76
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_10ec_01db(void)

{
  undefined1 extraout_AH;
  byte extraout_AH_00;
  undefined2 unaff_DS;
  
  FUN_1b58_0051();
  FUN_10ec_0280(CONCAT11(extraout_AH,0x15),CONCAT11(extraout_AH,0x26),CONCAT11(extraout_AH,1),
                CONCAT11(extraout_AH,1));
  func_0x00010ec0(7000,0xf92);
  FUN_10ec_0280(CONCAT11(extraout_AH_00,0x17),CONCAT11(extraout_AH_00,0x27),
                CONCAT11(extraout_AH_00,0x17),(uint)extraout_AH_00 << 8);
  *(undefined1 *)0x687a = 0x17;
  *(undefined1 *)0x687b = 1;
  *(undefined1 *)0x687c = 0x17;
  *(undefined1 *)0x687d = 0x15;
  FUN_1b58_0030();
  return;
}


