
void FUN_0000_080f(void)

{
  int unaff_BP;
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(unaff_BP + 6) + -4;
  FUN_0000_2670();
  FUN_0000_6d0d(0x21a,iVar1);
  uVar3 = 0x10;
  uVar2 = 0xf0;
  FUN_0000_49de(0x99c7,unaff_DS);
  FUN_0000_3721(0x21a,*(undefined2 *)(*(int *)(unaff_BP + 6) + -4),
                *(undefined2 *)(*(int *)(unaff_BP + 6) + -2),0,0,uVar2,uVar3);
  FUN_0000_453c(*(int *)(unaff_BP + 6) + -4);
  return;
}


