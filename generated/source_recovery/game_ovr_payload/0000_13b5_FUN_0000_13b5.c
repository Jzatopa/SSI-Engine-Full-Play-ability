/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:13b5
 * Ghidra name: FUN_0000_13b5
 * Linear address: 0x013B5
 * Original GAME.OVR file offset: 5053
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_13b5(void)

{
  undefined2 unaff_DS;
  
  *(undefined1 *)0x9ed7 = 1;
  if (*(char *)0x4438 == '\x03') {
    FUN_0000_0775();
  }
  else {
    *(undefined1 *)0x443d = 1;
  }
  *(undefined1 *)0x74aa = 0;
  return;
}


