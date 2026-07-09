/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:81ec
 * Ghidra name: FUN_2000_81ec
 * Linear address: 0x281EC
 * Original GAME.OVR file offset: 164340
 * Body addresses: 175
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_81ec(void)

{
  undefined2 unaff_DS;
  byte local_7;
  undefined4 local_6;
  
  for (local_6 = (undefined2 *)CONCAT22(*(undefined2 *)0x748b,(undefined2 *)*(undefined2 *)0x7489);
      (undefined2 *)local_6 != (undefined2 *)0x0 || local_6._2_2_ != 0;
      local_6 = (undefined2 *)CONCAT22(((undefined2 *)local_6)[1],(undefined2 *)*local_6)) {
    local_7 = 1;
    while( true ) {
      if (*(char *)((int)(undefined2 *)local_6 + local_7 + 0xc) != '\0') {
        *(undefined1 *)
         ((int)*(undefined4 *)0x71dc +
          ((int)*(char *)((int)(undefined2 *)local_6 + 0x17) +
          (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)(local_7 + 0x3189)]) * 0x32 +
          (int)*(char *)((undefined2 *)local_6 + 0xb) +
          (int)(char)((undefined *)&DAT_0000_26ca)[*(byte *)(local_7 + 0x3189)] + 7) =
             *(undefined1 *)((int)(undefined2 *)local_6 + 0x19);
      }
      if (local_7 == 9) break;
      local_7 = local_7 + 1;
    }
  }
  return;
}


