/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:4b2e
 * Ghidra name: FUN_1000_4b2e
 * Linear address: 0x14B2E
 * Original GAME.OVR file offset: 84790
 * Body addresses: 50
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_1000_4b2e(undefined1 *param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
             undefined2 param_5)

{
  undefined2 unaff_DS;
  
  *param_1 = 1;
  *(undefined1 *)0x72d0 = param_3;
  *(undefined *)&DAT_0000_72d1 = param_2;
  FUN_1000_3b01((undefined1 *)param_1,(int)((ulong)param_1 >> 0x10),0,0,0,param_4,param_5);
  return;
}


