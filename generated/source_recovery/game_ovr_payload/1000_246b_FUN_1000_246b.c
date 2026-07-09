/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:246b
 * Ghidra name: FUN_1000_246b
 * Linear address: 0x1246B
 * Original GAME.OVR file offset: 74867
 * Body addresses: 75
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_1000_246b(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined1 local_3;
  
  local_3 = 0;
  if ((uint)param_1 == 0 && param_1._2_2_ == 0) {
    param_2._0_2_ = 0;
  }
  else if ((param_2._2_2_ == param_1._2_2_) && ((uint)param_2 == (uint)param_1)) {
    local_3 = 1;
  }
  else {
    pcVar1 = (char *)((uint)param_2 + 0xd6);
    param_2._0_2_ = (uint)param_2 & 0xff00;
    if (*pcVar1 != *(char *)((uint)param_1 + 0xd6)) {
      param_2._0_2_ = (uint)param_2 + 1;
    }
    local_3 = (undefined1)(uint)param_2;
  }
  return CONCAT11((char)((uint)param_2 >> 8),local_3);
}


