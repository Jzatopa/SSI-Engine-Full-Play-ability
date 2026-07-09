
void __stdcall16far FUN_178b_071e(undefined4 param_1,uint *param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined1 local_8;
  byte local_7;
  uint local_6;
  undefined2 local_4;
  
  local_4 = 0;
  local_6 = 0;
  do {
    uVar2 = (undefined2)((ulong)param_1 >> 0x10);
    uVar1 = (undefined2)param_1;
    FUN_1cc0_1925(0,0,1,&local_7,unaff_SS,uVar1,uVar2);
    if (((char)local_7 < '\0') || (local_7 == 0x7f)) {
      if ((-0x80 < (char)local_7) && (0x7f < local_7)) {
        local_7 = -local_7;
        FUN_1cc0_1925(0,0,1,&local_8,unaff_SS,uVar1,uVar2);
        FUN_1cc0_1ad2(CONCAT11((char)local_7 >> 7,local_8),(int)(char)local_7,
                      (int)*param_3 + local_6,(int)((ulong)*param_3 >> 0x10));
        local_6 = local_6 + (int)(char)local_7;
      }
    }
    else {
      FUN_1cc0_1925(0,0,(char)local_7 + 1,(int)*param_3 + local_6,(int)((ulong)*param_3 >> 0x10),
                    uVar1,uVar2);
      local_6 = local_6 + (char)local_7 + 1;
    }
  } while (local_6 < *param_2);
  return;
}


