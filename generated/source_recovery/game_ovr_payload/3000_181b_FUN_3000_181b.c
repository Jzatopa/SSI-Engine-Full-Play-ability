/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:181b
 * Ghidra name: FUN_3000_181b
 * Linear address: 0x3181B
 * Original GAME.OVR file offset: 202787
 * Body addresses: 104
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_3000_181b(undefined1 *param_1,char *param_2,byte param_3,byte param_4)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  if (param_4 != 0) {
    *param_2 = ((undefined *)&DAT_0000_293c)[(uint)param_4 * 8 + (uint)param_3 * 2];
    *param_1 = ((undefined *)&DAT_0000_293d)[(uint)param_4 * 8 + (uint)param_3 * 2];
    if (-1 < *param_2) {
      local_3 = 1;
    }
  }
  return local_3;
}


