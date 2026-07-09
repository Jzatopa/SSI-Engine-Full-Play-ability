/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:dc7e
 * Ghidra name: FUN_0000_dc7e
 * Linear address: 0x0DC7E
 * Original GAME.OVR file offset: 56454
 * Body addresses: 191
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_dc7e(undefined2 param_1,byte param_2)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 unaff_DS;
  byte local_4;
  byte local_3;
  
  if ((param_2 & 8) != 0) {
    FUN_0000_df5c();
    return;
  }
  if (*(char *)0x4006 == '\x01') {
    local_3 = 4;
    while( true ) {
      uVar1 = FUN_0000_e1ea(10);
      if (uVar1 < 3) {
        uVar1 = (uint)local_3;
        uVar2 = 2;
        iVar3 = FUN_0000_e1ea(2);
        FUN_0000_dbe2(&stack0xfffe,iVar3 + 0x33,uVar2,uVar1);
      }
      if (local_3 == 6) break;
      local_3 = local_3 + 1;
    }
  }
  if (*(char *)0x4008 == '\x01') {
    if (*(char *)0x400d == '\0') {
      FUN_0000_defd();
      return;
    }
    local_4 = 2;
    while( true ) {
      uVar1 = FUN_0000_e1ea(10);
      if (4 < uVar1) {
        FUN_0000_dded();
        return;
      }
      iVar3 = FUN_0000_e1ea(3);
      if (iVar3 == 0) {
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 8) {
          uVar4 = (undefined1)(local_4 + 4 >> 8);
          FUN_0000_dbe2(&stack0xfffe,CONCAT11(uVar4,0x2e),CONCAT11(uVar4,local_4),local_4 + 4);
          uVar1 = FUN_0000_e1ea(10);
          if (uVar1 < 5) {
            uVar4 = (undefined1)(local_4 + 3 >> 8);
            FUN_0000_dbe2(&stack0xfffe,CONCAT11(uVar4,0x2f),CONCAT11(uVar4,local_4),local_4 + 3);
          }
        }
      }
      else if (iVar3 == 1) {
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 8) {
          uVar4 = (undefined1)(local_4 + 4 >> 8);
          FUN_0000_dbe2(&stack0xfffe,CONCAT11(uVar4,0x31),CONCAT11(uVar4,local_4),local_4 + 4);
          uVar1 = FUN_0000_e1ea(10);
          if (uVar1 < 5) {
            uVar4 = (undefined1)(local_4 + 3 >> 8);
            FUN_0000_dbe2(&stack0xfffe,CONCAT11(uVar4,0x2f),CONCAT11(uVar4,local_4),local_4 + 3);
          }
        }
      }
      else if ((iVar3 == 2) && (uVar1 = FUN_0000_e1ea(10), uVar1 < 8)) {
        uVar4 = (undefined1)(local_4 + 4 >> 8);
        FUN_0000_dbe2(&stack0xfffe,CONCAT11(uVar4,0x32),CONCAT11(uVar4,local_4),local_4 + 4);
        uVar1 = FUN_0000_e1ea(10);
        if (uVar1 < 5) {
          uVar4 = (undefined1)(local_4 + 3 >> 8);
          FUN_0000_dbe2(&stack0xfffe,CONCAT11(uVar4,0x2f),CONCAT11(uVar4,local_4),local_4 + 3);
        }
      }
      if (local_4 == 4) break;
      local_4 = local_4 + 1;
    }
  }
  return;
}


