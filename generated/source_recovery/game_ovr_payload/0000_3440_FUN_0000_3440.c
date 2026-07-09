/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:3440
 * Ghidra name: FUN_0000_3440
 * Linear address: 0x03440
 * Original GAME.OVR file offset: 13384
 * Body addresses: 44
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_3440(void)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  pcVar1 = (char *)((int)*(undefined4 *)0x4418 + 0x1f6);
  *pcVar1 = *pcVar1 + '\x01';
  if (*(byte *)((int)*(undefined4 *)0x4418 + 0x1f6) <= *(byte *)((int)*(undefined4 *)0x4418 + 0x1f7)
     ) {
    *(undefined2 *)0x4432 = *(undefined2 *)0x8c42;
  }
  return;
}


