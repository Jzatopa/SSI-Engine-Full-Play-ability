
undefined4 __stdcall16far FUN_2000_3ea6(char param_1,undefined4 param_2)

{
  int *piVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  int local_a;
  int iStack_8;
  int local_6;
  int local_4;
  
  uVar2 = (undefined2)((ulong)param_2 >> 0x10);
  iStack_8 = *(int *)((int)param_2 + 0xf9);
  local_a = *(int *)((int)param_2 + 0xf7);
  do {
    if (local_a == 0 && iStack_8 == 0) {
      local_6 = 0;
      local_4 = 0;
LAB_2000_3f18:
      return CONCAT22(local_4,local_6);
    }
    if (((*(byte *)(local_a + 0x34) & 0x80) != 0) &&
       (((undefined *)&DAT_0000_536e)[(uint)*(byte *)(local_a + 0x2e) * 9] == param_1)) {
      local_6 = local_a;
      local_4 = iStack_8;
      goto LAB_2000_3f18;
    }
    piVar1 = (int *)(local_a + 0x2a);
    iStack_8 = *(int *)(local_a + 0x2c);
    local_a = *piVar1;
  } while( true );
}


