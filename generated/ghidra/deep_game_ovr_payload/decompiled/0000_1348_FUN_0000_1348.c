
void __cdecl16far FUN_0000_1348(void)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  if (*(char *)((int)*(undefined4 *)0x441c + 0x2c1) != '\0') {
    pcVar1 = (char *)((int)*(undefined4 *)0x441c + 0x2c1);
    *pcVar1 = *pcVar1 + -1;
    FUN_0000_06f3();
  }
  *(int *)0x4432 = *(int *)0x4432 + 1;
  return;
}


