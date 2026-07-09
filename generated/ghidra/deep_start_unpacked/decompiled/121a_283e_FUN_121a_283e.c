
void __stdcall16far FUN_121a_283e(undefined4 param_1,undefined2 param_2,int param_3)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_318;
  undefined1 local_317;
  int local_316;
  undefined2 local_314;
  undefined1 *local_312;
  undefined1 local_302 [768];
  
  FUN_1cc0_09f6(0x300,local_302,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  if (*(char *)0x44c8 == '\x03') {
    local_316 = param_3;
    local_314 = param_2;
    local_312 = local_302 + param_3 * 3;
    local_317 = 0x10;
    local_318 = 0x12;
    FUN_1c3e_000b(&local_318);
  }
  return;
}


