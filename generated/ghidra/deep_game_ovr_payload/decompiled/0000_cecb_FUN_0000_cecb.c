
undefined1 __stdcall16far FUN_0000_cecb(undefined4 param_1)

{
  char cVar1;
  undefined1 local_3;
  
  FUN_0000_09fb();
  cVar1 = func_0x000009ce(0x99,(int)param_1,param_1._2_2_);
  if ((cVar1 == '\0') && (*(char *)((int)*(undefined4 *)((int)param_1 + 0xf3) + 1) != '\0')) {
    local_3 = func_0x0000058a(0x99,(int)param_1,param_1._2_2_);
  }
  else {
    local_3 = FUN_0000_0a28(0x99,(int)param_1,param_1._2_2_);
  }
  return local_3;
}


