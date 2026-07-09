/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:3d28
 * Ghidra name: FUN_3000_3d28
 * Linear address: 0x33D28
 * Original GAME.OVR file offset: 212272
 * Body addresses: 196
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_3000_3d28(undefined2 param_1,undefined2 param_2,char param_3,char param_4,char param_5,
             char param_6)

{
  char cVar1;
  char cVar2;
  int iVar3;
  undefined1 extraout_AH;
  byte extraout_AH_00;
  undefined2 uVar4;
  byte bVar5;
  byte extraout_AH_01;
  byte extraout_AH_02;
  char local_4;
  
  cVar2 = param_6;
  cVar1 = param_5;
  if (param_5 == param_3) {
    if (param_4 < param_6) {
      param_6 = param_4;
      param_4 = cVar2;
    }
    iVar3 = ((int)param_4 - (int)param_6) + 1;
    local_4 = (char)iVar3;
  }
  else {
    if (param_3 < param_5) {
      param_5 = param_3;
      param_3 = cVar1;
    }
    iVar3 = ((int)param_3 - (int)param_5) + 1;
    local_4 = (char)iVar3;
  }
  FUN_3000_3bb8(&stack0xfffe,CONCAT11((char)((uint)iVar3 >> 8),2));
  FUN_3000_3bb8(&stack0xfffe,CONCAT11(extraout_AH,1));
  uVar4 = FUN_3000_3bb8(&stack0xfffe,(uint)extraout_AH_00 << 8);
  while (bVar5 = (byte)((uint)uVar4 >> 8), '\x03' < local_4) {
    uVar4 = FUN_3000_3bb8(&stack0xfffe,CONCAT11(bVar5,1));
  }
  if (local_4 == '\x03') {
    FUN_3000_3bb8(&stack0xfffe,(uint)bVar5 << 8);
    bVar5 = extraout_AH_01;
  }
  if (local_4 == '\x02') {
    FUN_3000_3bb8(&stack0xfffe,CONCAT11(bVar5,1));
    bVar5 = extraout_AH_02;
  }
  if (local_4 == '\x01') {
    FUN_3000_3bb8(&stack0xfffe,CONCAT11(bVar5,3));
  }
  return;
}


