/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c435
 * Ghidra name: FUN_2000_c435
 * Linear address: 0x2C435
 * Original GAME.OVR file offset: 181309
 * Body addresses: 68
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

int __stdcall16far FUN_2000_c435(int param_1,int param_2)

{
  int *piVar1;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 uStack_6;
  
  local_a = 0;
  uStack_6 = param_2;
  local_8 = param_1;
  while (local_8 != 0 || uStack_6 != 0) {
    local_a = local_a + 1;
    piVar1 = (int *)(local_8 + 0x2a);
    uStack_6 = *(int *)(local_8 + 0x2c);
    local_8 = *piVar1;
  }
  return local_a;
}


