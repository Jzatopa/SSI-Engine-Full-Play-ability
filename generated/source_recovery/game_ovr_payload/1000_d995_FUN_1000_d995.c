/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:d995
 * Ghidra name: FUN_1000_d995
 * Linear address: 0x1D995
 * Original GAME.OVR file offset: 121245
 * Body addresses: 348
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_d995(undefined1 param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = param_4 + 0x8400;
  if (param_4 == 0x7c00) {
    if (param_2 == 0 && param_3 == 0) {
      *(undefined1 *)0x8c23 = 1;
    }
  }
  else if ((uVar1 < 0x10) || (0xb9 < uVar1)) {
    if (uVar1 == 0x100) {
      *(byte *)((int)*(undefined4 *)0x57fb + 0xd4) = (byte)param_2 & 0x7f;
      if (*(char *)((int)*(undefined4 *)0x57fb + 0xd4) == '\x01') {
        *(undefined1 *)((int)*(undefined4 *)0x57fb + 0xd5) = 1;
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)0x57fb + 0xd5) = 0;
      }
      FUN_0000_09c4();
    }
    else if (uVar1 == 0x10c) {
      *(byte *)((int)*(undefined4 *)0x57fb + 0xd6) = (byte)param_2 & 1;
      *(byte *)((int)*(undefined4 *)0x57fb + 0x4c) = (byte)param_2 & 0x40;
      *(byte *)((int)*(undefined4 *)0x57fb + 0xd7) = (byte)param_2 & 0x80;
      if (*(char *)((int)*(undefined4 *)0x57fb + 0xd6) == '\x01') {
        *(undefined1 *)0x8c39 = 1;
      }
    }
    else if (uVar1 == 0x10e) {
      *(byte *)((int)*(undefined4 *)0x57fb + 0xd8) = (byte)param_2;
    }
    else if (uVar1 == 0x119) {
      *(int *)((int)*(undefined4 *)0x57fb + 0xe3) = param_2;
    }
    else if (uVar1 == 0x11b) {
      *(byte *)((int)*(undefined4 *)0x57fb + 0xe5) = (byte)param_2;
    }
    else if (uVar1 == 0x312) {
      FUN_0000_8334(CONCAT11(3,(byte)param_2));
    }
  }
  else {
    FUN_0000_e6af(param_1);
  }
  return;
}


