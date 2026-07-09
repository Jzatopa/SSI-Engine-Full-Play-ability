
void __stdcall16far FUN_0000_f9c0(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_6;
  char local_5;
  char local_4;
  byte local_3;
  
  if ((*(char *)((int)*(undefined4 *)0x441c + 0x2c1) == '\0') &&
     (*" at sensor operation!\x0eShip Character\x01" != *(char *)(param_1 + -0xd))) {
    local_6 = '\x01';
  }
  else {
    local_6 = *(char *)((int)*(undefined4 *)0x441c + 0x2c1);
  }
  if (*(char *)0x443a != '\0') {
    local_6 = '\x02';
  }
  if (*" at sensor operation!\x0eShip Character\x01" != ((undefined *)&DAT_0000_fff2)[param_1]) {
    ((undefined *)&DAT_0000_fff2)[param_1] = *(undefined1 *)0x736b;
    *(byte *)0x4002 = *(byte *)0x736b >> 1;
    *(char *)0x3ffd = ((undefined *)&DAT_0000_26ca)[*(byte *)0x736b] * local_6 + *(char *)0x3ffc;
    *(char *)0x3fff =
         ((undefined *)&DAT_0000_26d3)[*(byte *)0x736b] * local_6 + (char)*(code *)FUN_0000_3ffe;
    *(undefined1 *)0x4003 = (char)((uint)((ulong)(long)(int)(*(byte *)0x736b + 4) % 8) >> 1);
    *(undefined1 *)0x400a = 0;
    while( true ) {
      local_3 = 0;
      while( true ) {
        if (local_3 == 1) {
          ((undefined *)&DAT_0000_fff6)[param_1] = 4;
        }
        else {
          ((undefined *)&DAT_0000_fff6)[param_1] = *(undefined1 *)(*(char *)0x400a + 0x4002);
        }
        local_5 = '\0';
        while( true ) {
          local_4 = '\0';
          while( true ) {
            if ((local_4 < *(char *)((uint)(byte)((undefined *)&DAT_0000_fff6)[param_1] * 0xc +
                                     local_5 * 2 + 0x71e)) ||
               (*(char *)((uint)(byte)((undefined *)&DAT_0000_fff6)[param_1] * 0xc + local_5 * 2 +
                         0x71f) < local_4)) {
              *(undefined1 *)
               (*(char *)0x400a * 0x108 + (uint)local_3 * 0x42 + local_5 * 0xb + (int)local_4 +
               0x3dec) = 0;
            }
            else {
              *(undefined1 *)
               (*(char *)0x400a * 0x108 + (uint)local_3 * 0x42 + local_5 * 0xb + (int)local_4 +
               0x3dec) = 1;
            }
            if (local_4 == '\n') break;
            local_4 = local_4 + '\x01';
          }
          if (local_5 == '\x05') break;
          local_5 = local_5 + '\x01';
        }
        if (local_3 == 3) break;
        local_3 = local_3 + 1;
      }
      if (*(char *)0x400a == '\x01') break;
      *(char *)0x400a = *(char *)0x400a + '\x01';
    }
  }
  return;
}


