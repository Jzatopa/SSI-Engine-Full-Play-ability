/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:defd
 * Ghidra name: FUN_0000_defd
 * Linear address: 0x0DEFD
 * Original GAME.OVR file offset: 57093
 * Body addresses: 95
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_defd(void)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  *(undefined1 *)(unaff_BP + -2) = 2;
  while( true ) {
    uVar1 = FUN_0000_e1ea(10);
    if (uVar1 < 8) {
      iVar2 = FUN_0000_e1ea(2);
      if (iVar2 == 0) {
        iVar2 = *(byte *)(unaff_BP + -2) + 4;
        uVar3 = (undefined1)((uint)iVar2 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2d),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar2);
      }
      else if (iVar2 == 1) {
        iVar2 = *(byte *)(unaff_BP + -2) + 4;
        uVar3 = (undefined1)((uint)iVar2 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x36),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar2);
      }
    }
    if (*(char *)(unaff_BP + -2) == '\x04') break;
    *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
  }
  return;
}


