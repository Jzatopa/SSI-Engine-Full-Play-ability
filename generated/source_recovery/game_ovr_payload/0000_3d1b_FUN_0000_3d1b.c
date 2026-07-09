/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:3d1b
 * Ghidra name: FUN_0000_3d1b
 * Linear address: 0x03D1B
 * Original GAME.OVR file offset: 15651
 * Body addresses: 739
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_3d1b(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 unaff_CS;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 unaff_DS;
  uint local_7;
  int iStack_5;
  undefined1 local_3;
  
  uVar4 = *(undefined2 *)0x57fb;
  uVar7 = *(undefined2 *)0x57fd;
  *(undefined2 *)0x536a = uVar4;
  *(undefined2 *)0x536c = uVar7;
  *(undefined1 *)0x74aa = 1;
  *(undefined1 *)0x8c34 = 0;
  *(undefined1 *)0x3de0 = 0;
  *(undefined1 *)0x3de1 = 0;
  *(undefined1 *)0x3dde = 0;
  *(undefined1 *)0x3ddf = 0;
  *(undefined1 *)0x8c3d = 1;
  *(undefined1 *)0x3ddd = 0;
  if (*(char *)((int)*(undefined4 *)0x4418 + 0xf2) == '\0') {
    *(undefined1 *)0x8c3d = 0;
    if (*(char *)0x443a == '\0') {
      *(undefined1 *)0x8c30 = 0x10;
      *(undefined1 *)0x4438 = 4;
      unaff_CS = 0xaf;
      uVar4 = FUN_0000_0b1a();
    }
    else {
      *(undefined1 *)0x8c30 = 0x18;
      *(undefined1 *)0x4438 = 4;
    }
    uVar5 = (undefined1)((uint)uVar4 >> 8);
  }
  else {
    uVar5 = (undefined1)((uint)uVar4 >> 8);
    *(undefined1 *)0x8c30 = *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf2);
  }
  uVar4 = CONCAT11(uVar5,*(undefined1 *)0x8c30);
  cVar3 = func_0x000006e4(unaff_CS,uVar4);
  if (cVar3 != '\0') {
    func_0x000006df(0x6b);
  }
  uVar7 = 0x6b;
  FUN_0000_3bdd(*(undefined2 *)0x4430);
  if (*(char *)0x443a != '\0') {
    iStack_5 = *(int *)0x5801;
    local_7 = *(int *)0x57ff;
    while (local_7 != 0 || iStack_5 != 0) {
      *(int *)0x57fb = local_7;
      *(int *)0x57fd = iStack_5;
      iVar1 = *(int *)(local_7 + 0xff);
      iStack_5 = *(int *)(local_7 + 0x101);
      uVar5 = (undefined1)((uint)iVar1 >> 8);
      FUN_0000_065a(uVar7,CONCAT11(uVar5,1),CONCAT11(uVar5,1));
      uVar7 = 99;
      local_7 = iVar1;
    }
    return;
  }
  if (*(char *)0x3ddd == '\0') {
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf2) = *(undefined1 *)0x8c30;
  }
  else {
    FUN_0000_3c29();
  }
  if ((*(char *)0x4438 != '\x03') && (*(char *)0x4441 != '\0')) {
    uVar6 = uVar7;
    if (*(char *)0x8c3d == '\x01') {
      uVar6 = 0x99;
      FUN_0000_0a2d(0x6b);
    }
    *(undefined1 *)0x74aa = 1;
    uVar7 = 0xb5;
    FUN_0000_0b75(uVar6);
  }
  *(undefined1 *)0x4441 = 0;
  *(undefined1 *)0x8c3f = 0;
LAB_0000_3e4d:
  uVar8 = 0x5f;
  local_3 = func_0x0000061a(uVar7);
  uVar6 = *(undefined2 *)0x57fb;
  uVar7 = *(undefined2 *)0x57fd;
  *(undefined2 *)0x536a = uVar6;
  *(undefined2 *)0x536c = uVar7;
  if (*(char *)0x3ddd == '\0') {
    uVar6 = CONCAT11((char)((uint)uVar6 >> 8),*(undefined1 *)0x8c30);
    *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf2) = *(undefined1 *)0x8c30;
  }
LAB_0000_3e76:
  uVar7 = uVar8;
  if (*(byte *)((int)*(undefined4 *)0x441c + 0x2ca) < 2) {
    uVar7 = 0xcc0;
    cVar3 = FUN_0000_e854(CONCAT11((char)((uint)uVar6 >> 8),local_3),uVar4);
    if (cVar3 != 'E') goto LAB_0000_3ef6;
  }
  if (*(char *)0x4446 != '\0') goto LAB_0000_3ef6;
  *(byte *)0x8c31 = *(byte *)((int)*(undefined4 *)0x441c + 0x2ca) & 1;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2ca) = 1;
  *(undefined1 *)0x74aa = 1;
  uVar8 = 0xb5;
  FUN_0000_0b75(uVar7);
  FUN_0000_3bdd(*(undefined2 *)0x442a);
  uVar5 = extraout_AH;
  if (*(char *)0x3ddd != '\0') {
    FUN_0000_3c29();
    uVar5 = extraout_AH_00;
  }
  uVar6 = CONCAT11(uVar5,*(undefined1 *)0x8c31);
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2ca) = *(undefined1 *)0x8c31;
  if (*(char *)0x4446 == '\0') {
    uVar8 = 0x5f;
    local_3 = func_0x0000061a(0xb5);
    uVar6 = *(undefined2 *)0x57fb;
    uVar7 = *(undefined2 *)0x57fd;
    *(undefined2 *)0x536a = uVar6;
    *(undefined2 *)0x536c = uVar7;
  }
  goto LAB_0000_3e76;
LAB_0000_3ef6:
  if (*(char *)0x4446 == '\0') {
    FUN_0000_3bdd(*(undefined2 *)0x4428);
  }
  if (*(char *)0x3ddd == '\0') {
    if (*(char *)0x4446 == '\0') {
      *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf0) = *(undefined1 *)0x7369;
      *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf1) = *(undefined1 *)0x736a;
      uVar6 = 0x5f;
      FUN_0000_0615(uVar7);
      if ((*(char *)((int)*(undefined4 *)0x4418 + 0xe6) != -0x5e) &&
         (*(char *)((int)*(undefined4 *)0x4418 + 0xe6) != -0x58)) {
        uVar6 = 0xb5;
        FUN_0000_0b75(0x5f);
      }
      uVar7 = uVar6;
      if ((*(char *)0x4438 == '\x04') &&
         (((int)*"s\x15 at sensor operation!\x0eShip Character\x01" !=
           (uint)*(byte *)((int)*(undefined4 *)0x4418 + 0xf0) ||
          ((int)*"\x15 at sensor operation!\x0eShip Character\x01" !=
           (uint)*(byte *)((int)*(undefined4 *)0x4418 + 0xf1))))) {
        uVar7 = 0x784;
        FUN_0000_7840(uVar6,*(undefined2 *)0x233e);
      }
      *(undefined1 *)0x8c33 = 0;
      FUN_0000_3bdd(*(undefined2 *)0x442a);
      if (*(char *)0x3ddd != '\0') {
        FUN_0000_3c29();
      }
    }
  }
  else {
    FUN_0000_3c29();
  }
  if (*(char *)0x4446 != '\0') {
    *(undefined1 *)0x4446 = 0;
    iStack_5 = *(int *)0x5801;
    local_7 = *(uint *)0x57ff;
    while (local_7 != 0 || iStack_5 != 0) {
      *(uint *)0x57fb = local_7;
      *(int *)0x57fd = iStack_5;
      uVar2 = *(uint *)(local_7 + 0xff);
      iStack_5 = *(int *)(local_7 + 0x101);
      FUN_0000_065a(uVar7,CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00);
      uVar7 = 99;
      local_7 = uVar2;
    }
    return;
  }
  goto LAB_0000_3e4d;
}


