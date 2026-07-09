
void __cdecl16far FUN_0000_309f(void)

{
  char *pcVar1;
  undefined2 in_AX;
  undefined2 in_DX;
  int unaff_BP;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_CS;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined2 *)(unaff_BP + -5) = in_AX;
  *(undefined2 *)(unaff_BP + -3) = in_DX;
  if (*(char *)(unaff_BP + -0xf) != '\0') {
    uVar4 = *(undefined2 *)0x5801;
    *(undefined2 *)0x57fb = *(undefined2 *)0x57ff;
    *(undefined2 *)0x57fd = uVar4;
  }
  *(undefined1 *)(unaff_BP + -0x10) = 0;
  while ((*(int *)0x57fb != 0 || *(int *)0x57fd != 0 && (*(char *)(unaff_BP + -0x10) == '\0'))) {
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar2 = (int)*(undefined4 *)0x57fb;
    uVar4 = *(undefined2 *)(iVar2 + 0xf9);
    *(undefined2 *)(unaff_BP + -9) = *(undefined2 *)(iVar2 + 0xf7);
    *(undefined2 *)(unaff_BP + -7) = uVar4;
    while ((*(int *)(unaff_BP + -9) != 0 || *(int *)(unaff_BP + -7) != 0 &&
           (*(char *)(unaff_BP + -0x10) == '\0'))) {
      uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -9) >> 0x10);
      iVar2 = (int)*(undefined4 *)(unaff_BP + -9);
      uVar4 = *(undefined2 *)(iVar2 + 0x2c);
      *(undefined2 *)(unaff_BP + -0xd) = *(undefined2 *)(iVar2 + 0x2a);
      *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) = uVar4;
      if (*(char *)(unaff_BP + -1) == *(char *)((int)*(undefined4 *)(unaff_BP + -9) + 0x2e)) {
        if ((((*(byte *)((int)*(undefined4 *)(unaff_BP + -9) + 0x34) & 0x20) == 0) &&
            (1 < *(byte *)((int)*(undefined4 *)(unaff_BP + -9) + 0x38))) &&
           (((undefined *)&DAT_0000_fff2)[unaff_BP] != '\0')) {
          pcVar1 = (char *)((int)*(undefined4 *)(unaff_BP + -9) + 0x38);
          *pcVar1 = *pcVar1 + -1;
        }
        else {
          uVar4 = unaff_CS;
          if ((*(byte *)((int)*(undefined4 *)(unaff_BP + -9) + 0x34) & 0x80) != 0) {
            uVar4 = 0x7e;
            func_0x0000083c(unaff_CS,unaff_BP + -0x11);
          }
          unaff_CS = 0x99;
          func_0x000009e7(uVar4,*(undefined2 *)(unaff_BP + -9),*(undefined2 *)(unaff_BP + -7),
                          *(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
        }
        *(undefined1 *)(unaff_BP + -0x10) = ((undefined *)&DAT_0000_fff2)[unaff_BP];
      }
      uVar4 = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
      *(undefined2 *)(unaff_BP + -9) = *(undefined2 *)(unaff_BP + -0xd);
      *(undefined2 *)(unaff_BP + -7) = uVar4;
    }
    if (*(char *)(unaff_BP + -0x10) == '\0') {
      *(bool *)(unaff_BP + -0x10) = *(char *)(unaff_BP + -0xf) == '\0';
    }
    FUN_0000_0a05(unaff_CS,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar2 = (int)*(undefined4 *)0x57fb;
    uVar4 = *(undefined2 *)(iVar2 + 0x101);
    *(undefined2 *)0x57fb = *(undefined2 *)(iVar2 + 0xff);
    *(undefined2 *)0x57fd = uVar4;
    unaff_CS = 0x99;
  }
  uVar4 = *(undefined2 *)(unaff_BP + -3);
  *(undefined2 *)0x57fb = *(undefined2 *)(unaff_BP + -5);
  *(undefined2 *)0x57fd = uVar4;
  return;
}


