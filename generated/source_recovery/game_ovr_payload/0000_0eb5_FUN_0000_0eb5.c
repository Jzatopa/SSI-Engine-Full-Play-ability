/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0eb5
 * Ghidra name: FUN_0000_0eb5
 * Linear address: 0x00EB5
 * Original GAME.OVR file offset: 3773
 * Body addresses: 87
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_0eb5(void)

{
  undefined1 in_AL;
  char in_CH;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_DS;
  
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + in_CH;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c1) = in_AL;
  if (*(byte *)((int)*(undefined4 *)0x441c + 0x2c0) < *(byte *)((int)*(undefined4 *)0x441c + 0x2c1))
  {
    *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c1) =
         *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c0);
  }
  FUN_0000_06f3();
  return;
}


