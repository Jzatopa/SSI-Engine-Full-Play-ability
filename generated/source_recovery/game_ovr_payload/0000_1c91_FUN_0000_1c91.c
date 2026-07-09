/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:1c91
 * Ghidra name: FUN_0000_1c91
 * Linear address: 0x01C91
 * Original GAME.OVR file offset: 7321
 * Body addresses: 74
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_1c91(undefined2 param_1,char param_2)

{
  uint in_AX;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_4f [21];
  undefined1 local_3a;
  undefined1 local_7;
  
  if (param_2 != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x11f7,unaff_CS,local_4f,unaff_SS,in_AX & 0xff00);
  }
  *(undefined1 *)0x7457 = 1;
  local_7 = 0;
  local_3a = 0;
  func_0x000006da();
  return;
}


