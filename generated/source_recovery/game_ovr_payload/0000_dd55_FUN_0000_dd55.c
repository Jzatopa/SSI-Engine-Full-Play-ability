/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:dd55
 * Ghidra name: FUN_0000_dd55
 * Linear address: 0x0DD55
 * Original GAME.OVR file offset: 56669
 * Body addresses: 153
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_dd55(void)

{
  undefined1 uVar3;
  int in_AX;
  uint uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined1 in_ZF;
  
  do {
    if ((bool)in_ZF) {
      uVar1 = FUN_0000_e1ea(10);
      if (uVar1 < 8) {
        iVar2 = *(byte *)(unaff_BP + -2) + 4;
        uVar3 = (undefined1)((uint)iVar2 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x31),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar2);
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 5) {
          iVar2 = *(byte *)(unaff_BP + -2) + 3;
          uVar3 = (undefined1)((uint)iVar2 >> 8);
          FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2))
                        ,iVar2);
        }
      }
    }
    else if ((in_AX == 2) && (uVar1 = FUN_0000_e1ea(10), uVar1 < 8)) {
      iVar2 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar2 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x32),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar2);
      uVar1 = FUN_0000_e1ea(10);
      if (uVar1 < 5) {
        iVar2 = *(byte *)(unaff_BP + -2) + 3;
        uVar3 = (undefined1)((uint)iVar2 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar2);
      }
    }
    while( true ) {
      if (*(char *)(unaff_BP + -2) == '\x04') {
        return;
      }
      *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
      uVar1 = FUN_0000_e1ea(10);
      if (4 < uVar1) {
        FUN_0000_dded();
        return;
      }
      in_AX = FUN_0000_e1ea(3);
      if (in_AX != 0) break;
      uVar1 = FUN_0000_e1ea(10);
      if (uVar1 < 8) {
        iVar2 = *(byte *)(unaff_BP + -2) + 4;
        uVar3 = (undefined1)((uint)iVar2 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2e),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar2);
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 5) {
          iVar2 = *(byte *)(unaff_BP + -2) + 3;
          uVar3 = (undefined1)((uint)iVar2 >> 8);
          FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2))
                        ,iVar2);
        }
      }
    }
    in_ZF = in_AX == 1;
  } while( true );
}


