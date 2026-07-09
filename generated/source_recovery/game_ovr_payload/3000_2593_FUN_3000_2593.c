/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:2593
 * Ghidra name: FUN_3000_2593
 * Linear address: 0x32593
 * Original GAME.OVR file offset: 206235
 * Body addresses: 40
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_3000_2593(undefined2 param_1,undefined2 param_2)

{
  uint uVar1;
  undefined2 unaff_DS;
  
  uVar1 = FUN_3000_25e3(param_1,param_2);
  return ((undefined *)&DAT_0000_69ee)[(uVar1 & 0xff) * 4];
}


