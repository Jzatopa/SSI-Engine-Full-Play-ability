/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:e3ed
 * Ghidra name: FUN_0000_e3ed
 * Linear address: 0x0E3ED
 * Original GAME.OVR file offset: 58357
 * Body addresses: 415
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_e3ed(int param_1)

{
  char cVar1;
  int iVar2;
  byte bVar5;
  uint uVar3;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 uVar6;
  undefined2 uVar4;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  byte extraout_AH_04;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte local_5;
  byte local_4;
  byte local_3;
  
  local_5 = *(char *)0x4006 != '\0';
  if (*(char *)0x4007 != '\0') {
    local_5 = local_5 + 2;
  }
  iVar2 = *(char *)(param_1 + -1) + -1;
  bVar5 = (byte)((uint)iVar2 >> 8);
  cVar1 = FUN_0000_e281((uint)bVar5 << 8,CONCAT11(bVar5,*(undefined1 *)(param_1 + -2)),iVar2);
  if (cVar1 != '\0') {
    local_5 = local_5 + 4;
  }
  iVar2 = *(char *)(param_1 + -2) + -1;
  cVar1 = FUN_0000_e281(CONCAT11((char)((uint)iVar2 >> 8),6),iVar2,*(undefined1 *)(param_1 + -1));
  if (cVar1 != '\0') {
    local_5 = local_5 + 8;
  }
  if (local_5 != 0) {
    local_4 = 0;
    while( true ) {
      local_3 = 1;
      while( true ) {
        if (*(char *)((uint)local_5 * 4 + (uint)local_4 * 2 + (uint)local_3 + 0x755) != -1) {
          FUN_0000_db35(*(undefined1 *)
                         ((uint)local_5 * 4 + (uint)local_4 * 2 + (uint)local_3 + 0x755),local_4,
                        local_3);
        }
        if (local_3 == 2) break;
        local_3 = local_3 + 1;
      }
      if (local_4 == 1) break;
      local_4 = local_4 + 1;
    }
  }
  iVar2 = *(char *)(param_1 + -1) + 1;
  bVar5 = (byte)((uint)iVar2 >> 8);
  cVar1 = FUN_0000_e281((uint)bVar5 << 8,CONCAT11(bVar5,*(undefined1 *)(param_1 + -2)),iVar2);
  local_5 = cVar1 != '\0';
  if (*(char *)0x4008 != '\0') {
    local_5 = local_5 + 2;
  }
  if (*(char *)0x4006 != '\0') {
    local_5 = local_5 + 4;
  }
  iVar2 = *(char *)(param_1 + -2) + -1;
  uVar3 = FUN_0000_e281(CONCAT11((char)((uint)iVar2 >> 8),2),iVar2,*(undefined1 *)(param_1 + -1));
  if ((char)uVar3 != '\0') {
    local_5 = local_5 + 8;
  }
  if (local_5 != 0) {
    local_4 = 0;
    while( true ) {
      local_3 = 5;
      while( true ) {
        uVar3 = (uint)local_5;
        if (*(char *)(uVar3 * 4 + (uint)local_4 * 2 + (uint)local_3 + 0x78d) != -1) {
          uVar3 = FUN_0000_db35(*(undefined1 *)
                                 ((uint)local_5 * 4 + (uint)local_4 * 2 + (uint)local_3 + 0x78d),
                                local_4,local_3);
        }
        if (local_3 == 6) break;
        local_3 = local_3 + 1;
      }
      if (local_4 == 1) break;
      local_4 = local_4 + 1;
    }
  }
  bVar5 = (byte)(uVar3 >> 8);
  if (*(char *)0x4006 == '\x03') {
    FUN_0000_db35(CONCAT11(bVar5,0x1e),(uint)bVar5 << 8,CONCAT11(bVar5,2));
    if (*(char *)0x4007 == '\0') {
      FUN_0000_db35(CONCAT11(extraout_AH,0x20),CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,2));
      uVar6 = extraout_AH_00;
    }
    else {
      FUN_0000_db35(CONCAT11(extraout_AH,0x2a),CONCAT11(extraout_AH,1),CONCAT11(extraout_AH,2));
      uVar6 = extraout_AH_01;
    }
    iVar2 = *(char *)(param_1 + -2) + -1;
    uVar4 = FUN_0000_e281(CONCAT11((char)((uint)iVar2 >> 8),2),iVar2,
                          CONCAT11(uVar6,*(undefined1 *)(param_1 + -1)));
    bVar5 = (byte)((uint)uVar4 >> 8);
    if ((char)uVar4 == '\0') {
      FUN_0000_db35(CONCAT11(bVar5,0x1f),(uint)bVar5 << 8,CONCAT11(bVar5,5));
      uVar6 = extraout_AH_02;
    }
    else {
      FUN_0000_db35(CONCAT11(bVar5,0x2b),(uint)bVar5 << 8,CONCAT11(bVar5,5));
      uVar6 = extraout_AH_03;
    }
    FUN_0000_db35(CONCAT11(uVar6,0x21),CONCAT11(uVar6,1),CONCAT11(uVar6,5));
    bVar5 = extraout_AH_04;
  }
  iVar2 = *(char *)(param_1 + -2) + -1;
  uVar4 = FUN_0000_e281(CONCAT11((char)((uint)iVar2 >> 8),2),iVar2,
                        CONCAT11(bVar5,*(undefined1 *)(param_1 + -1)));
  if ((char)uVar4 == '\x03') {
    bVar5 = (byte)((uint)uVar4 >> 8);
    if (*(char *)0x4006 == '\0') {
      FUN_0000_db35(CONCAT11(bVar5,0x27),(uint)bVar5 << 8,CONCAT11(bVar5,5));
    }
    else {
      FUN_0000_db35(CONCAT11(bVar5,0x29),(uint)bVar5 << 8,CONCAT11(bVar5,5));
    }
  }
  return;
}


