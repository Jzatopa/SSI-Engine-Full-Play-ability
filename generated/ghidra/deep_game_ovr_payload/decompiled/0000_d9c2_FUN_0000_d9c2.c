
void FUN_0000_d9c2(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int unaff_BP;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar7;
  undefined2 uVar8;
  
  if (*(char *)(unaff_BP + -7) == '\0') {
    *(undefined1 *)(unaff_BP + -7) = 1;
  }
  if (((undefined *)&DAT_0000_fffa)[unaff_BP] == '\0') {
    if (*(char *)(unaff_BP + -5) != '\0') {
      FUN_0000_d9cf();
      return;
    }
    *(undefined1 *)(unaff_BP + -5) = *(undefined1 *)(unaff_BP + -7);
    if (*(char *)(unaff_BP + -7) != '\0') {
      *(undefined1 *)((int)*(undefined4 *)0x71dc + 6) = 1;
    }
    *(undefined1 *)(unaff_BP + -3) = 0x14;
    uVar8 = *(undefined2 *)(unaff_BP + 0xe);
    uVar7 = *(undefined2 *)(unaff_BP + 0xc);
    uVar4 = 0xff;
    uVar3 = func_0x00000a1e();
    *(undefined1 *)(unaff_BP + -2) = uVar3;
    while( true ) {
      if (*(char *)(unaff_BP + -3) == '\0') {
        FUN_0000_d9c2();
        return;
      }
      if (((undefined *)&DAT_0000_fffa)[unaff_BP] != '\0') break;
      if (*(char *)(unaff_BP + -2) == '\0') {
        FUN_0000_d9c2();
        return;
      }
      *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + -1;
      uVar3 = FUN_0000_09ba(0x99,*(undefined1 *)(unaff_BP + -2),1,uVar4,uVar7,uVar8);
      *(undefined1 *)(unaff_BP + -4) = uVar3;
      if (((undefined *)&DAT_0000_74ba)[*(byte *)(unaff_BP + -4)] != '\0') {
        iVar5 = (uint)(byte)((undefined *)&DAT_0000_74ba)[*(byte *)(unaff_BP + -4)] * 4;
        uVar1 = *(undefined2 *)((undefined *)&DAT_0000_7081 + iVar5);
        *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) =
             *(undefined2 *)((undefined *)&DAT_0000_707f + iVar5);
        *(undefined2 *)(unaff_BP + -9) = uVar1;
        if ((*(char *)(unaff_BP + 10) == '\0') ||
           (*(char *)((int)*(undefined4 *)0x71dc + 6) == '\0')) {
                    /* WARNING: Subroutine does not return */
          thunk_FUN_0000_643a(0x99,*(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP),
                              *(undefined2 *)(unaff_BP + -9),*(undefined2 *)(unaff_BP + 0xc),
                              *(undefined2 *)(unaff_BP + 0xe));
        }
        ((undefined *)&DAT_0000_fffa)[unaff_BP] = 1;
        uVar1 = *(undefined2 *)(unaff_BP + -9);
        uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0xf3);
        uVar6 = (undefined2)((ulong)uVar2 >> 0x10);
        iVar5 = (int)uVar2;
        *(undefined2 *)(iVar5 + 8) = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
        *(undefined2 *)(iVar5 + 10) = uVar1;
      }
    }
    FUN_0000_d9c2();
    return;
  }
  FUN_0000_d9cf();
  return;
}


