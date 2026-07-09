
void __cdecl16near FUN_1bdc_047c(void)

{
  char in_AL;
  char extraout_DL;
  undefined2 unaff_DS;
  
  thunk_FUN_1bdc_0609();
  if (in_AL == '\a') {
    FUN_1bdc_0609();
  }
  else if (((in_AL != '\b') && (in_AL != '\r')) &&
          ((in_AL == '\n' || (FUN_1bdc_0609(), *(byte *)0x9f3e < (byte)(extraout_DL + 1U))))) {
    FUN_1bdc_04d5();
  }
  thunk_FUN_1bdc_0609();
  return;
}


