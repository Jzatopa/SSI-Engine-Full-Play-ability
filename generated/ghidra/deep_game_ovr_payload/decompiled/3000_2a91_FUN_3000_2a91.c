
undefined2 __stdcall16far FUN_3000_2a91(char param_1,byte param_2,byte param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 in_AX;
  undefined1 uVar3;
  uint uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_9;
  char local_8;
  byte local_7;
  char local_6;
  byte local_5;
  byte local_4;
  undefined1 local_3;
  
  uVar3 = (undefined1)((uint)in_AX >> 8);
  if (*(char *)0x4438 == '\x05') {
    local_3 = 0;
    local_4 = FUN_3000_25e3((int)param_4,param_4._2_2_);
    ((undefined *)&DAT_0000_69f0)[(uint)local_4 * 4] = *(byte *)((int)param_4 + 0x34) & 0x7f;
    ((undefined *)&DAT_0000_69ed)[(uint)local_4 * 4] = param_3;
    ((undefined *)&DAT_0000_69ee)[(uint)local_4 * 4] = param_2;
    FUN_3000_263d(&local_9,unaff_SS,&local_7,unaff_SS,&local_6,unaff_SS,8,(int)param_4,param_4._2_2_
                 );
    if (((local_6 == '\0') && (local_7 != 0)) &&
       (((undefined *)&DAT_0000_26d8)[(uint)local_7 * 4] != -1)) {
      local_3 = 1;
      if ((param_1 != '\0') && (*(char *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 0xf) == '\0'))
      {
        bVar1 = *(byte *)0x71db;
        if (bVar1 != 0) {
          local_5 = 1;
          while( true ) {
            if ((*(int *)((uint)local_5 * 7 + 0x719e) == param_4._2_2_) &&
               (*(int *)((uint)local_5 * 7 + 0x719c) == (int)param_4)) {
              if (*(char *)((uint)local_5 * 7 + 0x71a2) != '\x05') {
                local_7 = *(byte *)((uint)local_5 * 7 + 0x71a2);
              }
              FUN_0000_e6d2(0);
            }
            if (local_5 == bVar1) break;
            local_5 = local_5 + 1;
          }
        }
        local_8 = '\0';
        if (*(byte *)0x71db != 0) {
          local_5 = 1;
          while( true ) {
            if (((*(int *)((uint)local_5 * 7 + 0x719c) != 0 ||
                  *(int *)((uint)local_5 * 7 + 0x719e) != 0) &&
                ((int)*(char *)((uint)local_5 * 7 + 0x71a0) == (uint)param_3)) &&
               ((int)*(char *)((uint)local_5 * 7 + 0x71a1) == (uint)param_2)) {
              local_8 = '\x01';
            }
            if (local_5 == *(byte *)0x71db) break;
            local_5 = local_5 + 1;
          }
        }
        if (local_8 == '\0') {
          *(byte *)((int)*(undefined4 *)0x71dc + (uint)param_2 * 0x32 + (uint)param_3 + 7) = local_7
          ;
        }
      }
      uVar2 = FUN_3000_1dba();
    }
    else {
      uVar2 = (uint)local_4;
      ((undefined *)&DAT_0000_69f0)[uVar2 * 4] = 0;
    }
    uVar3 = (undefined1)(uVar2 >> 8);
  }
  else {
    local_3 = 1;
  }
  return CONCAT11(uVar3,local_3);
}


