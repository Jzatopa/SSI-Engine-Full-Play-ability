
void FUN_0000_4fd0(void)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  byte bVar10;
  undefined2 uVar8;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar11;
  undefined1 uVar9;
  
  if (*(int *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) +
               *(char *)(unaff_BP + 10) * 2 + 0x16) == 0) {
    *(undefined1 *)(unaff_BP + 10) = 0;
  }
  uVar2 = *(uint *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) +
                    *(char *)(unaff_BP + 10) * 2 + 0x16);
  uVar4 = *(uint *)(unaff_BP + 8);
  if (((int)uVar2 < 0 && (int)uVar2 >> 0xf < 1) || (((int)uVar2 >> 0xf < 1 && (uVar2 < uVar4)))) {
    uVar4 = *(uint *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) +
                      *(char *)(unaff_BP + 10) * 2 + 0x16);
    *(uint *)(unaff_BP + 8) = uVar4;
  }
  if (*(int *)(unaff_BP + 8) != 0) {
    uVar8 = *(undefined2 *)(unaff_BP + 0xe);
    uVar11 = *(undefined2 *)(unaff_BP + 0xc);
    uVar9 = (undefined1)(uVar4 >> 8);
    uVar5 = CONCAT11(uVar9,*(undefined1 *)(unaff_BP + 10));
    uVar6 = CONCAT11(uVar9,1);
    func_0x00000a64();
    iVar7 = *(char *)(unaff_BP + 10) * 2;
    piVar1 = (int *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + iVar7 + 0x16);
    *piVar1 = *piVar1 - *(int *)(unaff_BP + 8);
    bVar10 = (byte)((uint)iVar7 >> 8);
    func_0x00000a64(0x99,(uint)bVar10 << 8,CONCAT11(bVar10,*(undefined1 *)(unaff_BP + 10)),
                    *(undefined2 *)(unaff_BP + 0xc),*(undefined2 *)(unaff_BP + 0xe),uVar6,uVar5,
                    uVar11,uVar8);
    iVar7 = *(char *)(unaff_BP + 10) * 2;
    if (*(int *)((int)*(undefined4 *)((undefined *)&DAT_0000_fff4 + unaff_BP) + iVar7 + 0x16) == 0)
    {
      if ((*(int *)(unaff_BP + 0xe) == *(int *)0x534c) &&
         (*(int *)(unaff_BP + 0xc) == *(int *)0x534a)) {
        FUN_0000_4cde(*(undefined2 *)(unaff_BP + 6));
      }
      uVar8 = FUN_0000_4339(*(undefined2 *)(unaff_BP + 6),*(undefined2 *)(unaff_BP + 0xc),
                            *(undefined2 *)(unaff_BP + 0xe));
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(*(char *)(unaff_BP + 10) * 0x12 + 0x11e2,unaff_DS,unaff_BP + -0x10c,unaff_SS,
                    uVar8);
    }
    if (*(char *)(unaff_BP + -8) != '\0') {
      uVar9 = (undefined1)((uint)iVar7 >> 8);
      FUN_0000_4a92(*(undefined2 *)(unaff_BP + 6),CONCAT11(uVar9,1),CONCAT11(uVar9,100));
    }
    cVar3 = FUN_0000_09b5(*(uint *)(unaff_BP + 8) >> 1);
    if ((cVar3 != '\0') && (*(int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30) != 0)) {
      piVar1 = (int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30);
      *piVar1 = *piVar1 + -1;
    }
  }
  return;
}


