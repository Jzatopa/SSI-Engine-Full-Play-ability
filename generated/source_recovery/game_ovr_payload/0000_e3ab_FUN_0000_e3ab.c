/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e3ab
 * Ghidra name: FUN_0000_e3ab
 * Linear address: 0x0E3AB
 * Original GAME.OVR file offset: 58291
 * Body addresses: 66
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_e3ab(void)

{
  undefined2 in_AX;
  byte bVar1;
  byte extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_DS;
  
  bVar1 = (byte)((uint)in_AX >> 8);
  if (*(char *)0x4006 == '\x01') {
    FUN_0000_db35(CONCAT11(bVar1,0x18),(uint)bVar1 << 8,CONCAT11(bVar1,3));
    FUN_0000_db35(CONCAT11(extraout_AH,0x18),(uint)extraout_AH << 8,CONCAT11(extraout_AH,4));
    FUN_0000_db35(CONCAT11(extraout_AH_00,0x19),CONCAT11(extraout_AH_00,1),
                  CONCAT11(extraout_AH_00,3));
    FUN_0000_db35(CONCAT11(extraout_AH_01,0x19),CONCAT11(extraout_AH_01,1),
                  CONCAT11(extraout_AH_01,4));
  }
  return;
}


