/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:6308
 * Ghidra name: FUN_0000_6308
 * Linear address: 0x06308
 * Original GAME.OVR file offset: 25360
 * Body addresses: 85
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_6308(undefined2 param_1,byte param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 local_7;
  undefined1 local_3;
  
  uVar3 = (undefined2)((ulong)param_3 >> 0x10);
  iVar2 = (int)param_3 + (uint)param_2 * 6;
  local_7 = (undefined1 *)CONCAT22(uVar3,(undefined1 *)(iVar2 + 0x3c));
  uVar1 = CONCAT11((char)((uint)param_2 * 6 >> 8),*local_7) & 0xff7f;
  if ((((byte)uVar1 < 3) || (*(char *)(iVar2 + 0x41) == '\0')) || (*(char *)(iVar2 + 0x40) != '\0'))
  {
    local_3 = 0;
  }
  else {
    local_3 = 1;
  }
  return CONCAT11((char)(uVar1 >> 8),local_3);
}


