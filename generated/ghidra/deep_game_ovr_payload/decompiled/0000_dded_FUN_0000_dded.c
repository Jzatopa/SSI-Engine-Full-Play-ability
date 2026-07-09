
void __stdcall16far FUN_0000_dded(void)

{
  undefined1 uVar3;
  int iVar1;
  uint uVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  
  iVar1 = FUN_0000_e1ea(6);
  if (iVar1 == 0) {
    uVar2 = FUN_0000_e1ea(10);
    if (uVar2 < 8) {
      iVar1 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2d),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar1);
    }
  }
  else if (iVar1 == 1) {
    uVar2 = FUN_0000_e1ea(10);
    if (uVar2 < 8) {
      iVar1 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2e),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar1);
    }
  }
  else if (iVar1 == 2) {
    uVar2 = FUN_0000_e1ea(10);
    if (uVar2 < 8) {
      iVar1 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x30),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar1);
    }
  }
  else if (iVar1 == 3) {
    uVar2 = FUN_0000_e1ea(10);
    if (uVar2 < 8) {
      iVar1 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x31),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar1);
    }
  }
  else if (iVar1 == 4) {
    uVar2 = FUN_0000_e1ea(10);
    if (uVar2 < 8) {
      iVar1 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x35),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar1);
    }
  }
  else if ((iVar1 == 5) && (uVar2 = FUN_0000_e1ea(10), uVar2 < 8)) {
    iVar1 = *(byte *)(unaff_BP + -2) + 4;
    uVar3 = (undefined1)((uint)iVar1 >> 8);
    FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x36),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),iVar1
                 );
  }
  while( true ) {
    if (*(char *)(unaff_BP + -2) == '\x04') {
      return;
    }
    *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
    uVar2 = FUN_0000_e1ea(10);
    if (4 < uVar2) break;
    iVar1 = FUN_0000_e1ea(3);
    if (iVar1 == 0) {
      uVar2 = FUN_0000_e1ea(10);
      if (uVar2 < 8) {
        iVar1 = *(byte *)(unaff_BP + -2) + 4;
        uVar3 = (undefined1)((uint)iVar1 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2e),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar1);
        uVar2 = FUN_0000_e1ea(10);
        if (uVar2 < 5) {
          iVar1 = *(byte *)(unaff_BP + -2) + 3;
          uVar3 = (undefined1)((uint)iVar1 >> 8);
          FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2))
                        ,iVar1);
        }
      }
    }
    else if (iVar1 == 1) {
      uVar2 = FUN_0000_e1ea(10);
      if (uVar2 < 8) {
        iVar1 = *(byte *)(unaff_BP + -2) + 4;
        uVar3 = (undefined1)((uint)iVar1 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x31),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar1);
        uVar2 = FUN_0000_e1ea(10);
        if (uVar2 < 5) {
          iVar1 = *(byte *)(unaff_BP + -2) + 3;
          uVar3 = (undefined1)((uint)iVar1 >> 8);
          FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2))
                        ,iVar1);
        }
      }
    }
    else if ((iVar1 == 2) && (uVar2 = FUN_0000_e1ea(10), uVar2 < 8)) {
      iVar1 = *(byte *)(unaff_BP + -2) + 4;
      uVar3 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x32),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                    iVar1);
      uVar2 = FUN_0000_e1ea(10);
      if (uVar2 < 5) {
        iVar1 = *(byte *)(unaff_BP + -2) + 3;
        uVar3 = (undefined1)((uint)iVar1 >> 8);
        FUN_0000_dbe2(unaff_BP,CONCAT11(uVar3,0x2f),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                      iVar1);
      }
    }
  }
  FUN_0000_dded();
  return;
}


