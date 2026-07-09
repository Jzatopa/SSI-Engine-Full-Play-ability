
void __stdcall16far FUN_2000_558d(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  byte local_5;
  
  local_5 = 1;
  do {
    uVar4 = (undefined2)((ulong)param_1 >> 0x10);
    iVar3 = (int)param_1;
    bVar1 = *(byte *)(*(char *)(iVar3 + 0x28) * 0x18 + (uint)local_5 * 2 + 0x35b2);
    uVar2 = (uint)local_5;
    local_5 = local_5 + 1;
    if (bVar1 == 0) {
      return;
    }
    *(undefined1 *)(iVar3 + (uint)bVar1 + 0x4c) =
         *(undefined1 *)(*(char *)(iVar3 + 0x28) * 0x18 + uVar2 * 2 + 0x35b3);
  } while (local_5 < 0xd);
  return;
}


