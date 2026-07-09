/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:664d
 * Ghidra name: FUN_0000_664d
 * Linear address: 0x0664D
 * Original GAME.OVR file offset: 26197
 * Body addresses: 291
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far
FUN_0000_664d(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_5;
  char local_4;
  undefined1 local_3;
  
  if ((param_4._2_2_ == *(int *)0x534c) && ((int)param_4 == *(int *)0x534a)) {
    local_5 = '\0';
  }
  else {
    local_5 = '\x01';
  }
  local_3 = 0;
  if ((local_5 == '\x01') || (cVar1 = FUN_0000_0a6e(), cVar1 != '\0')) {
    local_4 = '\0';
    while( true ) {
      if (((*(int *)((int)param_4 + local_4 * 2 + 0x16) <
            *(int *)((int)param_4 + local_4 * 2 + 0x22)) &&
          (*(int *)((undefined *)&DAT_0000_ffdb + param_1 + local_5 * 0xc + local_4 * 2) == 0)) &&
         (local_4 != '\x04')) {
        local_3 = 1;
      }
      if (local_4 == '\x05') break;
      local_4 = local_4 + '\x01';
    }
    *(undefined1 *)0x7817 = 0;
    while( true ) {
      if ((*(byte *)((int)param_4 + *(char *)0x7817 * 6 + 0x3e) <
           *(byte *)((int)param_4 + *(char *)0x7817 * 6 + 0x3d)) &&
         ((byte)((undefined *)&DAT_0000_ffcb)[param_1 + local_5 * 8 + (int)*(char *)0x7817] <
          *(byte *)((int)param_4 + *(char *)0x7817 * 6 + 0x3d))) {
        local_3 = 1;
      }
      if (*(char *)0x7817 == '\a') break;
      *(char *)0x7817 = *(char *)0x7817 + '\x01';
    }
  }
  return local_3;
}


