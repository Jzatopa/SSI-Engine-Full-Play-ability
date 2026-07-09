/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:a35c
 * Ghidra name: FUN_2000_a35c
 * Linear address: 0x2A35C
 * Original GAME.OVR file offset: 172900
 * Body addresses: 56
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_a35c(byte *param_1)

{
  char cVar1;
  undefined2 unaff_BP;
  
  if ('\0' < (char)*param_1) {
    cVar1 = FUN_0000_8695();
    if (cVar1 == '\0') {
      FUN_0000_c05c(0x46,unaff_BP);
    }
    else {
      *param_1 = *param_1 & 1;
    }
  }
  *param_1 = *param_1 - 1;
  return;
}


