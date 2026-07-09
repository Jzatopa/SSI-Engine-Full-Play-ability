/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:2dea
 * Ghidra name: FUN_121a_2dea
 * Linear address: 0x14F8A
 * Body addresses: 430
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_121a_2dea(char param_1,byte param_2,byte param_3,byte param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 uStack_4;
  
  iVar1 = *(int *)((int)*(undefined4 *)0x7507 + 0x12);
  iVar4 = (uint)param_2 * iVar1;
  if (param_1 == '\0') {
    uVar2 = *(undefined4 *)((uint)param_4 * 8 + (uint)param_3 * 4 + 0x68c0);
    FUN_1cc0_1aaf(iVar1,(int)*(undefined4 *)0x7507 + iVar4 + 0x1b,
                  (int)((ulong)*(undefined4 *)0x7507 >> 0x10),(int)uVar2 + 0x1b,
                  (int)((ulong)uVar2 >> 0x10));
    uVar2 = *(undefined4 *)((uint)param_4 * 8 + (uint)param_3 * 4 + 0x68c0);
    *(undefined1 *)((int)*(undefined4 *)0x7507 + 0x16) = *(undefined1 *)((int)uVar2 + 0x16);
    uVar2 = *(undefined4 *)((uint)param_4 * 8 + (uint)param_3 * 4 + 0x68c0);
    uVar6 = (undefined2)((ulong)uVar2 >> 0x10);
    iVar5 = (int)uVar2;
    if (*(int *)(iVar5 + 0x17) != 0 || *(int *)(iVar5 + 0x19) != 0) {
      uVar2 = *(undefined4 *)((uint)param_4 * 8 + (uint)param_3 * 4 + 0x68c0);
      uVar2 = *(undefined4 *)((int)uVar2 + 0x17);
      uVar3 = *(undefined4 *)((int)*(undefined4 *)0x7507 + 0x17);
      FUN_1cc0_1aaf(iVar1,(int)uVar3 + iVar4,(int)((ulong)uVar3 >> 0x10),(int)uVar2,
                    (int)((ulong)uVar2 >> 0x10));
    }
  }
  else {
    FUN_121a_22ad(&local_6,unaff_SS,1,1,3,0x18);
    iVar5 = (uint)param_4 * 8 + (uint)param_3 * 4;
    FUN_121a_0eff(local_6,uStack_4,*(undefined2 *)(iVar5 + 0x68c0),*(undefined2 *)(iVar5 + 0x68c2));
    FUN_1cc0_1aaf(iVar1,(int)*(undefined4 *)0x7507 + iVar4 + 0x1b,
                  (int)((ulong)*(undefined4 *)0x7507 >> 0x10),(int)_local_6 + 0x1b,
                  (int)((ulong)_local_6 >> 0x10));
    uVar2 = *(undefined4 *)((uint)param_4 * 8 + (uint)param_3 * 4 + 0x68c0);
    *(undefined1 *)((int)*(undefined4 *)0x7507 + 0x16) = *(undefined1 *)((int)uVar2 + 0x16);
    uVar6 = (undefined2)((ulong)_local_6 >> 0x10);
    iVar5 = (int)_local_6;
    if (*(int *)(iVar5 + 0x17) != 0 || *(int *)(iVar5 + 0x19) != 0) {
      uVar2 = *(undefined4 *)((int)*(undefined4 *)0x7507 + 0x17);
      FUN_1cc0_1aaf(iVar1,(int)uVar2 + iVar4,(int)((ulong)uVar2 >> 0x10),
                    (int)*(undefined4 *)(iVar5 + 0x17),
                    (int)((ulong)*(undefined4 *)(iVar5 + 0x17) >> 0x10));
    }
    FUN_121a_239c(&local_6,unaff_SS);
  }
  return;
}


