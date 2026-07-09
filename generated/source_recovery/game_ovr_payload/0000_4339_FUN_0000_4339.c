/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4339
 * Ghidra name: FUN_0000_4339
 * Linear address: 0x04339
 * Original GAME.OVR file offset: 17217
 * Body addresses: 67
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_0000_4339(undefined2 param_1,int param_2,int param_3)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  if ((param_3 == *(int *)0x534c) && (param_2 == *(int *)0x534a)) {
    local_3 = 0xb;
  }
  else if ((param_3 == *(int *)0x5350) && (param_2 == *(int *)0x534e)) {
    local_3 = 0xe;
  }
  else {
    local_3 = 0xc;
  }
  return local_3;
}


