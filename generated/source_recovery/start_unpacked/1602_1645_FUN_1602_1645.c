/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:1645
 * Ghidra name: FUN_1602_1645
 * Linear address: 0x17665
 * Body addresses: 96
 * Calling convention: __stdcall16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined4 FUN_1602_1645(undefined2 param_1,byte param_2,byte param_3,int param_4,int param_5)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  
  pbVar2 = (byte *)(param_4 * 0x140 + param_5);
  out(0x3ce,0xa05);
  out(0x3ce,3);
  out(0x3ce,7);
  iVar4 = 0;
  iVar3 = 8;
  do {
    bVar1 = *(byte *)(iVar4 + 0x6870);
    out(0x3ce,CONCAT11(bVar1,8));
    *pbVar2 = *pbVar2 & param_3;
    out(0x3ce,CONCAT11(~bVar1,8));
    *pbVar2 = *pbVar2 & param_2;
    pbVar2 = pbVar2 + 0x28;
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  out(0x3ce,5);
  out(0x3ce,0xff08);
  out(0x3ce,3);
  out(0x3ce,0xf07);
  return 0x3ce0f07;
}


