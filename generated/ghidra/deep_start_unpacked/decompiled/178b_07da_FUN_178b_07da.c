
undefined1 __stdcall16far
FUN_178b_07da(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
             undefined4 param_5)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined1 local_231 [256];
  undefined1 local_131 [258];
  undefined1 local_2f [2];
  undefined1 local_2d [21];
  undefined1 local_18 [21];
  undefined1 local_3;
  
  FUN_1cc0_0adc(0x14,local_18,unaff_SS,(int)param_5,(int)((ulong)param_5 >> 0x10));
  FUN_1cc0_0adc(0x14,local_2d,unaff_SS,(int)param_4,(int)((ulong)param_4 >> 0x10));
  puVar4 = local_131;
  uVar5 = unaff_SS;
  FUN_1cc0_0ac2(local_18,unaff_SS);
  FUN_1cc0_0b4f(local_2d,unaff_SS);
  uVar2 = (undefined2)((ulong)param_2 >> 0x10);
  cVar1 = FUN_178b_02e6((int)param_2,uVar2,
                        CONCAT11((char)((uint)*(byte *)0x50d2 * 0x1e >> 8),*(undefined1 *)0x52d4),
                        (uint)*(byte *)0x50d2 * 0x1e + 0x2358,unaff_DS,puVar4,uVar5);
  if (cVar1 == '\0') {
    local_3 = 0;
  }
  else {
    puVar4 = local_231;
    uVar5 = unaff_SS;
    FUN_1cc0_0ac2(local_18,unaff_SS);
    FUN_1cc0_0b4f(local_2d,unaff_SS);
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    cVar1 = FUN_178b_02e6((int)param_1,uVar3,
                          CONCAT11((char)((uint)*(byte *)0x50d2 * 0x1e >> 8),*(undefined1 *)0x52d4),
                          (uint)*(byte *)0x50d2 * 0x1e + 0x2358,unaff_DS,puVar4,uVar5);
    if (cVar1 == '\0') {
      local_3 = 0;
    }
    else {
      FUN_1cc0_1925(local_2f,unaff_SS,2,(int *)param_3,(int)((ulong)param_3 >> 0x10),(int)param_1,
                    uVar3);
      *param_3 = *param_3 + 2;
      FUN_1cc0_198d(*param_3,0,(int)param_2,uVar2);
      local_3 = 1;
    }
  }
  return local_3;
}


