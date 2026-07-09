
void FUN_1602_15a6(undefined2 param_1,byte param_2,byte param_3,int param_4,int param_5)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  byte *pbVar11;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)(param_4 * 0x140 + param_5 * 2);
  bVar8 = *(byte *)(param_3 + 0x22cb);
  bVar9 = *(byte *)(param_2 + 0x22cb);
  iVar10 = 0;
  uVar3 = 0x100;
  iVar5 = 4;
  do {
    iVar6 = 2;
    pbVar2 = pbVar2 + 1;
    do {
      pbVar11 = pbVar2;
      iVar7 = 4;
      uVar3 = uVar3 & 0xff00;
      do {
        bVar4 = (byte)(uVar3 >> 8);
        bVar1 = bVar9;
        if ((*(byte *)(iVar10 + 0x6870) & bVar4) != 0) {
          bVar1 = bVar8;
        }
        bVar1 = (byte)uVar3 | bVar1;
        bVar8 = bVar8 << 1 | (char)bVar8 < '\0';
        bVar8 = bVar8 << 1 | (char)bVar8 < '\0';
        bVar9 = bVar9 << 1 | (char)bVar9 < '\0';
        bVar9 = bVar9 << 1 | (char)bVar9 < '\0';
        uVar3 = CONCAT11(bVar4 << 1 | (int)uVar3 < 0,bVar1);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *pbVar11 = bVar1;
      iVar6 = iVar6 + -1;
      pbVar2 = pbVar11 + -1;
    } while (iVar6 != 0);
    uVar3 = 0x100;
    iVar6 = 2;
    pbVar11 = pbVar11 + 1;
    do {
      pbVar2 = pbVar11;
      iVar7 = 4;
      uVar3 = uVar3 & 0xff00;
      do {
        bVar4 = (byte)(uVar3 >> 8);
        bVar1 = bVar9;
        if ((*(byte *)(iVar10 + 0x6871) & bVar4) != 0) {
          bVar1 = bVar8;
        }
        bVar1 = (byte)uVar3 | bVar1;
        bVar8 = bVar8 << 1 | (char)bVar8 < '\0';
        bVar8 = bVar8 << 1 | (char)bVar8 < '\0';
        bVar9 = bVar9 << 1 | (char)bVar9 < '\0';
        bVar9 = bVar9 << 1 | (char)bVar9 < '\0';
        uVar3 = CONCAT11(bVar4 << 1 | (int)uVar3 < 0,bVar1);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *pbVar2 = bVar1;
      iVar6 = iVar6 + -1;
      pbVar11 = pbVar2 + -1;
    } while (iVar6 != 0);
    iVar10 = iVar10 + 2;
    pbVar2 = pbVar2 + 0x50;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


