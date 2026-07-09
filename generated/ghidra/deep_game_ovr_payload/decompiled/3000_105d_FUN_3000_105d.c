
undefined1 __stdcall16far
FUN_3000_105d(uint *param_1,char *param_2,char *param_3,char param_4,char param_5)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar4;
  char local_21;
  int local_1b;
  int local_19;
  int local_17;
  int local_15;
  int local_d;
  int local_b;
  byte local_5;
  
  *(undefined1 *)0x4134 = 0;
  *(undefined1 *)0x4135 = 0;
  *(undefined1 *)0x4136 = 0;
  local_21 = '\x02';
  uVar2 = *param_1;
  local_1b = (int)param_5;
  local_19 = (int)param_4;
  local_17 = (int)*param_3;
  local_15 = (int)*param_2;
  FUN_3000_0e11(&local_1b,unaff_SS);
  while( true ) {
    bVar4 = false;
    bVar1 = *(byte *)((int)*(undefined4 *)0x71dc + local_b * 0x32 + local_d + 7);
    if (bVar1 == 1) {
      *(undefined1 *)0x4134 = 1;
      bVar4 = *(char *)0x4137 != '\0';
    }
    else if (bVar1 == 4) {
      *(undefined1 *)0x4135 = 1;
    }
    else if (local_21 == '\0') {
      if (((undefined *)&DAT_0000_26d9)[(uint)bVar1 * 4] == '\x02') {
        *(undefined1 *)0x4136 = 1;
      }
    }
    else {
      local_21 = local_21 + -1;
    }
    if ((((*(char *)((int)*(undefined4 *)0x71dc + 6) == '\0') &&
         (((undefined *)&DAT_0000_26d9)[(uint)bVar1 * 4] == '\x01')) &&
        ((param_5 != *param_3 || (param_4 != *param_2)))) ||
       ((bVar4 || (uVar2 * 2 + 1 < (uint)local_5)))) break;
    cVar3 = FUN_3000_0eb8(&local_1b,unaff_SS);
    if (cVar3 == '\0') {
      *param_1 = (uint)local_5;
      *(undefined1 *)0x4137 = 0;
      return 1;
    }
  }
  *param_3 = (char)local_d;
  *param_2 = (char)local_b;
  *param_1 = (uint)local_5;
  *(undefined1 *)0x4137 = 0;
  return 0;
}


