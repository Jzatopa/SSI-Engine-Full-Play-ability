/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4652
 * Ghidra name: FUN_0000_4652
 * Linear address: 0x04652
 * Original GAME.OVR file offset: 18010
 * Body addresses: 262
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_4652(int param_1,byte param_2,char param_3,undefined4 param_4)

{
  uint uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 local_8;
  char local_4;
  undefined1 local_3;
  
  if ((param_4._2_2_ == *(int *)0x534c) && ((int)param_4 == *(int *)0x534a)) {
    local_4 = '\0';
  }
  else {
    local_4 = '\x01';
  }
  param_4._0_2_ = (int)param_4 + (uint)param_2 * 6;
  local_8 = (byte *)CONCAT22(param_4._2_2_,(byte *)((int)param_4 + 0x3c));
  uVar1 = CONCAT11((char)((uint)param_2 * 6 >> 8),*local_8) & 0xff7f;
  if ((char)uVar1 == '\0') {
    local_3 = 7;
  }
  else if ((param_3 == '\0') || (0x7f < *local_8)) {
    if ((param_3 == '\0') && (0x7f < *local_8)) {
      local_3 = 2;
    }
    else if (*(char *)((int)param_4 + 0x3e) == '\0') {
      local_3 = 3;
    }
    else {
      uVar1 = CONCAT11((char)(uVar1 >> 8),*local_8) & 0xff7f;
      if (((byte)uVar1 < 3) || (*(char *)((int)param_4 + 0x40) != '\0')) {
        uVar1 = 0;
        if ((byte)((undefined *)&DAT_0000_ffbb)[param_1 + local_4 * 8 + (uint)param_2] <
            *(byte *)((int)param_4 + 0x3e)) {
          uVar1 = (uint)*(char *)0x5359;
          if ((int)(uint)*(byte *)((uint)(*local_8 & 0x7f) * 0x22 + 0x2408) < (int)uVar1) {
            local_3 = 6;
          }
          else {
            local_3 = 0;
          }
        }
        else {
          local_3 = 5;
        }
      }
      else {
        local_3 = 4;
      }
    }
  }
  else {
    local_3 = 1;
  }
  return CONCAT11((char)(uVar1 >> 8),local_3);
}


