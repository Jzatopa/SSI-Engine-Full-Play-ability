
void FUN_0000_4913(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_BP;
  int iVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  
  *(char *)0x7817 = *(char *)0x7817 + -1;
  *(int *)(unaff_BP + -0x10) = ((uint)*(byte *)(unaff_BP + -7) + *(char *)0x7817 * 3) * 6 + 0x253a;
  *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = unaff_DS;
  uVar8 = 0x44ce;
  FUN_0000_444d();
  uVar1 = (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 5) + *(int *)(unaff_BP + -4);
  iVar3 = ((uint)*(byte *)(unaff_BP + -7) + *(char *)0x7817 * 3) * 4;
  uVar7 = *(undefined2 *)(iVar3 + 0x52d8);
  uVar6 = *(undefined2 *)(iVar3 + 0x52d6);
  uVar5 = *(undefined2 *)0x44cc;
  uVar4 = *(undefined2 *)0x44ca;
  FUN_0000_2e9a(uVar4,uVar5,uVar6,uVar7,CONCAT11((char)(uVar1 >> 8),5),uVar1 & 0xff00,uVar1,
                (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 4) + *(int *)(unaff_BP + -2)
                ,uVar8);
  FUN_0000_39b7();
  FUN_0000_c05c(0x3c,uVar4,uVar5,uVar6,uVar7);
  uVar2 = (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 5) + *(int *)(unaff_BP + -4);
  uVar1 = uVar2 >> 8;
  FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x44ce,
                *(undefined2 *)0x44d0,uVar1 << 8,uVar1 << 8,uVar2,
                (int)*(char *)((int)*(undefined4 *)(unaff_BP + -0x10) + 4) + *(int *)(unaff_BP + -2)
               );
  FUN_0000_453c(0x44ce);
  if (*(char *)0x7817 != '\0') {
    FUN_0000_4913();
    return;
  }
  FUN_0000_39b7();
  uVar7 = *(undefined2 *)(unaff_BP + -9);
  *(undefined2 *)0x44ce = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
  *(undefined2 *)0x44d0 = uVar7;
  return;
}


