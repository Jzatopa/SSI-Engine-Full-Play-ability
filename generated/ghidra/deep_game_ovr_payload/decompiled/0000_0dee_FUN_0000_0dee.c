
void FUN_0000_0dee(void)

{
  uint uVar1;
  undefined2 in_AX;
  uint uVar2;
  undefined2 in_DX;
  int unaff_BP;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while( true ) {
    *(undefined2 *)(unaff_BP + -4) = in_AX;
    *(undefined2 *)(unaff_BP + -2) = in_DX;
    *(char *)(unaff_BP + -7) = *(char *)(unaff_BP + -7) + '\x01';
    if (((byte)((undefined *)&DAT_0000_fffa)[unaff_BP] <= *(byte *)(unaff_BP + -7)) ||
       (*(int *)(unaff_BP + -4) == 0 && *(int *)(unaff_BP + -2) == 0)) break;
    uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar3 = (int)*(undefined4 *)(unaff_BP + -4);
    in_AX = *(undefined2 *)(iVar3 + 0xff);
    in_DX = *(undefined2 *)(iVar3 + 0x101);
  }
  if (*(int *)(unaff_BP + -4) == 0 && *(int *)(unaff_BP + -2) == 0) {
    *(undefined1 *)0x8c3c = 1;
  }
  else {
    uVar4 = *(undefined2 *)(unaff_BP + -2);
    *(undefined2 *)0x57fb = *(undefined2 *)(unaff_BP + -4);
    *(undefined2 *)0x57fd = uVar4;
    *(undefined1 *)0x8c3c = 0;
  }
  if (((*(char *)(unaff_BP + -8) != '\0') && (*(char *)0x8c22 != '\0')) && (*(char *)0x8c23 != '\0')
     ) {
    uVar1 = *(uint *)0x536a;
    if ((*(int *)0x536c == *(int *)0x57fd) && (uVar1 == *(uint *)0x57fb)) {
      *(undefined1 *)0x3dde = 0;
    }
    uVar2 = uVar1 & 0xff00;
    uVar4 = CONCAT11((char)(uVar1 >> 8),1);
    FUN_0000_065a();
    FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar4,uVar2);
    *(undefined1 *)0x8c22 = 0;
    *(undefined1 *)0x8c23 = 0;
  }
  return;
}


