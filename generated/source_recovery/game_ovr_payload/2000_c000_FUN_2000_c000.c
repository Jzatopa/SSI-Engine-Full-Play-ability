/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c000
 * Ghidra name: FUN_2000_c000
 * Linear address: 0x2C000
 * Original GAME.OVR file offset: 180232
 * Body addresses: 61
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_c000(void)

{
  undefined2 unaff_DS;
  byte local_3;
  
  if (*(char *)0x535f != '\0') {
    *(undefined1 *)0x535f = 0;
    for (local_3 = 0; FUN_0000_453c((uint)local_3 * 4 + 0x52d6), local_3 != 0x1c;
        local_3 = local_3 + 1) {
    }
  }
  return;
}


