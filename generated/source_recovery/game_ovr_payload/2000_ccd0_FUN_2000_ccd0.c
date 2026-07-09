/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:ccd0
 * Ghidra name: FUN_2000_ccd0
 * Linear address: 0x2CCD0
 * Original GAME.OVR file offset: 183512
 * Body addresses: 82
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_ccd0(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((((*(char *)0x8c3f == '\0') || (*(char *)0x4438 != '\x04')) ||
      (*(int *)(param_1 + -0x20e) < 3)) ||
     (((0xd < *(int *)(param_1 + -0x20e) || (*(int *)(param_1 + -0x210) < 3)) ||
      (0xd < *(int *)(param_1 + -0x210))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


