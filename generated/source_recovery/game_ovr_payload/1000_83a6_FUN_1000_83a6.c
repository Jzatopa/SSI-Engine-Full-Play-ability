/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:83a6
 * Ghidra name: FUN_1000_83a6
 * Linear address: 0x183A6
 * Original GAME.OVR file offset: 99246
 * Body addresses: 93
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_83a6(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_3;
  
  for (local_3 = '\0';
      *(char *)((int)*(undefined4 *)(param_1 + -4) + (int)local_3 + 0x1e) =
           ((undefined *)&DAT_0000_3562)[local_3] -
           ((undefined *)&DAT_0000_351a)
           [*(char *)((int)*(undefined4 *)(param_1 + -4) + 0x27) * 8 + (int)local_3],
      local_3 != '\a'; local_3 = local_3 + '\x01') {
  }
  return;
}


