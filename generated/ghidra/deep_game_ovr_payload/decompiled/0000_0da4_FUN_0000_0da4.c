
void FUN_0000_0da4(void)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined2 uVar4;
  char in_CL;
  int in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(int *)((undefined *)&DAT_0000_ff9a + in_BX + unaff_SI) =
       *(int *)((undefined *)&DAT_0000_ff9a + in_BX + unaff_SI) + in_DX;
  pcVar1 = (char *)(in_BX + unaff_SI + -0x5ba);
  *pcVar1 = *pcVar1 + in_CL;
  uVar4 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
  *(undefined2 *)(unaff_BP + -2) = uVar4;
  *(byte *)(unaff_BP + -8) = ((undefined *)&DAT_0000_fffa)[unaff_BP] & 0x80;
  ((undefined *)&DAT_0000_fffa)[unaff_BP] = ((undefined *)&DAT_0000_fffa)[unaff_BP] & 0x7f;
  if (((undefined *)&DAT_0000_fffa)[unaff_BP] != '\0') {
    while ((*(byte *)(unaff_BP + -7) < (byte)((undefined *)&DAT_0000_fffa)[unaff_BP] &&
           (*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0))) {
      uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
      uVar4 = *(undefined2 *)(iVar5 + 0x101);
      *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar5 + 0xff);
      *(undefined2 *)(unaff_BP + -2) = uVar4;
      *(char *)(unaff_BP + -7) = *(char *)(unaff_BP + -7) + '\x01';
    }
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


