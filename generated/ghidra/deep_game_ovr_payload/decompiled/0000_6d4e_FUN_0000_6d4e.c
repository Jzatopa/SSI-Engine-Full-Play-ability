
void __stdcall16far FUN_0000_6d4e(void)

{
  undefined1 uVar1;
  char cVar2;
  int unaff_BP;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)(*(int *)(unaff_BP + 6) + -0xd) = 1;
  if (-1 < (char)((undefined *)&DAT_0000_fff5)[*(int *)(unaff_BP + 6)]) {
    FUN_0000_4cde(*(undefined2 *)(unaff_BP + 6));
  }
  while (('\0' < *(char *)(unaff_BP + -3) &&
         (((undefined *)&DAT_0000_fffa)[*(int *)(unaff_BP + 6)] == '\0'))) {
    *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + -1;
    if (*(char *)(unaff_BP + -4) == '\0') {
      cVar2 = FUN_0000_5844(*(undefined2 *)(unaff_BP + 6),0,0,*(undefined2 *)0x534e,
                            *(undefined2 *)0x5350);
      if (cVar2 == '\0') {
        *(undefined1 *)(unaff_BP + -3) = 0;
      }
    }
    else {
      uVar1 = FUN_0000_55ee(*(undefined2 *)(unaff_BP + 6),0,0,*(undefined2 *)0x534e,
                            *(undefined2 *)0x5350);
      *(undefined1 *)(unaff_BP + -5) = uVar1;
      *(undefined1 *)(unaff_BP + -4) = 0;
    }
  }
  if (*(char *)(*(int *)(unaff_BP + 6) + -7) == '\0') {
    *(undefined1 *)(*(int *)(unaff_BP + 6) + -7) = 0;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x268c,unaff_CS,unaff_BP + -0x32,unaff_SS,0xe);
}


