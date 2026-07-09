
undefined1 __stdcall16far FUN_1000_59e5(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar3 = (undefined2)param_2;
  uVar4 = param_2._2_2_;
  bVar1 = func_0x00000814();
  if (bVar1 < 2) {
    cVar2 = func_0x00000dd5(0x7e,(int)param_1,param_1._2_2_,(undefined2)param_2,param_2._2_2_,uVar3,
                            uVar4);
    if (cVar2 == *(char *)((int)*(undefined4 *)((int)param_1 + 0xf3) + 7)) {
      bVar1 = func_0x00000a73(0xdb,&param_2);
      if ((bVar1 < 2) && (bVar1 = func_0x00000a73(0x99,&param_2), bVar1 < 2)) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


