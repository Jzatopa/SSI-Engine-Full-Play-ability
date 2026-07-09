/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:09ba
 * Ghidra name: FUN_0000_09ba
 * Linear address: 0x009BA
 * Original GAME.OVR file offset: 2498
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x00000a29) overlaps instruction at (ram,0x00000a28)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0000_09ba(void)

{
  uint in_AX;
  char cVar2;
  int iVar1;
  undefined2 in_CX;
  char *in_BX;
  int unaff_BP;
  int unaff_SI;
  char *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_stack_00000000;
  
  *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) | in_AX;
  *unaff_DI = *unaff_DI + (char)((uint)in_CX >> 8);
  in_BX[unaff_SI] = in_BX[unaff_SI] + (char)((uint)in_BX >> 8);
  *in_BX = *in_BX + (char)in_CX;
  cVar2 = (char)(in_AX >> 8);
  unaff_DI[unaff_BP] = unaff_DI[unaff_BP] + cVar2;
  *(undefined2 *)(in_BX + unaff_SI) = in_stack_00000000;
  iVar1 = CONCAT11(cVar2,*(undefined1 *)0xef00);
  *(int *)(iVar1 + -2) = iVar1;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


