/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:013b
 * Ghidra name: FUN_1602_013b
 * Linear address: 0x1615B
 * Body addresses: 186
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far
FUN_1602_013b(undefined1 param_1,undefined1 param_2,char param_3,char param_4,char param_5,
             char param_6)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  undefined2 local_9;
  undefined2 local_5;
  
  uVar1 = *(undefined1 *)0x44c4;
  local_5 = param_5 * 0x140 + (int)param_6;
  iVar2 = (((int)param_3 - (int)param_5) + 1) * 8 + -1;
  FUN_1602_0124(CONCAT11((char)((uint)iVar2 >> 8),param_2));
  FUN_1602_0084();
  out(0x3ce,5);
  out(0x3cf,2);
  local_9 = 0;
  while( true ) {
    iVar3 = ((int)param_4 - (int)param_6) + 1;
    FUN_1cc0_1ad2(CONCAT11((char)((uint)iVar3 >> 8),param_1),iVar3,local_5,*(undefined2 *)0x44c2);
    local_5 = local_5 + 0x28;
    if (local_9 == iVar2) break;
    local_9 = local_9 + 1;
  }
  out(0x3ce,5);
  out(0x3cf,0);
  *(undefined1 *)0x44c4 = uVar1;
  FUN_1602_0124(CONCAT11((char)((uint)local_9 >> 8),*(undefined1 *)0x44c4));
  return;
}


