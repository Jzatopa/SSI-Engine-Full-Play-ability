
void __stdcall16far FUN_1000_1391(char param_1)

{
  undefined2 unaff_DS;
  
  if (param_1 == '\0') {
    *(byte *)0x72c9 = *(byte *)0x72c9 >> 1;
    *(byte *)0x72c8 = *(byte *)0x72c8 >> 1;
  }
  return;
}


