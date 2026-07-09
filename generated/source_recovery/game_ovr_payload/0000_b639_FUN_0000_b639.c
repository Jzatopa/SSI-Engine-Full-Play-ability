/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:b639
 * Ghidra name: FUN_0000_b639
 * Linear address: 0x0B639
 * Original GAME.OVR file offset: 46657
 * Body addresses: 186
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_b639(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 in_AX;
  byte bVar8;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  byte extraout_AH;
  undefined2 uVar6;
  uint uVar7;
  undefined2 unaff_SS;
  undefined2 uVar9;
  
  bVar8 = (byte)((uint)in_AX >> 8);
  uVar1 = *(undefined4 *)((int)*(undefined4 *)(param_1 + 0xc) + 0xf3);
  *(undefined1 *)((int)uVar1 + 3) = *(undefined1 *)(param_1 + -1);
  iVar3 = (uint)bVar8 << 8;
  iVar4 = (uint)bVar8 << 8;
  uVar6 = *(undefined2 *)(param_1 + 0xe);
  uVar9 = *(undefined2 *)(param_1 + 0xc);
  uVar5 = func_0x00000e2f();
  FUN_0000_0e07(0xdb,uVar5,uVar9,uVar6,iVar4,iVar3);
  cVar2 = func_0x00000e3e(0xdb,(uint)extraout_AH << 8,
                          CONCAT11(extraout_AH,*(undefined1 *)(param_1 + -4)),
                          CONCAT11(extraout_AH,*(undefined1 *)(param_1 + -3)),
                          *(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe));
  *(bool *)*(undefined4 *)(param_1 + 6) = cVar2 == '\0';
  uVar6 = FUN_0000_0e20(0xdb,*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe));
  uVar7 = FUN_0000_0e25(*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe),uVar6);
  FUN_0000_0e16(0xdb,8,uVar7 & 0xff00,uVar7);
  uVar1 = *(undefined4 *)((int)*(undefined4 *)(param_1 + 0xc) + 0xf3);
  *(undefined1 *)((int)uVar1 + 7) = *(undefined1 *)(param_1 + -2);
  *(undefined1 *)(param_1 + -7) = 8;
  return;
}


