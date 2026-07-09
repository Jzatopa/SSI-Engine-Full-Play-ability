/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:9cca
 * Ghidra name: FUN_1000_9cca
 * Linear address: 0x19CCA
 * Original GAME.OVR file offset: 105682
 * Body addresses: 76
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_9cca(int param_1)

{
  undefined1 local_4;
  undefined1 local_3;
  
  local_3 = 0;
  while( true ) {
    local_4 = 0;
    while( true ) {
      FUN_0000_453c(param_1 + (uint)local_3 * 8 + (uint)local_4 * 4);
      if (local_4 == 1) break;
      local_4 = local_4 + 1;
    }
    if (local_3 == 0x23) break;
    local_3 = local_3 + 1;
  }
  return;
}


