/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:cd55
 * Ghidra name: FUN_2000_cd55
 * Linear address: 0x2CD55
 * Original GAME.OVR file offset: 183645
 * Body addresses: 41
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

bool __stdcall16far FUN_2000_cd55(int param_1)

{
  undefined2 unaff_SS;
  
  return (int)(uint)*(byte *)(param_1 + -0x24a) <= *(int *)(param_1 + -0x210);
}


