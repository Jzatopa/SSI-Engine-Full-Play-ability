/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:8467
 * Ghidra name: FUN_1000_8467
 * Linear address: 0x18467
 * Original GAME.OVR file offset: 99439
 * Body addresses: 70
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - character_creation (character_creation), previous candidate, distance 70 byte(s), source offset 99509
 */

void __stdcall16far FUN_1000_8467(void)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  uVar1 = *(undefined4 *)0x57fb;
  local_3 = 1;
  while( true ) {
    uVar2 = FUN_0000_088a(unaff_CS,local_3,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
    *(undefined1 *)((int)uVar1 + (uint)local_3 + 0x4c) = uVar2;
    if (local_3 == 0x55) break;
    local_3 = local_3 + 1;
    unaff_CS = 0x86;
  }
  return;
}


