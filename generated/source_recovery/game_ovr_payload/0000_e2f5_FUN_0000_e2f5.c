/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e2f5
 * Ghidra name: FUN_0000_e2f5
 * Linear address: 0x0E2F5
 * Original GAME.OVR file offset: 58109
 * Body addresses: 155
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_e2f5(void)

{
  undefined1 uVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  undefined1 extraout_AH_05;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  if (*(char *)0x4007 == '\x01') {
    local_3 = 2;
    while( true ) {
      uVar1 = (undefined1)(local_3 - 1 >> 8);
      FUN_0000_db35(CONCAT11(uVar1,0x1b),CONCAT11(uVar1,local_3),local_3 - 1);
      FUN_0000_db35(CONCAT11(extraout_AH,0x1c),CONCAT11(extraout_AH,local_3),
                    CONCAT11(extraout_AH,local_3));
      uVar1 = (undefined1)(local_3 + 1 >> 8);
      FUN_0000_db35(CONCAT11(uVar1,0x1a),CONCAT11(uVar1,local_3),local_3 + 1);
      if (local_3 == 4) break;
      local_3 = local_3 + 1;
    }
  }
  else if (*(char *)0x4007 == '\x03') {
    FUN_0000_db35(0x1b,2,1);
    FUN_0000_db35(CONCAT11(extraout_AH_00,0x1d),CONCAT11(extraout_AH_00,2),
                  CONCAT11(extraout_AH_00,2));
    FUN_0000_db35(CONCAT11(extraout_AH_01,0x22),CONCAT11(extraout_AH_01,2),
                  CONCAT11(extraout_AH_01,3));
    FUN_0000_db35(CONCAT11(extraout_AH_02,0x25),CONCAT11(extraout_AH_02,3),
                  CONCAT11(extraout_AH_02,2));
    FUN_0000_db35(CONCAT11(extraout_AH_03,0x26),CONCAT11(extraout_AH_03,3),
                  CONCAT11(extraout_AH_03,3));
    FUN_0000_db35(CONCAT11(extraout_AH_04,0x23),CONCAT11(extraout_AH_04,4),
                  CONCAT11(extraout_AH_04,4));
    FUN_0000_db35(CONCAT11(extraout_AH_05,0x24),CONCAT11(extraout_AH_05,4),
                  CONCAT11(extraout_AH_05,5));
  }
  return;
}


