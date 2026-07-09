
void __cdecl16far FUN_1b6f_029d(void)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  undefined2 uVar3;
  byte local_f;
  uint local_e;
  uint local_b;
  uint local_9;
  char local_7;
  uint local_6;
  uint local_4;
  
  FUN_1b6f_0000();
  if (*(char *)0x8db8 != '\0') {
    local_4 = 0;
    local_6 = 0;
    local_e = 1;
    while( true ) {
      local_7 = FUN_1b6f_060d(&local_f,unaff_SS,&local_b,unaff_SS,&local_9,unaff_SS,1);
      local_4 = local_4 + local_9;
      local_6 = local_6 + local_b;
      if (local_e == 0x14) break;
      local_e = local_e + 1;
    }
    *(uint *)0x8d86 = local_4 / 0x14;
    *(uint *)0x8d94 = local_6 / 0x14;
    do {
      FUN_1bdc_01c0();
      uVar2 = 0xa04e;
      uVar3 = unaff_DS;
      FUN_1cc0_0917(0,0x1d7,0x1bdc);
      FUN_1cc0_0848(uVar2,uVar3);
      local_e = 0;
      do {
        local_7 = FUN_1b6f_060d(&local_f,unaff_SS,&local_b,unaff_SS,&local_9,unaff_SS,1);
        local_e = local_e + 1;
        if (20000 < local_e) break;
      } while ((local_7 == '\0') || ((local_f & 1) == 0));
      if (20000 < local_e) {
        FUN_1bdc_01c0();
        uVar3 = 0xa04e;
        FUN_1cc0_0917(0,0x220,0x1bdc);
        FUN_1cc0_0848(uVar3,unaff_DS);
        FUN_1bdc_029c(2000);
        return;
      }
      local_4 = 0xffff;
      local_6 = 0xffff;
      *(undefined1 *)0x7817 = 1;
      while( true ) {
        cVar1 = FUN_1b6f_060d(&local_f,unaff_SS,&local_b,unaff_SS,&local_9,unaff_SS,1);
        if (cVar1 == '\0') {
          FUN_1bdc_01c0();
          uVar3 = 0xa04e;
          FUN_1cc0_0917(0,0x220,0x1bdc);
          FUN_1cc0_0848(uVar3,unaff_DS);
          FUN_1bdc_029c(2000);
          return;
        }
        if ((local_f & 1) != 0) {
          if (local_9 < local_4) {
            local_4 = local_9;
          }
          if (local_b < local_6) {
            local_6 = local_b;
          }
        }
        if (*(char *)0x7817 == '\x14') break;
        *(char *)0x7817 = *(char *)0x7817 + '\x01';
      }
    } while (local_7 == '\0');
    *(uint *)0x8d80 = local_4;
    *(int *)0x8d82 = (uint)(*(int *)0x8d86 - *(int *)0x8d80) / 3 + *(int *)0x8d80;
    *(int *)0x8d84 = (uint)((*(int *)0x8d86 - *(int *)0x8d80) * 2) / 3 + *(int *)0x8d80;
    *(uint *)0x8d8e = local_6;
    *(int *)0x8d90 = (uint)(*(int *)0x8d94 - *(int *)0x8d8e) / 3 + *(int *)0x8d8e;
    *(int *)0x8d92 = (uint)((*(int *)0x8d94 - *(int *)0x8d8e) * 2) / 3 + *(int *)0x8d8e;
    do {
      cVar1 = FUN_1b6f_0107(1,1);
    } while (cVar1 != '\0');
    do {
      FUN_1bdc_01c0();
      uVar2 = 0xa04e;
      uVar3 = unaff_DS;
      FUN_1cc0_0917(0,0x253,0x1bdc);
      FUN_1cc0_0848(uVar2,uVar3);
      local_e = 0;
      do {
        local_7 = FUN_1b6f_060d(&local_f,unaff_SS,&local_b,unaff_SS,&local_9,unaff_SS,1);
        local_e = local_e + 1;
        if (20000 < local_e) break;
      } while ((local_7 == '\0') || ((local_f & 1) == 0));
      if (20000 < local_e) {
        FUN_1bdc_01c0();
        uVar3 = 0xa04e;
        FUN_1cc0_0917(0,0x220,0x1bdc);
        FUN_1cc0_0848(uVar3,unaff_DS);
        FUN_1bdc_029c(2000);
        return;
      }
      local_4 = 0;
      local_6 = 0;
      *(undefined1 *)0x7817 = 1;
      while( true ) {
        cVar1 = FUN_1b6f_060d(&local_f,unaff_SS,&local_b,unaff_SS,&local_9,unaff_SS,1);
        if (cVar1 == '\0') {
          FUN_1bdc_01c0();
          uVar3 = 0xa04e;
          FUN_1cc0_0917(0,0x220,0x1bdc);
          FUN_1cc0_0848(uVar3,unaff_DS);
          FUN_1bdc_029c(2000);
          return;
        }
        if ((local_f & 1) != 0) {
          if (local_4 < local_9) {
            local_4 = local_9;
          }
          if (local_6 < local_b) {
            local_6 = local_b;
          }
        }
        if (*(char *)0x7817 == '\x14') break;
        *(char *)0x7817 = *(char *)0x7817 + '\x01';
      }
    } while (local_7 == '\0');
    *(uint *)0x8d8c = local_4;
    *(int *)0x8d88 = (uint)(*(int *)0x8d8c - *(int *)0x8d86) / 3 + *(int *)0x8d86;
    *(int *)0x8d8a = (uint)((*(int *)0x8d8c - *(int *)0x8d86) * 2) / 3 + *(int *)0x8d86;
    *(uint *)0x8d9a = local_6;
    *(int *)0x8d96 = (uint)(*(int *)0x8d9a - *(int *)0x8d94) / 3 + *(int *)0x8d94;
    *(int *)0x8d98 = (uint)((*(int *)0x8d9a - *(int *)0x8d94) * 2) / 3 + *(int *)0x8d94;
    *(undefined1 *)0x8db8 = 1;
  }
  return;
}


