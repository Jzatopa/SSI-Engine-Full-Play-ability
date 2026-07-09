/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b552
 * Ghidra name: FUN_2000_b552
 * Linear address: 0x2B552
 * Original GAME.OVR file offset: 177498
 * Body addresses: 75
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

char __stdcall16far FUN_2000_b552(undefined1 param_1,char param_2)

{
  char cVar1;
  char local_5;
  char local_4;
  
  local_5 = '\0';
  if (param_2 != '\0') {
    if (param_2 != '\0') {
      local_4 = '\x01';
      while( true ) {
        cVar1 = FUN_0000_e1ea(param_1);
        local_5 = local_5 + cVar1 + '\x01';
        if (local_4 == param_2) break;
        local_4 = local_4 + '\x01';
      }
    }
  }
  return local_5;
}


