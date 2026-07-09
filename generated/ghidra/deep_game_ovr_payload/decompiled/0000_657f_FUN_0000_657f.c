
undefined2 __stdcall16far FUN_0000_657f(void)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined2 in_AX;
  undefined1 uVar3;
  undefined1 extraout_AH;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while( true ) {
    uVar3 = (undefined1)((uint)in_AX >> 8);
    if ((char)in_AX != '\0') {
      *(undefined1 *)(unaff_DI + -3) = *(undefined1 *)(unaff_DI + -2);
    }
    if (*(char *)(unaff_DI + -2) == '\a') break;
    *(char *)(unaff_DI + -2) = *(char *)(unaff_DI + -2) + '\x01';
    in_AX = FUN_0000_6308(*(undefined2 *)(unaff_DI + 6),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_DI + -2)),
                          *(undefined2 *)(unaff_DI + 0xc),*(undefined2 *)(unaff_DI + 0xe));
  }
  if (*(char *)(unaff_DI + -3) < '\0') {
    *(undefined1 *)(unaff_DI + -1) = 0;
  }
  else {
    uVar2 = *(undefined4 *)(unaff_DI + 0xc);
    *(int *)(unaff_DI + -0x108) = (int)uVar2 + *(char *)(unaff_DI + -3) * 6 + 0x3c;
    *(undefined2 *)(unaff_DI + -0x106) = (int)((ulong)uVar2 >> 0x10);
    pcVar1 = (char *)((int)*(undefined4 *)(unaff_DI + -0x108) + 5);
    *pcVar1 = *pcVar1 + -1;
    pcVar1 = (char *)((int)*(undefined4 *)(unaff_DI + -0x108) + 4);
    *pcVar1 = *pcVar1 + *(char *)((uint)(*(byte *)*(undefined4 *)(unaff_DI + -0x108) & 0x7f) * 0x22
                                 + 0x240a);
    FUN_0000_4339(*(undefined2 *)(unaff_DI + 6),*(undefined2 *)(unaff_DI + 0xc),
                  *(undefined2 *)(unaff_DI + 0xe));
    FUN_0000_4389();
    func_0x0000d74f();
    func_0x0000d74f(0xcc0,(uint)(*(byte *)*(undefined4 *)(unaff_DI + -0x108) & 0x7f) * 0x22 + 0x2411
                   );
    func_0x0000d74f(0xcc0,0x20af,0xcc0);
    FUN_0000_715c(0xcc0);
    *(undefined1 *)(unaff_DI + -1) = 1;
    uVar3 = extraout_AH;
  }
  return CONCAT11(uVar3,*(undefined1 *)(unaff_DI + -1));
}


