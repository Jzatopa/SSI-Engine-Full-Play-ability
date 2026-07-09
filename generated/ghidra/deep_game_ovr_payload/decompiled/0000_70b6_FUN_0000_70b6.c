
void FUN_0000_70b6(void)

{
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(int *)(*(int *)(unaff_BP + 6) + -2) != *(int *)0x5354) {
    FUN_0000_71c3();
    return;
  }
  if (*(int *)(*(int *)(unaff_BP + 6) + -4) != *(int *)0x5352) {
    FUN_0000_71c3();
    return;
  }
  if (*(char *)(*(int *)(unaff_BP + 6) + -0x106) == '\0') {
    FUN_0000_71c0();
    return;
  }
  if ('\x01' < *(char *)0x5359) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS);
}


