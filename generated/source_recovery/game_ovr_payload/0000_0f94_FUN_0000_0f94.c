/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0f94
 * Ghidra name: FUN_0000_0f94
 * Linear address: 0x00F94
 * Original GAME.OVR file offset: 3996
 * Body addresses: 66
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0f94(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar3;
  int iVar4;
  
  if (*(byte *)((int)*(undefined4 *)0x4418 + 0xb6) < 5) {
    *(uint *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xe3) =
         (*(byte *)((int)*(undefined4 *)0x4418 + 0xb6) + 2) *
         *(int *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xe3) >> 2;
    if (*(int *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xe3) == 0) {
      *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xe3) = 1;
    }
    *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0x45) =
         *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -0x10) + 0xe3);
  }
  iVar4 = unaff_BP + -0x117;
  uVar3 = 0x103;
  func_0x0000d5f6();
  uVar1 = *(undefined2 *)(unaff_BP + -0x126);
  *(undefined2 *)(unaff_BP + -0x130) = *(undefined2 *)(unaff_BP + -0x128);
  *(undefined2 *)(unaff_BP + -0x12e) = uVar1;
  uVar1 = *(undefined2 *)(unaff_BP + -0x134);
  uVar2 = *(undefined2 *)(unaff_BP + -0x132);
  *(undefined2 *)(unaff_BP + -0x13c) = uVar1;
  *(undefined2 *)(unaff_BP + -0x13a) = uVar2;
                    /* WARNING: Subroutine does not return */
  FUN_0000_06d5(0xcc0,CONCAT11((char)((uint)uVar1 >> 8),3),uVar3,iVar4);
}


