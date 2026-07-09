/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:3bb8
 * Ghidra name: FUN_3000_3bb8
 * Linear address: 0x33BB8
 * Original GAME.OVR file offset: 211904
 * Body addresses: 368
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_3bb8(int param_1,char param_2)

{
  undefined2 in_AX;
  undefined1 uVar4;
  uint uVar1;
  uint uVar2;
  undefined1 extraout_AH;
  int iVar3;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 extraout_AH_03;
  undefined1 extraout_AH_04;
  undefined1 extraout_AH_05;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined1 local_3;
  
  uVar4 = (undefined1)((uint)in_AX >> 8);
  iVar3 = CONCAT11(uVar4,param_2);
  if (param_2 == '\0') {
    local_3 = -1;
  }
  else if (param_2 == '\x01') {
    iVar3 = *(byte *)(param_1 + -1) + 4;
    local_3 = (char)iVar3;
  }
  else if (param_2 == '\x02') {
    local_3 = *(char *)(param_1 + 8);
    iVar3 = CONCAT11(uVar4,local_3);
  }
  else if (param_2 == '\x03') {
    local_3 = *(char *)(param_1 + 6);
    iVar3 = CONCAT11(uVar4,local_3);
  }
  uVar4 = (undefined1)((uint)iVar3 >> 8);
  uVar5 = local_3 == '\0';
  if (-1 < local_3) {
    uVar1 = (uint)local_3;
    uVar2 = uVar1 + *(uint *)0x26ba;
    uVar5 = ((int)uVar1 >> 0xf) + (uint)CARRY2(uVar1,*(uint *)0x26ba) == 0;
    uVar1 = uVar2 >> 8;
    FUN_3000_3a49(uVar1 << 8,uVar1 << 8,uVar2,CONCAT11(uVar4,*(undefined1 *)(param_1 + 0xe)),
                  CONCAT11(uVar4,*(undefined1 *)(param_1 + 0x10)));
  }
  uVar6 = 0x28a;
  FUN_0000_d977();
  uVar4 = extraout_AH;
  if (!(bool)uVar5) {
    iVar3 = *(char *)(param_1 + 0x10) + 2;
    uVar1 = *(int *)0x26ba + 10;
    uVar5 = uVar1 == 0;
    FUN_3000_3a49((uVar1 >> 8) << 8,(uVar1 >> 8) << 8,uVar1,
                  CONCAT11((char)((uint)iVar3 >> 8),*(undefined1 *)(param_1 + 0xe)),iVar3);
    uVar4 = extraout_AH_00;
  }
  FUN_0000_d977(0xcc0,0x2aa,0xcc0,CONCAT11(uVar4,local_3),uVar6);
  uVar4 = extraout_AH_01;
  if (!(bool)uVar5) {
    iVar3 = *(char *)(param_1 + 0x10) + -2;
    uVar1 = *(int *)0x26ba + 10;
    uVar5 = uVar1 == 0;
    FUN_3000_3a49((uVar1 >> 8) << 8,(uVar1 >> 8) << 8,uVar1,
                  CONCAT11((char)((uint)iVar3 >> 8),*(undefined1 *)(param_1 + 0xe)),iVar3);
    uVar4 = extraout_AH_02;
  }
  FUN_0000_d977(0xcc0,0x2ca,0xcc0,CONCAT11(uVar4,local_3));
  uVar4 = extraout_AH_03;
  if (!(bool)uVar5) {
    uVar1 = *(int *)0x26ba + 0xb;
    uVar5 = uVar1 == 0;
    FUN_3000_3a49((uVar1 >> 8) << 8,(uVar1 >> 8) << 8,uVar1,*(char *)(param_1 + 0xe) + 2,
                  CONCAT11(extraout_AH_03,*(undefined1 *)(param_1 + 0x10)));
    uVar4 = extraout_AH_04;
  }
  FUN_0000_d977(0xcc0,0x2ea,0xcc0,CONCAT11(uVar4,local_3));
  if (!(bool)uVar5) {
    uVar1 = *(int *)0x26ba + 0xbU >> 8;
    FUN_3000_3a49(uVar1 << 8,uVar1 << 8,*(int *)0x26ba + 0xbU,*(char *)(param_1 + 0xe) + -2,
                  CONCAT11(extraout_AH_05,*(undefined1 *)(param_1 + 0x10)));
  }
  if (*(char *)(param_1 + -1) == '\0') {
    *(char *)(param_1 + 0x10) = *(char *)(param_1 + 0x10) + '\x01';
  }
  else {
    *(char *)(param_1 + 0xe) = *(char *)(param_1 + 0xe) + '\x01';
  }
  *(char *)(param_1 + -2) = *(char *)(param_1 + -2) + -1;
  return;
}


