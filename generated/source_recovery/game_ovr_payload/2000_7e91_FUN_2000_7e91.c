/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:7e91
 * Ghidra name: FUN_2000_7e91
 * Linear address: 0x27E91
 * Original GAME.OVR file offset: 163481
 * Body addresses: 55
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_7e91(undefined2 param_1,undefined2 param_2)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 1;
  while( true ) {
    FUN_2000_768a(0,0,*(undefined1 *)(local_3 + 0xdd5),param_1,param_2);
    if (local_3 == 4) break;
    local_3 = local_3 + 1;
  }
  return;
}


