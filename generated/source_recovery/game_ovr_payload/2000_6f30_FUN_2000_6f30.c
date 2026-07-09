/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:6f30
 * Ghidra name: FUN_2000_6f30
 * Linear address: 0x26F30
 * Original GAME.OVR file offset: 159544
 * Body addresses: 165
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_6f30(char param_1,char param_2)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_12;
  char local_11;
  uint local_10 [7];
  
  for (local_11 = '\0';
      local_10[local_11] = (uint)*(byte *)((int)*(undefined4 *)0x4418 + (int)local_11 + 0xc6),
      local_11 != '\x06'; local_11 = local_11 + '\x01') {
  }
  if (param_2 != '\0') {
    local_12 = '\x01';
    while( true ) {
      local_10[param_1] = local_10[param_1] + 1;
      FUN_2000_6e65(local_10,unaff_SS);
      if (local_12 == param_2) break;
      local_12 = local_12 + '\x01';
    }
  }
  local_11 = '\0';
  while( true ) {
    *(undefined1 *)((int)*(undefined4 *)0x4418 + (int)local_11 + 0xc6) = (char)local_10[local_11];
    if (local_11 == '\x06') break;
    local_11 = local_11 + '\x01';
  }
  FUN_2000_6b7f(CONCAT11(0x4b,param_1),CONCAT11(0x4b,param_2));
  return;
}


