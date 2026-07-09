
char __cdecl16far FUN_2000_72e9(void)

{
  int *piVar1;
  undefined2 unaff_DS;
  undefined1 local_8;
  undefined2 local_7;
  undefined2 uStack_5;
  
  local_7 = *(int *)0x57ff;
  uStack_5 = *(int *)0x5801;
  local_8 = '\0';
  while (local_7 != 0 || uStack_5 != 0) {
    if ((*(char *)(local_7 + 0xe7) == '\0') || (*(char *)(local_7 + 0xe7) == -0x4d)) {
      local_8 = local_8 + '\x01';
    }
    piVar1 = (int *)(local_7 + 0xff);
    uStack_5 = *(int *)(local_7 + 0x101);
    local_7 = *piVar1;
  }
  return local_8;
}


