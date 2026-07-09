/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:fc83
 * Ghidra name: FUN_2000_fc83
 * Linear address: 0x2FC83
 * Original GAME.OVR file offset: 195723
 * Body addresses: 270
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_fc83(byte param_1,byte param_2,char param_3,char param_4)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_DS;
  byte local_b;
  int local_a;
  int local_8;
  
  local_b = *(byte *)(param_1 + 0xecc);
  iVar1 = (uint)*(byte *)(param_1 + 0xed6) + (int)param_4 + -1;
  iVar2 = (uint)*(byte *)(param_1 + 0xee0) + (int)param_3 + -1;
  local_a = (int)param_3;
  if (local_a <= iVar2) {
    while( true ) {
      local_8 = (int)param_4;
      if (local_8 <= iVar1) {
        while( true ) {
          if ((((-1 < local_a) && (local_a < 0xb)) && (-1 < local_8)) &&
             ((local_8 < 0xb &&
              (((undefined *)&DAT_0000_ff64)
               [(int)*(undefined4 *)0x735c + (uint)param_2 * 0x9c + (uint)local_b] != '\0')))) {
            FUN_0000_13ba(1);
          }
          local_b = local_b + 1;
          if (local_8 == iVar1) break;
          local_8 = local_8 + 1;
        }
      }
      if (local_a == iVar2) break;
      local_a = local_a + 1;
    }
  }
  return;
}


