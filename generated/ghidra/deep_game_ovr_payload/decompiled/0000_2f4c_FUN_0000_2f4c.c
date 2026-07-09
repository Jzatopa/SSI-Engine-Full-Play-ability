
void __cdecl16far FUN_0000_2f4c(void)

{
  undefined2 uVar1;
  uint in_AX;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  uVar2 = in_AX & 0xff00;
  uVar3 = 1;
  FUN_0000_065a();
  uVar1 = *(undefined2 *)0x57fd;
  *(undefined2 *)0x536a = *(undefined2 *)0x57fb;
  *(undefined2 *)0x536c = uVar1;
  FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar3,uVar2);
  return;
}


