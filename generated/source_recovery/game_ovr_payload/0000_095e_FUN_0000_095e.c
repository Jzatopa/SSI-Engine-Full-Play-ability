/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:095e
 * Ghidra name: FUN_0000_095e
 * Linear address: 0x0095E
 * Original GAME.OVR file offset: 2406
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x0000095f) overlaps instruction at (ram,0x0000095e)
    */

void FUN_0000_095e(void)

{
  char *pcVar1;
  char cVar2;
  char in_DL;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar1 = (undefined *)&DAT_0000_ff8d + in_BX + unaff_SI;
  cVar2 = *pcVar1;
  *pcVar1 = *pcVar1 + in_DL;
  if (*pcVar1 == '\0' || SCARRY1(cVar2,in_DL) != *pcVar1 < '\0') {
    unaff_DI = unaff_BP + -4;
  }
  FUN_0000_2670();
  FUN_0000_3721(0x21a,*(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2),0x15,3,unaff_DI)
  ;
  FUN_0000_453c(unaff_BP + -4);
  cVar2 = FUN_0000_00d2(5);
  if (cVar2 != '\0') {
    FUN_0000_03ab(0x21a);
    FUN_0000_07e8(0x21a);
    FUN_0000_016c();
    FUN_0000_09b1();
    return;
  }
  FUN_0000_03ab(0x21a);
  FUN_0000_07e8(0x21a);
  FUN_0000_016c();
  FUN_0000_09b1();
  return;
}


