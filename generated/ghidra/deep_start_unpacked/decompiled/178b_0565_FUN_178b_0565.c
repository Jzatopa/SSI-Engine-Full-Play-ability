
void __stdcall16far FUN_178b_0565(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 unaff_SS;
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  undefined1 local_306 [256];
  char local_206;
  char local_205;
  char local_204;
  char local_203;
  char local_202 [256];
  char local_102 [256];
  
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,(int)param_2,(int)((ulong)param_2 >> 0x10));
  FUN_1cc0_0adc(0xff,local_202,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  local_204 = local_202[0];
  local_206 = (local_102[0] - local_202[0]) + '\x01';
  local_203 = local_206;
  if (local_206 != '\0') {
    local_205 = '\x01';
    while( true ) {
      puVar2 = local_306;
      uVar1 = 1;
      uVar3 = unaff_SS;
      FUN_1cc0_0b0e(local_204,local_205,local_102,unaff_SS);
      FUN_1cc0_0bc7(local_202,unaff_SS,puVar2,uVar3);
      if ((bool)uVar1) {
        FUN_1cc0_0c73(local_204,local_205,local_102,unaff_SS);
      }
      if (local_205 == local_206) break;
      local_205 = local_205 + '\x01';
    }
  }
  FUN_1cc0_0adc(0xff,(int)param_3,(int)((ulong)param_3 >> 0x10),local_102,unaff_SS);
  return;
}


