
void __stdcall16far FUN_178b_0634(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar2;
  undefined2 uVar3;
  byte *pbVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  undefined1 local_303 [256];
  undefined1 local_203 [255];
  byte local_104;
  byte local_103;
  byte local_102 [256];
  
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  local_103 = 1;
  while( true ) {
    puVar6 = local_303;
    pbVar4 = local_102;
    puVar2 = local_203;
    uVar3 = unaff_SS;
    uVar5 = unaff_SS;
    uVar7 = unaff_SS;
    FUN_1cc0_0bf2(*(undefined1 *)(local_103 + 0xfd9));
    FUN_178b_0565(puVar2,uVar3,pbVar4,uVar5);
    FUN_1cc0_0adc(0xff,local_102,unaff_SS,puVar6,uVar7);
    if (local_103 == 10) break;
    local_103 = local_103 + 1;
  }
  puVar6 = local_203;
  uVar3 = unaff_SS;
  FUN_1cc0_0b0e(8,1,local_102,unaff_SS);
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,puVar6,uVar3);
  local_104 = local_102[0];
  if (local_102[0] != 0) {
    local_103 = 1;
    while( true ) {
      bVar1 = FUN_1cc0_1c54(local_102[local_103]);
      local_102[local_103] = bVar1;
      if (local_103 == local_104) break;
      local_103 = local_103 + 1;
    }
  }
  FUN_1cc0_0adc(0x50,(int)param_2,(int)((ulong)param_2 >> 0x10),local_102,unaff_SS);
  return;
}


