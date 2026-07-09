
undefined4 __stdcall16far FUN_187b_0000(undefined2 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  char local_112;
  char local_111;
  undefined2 local_110;
  undefined2 local_10e;
  int local_10c;
  undefined4 local_10a;
  char local_106 [256];
  undefined2 local_6;
  undefined2 local_4;
  
  FUN_1cc0_0adc(0xff,local_106,unaff_SS,(int)param_2,(int)((ulong)param_2 >> 0x10));
  local_6 = 0;
  local_4 = 0;
  uVar3 = (undefined2)((ulong)param_3 >> 0x10);
  uVar2 = (undefined2)param_3;
  FUN_1cc0_180c(local_106,unaff_SS,uVar2,uVar3);
  FUN_1cc0_183a(1,uVar2,uVar3);
  iVar1 = FUN_1cc0_04a2();
  if ((iVar1 == 0) && (local_106[0] != '\0')) {
    do {
      FUN_1cc0_1925(0,0,6,&local_112,unaff_SS,uVar2,uVar3);
      if (local_111 == -1) {
        FUN_1cc0_18bb(uVar2,uVar3);
        goto LAB_187b_0126;
      }
    } while ((local_111 != param_1._1_1_) || (local_112 != (char)param_1));
    FUN_1cc0_198d(local_110,local_10e,uVar2,uVar3);
    FUN_1cc0_1925(0,0,2,&local_10c,unaff_SS,uVar2,uVar3);
    local_10a = FUN_1cc0_023f(local_10c);
    FUN_1cc0_1aaf(2,local_10a,&local_10c,unaff_SS);
    FUN_1cc0_1925(0,0,local_10c + -2,(uint)local_10a + 2,
                  local_10a._2_2_ + (uint)(0xfffd < (uint)local_10a),uVar2,uVar3);
    local_6 = (uint)local_10a;
    local_4 = local_10a._2_2_;
  }
  FUN_1cc0_18bb(uVar2,uVar3);
LAB_187b_0126:
  return CONCAT22(local_4,local_6);
}


