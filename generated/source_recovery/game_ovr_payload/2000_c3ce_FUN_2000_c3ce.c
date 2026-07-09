/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c3ce
 * Ghidra name: FUN_2000_c3ce
 * Linear address: 0x2C3CE
 * Original GAME.OVR file offset: 181206
 * Body addresses: 103
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined4 __stdcall16far FUN_2000_c3ce(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 uStack_8;
  undefined2 local_6;
  undefined2 local_4;
  
  local_a = param_1;
  uStack_8 = param_2;
  for (local_c = 0; (local_a != 0 || uStack_8 != 0 && (local_c != param_3)); local_c = local_c + 1)
  {
    piVar1 = (int *)(local_a + 0x2a);
    uStack_8 = *(int *)(local_a + 0x2c);
    local_a = *piVar1;
  }
  if (local_c == param_3) {
    local_6 = local_a;
    local_4 = uStack_8;
  }
  else {
    local_6 = 0;
    local_4 = 0;
  }
  return CONCAT22(local_4,local_6);
}


