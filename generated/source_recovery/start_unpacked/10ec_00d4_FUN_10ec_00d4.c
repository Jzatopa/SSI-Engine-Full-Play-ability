/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10ec:00d4
 * Ghidra name: FUN_10ec_00d4
 * Linear address: 0x10F94
 * Body addresses: 37
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_10ec_00d4(void)

{
  byte extraout_AH;
  
  FUN_1b58_0051();
  FUN_10ec_0280(CONCAT11(extraout_AH,0x16),CONCAT11(extraout_AH,0x26),(uint)extraout_AH << 8,
                (uint)extraout_AH << 8);
  FUN_10ec_00c6();
  FUN_1b58_0030();
  return;
}


