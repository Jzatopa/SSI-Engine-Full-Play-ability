/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:d69b
 * Ghidra name: FUN_1000_d69b
 * Linear address: 0x1D69B
 * Original GAME.OVR file offset: 120483
 * Body addresses: 40
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_1000_d69b(byte param_1)

{
  undefined2 in_AX;
  int iVar1;
  undefined1 local_3;
  
  if (param_1 < 0x20) {
    iVar1 = param_1 + 0x40;
    local_3 = (byte)iVar1;
  }
  else {
    iVar1 = CONCAT11((char)((uint)in_AX >> 8),param_1);
    local_3 = param_1;
  }
  return CONCAT11((char)((uint)iVar1 >> 8),local_3);
}


