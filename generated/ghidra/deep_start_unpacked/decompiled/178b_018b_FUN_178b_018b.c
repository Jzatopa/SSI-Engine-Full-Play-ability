
void __stdcall16far FUN_178b_018b(undefined4 param_1)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_53 [81];
  
  FUN_1cc0_0adc(0x50,local_53,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  cVar1 = FUN_178b_051b(local_53,unaff_SS);
  if (cVar1 != '\0') {
    FUN_1cc0_180c(local_53,unaff_SS,0x67ea,unaff_DS);
    FUN_1cc0_18bb(0x67ea,unaff_DS);
    FUN_1cc0_1a49(0x67ea,unaff_DS);
  }
  return;
}


