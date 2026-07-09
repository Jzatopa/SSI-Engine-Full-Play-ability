/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:7263
 * Ghidra name: FUN_1000_7263
 * Linear address: 0x17263
 * Original GAME.OVR file offset: 94827
 * Body addresses: 96
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_7263(char param_1)

{
  undefined2 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar2;
  undefined1 local_114 [256];
  undefined4 local_14;
  undefined1 local_f [13];
  
  if (param_1 != '\0') {
    return;
  }
  local_14 = *(undefined4 *)0x5360;
  uVar1 = (undefined2)((ulong)local_14 >> 0x10);
  *(undefined1 *)0x5368 = *(undefined1 *)((int)local_14 + 0x39);
  *(undefined1 *)0x5369 = *(undefined1 *)((int)local_14 + 0x3a);
  puVar2 = local_f;
  FUN_0000_e390(4);
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0xca2,0xcc0,local_114,unaff_SS,puVar2);
}


