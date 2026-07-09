/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:855f
 * Ghidra name: FUN_0000_855f
 * Linear address: 0x0855F
 * Original GAME.OVR file offset: 34151
 * Body addresses: 22
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_855f(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_BP;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar7;
  
  uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
  iVar4 = (int)*(undefined4 *)(unaff_BP + -4);
  uVar5 = *(undefined2 *)(iVar4 + 0x101);
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar4 + 0xff);
  *(undefined2 *)(unaff_BP + -2) = uVar5;
  if (*(int *)(unaff_BP + -4) == 0 && *(int *)(unaff_BP + -2) == 0) {
    FUN_0000_8575();
    return;
  }
  uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
  iVar4 = (int)*(undefined4 *)(unaff_BP + -4);
  uVar5 = *(undefined2 *)(iVar4 + 0xf9);
  *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar4 + 0xf7);
  *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar5;
  if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd6) != '\x01') {
    FUN_0000_855f();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x01') {
    FUN_0000_855f();
    return;
  }
  uVar7 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3);
  if (*(char *)((int)uVar7 + 0xf) != '\0') {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x06') {
      FUN_0000_855f();
      return;
    }
    *(undefined1 *)0x3de4 = 1;
    uVar3 = *(uint *)((int)*(undefined4 *)(unaff_BP + -4) + 0xb2);
    puVar1 = (uint *)(unaff_BP + -8);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(uint *)((undefined *)&DAT_0000_fffa + unaff_BP) =
         *(int *)((undefined *)&DAT_0000_fffa + unaff_BP) + (uint)CARRY2(uVar2,uVar3);
    if (*(char *)0x8c26 == '\0') {
      uVar7 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3);
      if (*(char *)((int)uVar7 + 0xf) == '\x01') {
        uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
        iVar4 = (int)*(undefined4 *)(unaff_BP + -4);
        uVar3 = *(uint *)(iVar4 + 0x2b);
        iVar4 = *(int *)(iVar4 + 0x2d);
        puVar1 = (uint *)0x72ba;
        uVar2 = *puVar1;
        *puVar1 = *puVar1 + uVar3;
        *(int *)0x72bc = *(int *)0x72bc + iVar4 + (uint)CARRY2(uVar2,uVar3);
      }
      if (*(char *)((int)*(undefined4 *)0x441c + 0x2e3) != '\x01') {
        if (*(int *)(unaff_BP + -0x10) != 0 || *(int *)((undefined *)&DAT_0000_fff2 + unaff_BP) != 0
           ) {
          if ((*(byte *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0x34) & 0x40) == 0) {
            *(char *)(unaff_BP + -0x11) = *(char *)(unaff_BP + -0x11) + '\x01';
            if (*(int *)0x72be == 0 && *(int *)0x72c0 == 0) {
              *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP) = 0;
              *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP) = 0;
            }
            else {
              uVar5 = *(undefined2 *)0x72c0;
              *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP) = *(undefined2 *)0x72be;
              *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP) = uVar5;
            }
            uVar5 = 0x3e;
            uVar7 = FUN_0000_ce3f();
            *(uint *)0x72be = (uint)uVar7;
            *(undefined2 *)0x72c0 = (int)((ulong)uVar7 >> 0x10);
            uVar2 = (uint)uVar7 >> 8;
            FUN_0000_09bf(0xcc0,uVar2 << 8,uVar2 << 8,uVar2 << 8,uVar2 << 8,
                          *(undefined2 *)(unaff_BP + -0x10),
                          *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP),
                          *(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2),uVar5);
            func_0x0000d5f6(0x99,0x3e,(int)*(undefined4 *)0x72be,
                            (int)((ulong)*(undefined4 *)0x72be >> 0x10),
                            (int)*(undefined4 *)(unaff_BP + -0x10),
                            (int)((ulong)*(undefined4 *)(unaff_BP + -0x10) >> 0x10));
            *(byte *)((int)*(undefined4 *)0x72be + 0x34) =
                 *(byte *)((int)*(undefined4 *)0x72be + 0x34) & 0x7f;
            uVar5 = *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP);
            uVar6 = (undefined2)((ulong)*(undefined4 *)0x72be >> 0x10);
            iVar4 = (int)*(undefined4 *)0x72be;
            *(undefined2 *)(iVar4 + 0x2a) = *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP);
            *(undefined2 *)(iVar4 + 0x2c) = uVar5;
          }
          uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0x10) >> 0x10);
          iVar4 = (int)*(undefined4 *)(unaff_BP + -0x10);
          uVar5 = *(undefined2 *)(iVar4 + 0x2c);
          *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar4 + 0x2a);
          *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar5;
          FUN_0000_84a8();
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


