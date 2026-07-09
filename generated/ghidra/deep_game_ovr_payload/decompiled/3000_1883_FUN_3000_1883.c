
void __cdecl16far FUN_3000_1883(void)

{
  byte bVar1;
  undefined2 unaff_DS;
  byte local_3;
  
  bVar1 = *(byte *)&DAT_0000_69f0;
  if (bVar1 != 0) {
    local_3 = 1;
    while( true ) {
      ((undefined *)&DAT_0000_6b10)[local_3] =
           ((undefined *)&DAT_0000_69ed)[(uint)local_3 * 4] -
           *(char *)((int)*(undefined4 *)0x71dc + 2);
      ((undefined *)&DAT_0000_6b58)[local_3] =
           ((undefined *)&DAT_0000_69ee)[(uint)local_3 * 4] -
           *(char *)((int)*(undefined4 *)0x71dc + 3);
      if (local_3 == bVar1) break;
      local_3 = local_3 + 1;
    }
  }
  return;
}


