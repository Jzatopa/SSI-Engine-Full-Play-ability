
/* WARNING: Control flow encountered bad instruction data */

void FUN_0000_3721(void)

{
  char in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  ((undefined *)&DAT_0000_ff9a)[in_BX + unaff_SI] =
       ((undefined *)&DAT_0000_ff9a)[in_BX + unaff_SI] + in_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


