/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e6af
 * Ghidra name: FUN_0000_e6af
 * Linear address: 0x0E6AF
 * Original GAME.OVR file offset: 59063
 * Body addresses: 29
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_e6af(void)

{
  int iVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 in_AX;
  undefined2 unaff_DS;
  
  do {
    FUN_0000_db35(0x3a,3,in_AX);
    do {
      if (*(char *)0x4004 == '\x06') {
        if (*(char *)0x4005 == '\x02') {
          return;
        }
        *(char *)0x4005 = *(char *)0x4005 + '\x01';
        *(undefined1 *)0x4004 = 0xfa;
      }
      else {
        *(char *)0x4004 = *(char *)0x4004 + '\x01';
      }
      iVar1 = FUN_0000_e1ea(2);
    } while (iVar1 != 0);
    FUN_0000_db35(0x37,2,4);
    FUN_0000_db35(CONCAT11(extraout_AH,0x38),CONCAT11(extraout_AH,2),CONCAT11(extraout_AH,5));
    FUN_0000_db35(CONCAT11(extraout_AH_00,0x39),CONCAT11(extraout_AH_00,3),
                  CONCAT11(extraout_AH_00,5));
    in_AX = CONCAT11(extraout_AH_01,6);
  } while( true );
}


