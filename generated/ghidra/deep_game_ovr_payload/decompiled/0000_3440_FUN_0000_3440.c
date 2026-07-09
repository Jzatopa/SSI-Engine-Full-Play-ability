
void __cdecl16far FUN_0000_3440(void)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  pcVar1 = (char *)((int)*(undefined4 *)0x4418 + 0x1f6);
  *pcVar1 = *pcVar1 + '\x01';
  if (*(byte *)((int)*(undefined4 *)0x4418 + 0x1f6) <= *(byte *)((int)*(undefined4 *)0x4418 + 0x1f7)
     ) {
    *(undefined2 *)0x4432 = *(undefined2 *)0x8c42;
  }
  return;
}


