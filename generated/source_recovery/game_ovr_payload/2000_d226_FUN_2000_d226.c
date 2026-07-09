/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:d226
 * Ghidra name: FUN_2000_d226
 * Linear address: 0x2D226
 * Original GAME.OVR file offset: 184878
 * Body addresses: 82
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_d226(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((((*(char *)0x4438 == '\t') && (*(char *)0x8c3f != '\0')) &&
      (0x10 < *(int *)(param_1 + -0x20e))) &&
     (((*(int *)(param_1 + -0x20e) < 0x27 && (0 < *(int *)(param_1 + -0x210))) &&
      (*(int *)(param_1 + -0x210) < 0x17)))) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


