/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:d158
 * Ghidra name: FUN_2000_d158
 * Linear address: 0x2D158
 * Original GAME.OVR file offset: 184672
 * Body addresses: 47
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_d158(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x747e = 0xff;
  if ((*(char *)0x4438 == '\v') && (*(int *)(param_1 + -0x210) < 0x17)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


