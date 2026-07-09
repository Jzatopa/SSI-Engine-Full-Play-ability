
void __stdcall16far
FUN_1602_17b4(byte param_1,undefined1 param_2,undefined1 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined4 *)0x686c;
  pbVar5 = (byte *)((int)uVar1 + (uint)param_1 * 8);
  puVar7 = (undefined1 *)((param_4 * 0x140 + param_5) * 8);
  iVar2 = 8;
  do {
    iVar3 = 8;
    uVar4 = 0x80;
    do {
      puVar6 = puVar7;
      if ((*pbVar5 & uVar4) == 0) {
        *puVar6 = param_2;
      }
      else {
        *puVar6 = param_3;
      }
      uVar4 = uVar4 >> 1;
      iVar3 = iVar3 + -1;
      puVar7 = puVar6 + 1;
    } while (iVar3 != 0);
    pbVar5 = pbVar5 + 1;
    puVar7 = puVar6 + 0x139;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


