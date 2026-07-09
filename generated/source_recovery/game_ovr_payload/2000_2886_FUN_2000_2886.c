/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:2886
 * Ghidra name: FUN_2000_2886
 * Linear address: 0x22886
 * Original GAME.OVR file offset: 141454
 * Body addresses: 122
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_2000_2886(void)

{
  char cVar1;
  undefined2 unaff_DS;
  undefined1 local_104 [256];
  undefined1 local_4;
  undefined1 local_3;
  
  local_3 = 1;
  cVar1 = *(char *)((int)*(undefined4 *)0x57fb + 0x28);
  local_4 = *(undefined1 *)(cVar1 * 8 + 0xfdc);
  FUN_0000_0a78(CONCAT11(cVar1 >> 7,local_4),*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
  func_0x0000d6dc(0x99,0xff,local_104);
  return;
}


