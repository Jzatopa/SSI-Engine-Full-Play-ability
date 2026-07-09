/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:1348
 * Ghidra name: FUN_0000_1348
 * Linear address: 0x01348
 * Original GAME.OVR file offset: 4944
 * Body addresses: 58
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_1348(void)

{
  char *pcVar1;
  undefined2 unaff_DS;
  
  if (*(char *)((int)*(undefined4 *)0x441c + 0x2c1) != '\0') {
    pcVar1 = (char *)((int)*(undefined4 *)0x441c + 0x2c1);
    *pcVar1 = *pcVar1 + -1;
    FUN_0000_06f3();
  }
  *(int *)0x4432 = *(int *)0x4432 + 1;
  return;
}


