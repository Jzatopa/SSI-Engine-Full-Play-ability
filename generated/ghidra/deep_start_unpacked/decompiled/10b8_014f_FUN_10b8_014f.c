
uint __stdcall16far FUN_10b8_014f(uint param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  
  uVar10 = (undefined2)((ulong)param_3 >> 0x10);
  pbVar6 = (byte *)param_3;
  uVar9 = (undefined2)((ulong)param_2 >> 0x10);
  pbVar8 = (byte *)param_2;
  uVar5 = 0;
  uVar3 = 0;
  while (uVar5 < param_1) {
    if (*pbVar6 < 0x80) {
      uVar3 = (uint)*pbVar6;
      uVar5 = uVar5 + uVar3 + 2;
      for (iVar4 = uVar3 + 1; pbVar6 = pbVar6 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
        pbVar2 = pbVar8;
        pbVar8 = pbVar8 + 1;
        *pbVar2 = *pbVar6;
      }
    }
    else {
      uVar5 = uVar5 + 2;
      pbVar2 = pbVar6;
      pbVar7 = pbVar6 + 1;
      pbVar6 = pbVar6 + 2;
      bVar1 = *pbVar7;
      uVar3 = (uint)bVar1;
      for (iVar4 = 0x101 - (uint)*pbVar2; iVar4 != 0; iVar4 = iVar4 + -1) {
        pbVar2 = pbVar8;
        pbVar8 = pbVar8 + 1;
        *pbVar2 = bVar1;
      }
    }
  }
  return uVar3;
}


