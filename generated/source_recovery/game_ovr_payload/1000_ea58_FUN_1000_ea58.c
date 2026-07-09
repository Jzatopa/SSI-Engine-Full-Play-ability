/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:ea58
 * Ghidra name: FUN_1000_ea58
 * Linear address: 0x1EA58
 * Original GAME.OVR file offset: 125536
 * Body addresses: 53
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_ea58(undefined4 param_1)

{
  undefined2 unaff_BP;
  undefined2 uVar1;
  undefined4 uVar2;
  
  func_0x0000dd51();
  FUN_0000_dd3d(unaff_BP);
  uVar2 = FUN_0000_dd55();
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x2b) = (int)uVar2;
  *(undefined2 *)((int)param_1 + 0x2d) = (int)((ulong)uVar2 >> 0x10);
  return;
}


