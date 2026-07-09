/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:5338
 * Ghidra name: FUN_1000_5338
 * Linear address: 0x15338
 * Original GAME.OVR file offset: 86848
 * Body addresses: 362
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_5338(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  byte extraout_AH;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar10;
  byte local_3;
  
  *(undefined1 *)(param_1 + -0xdb) = 1;
  uVar4 = *(undefined2 *)(param_1 + 0x18);
  uVar9 = *(undefined2 *)(param_1 + 0x16);
  uVar3 = FUN_0000_0e20();
  uVar4 = FUN_0000_0e25(*(undefined2 *)(param_1 + 0x16),*(undefined2 *)(param_1 + 0x18),uVar3,uVar9,
                        uVar4);
  uVar4 = func_0x00000e2a(0xdb,*(undefined2 *)(param_1 + 0x16),*(undefined2 *)(param_1 + 0x18),0xff,
                          0xff,uVar4);
  func_0x00000da9(0xdb,uVar4);
  *(undefined1 *)(param_1 + -0xda) = 0;
  bVar1 = *(byte *)0x71e0;
  bVar6 = extraout_AH;
  if (bVar1 != 0) {
    local_3 = 1;
    uVar4 = 0xd7;
    while( true ) {
      iVar7 = (uint)*(byte *)((uint)local_3 * 3 + 0x71de) * 4;
      iVar2 = *(int *)((undefined *)&DAT_0000_707f + iVar7);
      iVar7 = *(int *)((undefined *)&DAT_0000_7081 + iVar7);
      iVar5 = FUN_1000_246b(iVar2,iVar7,*(undefined2 *)(param_1 + 0x16),
                            *(undefined2 *)(param_1 + 0x18));
      uVar9 = uVar4;
      if ((char)iVar5 != '\0') {
        *(char *)(param_1 + -0xda) = *(char *)(param_1 + -0xda) + '\x01';
        uVar9 = 0xcc0;
        func_0x0000d5f6(uVar4,3,param_1 + (uint)*(byte *)(param_1 + -0xda) * 3 + -0xdb);
        uVar10 = *(undefined4 *)((int)*(undefined4 *)(param_1 + 0x16) + 0xf3);
        uVar4 = (undefined2)((ulong)uVar10 >> 0x10);
        iVar8 = (int)uVar10;
        iVar5 = iVar2;
        if ((iVar7 == *(int *)(iVar8 + 10)) && (iVar2 == *(int *)(iVar8 + 8))) {
          iVar5 = CONCAT11((char)((uint)iVar2 >> 8),*(undefined1 *)(param_1 + -0xda));
          *(undefined1 *)(param_1 + -0xdb) = *(undefined1 *)(param_1 + -0xda);
        }
      }
      bVar6 = (byte)((uint)iVar5 >> 8);
      if (local_3 == bVar1) break;
      local_3 = local_3 + 1;
      uVar4 = uVar9;
    }
  }
  uVar10 = FUN_1000_50e2(param_1,(uint)bVar6 << 8);
  *(undefined2 *)(param_1 + -0xe4) = (int)uVar10;
  *(undefined2 *)(param_1 + -0xe2) = (int)((ulong)uVar10 >> 0x10);
  if ((*(int *)(param_1 + -0xe2) != *(int *)(param_1 + 0x18)) ||
     (*(int *)(param_1 + -0xe4) != *(int *)(param_1 + 0x16))) {
    *(undefined1 *)0x7482 = 0xff;
    *(undefined1 *)0x7457 = 4;
  }
  return;
}


