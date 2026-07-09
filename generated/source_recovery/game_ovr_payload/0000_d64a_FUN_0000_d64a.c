/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:d64a
 * Ghidra name: FUN_0000_d64a
 * Linear address: 0x0D64A
 * Original GAME.OVR file offset: 54866
 * Body addresses: 120
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_d64a(void)

{
  undefined2 uVar1;
  uint uVar2;
  int unaff_BP;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar6;
  
  uVar4 = *(undefined2 *)(unaff_BP + 0xe);
  uVar5 = *(undefined2 *)(unaff_BP + 0xc);
  uVar1 = 1;
  uVar6 = func_0x00000846();
  *(int *)((undefined *)&DAT_0000_ffe4 + unaff_BP) = (int)uVar6;
  *(int *)((undefined *)&DAT_0000_ffe6 + unaff_BP) = (int)((ulong)uVar6 >> 0x10);
  uVar2 = *(uint *)((undefined *)&DAT_0000_ffe8 + unaff_BP);
  if ((*(int *)((undefined *)&DAT_0000_ffea + unaff_BP) !=
       *(int *)((undefined *)&DAT_0000_ffe6 + unaff_BP)) ||
     (uVar2 != *(uint *)((undefined *)&DAT_0000_ffe4 + unaff_BP))) {
    if (*(int *)((undefined *)&DAT_0000_ffe4 + unaff_BP) != 0 ||
        *(int *)((undefined *)&DAT_0000_ffe6 + unaff_BP) != 0) {
      func_0x0000083c(0x7e,(int)*(undefined4 *)(unaff_BP + 6),
                      (int)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10),
                      *(undefined2 *)((undefined *)&DAT_0000_ffe4 + unaff_BP),
                      *(undefined2 *)((undefined *)&DAT_0000_ffe6 + unaff_BP),uVar1,uVar5,uVar4);
    }
    uVar2 = 0;
    if (*(int *)((undefined *)&DAT_0000_ffe8 + unaff_BP) != 0 ||
        *(int *)((undefined *)&DAT_0000_ffea + unaff_BP) != 0) {
      uVar2 = func_0x0000083c(0x7e,(int)*(undefined4 *)(unaff_BP + 6),
                              (int)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10),
                              *(undefined2 *)((undefined *)&DAT_0000_ffe8 + unaff_BP),
                              *(undefined2 *)((undefined *)&DAT_0000_ffea + unaff_BP),uVar1,uVar5,
                              uVar4);
    }
  }
  *(undefined1 *)*(undefined4 *)(unaff_BP + 6) = 0;
  uVar2 = uVar2 & 0xff00;
  uVar6 = func_0x00000846(0x7e,uVar2,*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe)
                         );
  *(int *)((undefined *)&DAT_0000_fff4 + unaff_BP) = (int)uVar6;
  *(int *)((undefined *)&DAT_0000_fff6 + unaff_BP) = (int)((ulong)uVar6 >> 0x10);
  if ((*(int *)((undefined *)&DAT_0000_fffa + unaff_BP) ==
       *(int *)((undefined *)&DAT_0000_fff6 + unaff_BP)) &&
     (*(int *)(unaff_BP + -8) == *(int *)((undefined *)&DAT_0000_fff4 + unaff_BP))) {
    uVar4 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 0xc) >> 0x10);
    iVar3 = (int)*(undefined4 *)(unaff_BP + 0xc);
    if ((*(int *)((undefined *)&DAT_0000_fffa + unaff_BP) == *(int *)(iVar3 + 0xed)) &&
       (*(int *)(unaff_BP + -8) == *(int *)(iVar3 + 0xeb))) goto LAB_0000_d706;
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
  uVar4 = *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP);
  uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 0xc) >> 0x10);
  iVar3 = (int)*(undefined4 *)(unaff_BP + 0xc);
  *(undefined2 *)(iVar3 + 0xeb) = *(undefined2 *)(unaff_BP + -8);
  *(undefined2 *)(iVar3 + 0xed) = uVar4;
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
    func_0x0000083c(0x7e,(int)*(undefined4 *)(unaff_BP + 6),
                    (int)((ulong)*(undefined4 *)(unaff_BP + 6) >> 0x10),
                    *(undefined2 *)((undefined *)&DAT_0000_ffec + unaff_BP),
                    *(undefined2 *)((undefined *)&DAT_0000_ffee + unaff_BP));
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
  uVar4 = *(undefined2 *)(unaff_BP + 0xe);
  uVar5 = *(undefined2 *)(unaff_BP + 0xc);
  FUN_0000_0a05(0x7e,uVar5,uVar4);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_0000_d6c2(*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe),uVar5,uVar4,
                      uVar2);
}


