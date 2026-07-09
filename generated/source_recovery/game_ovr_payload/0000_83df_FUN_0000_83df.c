/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:83df
 * Ghidra name: FUN_0000_83df
 * Linear address: 0x083DF
 * Original GAME.OVR file offset: 33767
 * Body addresses: 201
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_83df(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 unaff_DS;
  undefined4 uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  undefined2 uStack_e;
  undefined2 uStack_c;
  
  iVar6 = *(int *)0x57ff;
  iVar3 = *(int *)0x5801;
  if (iVar6 == 0 && iVar3 == 0) {
    FUN_0000_8575();
    return;
  }
  iVar9 = *(int *)(iVar6 + 0xf7);
  iVar10 = *(int *)(iVar6 + 0xf9);
  if (*(char *)(iVar6 + 0xd6) != '\x01') {
    FUN_0000_855f();
    return;
  }
  if (*(char *)(iVar6 + 0xd4) == '\x01') {
    FUN_0000_855f();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(iVar6 + 0xf3) + 0xf) != '\0') {
    if (*(char *)(iVar6 + 0xd4) == '\x06') {
      FUN_0000_855f();
      return;
    }
    *(undefined1 *)0x3de4 = 1;
    if (*(char *)0x8c26 == '\0') {
      if (*(char *)((int)*(undefined4 *)(iVar6 + 0xf3) + 0xf) == '\x01') {
        uVar4 = *(uint *)(iVar6 + 0x2b);
        iVar5 = *(int *)(iVar6 + 0x2d);
        puVar1 = (uint *)0x72ba;
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + uVar4;
        *(int *)0x72bc = *(int *)0x72bc + iVar5 + (uint)CARRY2(uVar2,uVar4);
      }
      if (*(char *)((int)*(undefined4 *)0x441c + 0x2e3) != '\x01') {
        if (iVar9 != 0 || iVar10 != 0) {
          if ((*(byte *)(iVar9 + 0x34) & 0x40) == 0) {
            if (*(int *)0x72be == 0 && *(int *)0x72c0 == 0) {
              uStack_e = 0;
              uStack_c = 0;
            }
            else {
              uStack_e = *(undefined2 *)0x72be;
              uStack_c = *(undefined2 *)0x72c0;
            }
            uVar8 = 0x3e;
            uVar7 = FUN_0000_ce3f();
            *(uint *)0x72be = (uint)uVar7;
            *(undefined2 *)0x72c0 = (int)((ulong)uVar7 >> 0x10);
            uVar2 = (uint)uVar7 >> 8;
            FUN_0000_09bf(0xcc0,uVar2 << 8,uVar2 << 8,uVar2 << 8,uVar2 << 8,iVar9,iVar10,iVar6,iVar3
                          ,uVar8);
            func_0x0000d5f6(0x99,0x3e,(int)*(undefined4 *)0x72be,
                            (int)((ulong)*(undefined4 *)0x72be >> 0x10),iVar9,iVar10);
            *(byte *)((int)*(undefined4 *)0x72be + 0x34) =
                 *(byte *)((int)*(undefined4 *)0x72be + 0x34) & 0x7f;
            uVar8 = (undefined2)((ulong)*(undefined4 *)0x72be >> 0x10);
            iVar6 = (int)*(undefined4 *)0x72be;
            *(undefined2 *)(iVar6 + 0x2a) = uStack_e;
            *(undefined2 *)(iVar6 + 0x2c) = uStack_c;
          }
          FUN_0000_84a8(*(undefined2 *)(iVar9 + 0x2a),*(undefined2 *)(iVar9 + 0x2c));
          return;
        }
        FUN_0000_855f();
        return;
      }
      FUN_0000_855f();
      return;
    }
    FUN_0000_855f();
    return;
  }
  FUN_0000_855f();
  return;
}


