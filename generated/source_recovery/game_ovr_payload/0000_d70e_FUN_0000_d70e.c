/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:d70e
 * Ghidra name: FUN_0000_d70e
 * Linear address: 0x0D70E
 * Original GAME.OVR file offset: 55062
 * Body addresses: 184
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_d70e(void)

{
  int unaff_BP;
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar3;
  
  *(byte *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0x34) =
       *(byte *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + 0x34) & 0x7f;
  uVar3 = *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP);
  uVar2 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 0xc) >> 0x10);
  iVar1 = (int)*(undefined4 *)(unaff_BP + 0xc);
  *(undefined2 *)(iVar1 + 0xeb) = *(undefined2 *)(unaff_BP + -8);
  *(undefined2 *)(iVar1 + 0xed) = uVar3;
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
  uVar3 = *(undefined2 *)(unaff_BP + 0xe);
  uVar2 = *(undefined2 *)(unaff_BP + 0xc);
  FUN_0000_0a05(unaff_CS,uVar2,uVar3);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_0000_d6c2(*(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe),uVar2,uVar3);
}


