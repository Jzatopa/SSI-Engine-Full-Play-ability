/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:cecb
 * Ghidra name: FUN_0000_cecb
 * Linear address: 0x0CECB
 * Original GAME.OVR file offset: 52947
 * Body addresses: 80
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_0000_cecb(undefined4 param_1)

{
  char cVar1;
  undefined1 local_3;
  
  FUN_0000_09fb();
  cVar1 = func_0x000009ce(0x99,(int)param_1,param_1._2_2_);
  if ((cVar1 == '\0') && (*(char *)((int)*(undefined4 *)((int)param_1 + 0xf3) + 1) != '\0')) {
    local_3 = func_0x0000058a(0x99,(int)param_1,param_1._2_2_);
  }
  else {
    local_3 = FUN_0000_0a28(0x99,(int)param_1,param_1._2_2_);
  }
  return local_3;
}


