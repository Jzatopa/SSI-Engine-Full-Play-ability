
undefined4 __stdcall16far FUN_2000_c3ce(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 uStack_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_a = param_1;
  uStack_8 = param_2;
  for (local_c = 0; (local_a != 0 || uStack_8 != 0 && (local_c != param_3)); local_c = local_c + 1)
  {
    piVar1 = (int *)(local_a + 0x2a);
    uStack_8 = *(int *)(local_a + 0x2c);
    local_a = *piVar1;
  }
  if (local_c == param_3) {
    local_6 = local_a;
    local_4 = uStack_8;
  }
  else {
    local_6 = 0;
    local_4 = 0;
  }
  return CONCAT22(local_4,local_6);
}


