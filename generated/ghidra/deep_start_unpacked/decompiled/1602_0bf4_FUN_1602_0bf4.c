
void __stdcall16far FUN_1602_0bf4(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  byte extraout_AH;
  byte extraout_AH_00;
  undefined2 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 local_32 [2];
  undefined1 local_30 [2];
  int local_2e;
  undefined1 local_2c;
  undefined1 local_2b [41];
  
  uVar2 = &stack0x0000 == (undefined1 *)0x32;
  FUN_1cc0_0adc(0x28,local_2b,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_1602_03d1(CONCAT11(extraout_AH,0x28),(uint)extraout_AH << 8,CONCAT11(extraout_AH,0x18),
                (uint)extraout_AH << 8);
  FUN_1602_041a(local_2b,unaff_SS,CONCAT11(extraout_AH_00,param_2),CONCAT11(extraout_AH_00,param_3),
                CONCAT11(extraout_AH_00,0x18),(uint)extraout_AH_00 << 8);
  do {
    uVar3 = uVar2;
    uVar1 = FUN_1836_01c7();
    local_2c = (undefined1)uVar1;
    FUN_1cc0_0d77(0xbd4,0x1836,uVar1);
    uVar2 = 1;
  } while ((bool)uVar3);
  if (*(char *)0x8d71 != '\0') {
    do {
      FUN_1b58_0072(local_32,unaff_SS,local_30,unaff_SS,&local_2e,unaff_SS);
    } while (local_2e != 0);
  }
  return;
}


