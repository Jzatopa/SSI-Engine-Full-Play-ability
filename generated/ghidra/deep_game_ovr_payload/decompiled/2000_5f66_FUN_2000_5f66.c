
int __stdcall16far FUN_2000_5f66(undefined2 param_1,undefined2 param_2,char param_3)

{
  undefined2 in_AX;
  byte bVar1;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  byte extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  byte extraout_AH_05;
  undefined1 extraout_AH_06;
  byte extraout_AH_07;
  byte extraout_AH_08;
  undefined1 extraout_AH_09;
  byte extraout_AH_10;
  undefined1 extraout_AH_11;
  undefined1 extraout_AH_12;
  byte extraout_AH_13;
  byte extraout_AH_14;
  undefined1 extraout_AH_15;
  byte extraout_AH_16;
  byte extraout_AH_17;
  byte extraout_AH_18;
  byte extraout_AH_19;
  byte extraout_AH_20;
  undefined2 unaff_DS;
  
  bVar1 = (byte)((uint)in_AX >> 8);
  if (param_3 == '\x01') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,6),CONCAT11(bVar1,10));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH,4),CONCAT11(extraout_AH,0x1e));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_00,0xf),CONCAT11(extraout_AH_00,0x28));
    bVar1 = extraout_AH_01;
  }
  else if (param_3 == '\x02') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,6),CONCAT11(bVar1,10));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_02,5),CONCAT11(extraout_AH_02,10));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_03,4),CONCAT11(extraout_AH_03,0x19));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_04,3),CONCAT11(extraout_AH_04,10));
    bVar1 = extraout_AH_05;
  }
  else if (param_3 == '\x11') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x12),CONCAT11(bVar1,0x1e));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_06,0x13),CONCAT11(extraout_AH_06,0x1e));
    bVar1 = extraout_AH_07;
  }
  else if (param_3 == '\x12') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x13),CONCAT11(bVar1,0x28));
    bVar1 = extraout_AH_08;
  }
  else if (param_3 == '\x17') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x16),CONCAT11(bVar1,0x19));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_09,0x14),CONCAT11(extraout_AH_09,0xf));
    bVar1 = extraout_AH_10;
  }
  else if (param_3 == '\x1b') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x2f),CONCAT11(bVar1,0x19));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_11,0x2e),CONCAT11(extraout_AH_11,0x19));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_12,0x2b),CONCAT11(extraout_AH_12,10));
    bVar1 = extraout_AH_13;
  }
  else if (param_3 == '\x1e') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x54),CONCAT11(bVar1,10));
    bVar1 = extraout_AH_14;
  }
  else if (param_3 == '$') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x2f),CONCAT11(bVar1,0xf));
    FUN_2000_5e38(&stack0xfffe,CONCAT11(extraout_AH_15,0x2e),CONCAT11(extraout_AH_15,0x14));
    bVar1 = extraout_AH_16;
  }
  else if (param_3 == '&') {
    if ((*(byte *)((int)*(undefined4 *)0x57fb + 0x90) < 10) &&
       (*(byte *)((int)*(undefined4 *)0x57fb + 0x99) < 10)) {
      FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x1a),CONCAT11(bVar1,10));
      bVar1 = extraout_AH_17;
    }
  }
  else if (param_3 == 'D') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x1a),CONCAT11(bVar1,10));
    bVar1 = extraout_AH_18;
  }
  else if (param_3 == 'J') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x4b),CONCAT11(bVar1,0x14));
    bVar1 = extraout_AH_19;
  }
  else if (param_3 == 'M') {
    FUN_2000_5e38(&stack0xfffe,CONCAT11(bVar1,0x1a),CONCAT11(bVar1,10));
    bVar1 = extraout_AH_20;
  }
  return (uint)bVar1 << 8;
}


