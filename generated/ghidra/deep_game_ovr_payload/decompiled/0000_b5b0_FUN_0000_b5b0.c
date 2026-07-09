
void FUN_0000_b5b0(void)

{
  undefined2 in_AX;
  undefined1 uVar1;
  undefined2 in_DX;
  int unaff_BP;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar4;
  
  *(undefined2 *)(unaff_BP + -5) = in_AX;
  *(undefined2 *)(unaff_BP + -3) = in_DX;
  while (*(int *)(unaff_BP + -5) != 0 || *(int *)(unaff_BP + -3) != 0) {
    if ((*(char *)((int)*(undefined4 *)(unaff_BP + -5) + 0xd4) == '\v') ||
       (*(char *)((int)*(undefined4 *)(unaff_BP + -5) + 0xd4) == '\r')) {
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -5) + 0xd4) = 1;
    }
    uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -5) >> 0x10);
    iVar2 = (int)*(undefined4 *)(unaff_BP + -5);
    uVar4 = *(undefined2 *)(iVar2 + 0x101);
    *(undefined2 *)(unaff_BP + -5) = *(undefined2 *)(iVar2 + 0xff);
    *(undefined2 *)(unaff_BP + -3) = uVar4;
  }
  uVar3 = 1;
  uVar4 = 1;
  FUN_0000_08c5();
  *(char *)0x74b9 = *(char *)0x74b9 + '\x01';
  FUN_0000_05c1(0x8a,uVar4,uVar3);
  FUN_0000_0945(0x56);
  FUN_0000_0a82();
  iVar2 = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
  uVar1 = (undefined1)((uint)iVar2 >> 8);
  FUN_0000_0e16(0x99,CONCAT11(uVar1,8),CONCAT11(uVar1,0xff),iVar2,
                *(char *)((int)*(undefined4 *)0x71dc + 2) + 3);
  return;
}


