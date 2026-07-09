
void __stdcall16far FUN_1602_0e39(byte param_1,byte param_2,byte param_3,byte param_4,byte param_5)

{
  char cVar1;
  byte extraout_AH;
  undefined1 extraout_AH_00;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  undefined2 local_e;
  undefined2 local_c;
  
  FUN_1b58_0051();
  cVar1 = *(char *)0x44c8;
  if (cVar1 == '\0') {
    local_c = (uint)param_4 << 2;
    uVar2 = (uint)param_2 * 4 + 3;
    iVar3 = (((uint)param_3 - (uint)param_5) + 1) * 2;
    if (local_c <= uVar2) {
      while( true ) {
        FUN_1cc0_1ad2(*(undefined1 *)(*(int *)((uint)param_1 * 2 + 0x22c3) + 0x22cb),iVar3,
                      local_c * 0x50 + (uint)param_5 * 2,0xb800);
        FUN_1cc0_1ad2(*(undefined1 *)(*(int *)((uint)param_1 * 2 + 0x22c3) + 0x22cb),iVar3,
                      local_c * 0x50 + (uint)param_5 * 2,0xba00);
        if (local_c == uVar2) break;
        local_c = local_c + 1;
      }
    }
  }
  else if (cVar1 == '\x01') {
    FUN_1602_013b(CONCAT11(extraout_AH,param_1),(uint)extraout_AH << 8,CONCAT11(extraout_AH,param_2)
                  ,CONCAT11(extraout_AH,param_3),CONCAT11(extraout_AH,param_4),
                  CONCAT11(extraout_AH,param_5));
    FUN_1602_013b(CONCAT11(extraout_AH_00,param_1),CONCAT11(extraout_AH_00,1),
                  CONCAT11(extraout_AH_00,param_2),CONCAT11(extraout_AH_00,param_3),
                  CONCAT11(extraout_AH_00,param_4),CONCAT11(extraout_AH_00,param_5));
  }
  else if (cVar1 == '\x03') {
    local_e = (uint)param_4 * 0xa00 + (uint)param_5 * 8;
    uVar2 = (param_2 + 1) * 8 - 1;
    local_c = (uint)param_4 << 3;
    if (local_c <= uVar2) {
      while( true ) {
        FUN_1cc0_1ad2(CONCAT11((char)((uint)local_e >> 8),param_1),
                      (((uint)param_3 - (uint)param_5) + 1) * 8,local_e,0xa000);
        local_e = local_e + 0x140;
        if (local_c == uVar2) break;
        local_c = local_c + 1;
      }
    }
  }
  else if (cVar1 == '\x02') {
    local_c = (uint)param_4 << 1;
    uVar2 = (uint)param_2 * 2 + 1;
    iVar3 = (uint)param_5 * 4;
    iVar4 = (((uint)param_3 - (uint)param_5) + 1) * 4;
    cVar1 = param_1 * '\x11';
    if (local_c <= uVar2) {
      while( true ) {
        FUN_1cc0_1ad2(CONCAT11(0xb8,cVar1),iVar4,local_c * 0xa0 + iVar3,0xb800);
        FUN_1cc0_1ad2(CONCAT11(0xba,cVar1),iVar4,local_c * 0xa0 + iVar3,0xba00);
        FUN_1cc0_1ad2(CONCAT11(0xbc,cVar1),iVar4,local_c * 0xa0 + iVar3,0xbc00);
        FUN_1cc0_1ad2(CONCAT11(0xbe,cVar1),iVar4,local_c * 0xa0 + iVar3,0xbe00);
        if (local_c == uVar2) break;
        local_c = local_c + 1;
      }
    }
  }
  FUN_1b58_0030();
  return;
}


