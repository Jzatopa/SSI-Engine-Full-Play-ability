/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:0c73
 * Ghidra name: FUN_1602_0c73
 * Linear address: 0x16C93
 * Body addresses: 122
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

int __cdecl16far FUN_1602_0c73(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  int local_e;
  undefined1 local_c [2];
  undefined1 local_a [2];
  undefined1 local_8 [6];
  
  FUN_1c3e_00a2(&local_e,unaff_SS,local_c,unaff_SS,local_a,unaff_SS,local_8,unaff_SS);
  uVar4 = 0;
  iVar1 = FUN_1cc0_0a12();
  uVar5 = 0;
  iVar2 = FUN_1cc0_0a12(iVar1,uVar4);
  iVar3 = FUN_1cc0_0a12(iVar2,uVar5);
  return local_e + iVar3 + iVar2 + iVar1;
}


