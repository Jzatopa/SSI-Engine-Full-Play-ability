/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:717f
 * Ghidra name: FUN_0000_717f
 * Linear address: 0x0717F
 * Original GAME.OVR file offset: 29063
 * Body addresses: 37
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_717f(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  
  uVar2 = *(undefined2 *)0x534e;
  cVar1 = func_0x00000a87();
  if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS,uVar2);
  }
  return;
}


