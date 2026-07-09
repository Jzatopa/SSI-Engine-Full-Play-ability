/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:72a2
 * Ghidra name: FUN_0000_72a2
 * Linear address: 0x072A2
 * Original GAME.OVR file offset: 29354
 * Body addresses: 41
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_72a2(void)

{
  undefined4 uVar1;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  if ((0 < *(int *)(unaff_DI + 0x18)) &&
     (uVar1 = *(undefined4 *)(*(int *)(unaff_BP + 6) + -4), *(char *)((int)uVar1 + 0x56) != '\0')) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(*(int *)(unaff_BP + 6) + -0x104,unaff_SS,unaff_BP + -0x100,unaff_SS);
  }
  return;
}


