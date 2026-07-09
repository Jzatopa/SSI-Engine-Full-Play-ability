
void __cdecl16far FUN_10ec_015f(void)

{
  undefined1 extraout_AH;
  byte extraout_AH_00;
  undefined2 unaff_DS;
  
  FUN_1b58_0051();
  FUN_10ec_0280(CONCAT11(extraout_AH,0x16),CONCAT11(extraout_AH,0x26),CONCAT11(extraout_AH,1),
                CONCAT11(extraout_AH,1));
  FUN_10ec_00c6();
  FUN_10ec_00f9(CONCAT11(extraout_AH_00,0x27),(uint)extraout_AH_00 << 8,
                CONCAT11(extraout_AH_00,0x10));
  *(undefined1 *)0x687a = 1;
  *(undefined1 *)0x687b = 0x11;
  *(undefined1 *)0x687c = 0x26;
  *(undefined1 *)0x687d = 0x16;
  FUN_1b58_0030();
  return;
}


