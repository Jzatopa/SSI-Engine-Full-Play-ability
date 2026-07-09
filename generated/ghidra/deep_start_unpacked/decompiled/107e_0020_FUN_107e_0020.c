
/* WARNING: Control flow encountered bad instruction data */

void FUN_107e_0020(void)

{
  code *pcVar1;
  undefined1 *in_BX;
  undefined2 *unaff_SI;
  undefined2 unaff_DS;
  
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  *in_BX = *in_BX;
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
  *unaff_SI = *unaff_SI;
  pcVar1 = (code *)swi(0x3f);
  (*pcVar1)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


