
undefined4 __stdcall16far FUN_2000_d805(undefined2 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 uStack_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_a = (int)param_2;
  uStack_8 = param_2._2_2_;
  local_e = 0;
  local_c = 0;
  for (local_10 = 0; (local_a != 0 || uStack_8 != 0 && (local_10 < param_3));
      local_10 = local_10 + 1) {
    if (*(char *)(local_a + 0x29) != '\0') {
      local_e = local_a;
      local_c = uStack_8;
    }
    piVar1 = (int *)(local_a + 0x2a);
    uStack_8 = *(int *)(local_a + 0x2c);
    local_a = *piVar1;
  }
  if ((local_e == 0 && local_c == 0) && (*(char *)((int)param_2 + 0x29) != '\0')) {
    local_6 = (int)param_2;
    local_4 = param_2._2_2_;
  }
  else {
    local_6 = local_e;
    local_4 = local_c;
  }
  return CONCAT22(local_4,local_6);
}


