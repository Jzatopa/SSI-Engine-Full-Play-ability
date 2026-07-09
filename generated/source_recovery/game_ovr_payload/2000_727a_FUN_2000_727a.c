/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:727a
 * Ghidra name: FUN_2000_727a
 * Linear address: 0x2727A
 * Original GAME.OVR file offset: 160386
 * Body addresses: 111
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_727a(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 uStack_4;
  
  local_6 = *(int *)0x57ff;
  uStack_4 = *(int *)0x5801;
  *(undefined1 *)0x748e = 1;
  while (local_6 != 0 || uStack_4 != 0) {
    if ((*(char *)(local_6 + 0xe7) == '\0') || (*(char *)(local_6 + 0xe7) == -0x4d)) {
      uVar4 = *(uint *)(local_6 + 0x2b);
      iVar5 = *(int *)(local_6 + 0x2d);
      puVar1 = (uint *)0x72ba;
      uVar3 = *puVar1;
      *puVar1 = *puVar1 + uVar4;
      *(int *)0x72bc = *(int *)0x72bc + iVar5 + (uint)CARRY2(uVar3,uVar4);
      *(undefined2 *)(local_6 + 0x2b) = 0;
      *(undefined2 *)(local_6 + 0x2d) = 0;
    }
    piVar2 = (int *)(local_6 + 0xff);
    uStack_4 = *(int *)(local_6 + 0x101);
    local_6 = *piVar2;
  }
  return;
}


