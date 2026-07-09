
void FUN_0000_4ebe(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined2 in_AX;
  undefined1 uVar5;
  undefined2 uVar4;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar5 = (undefined1)((uint)in_AX >> 8);
  *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
  if ('\0' < *(char *)(unaff_BP + -7)) {
    iVar2 = *(char *)(unaff_BP + -2) * 6;
    uVar5 = (undefined1)((uint)iVar2 >> 8);
    *(char *)(unaff_BP + -7) =
         *(char *)(unaff_BP + -7) - *(char *)((int)*(undefined4 *)(unaff_BP + 0xc) + iVar2 + 0x3e);
    if (*(char *)(unaff_BP + -7) < '\x01') {
      if ((*(int *)(unaff_BP + 0xe) == *(int *)0x534c) &&
         (*(int *)(unaff_BP + 0xc) == *(int *)0x534a)) {
        FUN_0000_4cde(*(undefined2 *)(unaff_BP + 6));
        func_0x00000a5f();
      }
      uVar4 = FUN_0000_4339(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 0xc),
                            *(undefined2 *)(unaff_BP + 0xe));
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2((uint)(*(byte *)((int)*(undefined4 *)(unaff_BP + 0xc) +
                                     *(char *)(unaff_BP + -2) * 6 + 0x3c) & 0x7f) * 0x22 + 0x2411,
                    unaff_DS,unaff_BP + -0x10c,unaff_SS,uVar4);
    }
  }
  if (*(char *)(unaff_BP + -2) == '\a') {
    if (*(char *)(unaff_BP + -8) != '\0') {
      FUN_0000_4a92(*(undefined2 *)(unaff_BP + 6),CONCAT11(uVar5,1),CONCAT11(uVar5,100));
    }
    cVar3 = FUN_0000_09b5(*(uint *)(unaff_BP + 8) >> 1);
    if ((cVar3 != '\0') && (*(int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30) != 0)) {
      piVar1 = (int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30);
      *piVar1 = *piVar1 + -1;
    }
    return;
  }
  FUN_0000_4ebe();
  return;
}


