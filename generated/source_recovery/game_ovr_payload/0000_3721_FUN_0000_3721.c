/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:3721
 * Ghidra name: FUN_0000_3721
 * Linear address: 0x03721
 * Original GAME.OVR file offset: 14121
 * Body addresses: 9
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_0000_3721(void)

{
  char in_DL;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  ((undefined *)&DAT_0000_ff9a)[in_BX + unaff_SI] =
       ((undefined *)&DAT_0000_ff9a)[in_BX + unaff_SI] + in_DL;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


