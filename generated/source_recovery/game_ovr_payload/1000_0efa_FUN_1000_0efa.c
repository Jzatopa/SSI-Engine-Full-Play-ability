/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:0efa
 * Ghidra name: FUN_1000_0efa
 * Linear address: 0x10EFA
 * Original GAME.OVR file offset: 69378
 * Body addresses: 44
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_0efa(void)

{
  undefined2 unaff_DS;
  undefined4 *in_stack_0000000a;
  
  *(undefined1 *)0x72c5 = 0;
  if (*(uint *)((int)*in_stack_0000000a + 0xe3) < (uint)*(byte *)0x72c6) {
    *(undefined1 *)0x72c6 = *(undefined1 *)((int)*in_stack_0000000a + 0xe3);
  }
  return;
}


