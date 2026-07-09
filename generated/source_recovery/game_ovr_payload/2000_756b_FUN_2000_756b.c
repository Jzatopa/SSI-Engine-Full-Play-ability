/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:756b
 * Ghidra name: FUN_2000_756b
 * Linear address: 0x2756B
 * Original GAME.OVR file offset: 161139
 * Body addresses: 53
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_756b(undefined4 param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined2 unaff_DS;
  
  if ((*(int *)0x72bc < 1) && ((*(int *)0x72bc < 0 || (*(int *)0x72ba == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *param_2 = uVar1;
  *(bool *)param_1 = *(int *)0x72be != 0 || *(int *)0x72c0 != 0;
  return;
}


