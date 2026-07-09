
/* WARNING: Instruction at (ram,0x00000a29) overlaps instruction at (ram,0x00000a28)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0000_09c4(undefined2 param_1)

{
  undefined2 in_AX;
  char cVar2;
  int iVar1;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  cVar2 = (char)((uint)in_AX >> 8);
  *(char *)(unaff_BP + unaff_DI) = *(char *)(unaff_BP + unaff_DI) + cVar2;
  *(undefined2 *)(in_BX + unaff_SI) = param_1;
  iVar1 = CONCAT11(cVar2,*(undefined1 *)0xef00);
  *(int *)(iVar1 + -2) = iVar1;
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


