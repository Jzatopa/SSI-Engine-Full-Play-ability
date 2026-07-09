/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2ced
 * Ghidra name: FUN_0000_2ced
 * Linear address: 0x02CED
 * Original GAME.OVR file offset: 11509
 * Body addresses: 19
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_2ced(void)

{
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  *(undefined1 *)0x6878 = *(undefined1 *)0x687a;
  *(char *)0x6879 = *(char *)0x6879 + '\x01';
  return;
}


