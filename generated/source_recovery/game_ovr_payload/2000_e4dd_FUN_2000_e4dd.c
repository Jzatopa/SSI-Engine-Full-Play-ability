/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:e4dd
 * Ghidra name: FUN_2000_e4dd
 * Linear address: 0x2E4DD
 * Original GAME.OVR file offset: 189669
 * Body addresses: 107
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_e4dd(void)

{
  uint in_AX;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_e [6];
  undefined1 local_8;
  undefined1 local_7;
  
  if (((*(char *)0x4438 != '\t') && (*(char *)0x4438 != '\x03')) && (*(char *)0x443d == '\0')) {
    if (*(char *)0x4438 == '\0') {
      local_7 = 1;
    }
    else {
      local_7 = 0x11;
    }
    *(undefined1 *)0x7479 = local_7;
    *(undefined1 *)0x747b = 4;
    *(undefined1 *)0x747a = 0x26;
    *(undefined1 *)0x747c = 3;
    local_8 = 2;
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x2104,unaff_CS,local_e,unaff_SS,in_AX & 0xff00);
  }
  return;
}


