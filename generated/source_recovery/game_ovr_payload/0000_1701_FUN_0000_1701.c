/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:1701
 * Ghidra name: FUN_0000_1701
 * Linear address: 0x01701
 * Original GAME.OVR file offset: 5897
 * Body addresses: 118
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_1701(void)

{
  char cVar1;
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  cVar1 = *(char *)0x764f;
  if (cVar1 == '\x16') {
    if (*(char *)0x7648 == '\0') {
      FUN_0000_0734();
    }
  }
  else if (cVar1 == '\x17') {
    if (*(char *)0x7649 == '\0') {
      FUN_0000_0734();
    }
  }
  else if (cVar1 == '\x18') {
    if (*(char *)0x764a == '\0') {
      FUN_0000_0734();
    }
  }
  else if (cVar1 == '\x19') {
    if (*(char *)0x764b == '\0') {
      FUN_0000_0734();
    }
  }
  else if (cVar1 == '\x1a') {
    if (*(char *)0x764c == '\0') {
      FUN_0000_0734();
    }
  }
  else if ((cVar1 == '\x1b') && (*(char *)0x764d == '\0')) {
    FUN_0000_0734();
  }
  return;
}


