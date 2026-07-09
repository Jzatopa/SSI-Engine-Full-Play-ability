/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:fb92
 * Ghidra name: FUN_0000_fb92
 * Linear address: 0x0FB92
 * Original GAME.OVR file offset: 64410
 * Body addresses: 925
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - combat_start (combat), previous candidate, distance 926 byte(s), source offset 65336
 */

void __cdecl16far FUN_0000_fb92(void)

{
  undefined1 uVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 unaff_DS;
  undefined2 uVar8;
  undefined *puVar9;
  char local_16;
  char local_15;
  byte local_14;
  byte local_11;
  byte local_b;
  int local_a;
  int iStack_8;
  int local_6;
  int iStack_4;
  
  uVar1 = *(undefined1 *)0x736b;
  local_11 = 0;
  func_0x00000a19();
  for (local_b = 1; ((undefined *)&DAT_0000_69f0)[(uint)local_b * 4] = 0, local_b != 0x48;
      local_b = local_b + 1) {
  }
  puVar9 = (undefined *)&DAT_0000_6ba1;
  uVar8 = 0x4e2;
  FUN_0000_e6d2(0x400);
  *(undefined1 *)0x3ffc = 0;
  *(code *)FUN_0000_3ffe = (code)0x0;
  *(undefined1 *)0x4000 = (char)(*(byte *)0x72c2 + 1 >> 1);
  if ((*(byte *)0x7512 & 0xf) == 0) {
    local_15 = '\x01';
  }
  else {
    local_15 = (*(byte *)0x7512 & 1) != 0;
    if ((*(byte *)0x7512 & 2) != 0) {
      local_15 = local_15 + '\x01';
    }
    if ((*(byte *)0x7512 & 4) != 0) {
      local_15 = local_15 + '\x01';
    }
    if ((*(byte *)0x7512 & 8) != 0) {
      local_15 = local_15 + '\x01';
    }
  }
  *(undefined1 *)0x4001 =
       (char)((ulong)(long)(int)((uint)*(byte *)0x72c3 + (uint)(byte)(local_15 << 1) + -1) /
             (ulong)(byte)(local_15 << 1));
  FUN_0000_f9c0(&stack0xfffe);
  local_b = 1;
  *(undefined *)&DAT_0000_69f0 = 1;
  local_6 = *(int *)0x57ff;
  iStack_4 = *(int *)0x5801;
  iStack_8 = *(int *)0x5801;
  local_a = *(int *)0x57ff;
  uVar7 = 0xcc0;
  while (local_a != 0 || iStack_8 != 0) {
    uVar6 = 0x836;
    func_0x0000874c(uVar7,uVar8,puVar9);
    *(int *)((undefined *)&DAT_0000_707f + (uint)local_b * 4) = local_a;
    *(int *)((undefined *)&DAT_0000_7081 + (uint)local_b * 4) = iStack_8;
    *(undefined1 *)0x400a = *(undefined1 *)(local_a + 0xd6);
    *(byte *)((uint)local_b * 4 + 0x69ef) = local_b;
    ((undefined *)&DAT_0000_69f0)[(uint)local_b * 4] = *(byte *)(local_a + 0x34) & 7;
    if (*(char *)0x7512 != '\0') {
      if (*(char *)(local_a + 0xd6) == '\0') {
        *(undefined1 *)0x736b = uVar1;
      }
      else {
        do {
          local_11 = local_11 + 1 & 3;
        } while (((byte)(1 << local_11) & *(byte *)0x7512) == 0);
        *" at sensor operation!\x0eShip Character\x01" = local_11 << 1;
      }
      FUN_0000_f9c0(&stack0xfffe);
    }
    local_14 = *(byte *)0x736b;
    if (*(char *)(local_a + 0xd6) == '\x01') {
      local_14 = (byte)((ulong)(long)(int)(local_14 + 4) % 8);
    }
    *(undefined1 *)((int)*(undefined4 *)(local_a + 0xf3) + 7) =
         *(undefined1 *)((local_14 >> 1) + 0x70a);
    if ((*(char *)0x8c26 == '\0') || (*(char *)(local_a + 0xd5) != '\0')) {
      local_16 = FUN_0000_f542(local_b);
    }
    else {
      local_16 = '\0';
    }
    if (local_16 == '\0') {
      ((undefined *)&DAT_0000_69f0)[(uint)local_b * 4] = 0;
      if (*(char *)((int)*(undefined4 *)(local_a + 0xf3) + 0xf) == '\x01') {
        *(undefined2 *)((undefined *)&DAT_0000_707f + (uint)local_b * 4) = 0;
        *(undefined2 *)((undefined *)&DAT_0000_7081 + (uint)local_b * 4) = 0;
        *(int *)0x57fb = local_a;
        *(int *)0x57fd = iStack_8;
        bVar5 = (byte)((uint)local_a >> 8);
        uVar6 = 99;
        FUN_0000_065a(0x836,(uint)bVar5 << 8,CONCAT11(bVar5,1));
      }
      else {
        local_6 = local_a;
        iStack_4 = iStack_8;
        local_b = local_b + 1;
        *(char *)&DAT_0000_69f0 = *(char *)&DAT_0000_69f0 + '\x01';
      }
    }
    else {
      local_6 = local_a;
      iStack_4 = iStack_8;
      uVar7 = uVar6;
      if ((*(char *)(local_a + 0xd5) == '\0') &&
         (((undefined *)&DAT_0000_69f0)[(uint)local_b * 4] = 0,
         *(char *)((int)*(undefined4 *)(local_a + 0xf3) + 0xf) == '\0')) {
        cVar2 = ((undefined *)&DAT_0000_69ed)[(uint)local_b * 4];
        cVar3 = ((undefined *)&DAT_0000_69ee)[(uint)local_b * 4];
        *(char *)0x71db = *(char *)0x71db + '\x01';
        uVar4 = FUN_0000_0ddf(0x836,cVar3,cVar2);
        *(undefined1 *)((uint)*(byte *)0x71db * 7 + 0x71a2) = uVar4;
        *(undefined1 *)((int)*(undefined4 *)0x71dc + cVar3 * 0x32 + (int)cVar2 + 7) = 5;
        bVar5 = *(byte *)0x71db;
        *(int *)((uint)bVar5 * 7 + 0x719c) = local_a;
        *(int *)((uint)bVar5 * 7 + 0x719e) = iStack_8;
        *(char *)((uint)*(byte *)0x71db * 7 + 0x71a0) = cVar2;
        *(char *)((uint)*(byte *)0x71db * 7 + 0x71a1) = cVar3;
        uVar7 = 0xdb;
      }
      uVar6 = 0xdb;
      func_0x00000dfd(uVar7);
      local_b = local_b + 1;
      *(char *)&DAT_0000_69f0 = *(char *)&DAT_0000_69f0 + '\x01';
    }
    iStack_8 = *(int *)(local_6 + 0x101);
    uVar7 = uVar6;
    local_a = *(int *)(local_6 + 0xff);
  }
  *(undefined2 *)(local_6 + 0xff) = 0;
  *(undefined2 *)(local_6 + 0x101) = 0;
  *(undefined1 *)0x736b = uVar1;
  return;
}


