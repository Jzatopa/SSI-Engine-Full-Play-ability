/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:84a8
 * Ghidra name: FUN_0000_84a8
 * Linear address: 0x084A8
 * Original GAME.OVR file offset: 33968
 * Body addresses: 127
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_84a8(void)

{
  uint uVar1;
  int unaff_BP;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar4;
  undefined2 uVar5;
  
  if (*(int *)(unaff_BP + -0x10) != 0 || *(int *)((undefined *)&DAT_0000_fff2 + unaff_BP) != 0) {
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
      uVar4 = FUN_0000_ce3f();
      *(uint *)0x72be = (uint)uVar4;
      *(undefined2 *)0x72c0 = (int)((ulong)uVar4 >> 0x10);
      uVar1 = (uint)uVar4 >> 8;
      FUN_0000_09bf(0xcc0,uVar1 << 8,uVar1 << 8,uVar1 << 8,uVar1 << 8,
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
      uVar3 = (undefined2)((ulong)*(undefined4 *)0x72be >> 0x10);
      iVar2 = (int)*(undefined4 *)0x72be;
      *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP);
      *(undefined2 *)(iVar2 + 0x2c) = uVar5;
    }
    uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0x10) >> 0x10);
    iVar2 = (int)*(undefined4 *)(unaff_BP + -0x10);
    uVar5 = *(undefined2 *)(iVar2 + 0x2c);
    *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar2 + 0x2a);
    *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar5;
    FUN_0000_84a8();
    return;
  }
  FUN_0000_855f();
  return;
}


