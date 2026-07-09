/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:d0b3
 * Ghidra name: FUN_2000_d0b3
 * Linear address: 0x2D0B3
 * Original GAME.OVR file offset: 184507
 * Body addresses: 51
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_d0b3(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(char *)0x7457 == *(char *)(param_1 + -0x23d)) {
    *(undefined1 *)0x7457 = 1;
  }
  else {
    *(char *)0x7457 = *(char *)0x7457 + '\x01';
  }
  FUN_2000_c618(param_1,*(undefined1 *)0x7457);
  *(undefined1 *)(param_1 + -0x212) = 0;
  return;
}


