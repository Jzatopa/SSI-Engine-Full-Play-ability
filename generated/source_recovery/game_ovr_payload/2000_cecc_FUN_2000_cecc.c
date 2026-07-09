/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:cecc
 * Ghidra name: FUN_2000_cecc
 * Linear address: 0x2CECC
 * Original GAME.OVR file offset: 184020
 * Body addresses: 98
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_cecc(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if ((((*(int *)(param_1 + -0x210) < 4) || (0x15 < *(int *)(param_1 + -0x210))) ||
      (*(int *)(param_1 + -0x20e) < 0x13)) || (0x24 < *(int *)(param_1 + -0x20e))) {
    FUN_2000_c83b(param_1);
    *(undefined1 *)0x8d71 = 0;
    *(undefined1 *)0x7483 = 0;
    *(undefined1 *)(param_1 + -0x212) = 0;
  }
  else {
    *(undefined1 *)0x7483 = 0x21;
    *(undefined1 *)(param_1 + -0x212) = 1;
  }
  *(undefined1 *)0x7458 = 0;
  return;
}


