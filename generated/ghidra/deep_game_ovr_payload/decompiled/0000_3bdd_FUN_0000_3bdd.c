
void __stdcall16far FUN_0000_3bdd(undefined2 param_1)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x7817 = 1;
  *(undefined2 *)0x4432 = param_1;
  *(undefined1 *)0x3ddc = 0;
  while ((*(char *)0x3ddc == '\0' && (*(char *)0x4446 == '\0'))) {
    *(undefined1 *)0x764e = *(undefined1 *)0x764f;
    *(undefined1 *)0x764f = *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x8000);
    FUN_0000_38e0();
  }
  *(undefined1 *)0x3ddc = 0;
  return;
}


