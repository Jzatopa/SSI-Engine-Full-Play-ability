/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:8527
 * Ghidra name: FUN_0000_8527
 * Linear address: 0x08527
 * Original GAME.OVR file offset: 34095
 * Body addresses: 56
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_8527(void)

{
  undefined2 uVar1;
  int unaff_BP;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(byte *)((int)*(undefined4 *)0x72be + 0x34) = *(byte *)((int)*(undefined4 *)0x72be + 0x34) & 0x7f
  ;
  uVar1 = *(undefined2 *)((undefined *)&DAT_0000_fff6 + unaff_BP);
  uVar3 = (undefined2)((ulong)*(undefined4 *)0x72be >> 0x10);
  iVar2 = (int)*(undefined4 *)0x72be;
  *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)((undefined *)&DAT_0000_fff4 + unaff_BP);
  *(undefined2 *)(iVar2 + 0x2c) = uVar1;
  uVar3 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -0x10) >> 0x10);
  iVar2 = (int)*(undefined4 *)(unaff_BP + -0x10);
  uVar1 = *(undefined2 *)(iVar2 + 0x2c);
  *(undefined2 *)(unaff_BP + -0x10) = *(undefined2 *)(iVar2 + 0x2a);
  *(undefined2 *)((undefined *)&DAT_0000_fff2 + unaff_BP) = uVar1;
  FUN_0000_84a8();
  return;
}


