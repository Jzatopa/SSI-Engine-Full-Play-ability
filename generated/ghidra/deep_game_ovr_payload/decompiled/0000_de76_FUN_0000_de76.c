
void __stdcall16far FUN_0000_de76(void)

{
  undefined1 uVar3;
  int in_AX;
  uint uVar1;
  int iVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  if (in_AX == 3) {
    uVar1 = FUN_0000_e1ea(10);
    if (uVar1 < 8) {
      iVar2 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar2 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x31),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar2);
    }
  }
  else if (in_AX == 4) {
    uVar1 = FUN_0000_e1ea(10);
    if (uVar1 < 8) {
      iVar2 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar2 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x35),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar2);
    }
  }
  else if ((in_AX == 5) && (uVar1 = FUN_0000_e1ea(10), uVar1 < 8)) {
    iVar2 = *(byte *)(unaff_BP + -2) + 4;
    uVar3 = (undefined1)((uint)iVar2 >> 8);
    FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x36),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar2
                 );
  }
  while( true ) {
    if (*(char *)(unaff_BP + -2) == '\x04') {
      return;
    }
    *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
    uVar1 = FUN_0000_e1ea(10);
    if (4 < uVar1) break;
    iVar2 = FUN_0000_e1ea(3);
    if (iVar2 == 0) {
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
    else if (iVar2 == 1) {
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
    else if ((iVar2 == 2) && (uVar1 = FUN_0000_e1ea(10), uVar1 < 8)) {
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
  }
  FUN_0000_dded();
  return;
}


