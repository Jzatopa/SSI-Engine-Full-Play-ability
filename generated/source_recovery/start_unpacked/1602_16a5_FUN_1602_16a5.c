/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:16a5
 * Ghidra name: FUN_1602_16a5
 * Linear address: 0x176C5
 * Body addresses: 267
 * Calling convention: __stdcall16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void FUN_1602_16a5(undefined2 param_1,byte param_2,byte param_3,int param_4,int param_5)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)(param_4 * 0x140 + param_5 * 4);
  iVar8 = 0;
  uVar3 = 0x100;
  iVar5 = 2;
  do {
    iVar6 = 4;
    pbVar2 = pbVar2 + 3;
    do {
      pbVar9 = pbVar2;
      iVar7 = 2;
      uVar3 = uVar3 & 0xff00;
      do {
        bVar4 = (byte)(uVar3 >> 8);
        bVar1 = param_2;
        if ((*(byte *)(iVar8 + 0x6870) & bVar4) != 0) {
          bVar1 = param_3;
        }
        bVar1 = (byte)uVar3 | bVar1;
        param_2 = param_2 << 4 | param_2 >> 4;
        param_3 = param_3 << 4 | param_3 >> 4;
        uVar3 = CONCAT11(bVar4 << 1 | (int)uVar3 < 0,bVar1);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *pbVar9 = bVar1;
      iVar6 = iVar6 + -1;
      pbVar2 = pbVar9 + -1;
    } while (iVar6 != 0);
    iVar6 = 4;
    pbVar2 = pbVar9 + 3;
    do {
      pbVar9 = pbVar2;
      iVar7 = 2;
      uVar3 = uVar3 & 0xff00;
      do {
        bVar4 = (byte)(uVar3 >> 8);
        bVar1 = param_2;
        if ((*(byte *)(iVar8 + 0x6871) & bVar4) != 0) {
          bVar1 = param_3;
        }
        bVar1 = (byte)uVar3 | bVar1;
        param_2 = param_2 << 4 | param_2 >> 4;
        param_3 = param_3 << 4 | param_3 >> 4;
        uVar3 = CONCAT11(bVar4 << 1 | (int)uVar3 < 0,bVar1);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *pbVar9 = bVar1;
      iVar6 = iVar6 + -1;
      pbVar2 = pbVar9 + -1;
    } while (iVar6 != 0);
    iVar6 = 4;
    pbVar2 = pbVar9 + 3;
    do {
      pbVar9 = pbVar2;
      iVar7 = 2;
      uVar3 = uVar3 & 0xff00;
      do {
        bVar4 = (byte)(uVar3 >> 8);
        bVar1 = param_2;
        if ((*(byte *)(iVar8 + 0x6872) & bVar4) != 0) {
          bVar1 = param_3;
        }
        bVar1 = (byte)uVar3 | bVar1;
        param_2 = param_2 << 4 | param_2 >> 4;
        param_3 = param_3 << 4 | param_3 >> 4;
        uVar3 = CONCAT11(bVar4 << 1 | (int)uVar3 < 0,bVar1);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *pbVar9 = bVar1;
      iVar6 = iVar6 + -1;
      pbVar2 = pbVar9 + -1;
    } while (iVar6 != 0);
    iVar6 = 4;
    pbVar9 = pbVar9 + 3;
    do {
      pbVar2 = pbVar9;
      iVar7 = 2;
      uVar3 = uVar3 & 0xff00;
      do {
        bVar4 = (byte)(uVar3 >> 8);
        bVar1 = param_2;
        if ((*(byte *)(iVar8 + 0x6873) & bVar4) != 0) {
          bVar1 = param_3;
        }
        bVar1 = (byte)uVar3 | bVar1;
        param_2 = param_2 << 4 | param_2 >> 4;
        param_3 = param_3 << 4 | param_3 >> 4;
        uVar3 = CONCAT11(bVar4 << 1 | (int)uVar3 < 0,bVar1);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      *pbVar2 = bVar1;
      iVar6 = iVar6 + -1;
      pbVar9 = pbVar2 + -1;
    } while (iVar6 != 0);
    iVar8 = iVar8 + 4;
    pbVar2 = pbVar2 + 0xa0;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


