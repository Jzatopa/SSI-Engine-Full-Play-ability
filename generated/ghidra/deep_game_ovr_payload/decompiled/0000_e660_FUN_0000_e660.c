
void __stdcall16far FUN_0000_e660(void)

{
  int iVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x4005 = 0xfe;
  while( true ) {
    *(undefined1 *)0x4004 = 0xfa;
    while( true ) {
      iVar1 = FUN_0000_e1ea(2);
      if (iVar1 == 0) {
        FUN_0000_db35(0x37,2,4);
        FUN_0000_db35(CONCAT11(extraout_AH,0x38),CONCAT11(extraout_AH,2),CONCAT11(extraout_AH,5));
        FUN_0000_db35(CONCAT11(extraout_AH_00,0x39),CONCAT11(extraout_AH_00,3),
                      CONCAT11(extraout_AH_00,5));
        FUN_0000_db35(CONCAT11(extraout_AH_01,0x3a),CONCAT11(extraout_AH_01,3),
                      CONCAT11(extraout_AH_01,6));
      }
      if (*(char *)0x4004 == '\x06') break;
      *(char *)0x4004 = *(char *)0x4004 + '\x01';
    }
    if (*(char *)0x4005 == '\x02') break;
    *(char *)0x4005 = *(char *)0x4005 + '\x01';
  }
  return;
}


