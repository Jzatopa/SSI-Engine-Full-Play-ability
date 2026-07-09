
int __cdecl16far FUN_187b_0e70(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  
  if ((param_4 == 0) && ((param_2 == 0 || (param_3 == 0)))) {
    param_1 = (int)(CONCAT22(param_2,param_1) / (ulong)param_3);
  }
  else {
    iVar1 = 0x20;
    uVar3 = 0;
    uVar2 = 0;
    do {
      bVar4 = param_1 < 0;
      param_1 = param_1 * 2;
      bVar5 = (int)param_2 < 0;
      param_2 = param_2 << 1 | (uint)bVar4;
      bVar4 = (int)uVar2 < 0;
      uVar2 = uVar2 << 1 | (uint)bVar5;
      uVar3 = uVar3 << 1 | (uint)bVar4;
      if ((param_4 <= uVar3) && ((param_4 < uVar3 || (param_3 <= uVar2)))) {
        bVar4 = uVar2 < param_3;
        uVar2 = uVar2 - param_3;
        uVar3 = (uVar3 - param_4) - (uint)bVar4;
        param_1 = param_1 + 1;
      }
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return param_1;
}


