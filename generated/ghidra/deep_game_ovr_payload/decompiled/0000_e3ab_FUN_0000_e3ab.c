
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


