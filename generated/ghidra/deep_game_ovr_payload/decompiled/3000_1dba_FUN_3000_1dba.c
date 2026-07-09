
void __cdecl16far FUN_3000_1dba(void)

{
  byte bVar1;
  char cVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_6;
  char local_5;
  char local_4;
  byte local_3;
  
  FUN_0000_e6d2(0x400);
  bVar1 = *(byte *)&DAT_0000_69f0;
  if (bVar1 != 0) {
    local_3 = 1;
    while( true ) {
      if (((undefined *)&DAT_0000_69f0)[(uint)local_3 * 4] != '\0') {
        local_4 = '\0';
        while( true ) {
          cVar2 = FUN_3000_181b(&local_6,unaff_SS,&local_5,unaff_SS,local_4,
                                ((undefined *)&DAT_0000_69f0)[(uint)local_3 * 4]);
          if (cVar2 != '\0') {
            ((undefined *)&DAT_0000_6ba1)
            [((int)(char)((undefined *)&DAT_0000_69ee)[(uint)local_3 * 4] + (int)local_6) * 0x32 +
             (int)(char)((undefined *)&DAT_0000_69ed)[(uint)local_3 * 4] + (int)local_5] = local_3;
          }
          if (local_4 == '\x03') break;
          local_4 = local_4 + '\x01';
        }
        ((undefined *)&DAT_0000_6b10)[local_3] =
             ((undefined *)&DAT_0000_69ed)[(uint)local_3 * 4] -
             *(char *)((int)*(undefined4 *)0x71dc + 2);
        ((undefined *)&DAT_0000_6b58)[local_3] =
             ((undefined *)&DAT_0000_69ee)[(uint)local_3 * 4] -
             *(char *)((int)*(undefined4 *)0x71dc + 3);
      }
      if (local_3 == bVar1) break;
      local_3 = local_3 + 1;
    }
  }
  return;
}


