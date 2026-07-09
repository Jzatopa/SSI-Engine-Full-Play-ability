
void FUN_0000_065a(void)

{
  int unaff_BP;
  undefined *unaff_DI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  if (in_ZF || in_OF != in_SF) {
    unaff_DI = (undefined *)&DAT_0000_fff6 + unaff_BP;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x1c9,unaff_CS,unaff_DI,unaff_SS);
}


