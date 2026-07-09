
undefined2 __stdcall16far FUN_3000_2d11(char param_1,char param_2)

{
  undefined1 extraout_AH;
  undefined1 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  bool bVar3;
  undefined4 local_9;
  byte local_5;
  char local_4;
  
  iVar2 = (int)*(undefined4 *)0x71dc + param_1 * 0x32 + (int)param_2;
  bVar3 = iVar2 == 0;
  local_4 = *(char *)(iVar2 + 7);
  FUN_0000_d977();
  if (bVar3) {
    uVar1 = extraout_AH;
    if (local_4 == '\x05') {
      if (*(byte *)0x71db != 0) {
        local_5 = 1;
        while( true ) {
          uVar1 = (undefined1)((uint)local_5 * 7 >> 8);
          if ((*(char *)((uint)local_5 * 7 + 0x71a0) == param_2) &&
             (uVar1 = (undefined1)((uint)local_5 * 7 >> 8),
             *(char *)((uint)local_5 * 7 + 0x71a1) == param_1)) {
            local_4 = *(char *)((uint)local_5 * 7 + 0x71a2);
            uVar1 = (undefined1)((uint)local_5 * 7 >> 8);
          }
          if (local_5 == *(byte *)0x71db) break;
          local_5 = local_5 + 1;
        }
      }
    }
  }
  else {
    for (local_9 = (undefined2 *)CONCAT22(*(undefined2 *)0x748b,(undefined2 *)*(undefined2 *)0x7489)
        ; (undefined2 *)local_9 != (undefined2 *)0x0 || local_9._2_2_ != 0;
        local_9 = (undefined2 *)CONCAT22(((undefined2 *)local_9)[1],(undefined2 *)*local_9)) {
      local_5 = 1;
      while( true ) {
        if (((*(char *)((int)(undefined2 *)local_9 + local_5 + 0xc) != '\0') &&
            ((int)*(char *)((undefined2 *)local_9 + 0xb) +
             (int)(char)((undefined *)&DAT_0000_26ca)[*(byte *)(local_5 + 0x3189)] == (int)param_2))
           && ((int)*(char *)((int)(undefined2 *)local_9 + 0x17) +
               (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)(local_5 + 0x3189)] == (int)param_1
              )) {
          local_4 = *(char *)((int)(undefined2 *)local_9 + local_5 + 3);
        }
        if (local_5 == 9) break;
        local_5 = local_5 + 1;
      }
    }
    uVar1 = 0;
  }
  return CONCAT11(uVar1,local_4);
}


