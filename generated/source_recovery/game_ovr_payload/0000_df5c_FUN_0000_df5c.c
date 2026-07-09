/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:df5c
 * Ghidra name: FUN_0000_df5c
 * Linear address: 0x0DF5C
 * Original GAME.OVR file offset: 57188
 * Body addresses: 654
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_df5c(void)

{
  undefined1 uVar3;
  uint uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (*(char *)0x4006 == '\x01') {
    if (*(char *)0x400d == '\0') {
      *(undefined1 *)(unaff_BP + -1) = 4;
      while( true ) {
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 8) {
          iVar2 = FUN_0000_e1ea(3);
          if (iVar2 == 0) {
            FUN_0000_dbe2(unaff_BP,0x3e,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 1) {
            FUN_0000_dbe2(unaff_BP,0x42,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 2) {
            FUN_0000_dbe2(unaff_BP,0x43,2,*(undefined1 *)(unaff_BP + -1));
          }
        }
        if (*(char *)(unaff_BP + -1) == '\x06') break;
        *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      }
    }
    else {
      *(undefined1 *)(unaff_BP + -1) = 4;
      while( true ) {
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 8) {
          iVar2 = FUN_0000_e1ea(6);
          if (iVar2 == 0) {
            FUN_0000_dbe2(unaff_BP,0x3b,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 1) {
            FUN_0000_dbe2(unaff_BP,0x3c,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 2) {
            FUN_0000_dbe2(unaff_BP,0x3e,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 3) {
            FUN_0000_dbe2(unaff_BP,0x3f,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 4) {
            FUN_0000_dbe2(unaff_BP,0x42,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 5) {
            FUN_0000_dbe2(unaff_BP,0x44,2,*(undefined1 *)(unaff_BP + -1));
          }
        }
        if (*(char *)(unaff_BP + -1) == '\x06') break;
        *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      }
    }
  }
  if (*(char *)0x4008 == '\x01') {
    if (*(char *)0x400d == '\0') {
      *(undefined1 *)(unaff_BP + -1) = 4;
      while( true ) {
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 8) {
          iVar2 = FUN_0000_e1ea(3);
          if (iVar2 == 0) {
            FUN_0000_dbe2(unaff_BP,0x3e,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 1) {
            FUN_0000_dbe2(unaff_BP,0x42,2,*(undefined1 *)(unaff_BP + -1));
          }
          else if (iVar2 == 2) {
            FUN_0000_dbe2(unaff_BP,0x43,2,*(undefined1 *)(unaff_BP + -1));
          }
        }
        if (*(char *)(unaff_BP + -1) == '\x06') break;
        *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      }
    }
    else {
      *(undefined1 *)(unaff_BP + -2) = 2;
      while( true ) {
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 8) {
          iVar2 = FUN_0000_e1ea(6);
          if (iVar2 == 0) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x3d),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
          }
          else if (iVar2 == 1) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x3e),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
          }
          else if (iVar2 == 2) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x41),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
          }
          else if (iVar2 == 3) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x42),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
          }
          else if (iVar2 == 4) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x43),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
          }
          else if (iVar2 == 5) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x3f),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
            uVar1 = FUN_0000_e1ea(10);
            if (uVar1 < 5) {
              iVar2 = *(byte *)(unaff_BP + -2) + 3;
              uVar3 = (undefined1)((uint)iVar2 >> 8);
              FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x40),
                            CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
            }
          }
        }
        if (*(char *)(unaff_BP + -2) == '\x04') break;
        *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
      }
    }
  }
  return;
}


