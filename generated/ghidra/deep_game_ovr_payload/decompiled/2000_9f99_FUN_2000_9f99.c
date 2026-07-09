
void __cdecl16far FUN_2000_9f99(void)

{
  char *pcVar1;
  int *piVar2;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 uStack_4;
  
  *(undefined1 *)0x72c2 = 0;
  *(undefined1 *)0x72c3 = 0;
  uStack_4 = *(int *)0x5801;
  local_6 = *(int *)0x57ff;
  while (local_6 != 0 || uStack_4 != 0) {
    if (*(char *)(local_6 + 0xd5) != '\0') {
      pcVar1 = (char *)(*(char *)(local_6 + 0xd6) + 0x72c2);
      *pcVar1 = *pcVar1 + '\x01';
    }
    piVar2 = (int *)(local_6 + 0xff);
    uStack_4 = *(int *)(local_6 + 0x101);
    local_6 = *piVar2;
  }
  return;
}


