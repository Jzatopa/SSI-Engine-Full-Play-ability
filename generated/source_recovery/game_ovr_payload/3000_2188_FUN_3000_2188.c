/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:2188
 * Ghidra name: FUN_3000_2188
 * Linear address: 0x32188
 * Original GAME.OVR file offset: 205200
 * Body addresses: 398
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_3000_2188(byte param_1,char param_2,char param_3)

{
  char cVar1;
  undefined1 uVar3;
  int iVar2;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 unaff_DS;
  char local_a;
  char local_9;
  char local_8;
  char local_7;
  byte local_4;
  undefined1 local_3;
  
  local_3 = 0;
  local_9 = *(char *)((int)*(undefined4 *)0x71dc + 2) + '\x03';
  local_a = *(char *)((int)*(undefined4 *)0x71dc + 3) + '\x03';
  local_4 = param_1;
  if (param_1 == 0xff) {
    local_4 = 0;
  }
  cVar1 = (char)((int)local_a + (uint)local_4);
  if ((((param_1 == 0xff) ||
       (uVar3 = (undefined1)((int)local_a + (uint)local_4 >> 8), param_3 < (char)(local_9 - local_4)
       )) || ((char)(local_9 + local_4) < param_3)) ||
     ((param_2 < (char)(local_a - local_4) || (cVar1 < param_2)))) {
    if (param_3 < (char)(local_9 - local_4)) {
      for (; (param_3 < local_9 && ('\x03' < local_9)); local_9 = local_9 + -1) {
      }
    }
    else if ((char)(local_9 + local_4) < param_3) {
      for (; (local_9 < param_3 && (local_9 < '.')); local_9 = local_9 + '\x01') {
      }
    }
    if (param_2 < (char)(local_a - local_4)) {
      for (; (param_2 < local_a && ('\x03' < local_a)); local_a = local_a + -1) {
      }
    }
    else if (cVar1 < param_2) {
      for (; (local_a < param_2 && (local_a < '\x15')); local_a = local_a + '\x01') {
      }
    }
    *(char *)((int)*(undefined4 *)0x71dc + 2) = local_9 + -3;
    iVar2 = (int)local_a;
    *(undefined1 *)((int)*(undefined4 *)0x71dc + 3) = (char)(iVar2 + -3);
    local_a = *(char *)((int)*(undefined4 *)0x71dc + 3);
    uVar3 = (undefined1)((uint)(iVar2 + -3) >> 8);
    local_8 = '\0';
    while( true ) {
      local_9 = *(char *)((int)*(undefined4 *)0x71dc + 2);
      local_7 = '\0';
      while( true ) {
        FUN_3000_1908(CONCAT11(uVar3,local_a),CONCAT11(uVar3,local_9),CONCAT11(uVar3,local_8),
                      CONCAT11(uVar3,local_7));
        local_9 = local_9 + '\x01';
        uVar3 = extraout_AH;
        if (local_7 == '\x06') break;
        local_7 = local_7 + '\x01';
      }
      local_a = local_a + '\x01';
      if (local_8 == '\x06') break;
      local_8 = local_8 + '\x01';
    }
    FUN_3000_1883();
    local_3 = 1;
    uVar3 = extraout_AH_00;
  }
  return CONCAT11(uVar3,local_3);
}


