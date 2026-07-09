
void __stdcall16far FUN_2000_756b(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  
  if ((*(int *)0x72bc < 1) && ((*(int *)0x72bc < 0 || (*(int *)0x72ba == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *param_2 = uVar1;
  *(bool *)param_1 = *(int *)0x72be != 0 || *(int *)0x72c0 != 0;
  return;
}


