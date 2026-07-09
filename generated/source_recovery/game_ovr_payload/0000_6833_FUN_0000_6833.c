/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:6833
 * Ghidra name: FUN_0000_6833
 * Linear address: 0x06833
 * Original GAME.OVR file offset: 26683
 * Body addresses: 144
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

char __stdcall16far FUN_0000_6833(int param_1)

{
  uint in_AX;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_5;
  char local_4;
  
  local_4 = '\0';
  local_5 = '\0';
  while( true ) {
    in_AX = FUN_0000_4652(*(undefined2 *)(*(int *)(param_1 + 6) + 6),local_5,in_AX & 0xff00,
                          *(undefined2 *)0x534e,*(undefined2 *)0x5350);
    if ((char)in_AX == '\0') {
      in_AX = (uint)*(byte *)((int)*(undefined4 *)0x534e + local_5 * 6 + 0x3e) *
              (uint)*(byte *)((uint)(*(byte *)((int)*(undefined4 *)0x534e + local_5 * 6 + 0x3c) &
                                    0x7f) * 0x22 + 0x240b);
      local_4 = local_4 + (char)in_AX;
    }
    if (local_5 == '\a') break;
    local_5 = local_5 + '\x01';
  }
  return local_4;
}


