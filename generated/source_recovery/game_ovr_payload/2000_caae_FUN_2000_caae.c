/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:caae
 * Ghidra name: FUN_2000_caae
 * Linear address: 0x2CAAE
 * Original GAME.OVR file offset: 182966
 * Body addresses: 56
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_2000_caae(int param_1)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((((*(char *)&DAT_0000_7513 == '\0') && (*(char *)0x750e == '\0')) ||
      (*(char *)0x4438 != '\x05')) || (0x15 < *(int *)(param_1 + -0x210))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


