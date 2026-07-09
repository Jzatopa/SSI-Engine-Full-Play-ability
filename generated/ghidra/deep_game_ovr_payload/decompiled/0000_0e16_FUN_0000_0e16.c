
void FUN_0000_0e16(void)

{
  int *piVar1;
  uint uVar2;
  int in_AX;
  uint uVar3;
  undefined2 uVar4;
  undefined2 in_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  piVar1 = (int *)(in_BX + unaff_SI + -0x782);
  *piVar1 = *piVar1 + in_AX;
  *(char *)(unaff_SI + 0x48) = *(char *)(unaff_SI + 0x48) + (char)((uint)in_DX >> 8);
  if ((*(char *)0x8c22 != '\0') && (*(char *)0x8c23 != '\0')) {
    uVar2 = *(uint *)0x536a;
    if ((*(int *)0x536c == *(int *)0x57fd) && (uVar2 == *(uint *)0x57fb)) {
      *(undefined1 *)0x3dde = 0;
    }
    uVar3 = uVar2 & 0xff00;
    uVar4 = CONCAT11((char)(uVar2 >> 8),1);
    FUN_0000_065a();
    FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar4,uVar3);
    *(undefined1 *)0x8c22 = 0;
    *(undefined1 *)0x8c23 = 0;
  }
  return;
}


