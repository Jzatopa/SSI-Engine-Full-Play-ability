/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1bdc:0097
 * Ghidra name: FUN_1bdc_0097
 * Linear address: 0x1BE57
 * Body addresses: 78
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1bdc_0097(void)

{
  undefined2 in_AX;
  char extraout_DL;
  
  DAT_0000_0487 = DAT_0000_0487 & 0xfe;
  if (((byte)in_AX != 7) && (3 < (byte)in_AX)) {
    in_AX = CONCAT11((char)((uint)in_AX >> 8),3);
  }
  FUN_1bdc_0609();
  if ((char)((uint)in_AX >> 8) != '\0') {
    FUN_1bdc_0609();
    FUN_1bdc_0609();
    if (extraout_DL == '*') {
      DAT_0000_0487 = DAT_0000_0487 | 1;
      FUN_1bdc_0609();
      FUN_1bdc_0609();
    }
  }
  return;
}


