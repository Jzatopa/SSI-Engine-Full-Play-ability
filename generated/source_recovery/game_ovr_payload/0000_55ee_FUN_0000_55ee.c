/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:55ee
 * Ghidra name: FUN_0000_55ee
 * Linear address: 0x055EE
 * Original GAME.OVR file offset: 22006
 * Body addresses: 88
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Removing unreachable block (ram,0x00005604) */

undefined2 __stdcall16far FUN_0000_55ee(void)

{
  undefined2 uVar1;
  undefined1 local_106 [258];
  undefined1 local_4;
  
  local_4 = 3;
  FUN_0000_4389();
  func_0x0000d74f();
  uVar1 = func_0x0000d6dc(0xcc0,0xff,local_106);
  return uVar1;
}


