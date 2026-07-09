/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:f542
 * Ghidra name: FUN_0000_f542
 * Linear address: 0x0F542
 * Original GAME.OVR file offset: 62794
 * Body addresses: 1150
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

bool __stdcall16far FUN_0000_f542(undefined1 param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  char cVar9;
  int iVar10;
  undefined1 uVar11;
  undefined2 unaff_DS;
  char local_1a;
  char local_19;
  char local_18;
  char local_17;
  byte local_16;
  byte local_15;
  char local_14;
  char local_13;
  byte local_12;
  byte local_11;
  byte local_c;
  byte local_9;
  char local_4;
  
  bVar6 = true;
  bVar7 = false;
  local_9 = 1;
  local_11 = 0;
  local_16 = 0;
  local_13 = *(char *)(*(char *)0x400a + 0x3ffc);
  local_14 = *(char *)(*(char *)0x400a + 0x3ffe);
  do {
    bVar4 = *(byte *)(*(char *)(*(char *)0x400a + 0x4002) * 4 + (uint)local_16 + 0x6fa) >> 1;
    iVar10 = 0;
    if (local_9 == 1) {
      local_19 = *(char *)((local_16 != 0) * 4 + (uint)bVar4 + 0x70e) +
                 ((undefined *)&DAT_0000_26ca)
                 [*(byte *)((int)((ulong)(long)(int)(bVar4 + 2) % 4) + 0x70a)] * local_11;
      iVar10 = (int)*(char *)((local_16 != 0) * 4 + (uint)bVar4 + 0x716) +
               (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)((bVar4 + 2) % 4 + 0x70a)] *
               (uint)local_11;
      local_1a = (char)iVar10;
      local_12 = 1;
      local_9 = 2;
      local_15 = 1;
      local_18 = local_1a;
      local_17 = local_19;
    }
    else if (local_9 == 2) {
      local_19 = local_17 +
                 ((undefined *)&DAT_0000_26ca)
                 [*(byte *)((int)((ulong)(long)(int)(bVar4 + 1) % 4) + 0x70a)] * local_12;
      iVar10 = (int)local_18 +
               (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)((bVar4 + 1) % 4 + 0x70a)] *
               (uint)local_12;
      local_1a = (char)iVar10;
      local_9 = 3;
      local_15 = local_15 + 1;
    }
    else if (local_9 == 3) {
      local_19 = local_17 +
                 ((undefined *)&DAT_0000_26ca)
                 [*(byte *)((int)((ulong)(long)(int)(bVar4 + 3) % 4) + 0x70a)] * local_12;
      iVar10 = (int)local_18 +
               (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)((bVar4 + 3) % 4 + 0x70a)] *
               (uint)local_12;
      local_1a = (char)iVar10;
      local_9 = 2;
      local_12 = local_12 + 1;
      local_15 = local_15 + 1;
    }
    if ((((local_19 < '\0') || (local_1a < '\0')) || ('\n' < local_19)) || ('\x05' < local_1a)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    if ((1 < local_9) &&
       ((((bVar5 && (uVar11 = (undefined1)((uint)iVar10 >> 8),
                    cVar9 = FUN_0000_f38e(CONCAT11(uVar11,local_1a),CONCAT11(uVar11,local_19)),
                    cVar9 == '\0')) ||
         ((bVar6 && ((int)*(char *)(*(char *)0x400a + 0x4000) <= (int)(uint)local_15)))) ||
        ((!bVar6 && (0xb < local_15)))))) {
      bVar4 = local_11 + 1;
      if ((*(char *)0x400a == '\0') &&
         ((((bool)(*(byte *)0x4002 & 1) && (local_16 == 0)) && (bVar4 == 1)))) {
        cVar9 = *"s\x15 at sensor operation!\x0eShip Character\x01";
        cVar2 = *(char *)(*(char *)0x400a + 0x3ffc);
        cVar1 = *"\x15 at sensor operation!\x0eShip Character\x01";
        cVar3 = *(char *)(*(char *)0x400a + 0x3ffe);
        bVar6 = false;
        local_c = 1;
        while( true ) {
          cVar8 = *(char *)(*(char *)0x400a + 0x4002) >> 7;
          if ((*(char *)0x4438 == '\x03') ||
             (cVar8 = FUN_0000_e281(CONCAT11(cVar8,*(undefined1 *)
                                                    (*(char *)(*(char *)0x400a + 0x4002) * 4 +
                                                     (uint)local_c + 0x6ea)),
                                    CONCAT11(cVar8,cVar3 + cVar1),CONCAT11(cVar8,cVar2 + cVar9)),
             cVar8 == '\0')) {
            bVar6 = true;
          }
          if (local_c == 3) break;
          local_c = local_c + 1;
        }
        if (bVar6) {
          bVar4 = local_11 + 2;
        }
      }
      local_11 = bVar4;
      local_9 = 1;
      bVar6 = false;
    }
    if ((bVar5) && (cVar9 = FUN_0000_f38e(local_1a,local_19), cVar9 != '\0')) {
      local_4 = '\0';
      local_9 = 0;
      while ((local_16 < 3 && (local_9 != 1))) {
        local_16 = local_16 + 1;
        bVar4 = *(byte *)(*(char *)(*(char *)0x400a + 0x4002) * 4 + (uint)local_16 + 0x6ea);
        cVar9 = *(char *)(*(char *)0x400a + 0x4002) >> 7;
        if ((*(char *)0x4438 == '\x03') ||
           (cVar9 = FUN_0000_e281(CONCAT11(cVar9,bVar4),
                                  CONCAT11(cVar9,*(char *)(*(char *)0x400a + 0x3ffe) +
                                                 *"\x15 at sensor operation!\x0eShip Character\x01")
                                  ,CONCAT11(cVar9,*(char *)(*(char *)0x400a + 0x3ffc) +
                                                  *
                                                  "s\x15 at sensor operation!\x0eShip Character\x01"
                                           )), cVar9 != '\x01')) {
          local_13 = *(char *)(*(char *)0x400a + 0x3ffc) + ((undefined *)&DAT_0000_26ca)[bVar4];
          local_14 = *(char *)(*(char *)0x400a + 0x3ffe) + ((undefined *)&DAT_0000_26d3)[bVar4];
          local_11 = 0;
          local_9 = 1;
        }
      }
      if (local_9 != 1) {
        bVar7 = true;
      }
    }
    if (!bVar5) {
      local_4 = FUN_0000_f3bf(local_16,local_14,local_13,local_1a,local_19,param_1);
    }
  } while ((local_4 == '\0') && (!bVar7));
  return !bVar7;
}


