
void __stdcall16far FUN_178b_0131(undefined4 param_1,undefined1 param_2)

{
  byte bVar1;
  byte extraout_AH;
  byte extraout_AH_00;
  uint uVar2;
  undefined2 unaff_SS;
  undefined1 local_2b [41];
  
  FUN_1cc0_0adc(0x28,local_2b,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_178b_0113(CONCAT11(extraout_AH,0x28),(uint)extraout_AH << 8,CONCAT11(extraout_AH,0x18),
                (uint)extraout_AH << 8);
  FUN_178b_00a3(local_2b,unaff_SS,CONCAT11(extraout_AH_00,param_2),CONCAT11(extraout_AH_00,0x18),
                (uint)extraout_AH_00 << 8);
  uVar2 = FUN_1836_01c7();
  bVar1 = (byte)(uVar2 >> 8);
  FUN_178b_0113(CONCAT11(bVar1,0x28),(uint)bVar1 << 8,CONCAT11(bVar1,0x18),uVar2 & 0xff00);
  return;
}


