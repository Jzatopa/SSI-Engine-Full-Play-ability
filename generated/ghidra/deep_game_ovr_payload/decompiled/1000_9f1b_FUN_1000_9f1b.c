
void __stdcall16far FUN_1000_9f1b(int param_1,byte param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined4 *)((uint)*(byte *)(param_1 + -0x11d) * 8 + 0x68c0);
  FUN_0000_e6af(*(undefined2 *)((int)uVar1 + 0x12));
  uVar1 = *(undefined4 *)((uint)*(byte *)(param_1 + -0x11d) * 8 + 0x68c4);
  FUN_0000_e6af(*(undefined2 *)((int)uVar1 + 0x12));
  uVar1 = *(undefined4 *)((int)*(undefined4 *)(param_1 + -0x11a) + (uint)param_2 * 8);
  uVar4 = (undefined2)((ulong)uVar1 >> 0x10);
  iVar3 = (int)uVar1;
  if (*(int *)(iVar3 + 0x17) == 0 && *(int *)(iVar3 + 0x19) == 0) {
    uVar1 = *(undefined4 *)((int)*(undefined4 *)(param_1 + -0x11a) + (uint)param_2 * 8);
    uVar2 = *(undefined4 *)((uint)*(byte *)(param_1 + -0x11d) * 8 + 0x68c0);
    *(undefined1 *)((int)uVar2 + 0x16) = *(undefined1 *)((int)uVar1 + 0x16);
  }
  else {
    FUN_0000_e6af(*(undefined2 *)(param_1 + -0x11c));
  }
  uVar1 = *(undefined4 *)((int)*(undefined4 *)(param_1 + -0x11a) + (uint)param_2 * 8 + 4);
  uVar4 = (undefined2)((ulong)uVar1 >> 0x10);
  iVar3 = (int)uVar1;
  if (*(int *)(iVar3 + 0x17) == 0 && *(int *)(iVar3 + 0x19) == 0) {
    uVar1 = *(undefined4 *)((int)*(undefined4 *)(param_1 + -0x11a) + (uint)param_2 * 8 + 4);
    uVar2 = *(undefined4 *)((uint)*(byte *)(param_1 + -0x11d) * 8 + 0x68c4);
    *(undefined1 *)((int)uVar2 + 0x16) = *(undefined1 *)((int)uVar1 + 0x16);
  }
  else {
    FUN_0000_e6af(*(undefined2 *)(param_1 + -0x11c));
  }
  return;
}


