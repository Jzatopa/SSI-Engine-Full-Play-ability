/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b332
 * Ghidra name: FUN_2000_b332
 * Linear address: 0x2B332
 * Original GAME.OVR file offset: 176954
 * Body addresses: 67
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_2000_b332(char param_1,undefined4 param_2)

{
  char extraout_AL;
  char extraout_AH;
  char cVar1;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  FUN_2000_b17d(param_1,(int)param_2,param_2._2_2_);
  if (extraout_AL == '\0') {
    local_3 = 0;
    cVar1 = extraout_AH;
  }
  else {
    cVar1 = *(char *)(param_1 * 0x1b + 0x153d);
    local_3 = *(undefined1 *)((int)param_2 + cVar1 + 0x10);
    cVar1 = cVar1 >> 7;
  }
  return CONCAT11(cVar1,local_3);
}


