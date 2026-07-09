/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:db22
 * Ghidra name: FUN_0000_db22
 * Linear address: 0x0DB22
 * Original GAME.OVR file offset: 56106
 * Body addresses: 19
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_db22(void)

{
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  uVar1 = *(undefined2 *)0x4016;
  *(undefined2 *)0x3dd0 = *(undefined2 *)0x4014;
  *(undefined2 *)0x3dd2 = uVar1;
  return;
}


