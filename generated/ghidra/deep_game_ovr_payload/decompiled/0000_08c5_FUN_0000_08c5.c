
void FUN_0000_08c5(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  
  FUN_0000_49de(unaff_DI,unaff_DS);
  FUN_0000_3721(0x21a,*(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2),7,0);
  uVar2 = unaff_SS;
  FUN_0000_453c(unaff_BP + -4);
  cVar1 = FUN_0000_00d2(5);
  if (cVar1 != '\0') {
    FUN_0000_03ab(0x21a);
    FUN_0000_07e8(0x21a);
    FUN_0000_016c();
    FUN_0000_09b1();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x790,0x21a,(undefined *)&DAT_0000_fff5 + unaff_BP,unaff_SS,uVar2);
}


