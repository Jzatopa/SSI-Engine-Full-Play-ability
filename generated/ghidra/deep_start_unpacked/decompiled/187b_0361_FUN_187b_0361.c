
undefined2 __stdcall16far FUN_187b_0361(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined1 extraout_AH;
  undefined1 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  long lVar4;
  undefined4 uVar5;
  undefined1 local_185 [2];
  undefined1 local_183 [128];
  undefined1 local_103 [256];
  undefined1 local_3;
  
  FUN_1cc0_0adc(0xff,local_103,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_187b_029c();
  FUN_1cc0_180c(local_103,unaff_SS,local_183,unaff_SS);
  FUN_1cc0_183a(1,local_183,unaff_SS);
  iVar1 = FUN_1cc0_04a2();
  if (iVar1 == 0) {
    lVar4 = FUN_1cc0_19d4(local_183,unaff_SS);
    iVar1 = 0;
    if (lVar4 != 0) {
      uVar2 = FUN_1cc0_19d4(local_183,unaff_SS);
      *(undefined2 *)0x9ee6 = uVar2;
      uVar5 = FUN_1cc0_023f(*(undefined2 *)0x9ee6);
      *(undefined2 *)0x9ee2 = (int)uVar5;
      *(undefined2 *)0x9ee4 = (int)((ulong)uVar5 >> 0x10);
      FUN_1cc0_1925(local_185,unaff_SS,*(undefined2 *)0x9ee6,(int)*(undefined4 *)0x9ee2,
                    (int)((ulong)*(undefined4 *)0x9ee2 >> 0x10),local_183,unaff_SS);
      FUN_1cc0_18bb(local_183,unaff_SS);
      local_3 = 1;
      uVar3 = extraout_AH;
      goto LAB_187b_0406;
    }
  }
  uVar3 = (undefined1)((uint)iVar1 >> 8);
  local_3 = 0;
LAB_187b_0406:
  return CONCAT11(uVar3,local_3);
}


