
void FUN_0000_0e07(void)

{
  uint uVar1;
  undefined2 in_AX;
  uint uVar2;
  undefined2 uVar3;
  undefined2 in_DX;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined2 *)0x57fb = in_AX;
  *(undefined2 *)0x57fd = in_DX;
  *(undefined1 *)0x8c3c = 0;
  if (((*(char *)(unaff_BP + -8) != '\0') && (*(char *)0x8c22 != '\0')) && (*(char *)0x8c23 != '\0')
     ) {
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


