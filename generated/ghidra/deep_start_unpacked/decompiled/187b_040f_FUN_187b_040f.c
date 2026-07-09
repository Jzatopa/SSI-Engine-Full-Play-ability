
void __stdcall16far FUN_187b_040f(undefined4 param_1,undefined4 param_2)

{
  undefined2 unaff_SS;
  undefined1 *puVar1;
  undefined2 uVar2;
  undefined1 *puVar3;
  undefined2 uVar4;
  undefined1 local_354 [256];
  undefined1 local_254 [256];
  undefined1 local_154 [256];
  byte local_54;
  char local_53 [81];
  
  FUN_1cc0_09f6(0x51,local_53,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  local_54 = 0;
  local_154[0] = 0;
  while ((local_54 < 0x50 && (local_53[local_54] != '\0'))) {
    puVar3 = local_354;
    uVar4 = unaff_SS;
    FUN_1cc0_0ac2(local_154,unaff_SS);
    puVar1 = local_254;
    uVar2 = unaff_SS;
    FUN_1cc0_0bf2(local_53[local_54]);
    FUN_1cc0_0b4f(puVar1,uVar2);
    FUN_1cc0_0adc(0xff,local_154,unaff_SS,puVar3,uVar4);
    local_54 = local_54 + 1;
  }
  FUN_1cc0_0adc(0xff,(int)param_2,(int)((ulong)param_2 >> 0x10),local_154,unaff_SS);
  return;
}


