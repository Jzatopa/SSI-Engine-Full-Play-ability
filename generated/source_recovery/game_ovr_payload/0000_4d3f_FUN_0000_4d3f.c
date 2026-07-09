/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4d3f
 * Ghidra name: FUN_0000_4d3f
 * Linear address: 0x04D3F
 * Original GAME.OVR file offset: 19783
 * Body addresses: 85
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_4d3f(void)

{
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int iVar1;
  
  (*(code *)*(undefined2 *)0xb857)();
  *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + 1;
  func_0x0000d6dc(0);
  if (*(int *)((undefined *)&DAT_0000_fff6 + *(int *)(unaff_BP + 6)) != 0) {
    iVar1 = unaff_BP + -0x106;
    FUN_0000_e390(5);
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(unaff_BP + -0x100,unaff_SS,unaff_BP + -0x206,unaff_SS,iVar1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(unaff_BP + -0x100,unaff_SS,unaff_BP + -0x206,unaff_SS);
}


