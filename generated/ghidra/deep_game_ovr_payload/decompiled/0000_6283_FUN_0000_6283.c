
void __stdcall16far FUN_0000_6283(void)

{
  char *pcVar1;
  char in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0xca);
  *pcVar1 = *pcVar1 + (char)in_BX;
  ((undefined *)&DAT_0000_5dec)[in_BX + unaff_DI] =
       ((undefined *)&DAT_0000_5dec)[in_BX + unaff_DI] + in_CL;
  return;
}


