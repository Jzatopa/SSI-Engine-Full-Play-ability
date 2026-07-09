/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:47f6
 * Ghidra name: FUN_0000_47f6
 * Linear address: 0x047F6
 * Original GAME.OVR file offset: 18430
 * Body addresses: 285
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_47f6(undefined2 param_1,undefined2 param_2,char param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 uVar7;
  uint uVar5;
  int iVar6;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  byte *local_12;
  byte local_9;
  int local_6;
  int local_4;
  
  uVar1 = *(undefined2 *)0x44ce;
  uVar2 = *(undefined2 *)0x44d0;
  *(undefined2 *)0x44ce = 0;
  *(undefined2 *)0x44d0 = 0;
  if (param_3 < '\0') {
    unaff_CS = 0x99;
    param_3 = FUN_0000_09ba();
  }
  uVar3 = FUN_0000_09ba(unaff_CS,8,1);
  iVar4 = 7 - (int)((uVar3 & 0xff) - 1) / 2;
  uVar7 = (undefined1)((uint)iVar4 >> 8);
  uVar5 = FUN_0000_09ba(0x99,CONCAT11(uVar7,3),CONCAT11(uVar7,1));
  iVar6 = (uVar5 & 0xff) - 2;
  uVar7 = (undefined1)((uint)iVar6 >> 8);
  uVar5 = FUN_0000_09ba(0x99,CONCAT11(uVar7,3),CONCAT11(uVar7,1));
  if ((param_3 == '\x01') || (param_3 == '\x02')) {
    local_9 = 2;
  }
  else if (param_3 == '\x06') {
    local_9 = 1;
  }
  else {
    local_9 = 3;
  }
  _local_12 = (byte *)CONCAT22(unaff_DS,(byte *)((uint)local_9 * 6 + 0x253a));
  local_4 = ((uVar3 & 0xff) + 8 + iVar6) - (uint)(*(byte *)((uint)local_9 * 6 + 0x253b) >> 1);
  local_6 = (iVar4 + ((uVar5 & 0xff) - 2)) - (uint)(*_local_12 >> 4);
  if (local_4 < 0) {
    local_4 = 0;
  }
  if (local_6 < 0) {
    local_6 = 0;
  }
  if (0 < (int)((undefined *)&DAT_0000_fff5 + (uint)(*_local_12 >> 3) + local_6)) {
    local_6 = local_6 - (int)((undefined *)&DAT_0000_fff5 + (uint)(*_local_12 >> 3) + local_6);
  }
  *(undefined1 *)0x7817 = 4;
  iVar4 = ((uint)local_9 + *(char *)0x7817 * 3) * 6;
  FUN_0000_444d(0x99,0x44ce);
  uVar3 = *(char *)(iVar4 + 0x253f) + local_6;
  iVar6 = ((uint)local_9 + *(char *)0x7817 * 3) * 4;
  uVar11 = *(undefined2 *)(iVar6 + 0x52d8);
  uVar10 = *(undefined2 *)(iVar6 + 0x52d6);
  uVar9 = *(undefined2 *)0x44cc;
  uVar8 = *(undefined2 *)0x44ca;
  FUN_0000_2e9a(uVar8,uVar9,uVar10,uVar11,CONCAT11((char)(uVar3 >> 8),5),uVar3 & 0xff00,uVar3,
                *(char *)(iVar4 + 0x253e) + local_4);
  FUN_0000_39b7();
  FUN_0000_c05c(0x3c,uVar8,uVar9,uVar10,uVar11);
  uVar5 = *(char *)(iVar4 + 0x253f) + local_6;
  uVar3 = uVar5 >> 8;
  FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x44ce,
                *(undefined2 *)0x44d0,uVar3 << 8,uVar3 << 8,uVar5,
                *(char *)(iVar4 + 0x253e) + local_4);
  FUN_0000_453c(0x44ce);
  if (*(char *)0x7817 == '\0') {
    FUN_0000_39b7();
    *(undefined2 *)0x44ce = uVar1;
    *(undefined2 *)0x44d0 = uVar2;
    return;
  }
  FUN_0000_4913();
  return;
}


