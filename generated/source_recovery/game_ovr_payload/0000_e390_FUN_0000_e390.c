/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e390
 * Ghidra name: FUN_0000_e390
 * Linear address: 0x0E390
 * Original GAME.OVR file offset: 58264
 * Body addresses: 27
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_e390(void)

{
  undefined2 in_AX;
  undefined1 extraout_AH;
  
  FUN_0000_db35(0x23,in_AX);
  FUN_0000_db35(CONCAT11(extraout_AH,0x24),CONCAT11(extraout_AH,4));
  return;
}


