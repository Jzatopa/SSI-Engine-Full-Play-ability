/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:0ced
 * Ghidra name: FUN_1602_0ced
 * Linear address: 0x16D0D
 * Body addresses: 215
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_1602_0ced(void)

{
  char cVar1;
  undefined2 in_AX;
  byte bVar2;
  byte extraout_AH;
  undefined2 unaff_DS;
  
  cVar1 = *(char *)0x44c8;
  bVar2 = (byte)((uint)in_AX >> 8);
  if (cVar1 == '\0') {
    FUN_1cc0_1ad2(0x1f00,8000,0,0xba00);
    FUN_1cc0_1ad2(0x1f00,8000,0,0xb800);
  }
  else if (cVar1 == '\x01') {
    FUN_1602_013b((uint)bVar2 << 8,(uint)bVar2 << 8,CONCAT11(bVar2,0x18),CONCAT11(bVar2,0x27),
                  (uint)bVar2 << 8,(uint)bVar2 << 8);
    FUN_1602_013b((uint)extraout_AH << 8,CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,0x18),
                  CONCAT11(extraout_AH,0x27),(uint)extraout_AH << 8,(uint)extraout_AH << 8);
  }
  else if (cVar1 == '\x03') {
    FUN_1cc0_1ad2(64000,64000,0,0xa000);
  }
  else if (cVar1 == '\x02') {
    FUN_1cc0_1ad2(0x1f00,8000,0,0xb800);
    FUN_1cc0_1ad2(0x1f00,8000,0,0xba00);
    FUN_1cc0_1ad2(0x1f00,8000,0,0xbc00);
    FUN_1cc0_1ad2(0x1f00,8000,0,0xbe00);
  }
  return;
}


