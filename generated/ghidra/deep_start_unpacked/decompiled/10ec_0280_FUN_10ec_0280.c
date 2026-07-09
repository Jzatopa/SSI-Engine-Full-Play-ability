
void __stdcall16far FUN_10ec_0280(char param_1,char param_2,char param_3,char param_4)

{
  char cVar1;
  byte extraout_AH;
  byte extraout_AH_00;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined2 unaff_DS;
  undefined2 local_10;
  undefined2 local_e;
  
  FUN_1b58_0051();
  cVar1 = *(char *)0x44c8;
  if (cVar1 == '\0') {
    local_e = (int)param_3 << 2;
    uVar4 = param_1 * 4 + 3;
    iVar2 = (((int)param_2 - (int)param_4) + 1) * 2;
    if (local_e <= uVar4) {
      while( true ) {
        FUN_1cc0_1ad2(0xb800,iVar2,local_e * 0x50 + param_4 * 2,0xb800);
        FUN_1cc0_1ad2(0xba00,iVar2,local_e * 0x50 + param_4 * 2,0xba00);
        if (local_e == uVar4) break;
        local_e = local_e + 1;
      }
    }
  }
  else if (cVar1 == '\x01') {
    FUN_1602_013b((uint)extraout_AH << 8,(uint)extraout_AH << 8,CONCAT11(extraout_AH,param_1),
                  CONCAT11(extraout_AH,param_2),CONCAT11(extraout_AH,param_3),
                  CONCAT11(extraout_AH,param_4));
    FUN_1602_013b((uint)extraout_AH_00 << 8,CONCAT11(extraout_AH_00,1),
                  CONCAT11(extraout_AH_00,param_1),CONCAT11(extraout_AH_00,param_2),
                  CONCAT11(extraout_AH_00,param_3),CONCAT11(extraout_AH_00,param_4));
  }
  else if (cVar1 == '\x02') {
    local_e = (int)param_3 << 1;
    uVar4 = param_1 * 2 + 1;
    iVar2 = param_4 * 4;
    iVar3 = (((int)param_2 - (int)param_4) + 1) * 4;
    if (local_e <= uVar4) {
      while( true ) {
        FUN_1cc0_1ad2(0xb800,iVar3,local_e * 0xa0 + iVar2,0xb800);
        FUN_1cc0_1ad2(0xba00,iVar3,local_e * 0xa0 + iVar2,0xba00);
        FUN_1cc0_1ad2(0xbc00,iVar3,local_e * 0xa0 + iVar2,0xbc00);
        FUN_1cc0_1ad2(0xbe00,iVar3,local_e * 0xa0 + iVar2,0xbe00);
        if (local_e == uVar4) break;
        local_e = local_e + 1;
      }
    }
  }
  else if (cVar1 == '\x03') {
    local_10 = param_3 * 0xa00 + param_4 * 8;
    uVar4 = (param_1 + 1) * 8 - 1;
    local_e = (int)param_3 << 3;
    if (local_e <= uVar4) {
      while( true ) {
        FUN_1cc0_1ad2(local_10 & 0xff00,(((int)param_2 - (int)param_4) + 1) * 8,local_10,0xa000);
        local_10 = local_10 + 0x140;
        if (local_e == uVar4) break;
        local_e = local_e + 1;
      }
    }
  }
  FUN_1b58_0030();
  return;
}


