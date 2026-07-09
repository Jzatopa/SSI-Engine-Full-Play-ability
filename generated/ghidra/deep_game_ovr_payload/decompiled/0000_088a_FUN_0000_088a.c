
void FUN_0000_088a(void)

{
  int unaff_BP;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x3ddb = *(undefined1 *)0x50d2;
  *(undefined1 *)0x50d2 = 6;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x790,unaff_CS,(undefined *)&DAT_0000_fff5 + unaff_BP,unaff_SS,unaff_ES);
}


