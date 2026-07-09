
undefined1 __stdcall16far FUN_2000_ccd0(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((((*(char *)0x8c3f == '\0') || (*(char *)0x4438 != '\x04')) ||
      (*(int *)(param_1 + -0x20e) < 3)) ||
     (((0xd < *(int *)(param_1 + -0x20e) || (*(int *)(param_1 + -0x210) < 3)) ||
      (0xd < *(int *)(param_1 + -0x210))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


