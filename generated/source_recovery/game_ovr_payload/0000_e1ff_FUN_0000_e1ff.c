/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e1ff
 * Ghidra name: FUN_0000_e1ff
 * Linear address: 0x0E1FF
 * Original GAME.OVR file offset: 57863
 * Body addresses: 1
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2
FUN_0000_e1ff(undefined2 param_1,undefined2 param_2,char param_3,char param_4,char param_5)

{
  char extraout_AL;
  char extraout_AL_00;
  undefined2 in_AX;
  undefined1 uVar4;
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 unaff_DS;
  undefined1 uStack_3;
  
  uVar4 = (undefined1)((uint)in_AX >> 8);
  if ((((param_5 < '\0') || ('\x0f' < param_5)) || (param_4 < '\0')) || ('\x0f' < param_4)) {
    if ((param_4 == *"\x15 at sensor operation!\x0eShip Character\x01") &&
       ((param_3 == '\x02' || (param_3 == '\x06')))) {
      uStack_3 = 0;
    }
    else {
      uStack_3 = 1;
    }
  }
  else {
    uVar1 = CONCAT11(uVar4,param_5);
    uVar2 = CONCAT11(uVar4,param_4);
    uVar3 = CONCAT11(uVar4,param_3);
    func_0x00000d3f();
    if (extraout_AL == '\0') {
      uStack_3 = 1;
      uVar4 = extraout_AH;
    }
    else {
      FUN_0000_0d3a(0xd1,CONCAT11(extraout_AH,param_3),CONCAT11(extraout_AH,param_4),
                    CONCAT11(extraout_AH,param_5),uVar3,uVar2,uVar1);
      uVar4 = extraout_AH_00;
      if (extraout_AL_00 == '\0') {
        uStack_3 = 0;
      }
      else {
        uStack_3 = 3;
      }
    }
  }
  return CONCAT11(uVar4,uStack_3);
}


