/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:643a
 * Ghidra name: FUN_0000_643a
 * Linear address: 0x0643A
 * Original GAME.OVR file offset: 25666
 * Body addresses: 63
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x0000643c) overlaps instruction at (ram,0x0000643b)
    */

void FUN_0000_643a(void)

{
  char *pcVar1;
  char cVar2;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  bool bVar3;
  
  pcVar1 = (char *)(in_BX + unaff_SI);
  *pcVar1 = *pcVar1 + '\x01';
  bVar3 = *pcVar1 == '\0';
  if (in_CF || bVar3) goto LAB_0000_6446;
  while( true ) {
    cVar2 = FUN_0000_6308();
    bVar3 = cVar2 == '\0';
LAB_0000_6446:
    if (!bVar3) break;
    if (*(char *)(unaff_BP + -2) == '\a') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(unaff_BP + -0x103,unaff_SS,unaff_BP + -0x204,unaff_SS);
    }
    *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(unaff_BP + -0x103,unaff_SS,unaff_BP + -0x204,unaff_SS);
}


