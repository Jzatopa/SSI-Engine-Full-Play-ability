
void FUN_0000_71c3(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  
  if (*(char *)(*(int *)(*(int *)(unaff_BP + 6) + 6) + -5) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS);
  }
  uVar5 = *(undefined2 *)(*(int *)(unaff_BP + 6) + -2);
  uVar4 = *(undefined2 *)(*(int *)(unaff_BP + 6) + -4);
  cVar2 = FUN_0000_080a();
  if (cVar2 != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS,uVar4);
  }
  uVar3 = 3;
  cVar2 = FUN_0000_0a6e(0x7e,3,*(undefined2 *)(*(int *)(unaff_BP + 6) + -4),
                        *(undefined2 *)(*(int *)(unaff_BP + 6) + -2),uVar4,uVar5);
  if (((cVar2 != '\0') && (0 < *(int *)((int)*(undefined4 *)0x534a + 0x20))) &&
     (*(char *)0x535c < '\x02')) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS,uVar3);
  }
  if ((0 < *(int *)((int)*(undefined4 *)0x534a + 0x18)) &&
     (uVar1 = *(undefined4 *)(*(int *)(unaff_BP + 6) + -4), *(char *)((int)uVar1 + 0x56) != '\0')) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS,uVar3);
  }
  return;
}


