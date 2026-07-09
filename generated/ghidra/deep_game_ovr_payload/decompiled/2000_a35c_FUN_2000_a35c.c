
void __stdcall16far FUN_2000_a35c(byte *param_1)

{
  char cVar1;
  undefined2 unaff_BP;
  
  if ('\0' < (char)*param_1) {
    cVar1 = FUN_0000_8695();
    if (cVar1 == '\0') {
      FUN_0000_c05c(0x46,unaff_BP);
    }
    else {
      *param_1 = *param_1 & 1;
    }
  }
  *param_1 = *param_1 - 1;
  return;
}


