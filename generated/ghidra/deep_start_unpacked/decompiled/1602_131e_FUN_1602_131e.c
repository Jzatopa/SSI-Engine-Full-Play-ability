
void __stdcall16far FUN_1602_131e(undefined1 param_1,undefined4 param_2)

{
  undefined2 unaff_SS;
  undefined1 local_102 [256];
  
  FUN_1cc0_1790(0xff,local_102,unaff_SS,0,param_1,0);
  FUN_1cc0_0adc(0xff,(int)param_2,(int)((ulong)param_2 >> 0x10),local_102,unaff_SS);
  return;
}


