/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7b00
 * Ghidra name: FUN_0000_7b00
 * Linear address: 0x07B00
 * Original GAME.OVR file offset: 31496
 * Body addresses: 68
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_7b00(void)

{
  int unaff_BP;
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined4 uVar6;
  undefined2 uVar7;
  
  uVar7 = 0x12;
  uVar6 = FUN_0000_ce3f();
  uVar3 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) >> 0x10);
  iVar1 = (int)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP);
  *(undefined2 *)(iVar1 + 0xf3) = (int)uVar6;
  *(undefined2 *)(iVar1 + 0xf5) = (int)((ulong)uVar6 >> 0x10);
  uVar6 = *(undefined4 *)((int)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) + 0xf3);
  uVar4 = (undefined2)((ulong)uVar6 >> 0x10);
  uVar2 = (undefined2)uVar6;
  FUN_0000_e6d2(0);
  uVar5 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) >> 0x10);
  iVar1 = (int)*(undefined4 *)((undefined *)&DAT_0000_ffb3 + unaff_BP);
  uVar3 = *(undefined2 *)(iVar1 + 0x101);
  *(undefined2 *)((undefined *)&DAT_0000_ffb3 + unaff_BP) = *(undefined2 *)(iVar1 + 0xff);
  *(undefined2 *)((undefined *)&DAT_0000_ffb5 + unaff_BP) = uVar3;
  FUN_0000_7afb(uVar2,uVar4,uVar7);
  return;
}


