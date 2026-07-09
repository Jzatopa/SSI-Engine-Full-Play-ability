/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:cd22
 * Ghidra name: FUN_2000_cd22
 * Linear address: 0x2CD22
 * Original GAME.OVR file offset: 183594
 * Body addresses: 51
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_cd22(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x7458 = 1;
  *(undefined1 *)0x7483 =
       *(undefined1 *)(*(int *)(param_1 + -0x210) * 0xb + *(int *)(param_1 + -0x20e) + 0x3179);
  *(undefined1 *)(param_1 + -0x212) = 1;
  return;
}


