/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:263d
 * Ghidra name: FUN_3000_263d
 * Linear address: 0x3263D
 * Original GAME.OVR file offset: 206405
 * Body addresses: 340
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_3000_263d(undefined1 *param_1,byte *param_2,byte *param_3,byte param_4,undefined2 param_5,
             undefined2 param_6)

{
  char cVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_d;
  char local_c;
  char local_b;
  char local_a;
  undefined1 local_9;
  char local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  byte local_4;
  char local_3;
  
  *param_3 = 0;
  *param_2 = 0x17;
  local_7 = 1;
  *param_1 = 0;
  local_4 = FUN_3000_25e3(param_5,param_6);
  local_a = ((undefined *)&DAT_0000_69ed)[(uint)local_4 * 4];
  local_b = ((undefined *)&DAT_0000_69ee)[(uint)local_4 * 4];
  local_3 = '\0';
  while( true ) {
    cVar1 = FUN_3000_181b(&local_d,unaff_SS,&local_c,unaff_SS,local_3,
                          ((undefined *)&DAT_0000_69f0)[(uint)local_4 * 4]);
    if (cVar1 != '\0') {
      local_8 = local_a + local_c + ((undefined *)&DAT_0000_26ca)[param_4];
      iVar2 = (int)local_b + (int)local_d + (int)(char)((undefined *)&DAT_0000_26d3)[param_4];
      local_9 = (undefined1)iVar2;
      FUN_3000_1ed8(&local_6,unaff_SS,&local_5,unaff_SS,iVar2,
                    CONCAT11((char)((uint)iVar2 >> 8),local_8));
      if (local_5 == local_4) {
        local_5 = 0;
      }
      if (local_5 != 0) {
        *param_3 = local_5;
      }
      if (local_6 == 2) {
        *param_1 = 1;
      }
      if ((local_6 == 0) || (*param_2 == 0)) {
        *param_2 = 0;
      }
      else if (local_7 <= (byte)((undefined *)&DAT_0000_26d8)[(uint)local_6 * 4]) {
        local_7 = ((undefined *)&DAT_0000_26d8)[(uint)local_6 * 4];
        *param_2 = local_6;
      }
    }
    if (local_3 == '\x03') break;
    local_3 = local_3 + '\x01';
  }
  return;
}


