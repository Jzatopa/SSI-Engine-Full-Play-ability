/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b0a4
 * Ghidra name: FUN_2000_b0a4
 * Linear address: 0x2B0A4
 * Original GAME.OVR file offset: 176300
 * Body addresses: 53
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_b0a4(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = FUN_2000_b061((int)param_1,param_1._2_2_);
  if ((cVar1 == '\0') || (*(char *)((int)*(undefined4 *)((int)param_1 + 0xeb) + 0x38) == '\0')) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


