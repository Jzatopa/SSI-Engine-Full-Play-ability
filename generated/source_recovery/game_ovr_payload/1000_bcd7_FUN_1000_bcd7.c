/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:bcd7
 * Ghidra name: FUN_1000_bcd7
 * Linear address: 0x1BCD7
 * Original GAME.OVR file offset: 113887
 * Body addresses: 94
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

ulong __stdcall16far FUN_1000_bcd7(undefined4 param_1)

{
  undefined2 unaff_DS;
  ulong uVar1;
  
  if (*(char *)((int)*(undefined4 *)0x441c + 0x36d) == '\0') {
    uVar1 = (ulong)*(uint *)((int)param_1 + 0x39);
  }
  else {
    func_0x0000d612();
    uVar1 = FUN_0000_d62d(0xcc0);
  }
  return uVar1;
}


