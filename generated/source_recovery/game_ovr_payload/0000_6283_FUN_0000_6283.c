/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:6283
 * Ghidra name: FUN_0000_6283
 * Linear address: 0x06283
 * Original GAME.OVR file offset: 25227
 * Body addresses: 12
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_6283(void)

{
  char *pcVar1;
  char in_CL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar1 = (char *)(unaff_BP + unaff_SI + 0xca);
  *pcVar1 = *pcVar1 + (char)in_BX;
  ((undefined *)&DAT_0000_5dec)[in_BX + unaff_DI] =
       ((undefined *)&DAT_0000_5dec)[in_BX + unaff_DI] + in_CL;
  return;
}


