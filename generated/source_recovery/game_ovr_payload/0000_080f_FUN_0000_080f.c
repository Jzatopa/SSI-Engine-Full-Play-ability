/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:080f
 * Ghidra name: FUN_0000_080f
 * Linear address: 0x0080F
 * Original GAME.OVR file offset: 2071
 * Body addresses: 34
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_080f(void)

{
  int unaff_BP;
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(unaff_BP + 6) + -4;
  FUN_0000_2670();
  FUN_0000_6d0d(0x21a,iVar1);
  uVar3 = 0x10;
  uVar2 = 0xf0;
  FUN_0000_49de(0x99c7,unaff_DS);
  FUN_0000_3721(0x21a,*(undefined2 *)(*(int *)(unaff_BP + 6) + -4),
                *(undefined2 *)(*(int *)(unaff_BP + 6) + -2),0,0,uVar2,uVar3);
  FUN_0000_453c(*(int *)(unaff_BP + 6) + -4);
  return;
}


