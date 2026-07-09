/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:635d
 * Ghidra name: FUN_0000_635d
 * Linear address: 0x0635D
 * Original GAME.OVR file offset: 25445
 * Body addresses: 62
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_0000_635d(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  char cVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  *(undefined1 *)0x7817 = 0;
  while( true ) {
    cVar1 = FUN_0000_6308(param_1,*(undefined1 *)0x7817,param_2,param_3);
    if (cVar1 != '\0') {
      local_3 = 1;
    }
    if (*(char *)0x7817 == '\a') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
  }
  return local_3;
}


