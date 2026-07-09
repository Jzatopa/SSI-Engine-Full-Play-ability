/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0734
 * Ghidra name: FUN_0000_0734
 * Linear address: 0x00734
 * Original GAME.OVR file offset: 1852
 * Body addresses: 10
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0734(void)

{
  char *pcVar1;
  char cVar2;
  byte in_DL;
  byte bVar3;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  bVar3 = in_DL | ((undefined *)&DAT_0000_ffb0)[in_BX + unaff_SI];
  pcVar1 = (undefined *)&DAT_0000_ff8d + in_BX + unaff_SI;
  cVar2 = *pcVar1;
  *pcVar1 = *pcVar1 + bVar3;
  if (*pcVar1 != '\0' && SCARRY1(cVar2,bVar3) == *pcVar1 < '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x238,unaff_CS,unaff_DI,unaff_SS);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x21d,unaff_CS);
}


