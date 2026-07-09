
void __stdcall16far FUN_0000_dd3d(void)

{
  uint uVar1;
  undefined1 uVar3;
  uint in_AX;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  do {
    iVar2 = (in_AX & 0xff) + 3;
    uVar3 = (undefined1)((uint)iVar2 >> 8);
    FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2
                 );
    do {
      do {
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
          iVar2 = FUN_0000_e1ea(3);
          if (iVar2 == 0) break;
          if (iVar2 == 1) {
            uVar1 = FUN_0000_e1ea(10);
            if (uVar1 < 8) {
              iVar2 = *(byte *)(unaff_BP + -2) + 4;
              uVar3 = (undefined1)((uint)iVar2 >> 8);
              FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x31),
                            CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
              uVar1 = FUN_0000_e1ea(10);
              if (uVar1 < 5) {
                iVar2 = *(byte *)(unaff_BP + -2) + 3;
                uVar3 = (undefined1)((uint)iVar2 >> 8);
                FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),
                              CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
              }
            }
          }
          else if ((iVar2 == 2) && (uVar1 = FUN_0000_e1ea(10), uVar1 < 8)) {
            iVar2 = *(byte *)(unaff_BP + -2) + 4;
            uVar3 = (undefined1)((uint)iVar2 >> 8);
            FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x32),
                          CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
            uVar1 = FUN_0000_e1ea(10);
            if (uVar1 < 5) {
              iVar2 = *(byte *)(unaff_BP + -2) + 3;
              uVar3 = (undefined1)((uint)iVar2 >> 8);
              FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),
                            CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2);
            }
          }
        }
        uVar1 = FUN_0000_e1ea(10);
      } while (7 < uVar1);
      iVar2 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar2 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2e),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar2);
      uVar1 = FUN_0000_e1ea(10);
    } while (4 < uVar1);
    in_AX = (uint)*(byte *)(unaff_BP + -2);
  } while( true );
}


