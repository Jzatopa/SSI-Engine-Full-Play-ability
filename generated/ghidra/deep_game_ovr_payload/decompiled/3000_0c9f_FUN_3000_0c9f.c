
void __cdecl16far FUN_3000_0c9f(void)

{
  char cVar1;
  byte bVar2;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined1 local_9 [3];
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  
  if ((1 < *(byte *)0x71e0) && (cVar1 = *(char *)0x71e0, cVar1 != '\x01')) {
    local_3 = 1;
    while( true ) {
      bVar2 = *(byte *)0x71e0;
      local_4 = local_3 + 1;
      if (local_4 <= bVar2) {
        while( true ) {
          local_6 = *(byte *)((uint)local_3 * 3 + 0x71e0);
          local_5 = *(byte *)((uint)local_4 * 3 + 0x71e0);
          if ((*(byte *)((uint)local_4 * 3 + 0x71df) < *(byte *)((uint)local_3 * 3 + 0x71df)) ||
             (((*(char *)((uint)local_4 * 3 + 0x71df) == *(char *)((uint)local_3 * 3 + 0x71df) &&
               (local_5 < local_6)) &&
              ((uint)local_5 % 2 <= (uint)((ulong)(long)(int)(uint)local_6 % 2))))) {
            func_0x0000d5f6(unaff_CS,3,local_9);
            func_0x0000d5f6(0xcc0,3,(uint)local_3 * 3 + 0x71de);
            unaff_CS = 0xcc0;
            func_0x0000d5f6(0xcc0,3,(uint)local_4 * 3 + 0x71de);
          }
          if (local_4 == bVar2) break;
          local_4 = local_4 + 1;
        }
      }
      if (local_3 == (byte)(cVar1 - 1U)) break;
      local_3 = local_3 + 1;
    }
  }
  return;
}


