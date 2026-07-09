
void __cdecl16far FUN_0000_0e25(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  bool in_ZF;
  
  if ((!in_ZF) && (*(char *)0x8c23 != '\0')) {
    uVar1 = *(uint *)0x536a;
    if ((*(int *)0x536c == *(int *)0x57fd) && (uVar1 == *(uint *)0x57fb)) {
      *(undefined1 *)0x3dde = 0;
    }
    uVar2 = uVar1 & 0xff00;
    uVar3 = CONCAT11((char)(uVar1 >> 8),1);
    FUN_0000_065a();
    FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar3,uVar2);
    *(undefined1 *)0x8c22 = 0;
    *(undefined1 *)0x8c23 = 0;
  }
  return;
}


