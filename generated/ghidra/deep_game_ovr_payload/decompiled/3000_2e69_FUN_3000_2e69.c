
void __stdcall16far FUN_3000_2e69(undefined1 param_1,char param_2,char param_3)

{
  byte bVar1;
  bool bVar2;
  undefined2 unaff_DS;
  undefined4 local_7;
  byte local_3;
  
  bVar2 = false;
  for (local_7 = (undefined2 *)CONCAT22(*(undefined2 *)0x748b,(undefined2 *)*(undefined2 *)0x7489);
      (undefined2 *)local_7 != (undefined2 *)0x0 || local_7._2_2_ != 0;
      local_7 = (undefined2 *)CONCAT22(((undefined2 *)local_7)[1],(undefined2 *)*local_7)) {
    local_3 = 1;
    while( true ) {
      if (((*(char *)((int)(undefined2 *)local_7 + local_3 + 0xc) != '\0') &&
          ((int)*(char *)((undefined2 *)local_7 + 0xb) +
           (int)(char)((undefined *)&DAT_0000_26ca)[*(byte *)(local_3 + 0x3189)] == (int)param_3))
         && ((int)*(char *)((int)(undefined2 *)local_7 + 0x17) +
             (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)(local_3 + 0x3189)] == (int)param_2))
      {
        *(undefined1 *)((int)(undefined2 *)local_7 + local_3 + 3) = param_1;
        bVar2 = true;
      }
      if (local_3 == 9) break;
      local_3 = local_3 + 1;
    }
  }
  bVar1 = *(byte *)0x71db;
  if (bVar1 != 0) {
    local_3 = 1;
    while( true ) {
      if ((*(char *)((uint)local_3 * 7 + 0x71a0) == param_3) &&
         (*(char *)((uint)local_3 * 7 + 0x71a1) == param_2)) {
        *(undefined1 *)((uint)local_3 * 7 + 0x71a2) = param_1;
        bVar2 = true;
      }
      if (local_3 == bVar1) break;
      local_3 = local_3 + 1;
    }
  }
  if (!bVar2) {
    *(undefined1 *)((int)*(undefined4 *)0x71dc + param_2 * 0x32 + (int)param_3 + 7) = param_1;
  }
  return;
}


