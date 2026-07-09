/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:bfcf
 * Ghidra name: FUN_2000_bfcf
 * Linear address: 0x2BFCF
 * Original GAME.OVR file offset: 180183
 * Body addresses: 49
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_bfcf(void)

{
  undefined2 unaff_DS;
  
  if (*(char *)0x535e != '\0') {
    *(undefined1 *)0x535e = 0;
    FUN_0000_453c(0x68a8);
    FUN_0000_453c(0x5364);
    FUN_0000_453c(0x744a);
  }
  return;
}


