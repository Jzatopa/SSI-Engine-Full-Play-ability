/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:77e5
 * Ghidra name: FUN_2000_77e5
 * Linear address: 0x277E5
 * Original GAME.OVR file offset: 161773
 * Body addresses: 37
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_77e5(void)

{
  undefined2 unaff_DS;
  byte in_stack_0000000e;
  
  (**(code **)((undefined *)&DAT_0000_72d7 + (uint)in_stack_0000000e * 4))();
  return;
}


