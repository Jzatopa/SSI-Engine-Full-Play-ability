/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4cde
 * Ghidra name: FUN_0000_4cde
 * Linear address: 0x04CDE
 * Original GAME.OVR file offset: 19686
 * Body addresses: 42
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_4cde(int param_1)

{
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined1 local_208 [518];
  
  if (*(char *)(param_1 + -8) == '\0') {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x971,unaff_CS,local_208,unaff_SS);
}


