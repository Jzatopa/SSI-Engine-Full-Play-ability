
void __cdecl16far FUN_0000_0e39(void)

{
  uint in_AX;
  uint uVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool in_ZF;
  
  if ((in_ZF) && (in_AX == *(uint *)0x57fb)) {
    *(undefined1 *)0x3dde = 0;
  }
  uVar1 = in_AX & 0xff00;
  uVar2 = 1;
  FUN_0000_065a();
  FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar2,uVar1);
  *(undefined1 *)0x8c22 = 0;
  *(undefined1 *)0x8c23 = 0;
  return;
}


