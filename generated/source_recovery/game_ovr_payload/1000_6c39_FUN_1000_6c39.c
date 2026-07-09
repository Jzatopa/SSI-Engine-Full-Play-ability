/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:6c39
 * Ghidra name: FUN_1000_6c39
 * Linear address: 0x16C39
 * Original GAME.OVR file offset: 93249
 * Body addresses: 287
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_1000_6c39(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 uStack_4;
  
  local_6 = *(int *)0x57ff;
  uStack_4 = *(int *)0x5801;
  if ((uStack_4 != *(int *)0x57fd) || (local_6 != *(int *)0x57fb)) {
    while ((*(int *)(local_6 + 0x101) != *(int *)0x57fd ||
           (*(int *)(local_6 + 0xff) != *(int *)0x57fb))) {
      piVar1 = (int *)(local_6 + 0xff);
      uStack_4 = *(int *)(local_6 + 0x101);
      local_6 = *piVar1;
    }
  }
  uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar3 = (int)*(undefined4 *)0x57fb;
  iVar2 = *(int *)(iVar3 + 0xff);
  iVar3 = *(int *)(iVar3 + 0x101);
  if (iVar2 == 0 && iVar3 == 0) {
    uVar5 = *(undefined2 *)0x5801;
    uVar6 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar4 = (int)*(undefined4 *)0x57fb;
    *(undefined2 *)(iVar4 + 0xff) = *(undefined2 *)0x57ff;
    *(undefined2 *)(iVar4 + 0x101) = uVar5;
    uVar5 = *(undefined2 *)0x57fd;
    *(undefined2 *)0x57ff = *(undefined2 *)0x57fb;
    *(undefined2 *)0x5801 = uVar5;
    *(int *)(local_6 + 0xff) = iVar2;
    *(int *)(local_6 + 0x101) = iVar3;
  }
  else {
    uVar5 = *(undefined2 *)(iVar2 + 0x101);
    uVar6 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar4 = (int)*(undefined4 *)0x57fb;
    *(undefined2 *)(iVar4 + 0xff) = *(undefined2 *)(iVar2 + 0xff);
    *(undefined2 *)(iVar4 + 0x101) = uVar5;
    if ((*(int *)0x5801 == *(int *)0x57fd) && (*(int *)0x57ff == *(int *)0x57fb)) {
      *(int *)0x57ff = iVar2;
      *(int *)0x5801 = iVar3;
    }
    if ((uStack_4 != *(int *)0x57fd) || (local_6 != *(int *)0x57fb)) {
      *(int *)(local_6 + 0xff) = iVar2;
      *(int *)(local_6 + 0x101) = iVar3;
    }
    uVar5 = *(undefined2 *)0x57fd;
    *(undefined2 *)(iVar2 + 0xff) = *(undefined2 *)0x57fb;
    *(undefined2 *)(iVar2 + 0x101) = uVar5;
  }
  return;
}


