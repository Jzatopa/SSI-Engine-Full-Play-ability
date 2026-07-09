/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c83b
 * Ghidra name: FUN_2000_c83b
 * Linear address: 0x2C83B
 * Original GAME.OVR file offset: 182339
 * Body addresses: 57
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_c83b(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(char *)0x8d71 != '\0') {
    do {
      FUN_0000_b5f2(param_1 + -0x248);
    } while (*(int *)(param_1 + -0x244) != 0);
  }
  return;
}


