/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:1ed8
 * Ghidra name: FUN_3000_1ed8
 * Linear address: 0x31ED8
 * Original GAME.OVR file offset: 204512
 * Body addresses: 109
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_1ed8(undefined1 *param_1,undefined1 *param_2,char param_3,char param_4)

{
  undefined2 unaff_DS;
  
  if ((((param_4 < '\0') || ('1' < param_4)) || (param_3 < '\0')) || ('\x18' < param_3)) {
    *param_2 = 0;
    *param_1 = 0;
  }
  else {
    *param_1 = *(undefined1 *)((int)*(undefined4 *)0x71dc + param_3 * 0x32 + (int)param_4 + 7);
    *param_2 = ((undefined *)&DAT_0000_6ba1)[param_3 * 0x32 + (int)param_4];
  }
  return;
}


