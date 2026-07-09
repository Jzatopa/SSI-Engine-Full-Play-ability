/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:6ae1
 * Ghidra name: FUN_1000_6ae1
 * Linear address: 0x16AE1
 * Original GAME.OVR file offset: 92905
 * Body addresses: 344
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_1000_6ae1(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  int local_a;
  int iStack_8;
  undefined4 local_6;
  
  local_a = *(int *)0x57ff;
  iStack_8 = *(int *)0x5801;
  local_6 = 0;
  if ((iStack_8 == *(int *)0x57fd) && (local_a == *(int *)0x57fb)) {
    while (*(int *)(local_a + 0xff) != 0 || *(int *)(local_a + 0x101) != 0) {
      piVar1 = (int *)(local_a + 0xff);
      iStack_8 = *(int *)(local_a + 0x101);
      local_a = *piVar1;
    }
  }
  else {
    while ((*(int *)(local_a + 0x101) != *(int *)0x57fd ||
           (*(int *)(local_a + 0xff) != *(int *)0x57fb))) {
      local_6 = CONCAT22(iStack_8,local_a);
      piVar1 = (int *)(local_a + 0xff);
      iStack_8 = *(int *)(local_a + 0x101);
      local_a = *piVar1;
    }
  }
  uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar2 = (int)*(undefined4 *)0x57fb;
  iVar3 = *(int *)(iVar2 + 0xff);
  iVar2 = *(int *)(iVar2 + 0x101);
  if ((*(int *)0x5801 == *(int *)0x57fd) && (*(int *)0x57ff == *(int *)0x57fb)) {
    if (iVar3 != 0 || iVar2 != 0) {
      *(int *)0x57ff = iVar3;
      *(int *)0x5801 = iVar2;
    }
    uVar4 = *(undefined2 *)0x57fd;
    *(undefined2 *)(local_a + 0xff) = *(undefined2 *)0x57fb;
    *(undefined2 *)(local_a + 0x101) = uVar4;
    uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar3 = (int)*(undefined4 *)0x57fb;
    *(undefined2 *)(iVar3 + 0xff) = 0;
    *(undefined2 *)(iVar3 + 0x101) = 0;
  }
  else {
    *(int *)(local_a + 0xff) = iVar3;
    *(int *)(local_a + 0x101) = iVar2;
    uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar3 = (int)*(undefined4 *)0x57fb;
    *(int *)(iVar3 + 0xff) = local_a;
    *(int *)(iVar3 + 0x101) = iStack_8;
    if ((iStack_8 != *(int *)0x5801) || (local_a != *(int *)0x57ff)) {
      if ((int)local_6 != 0 || local_6._2_2_ != 0) {
        uVar4 = *(undefined2 *)0x57fd;
        *(undefined2 *)((int)local_6 + 0xff) = *(undefined2 *)0x57fb;
        *(undefined2 *)((int)local_6 + 0x101) = uVar4;
        return;
      }
    }
    uVar4 = *(undefined2 *)0x57fd;
    *(undefined2 *)0x57ff = *(undefined2 *)0x57fb;
    *(undefined2 *)0x5801 = uVar4;
  }
  return;
}


