
void __stdcall16far FUN_2000_e480(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_CS;
  int local_6;
  int iStack_4;
  
  local_6 = *param_1;
  iStack_4 = ((int *)param_1)[1];
  while (local_6 != 0 || iStack_4 != 0) {
    iVar1 = *(int *)(local_6 + 0x2a);
    iVar2 = *(int *)(local_6 + 0x2c);
    FUN_0000_ce54(unaff_CS,0x2e,local_6,iStack_4);
    unaff_CS = 0xcc0;
    local_6 = iVar1;
    iStack_4 = iVar2;
  }
  return;
}


