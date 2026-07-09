
void __stdcall16far FUN_0000_d6c2(void)

{
  int in_AX;
  int unaff_BP;
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_ZF;
  
  if ((in_ZF) && (in_AX == *(int *)((undefined *)&DAT_0000_fff4 + unaff_BP))) {
    uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 0xc) >> 0x10);
    iVar1 = (int)*(undefined4 *)(unaff_BP + 0xc);
    if ((*(int *)((undefined *)&DAT_0000_fffa + unaff_BP) == *(int *)(iVar1 + 0xed)) &&
       (*(int *)(unaff_BP + -8) == *(int *)(iVar1 + 0xeb))) goto LAB_0000_d706;
  }
  if ((*(int *)(unaff_BP + -8) != 0 || *(int *)((undefined *)&DAT_0000_fffa + unaff_BP) != 0) &&
     (((undefined *)&DAT_0000_5371)[(uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -8) + 0x2e) * 9]
      != '\0')) {
    *(undefined1 *)*(undefined4 *)(unaff_BP + 6) = 1;
  }
LAB_0000_d706:
  if (*(int *)((undefined *)&DAT_0000_fff4 + unaff_BP) != 0 ||
      *(int *)((undefined *)&DAT_0000_fff6 + unaff_BP) != 0) {
    *(byte *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0x34) =
         *(byte *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0x34) & 0x7f;
  }
  uVar2 = *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP);
  uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 0xc) >> 0x10);
  iVar1 = (int)*(undefined4 *)(unaff_BP + 0xc);
  *(undefined2 *)(iVar1 + 0xeb) = *(undefined2 *)(unaff_BP + -8);
  *(undefined2 *)(iVar1 + 0xed) = uVar2;
  if (*(int *)(unaff_BP + -8) != 0 || *(int *)((undefined *)&DAT_0000_fffa + unaff_BP) != 0) {
    *(byte *)((int)*(undefined4 *)(unaff_BP + -8) + 0x34) =
         *(byte *)((int)*(undefined4 *)(unaff_BP + -8) + 0x34) | 0x80;
  }
  if ((((*(char *)*(undefined4 *)(unaff_BP + 6) == '\0') &&
       (*(int *)((undefined *)&DAT_0000_ffec + unaff_BP) != 0 ||
        *(int *)((undefined *)&DAT_0000_ffee + unaff_BP) != 0)) &&
      (*(char *)(unaff_BP + -0x1d) == '\0')) &&
     (((undefined *)&DAT_0000_5370)[(uint)*(byte *)((int)*(undefined4 *)(unaff_BP + -8) + 0x2e) * 9]
      == '\b')) {
    unaff_CS = 0x7e;
    func_0x0000083c();
  }
  if (((*(int *)((undefined *)&DAT_0000_ffe6 + unaff_BP) ==
        *(int *)((undefined *)&DAT_0000_ffea + unaff_BP)) &&
      (*(int *)((undefined *)&DAT_0000_ffe4 + unaff_BP) ==
       *(int *)((undefined *)&DAT_0000_ffe8 + unaff_BP))) &&
     ((*(int *)((undefined *)&DAT_0000_fff6 + unaff_BP) ==
       *(int *)((undefined *)&DAT_0000_fffa + unaff_BP) &&
      ((*(int *)((undefined *)&DAT_0000_fff4 + unaff_BP) == *(int *)(unaff_BP + -8) &&
       (*(char *)*(undefined4 *)(unaff_BP + 6) == '\0')))))) {
    return;
  }
  uVar2 = *(undefined2 *)(unaff_BP + 0xe);
  uVar3 = *(undefined2 *)(unaff_BP + 0xc);
  FUN_0000_0a05(unaff_CS,uVar3,uVar2);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_0000_d6c2(*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe),uVar3,uVar2);
}


