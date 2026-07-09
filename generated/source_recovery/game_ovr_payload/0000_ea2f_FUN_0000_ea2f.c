/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:ea2f
 * Ghidra name: FUN_0000_ea2f
 * Linear address: 0x0EA2F
 * Original GAME.OVR file offset: 59959
 * Body addresses: 779
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_ea2f(char param_1,byte param_2)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  undefined1 uVar7;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined1 extraout_DH;
  undefined1 *puVar8;
  undefined2 uVar9;
  uint uVar10;
  undefined2 unaff_DS;
  undefined2 uVar11;
  undefined2 uVar12;
  uint uVar13;
  undefined1 *local_1c;
  undefined1 in_stack_0000ffea;
  undefined1 in_stack_0000ffec;
  byte local_b;
  byte local_a;
  char local_9;
  char local_8;
  byte local_7;
  byte local_6;
  char local_4;
  char local_3;
  
  _local_1c = (undefined1 *)CONCAT22(unaff_DS,(undefined1 *)((uint)param_2 * 0xb + 0x7c7));
  uVar7 = (undefined1)((uint)param_2 * 0xb >> 8);
  if (param_1 != '\0') {
    local_3 = '\x01';
    while( true ) {
      uVar4 = FUN_0000_09b5(CONCAT11(uVar7,*_local_1c));
      if ((char)uVar4 != '\0') {
        uVar9 = (undefined2)((ulong)_local_1c >> 0x10);
        puVar8 = (undefined1 *)_local_1c;
        uVar13 = (uint)(byte)puVar8[2];
        uVar12 = 0x99;
        uVar11 = 0xea8b;
        uVar5 = FUN_0000_09ba(0x99,uVar13,puVar8[1]);
        local_4 = (char)uVar5;
        bVar1 = true;
        local_6 = puVar8[4];
        uVar4 = CONCAT11((char)((uint)uVar5 >> 8),puVar8[6]) & 0xff10;
        uVar7 = (undefined1)(uVar4 >> 8);
        if ((char)uVar4 == '\0') {
          uVar4 = FUN_0000_09ba(0x99,CONCAT11(uVar7,0x32),CONCAT11(uVar7,1));
          iVar6 = (uVar4 & 0xff) - 1;
          *(undefined1 *)0x4018 = (char)iVar6;
          uVar7 = (undefined1)((uint)iVar6 >> 8);
          uVar13 = CONCAT11(uVar7,1);
          uVar12 = CONCAT11(uVar7,0x19);
          uVar11 = 0x99;
          uVar4 = FUN_0000_09ba(0x99,uVar12,uVar13);
          uVar4 = (uVar4 & 0xff) - 1;
          *(undefined1 *)0x4019 = (char)uVar4;
        }
        if (puVar8[5] != '\0') {
          uVar7 = (undefined1)(uVar4 >> 8);
          uVar13 = 0x99;
          uVar12 = 0xeaef;
          uVar4 = FUN_0000_09ba(0x99,CONCAT11(uVar7,puVar8[5]),CONCAT11(uVar7,1));
          local_6 = local_6 + (char)uVar4;
        }
        uVar10 = 0x99;
        if ('\0' < *(char *)0x401a) {
          local_6 = *(byte *)0x401a;
          uVar4 = CONCAT11((char)(uVar4 >> 8),local_6);
        }
        for (; local_4 != '\0'; local_4 = local_4 + -1) {
          puVar8 = (undefined1 *)_local_1c;
          uVar5 = (undefined2)((ulong)_local_1c >> 0x10);
          if ((bVar1) ||
             (uVar4 = CONCAT11((char)(uVar4 >> 8),puVar8[6]) & 0xff02, (char)uVar4 == '\0')) {
            cVar2 = puVar8[7];
            uVar7 = (undefined1)(uVar4 >> 8);
            iVar6 = CONCAT11(uVar7,cVar2);
            if (puVar8[9] == '\0') {
              local_7 = 0;
            }
            else {
              uVar12 = 0xeb42;
              uVar13 = uVar10;
              uVar4 = FUN_0000_09ba(uVar10,CONCAT11(uVar7,puVar8[9]),CONCAT11(uVar7,1));
              iVar6 = (uVar4 & 0xff) - 1;
              local_7 = (byte)iVar6;
              uVar10 = 0x99;
            }
            uVar4 = CONCAT11((char)((uint)iVar6 >> 8),puVar8[6]) & 0xff08;
            if ((char)uVar4 != '\0') {
              uVar4 = (uint)local_7 << 1;
              local_7 = (byte)uVar4;
            }
            uVar7 = (undefined1)(uVar4 >> 8);
            local_8 = cVar2 + local_7;
            local_9 = puVar8[8];
            uVar4 = CONCAT11(uVar7,local_9);
            if (puVar8[8] != '\x06') {
              uVar4 = CONCAT11(uVar7,puVar8[6]) & 0xff04;
              uVar7 = (undefined1)(uVar4 >> 8);
              if ((char)uVar4 == '\0') {
                if (puVar8[10] == '\0') {
                  local_7 = 0;
                }
                else {
                  uVar12 = 0xebae;
                  uVar13 = uVar10;
                  uVar4 = FUN_0000_09ba(uVar10,CONCAT11(uVar7,puVar8[10]),CONCAT11(uVar7,1));
                  uVar4 = (uVar4 & 0xff) - 1;
                  local_7 = (byte)uVar4;
                  uVar10 = 0x99;
                }
                uVar4 = CONCAT11((char)(uVar4 >> 8),puVar8[6]) & 0xff08;
                if ((char)uVar4 != '\0') {
                  uVar4 = (uint)local_7 << 1;
                  local_7 = (byte)uVar4;
                }
                uVar4 = CONCAT11((char)(uVar4 >> 8),local_7);
                local_9 = local_9 + local_7;
              }
              else {
                uVar4 = CONCAT11(uVar7,local_7);
                local_9 = local_9 + local_7;
              }
            }
            bVar1 = false;
          }
          if (local_6 == 0) {
            local_a = *(byte *)0x4018;
            local_b = *(byte *)0x4019;
          }
          else {
            uVar4 = CONCAT11((char)(uVar4 >> 8),puVar8[6]) & 0xff20;
            if ((char)uVar4 == '\0') {
              FUN_0000_09ba(uVar10,local_6 + 1,CONCAT11((char)(uVar4 >> 8),1));
              uVar13 = 0x99;
              uVar12 = 0xec20;
              func_0x0000dd51(0x99);
            }
            else {
              func_0x0000dd51(uVar10);
            }
            uVar9 = 0xcc0;
            uVar5 = 0xec2e;
            FUN_0000_e200();
            _local_1c = (undefined1 *)CONCAT22(0xec3a,puVar8);
            FUN_0000_dd3d(in_stack_0000ffea);
            FUN_0000_dd3d(in_stack_0000ffec);
            in_stack_0000ffec = 0xc0;
            in_stack_0000ffea = 0x5f;
            func_0x0000de63(0xc0,extraout_DH);
            FUN_0000_dd3d(uVar11);
            cVar2 = FUN_0000_dd55(uVar12);
            uVar11 = 0xec83;
            FUN_0000_de76(uVar13);
            uVar12 = 0xec91;
            FUN_0000_dd3d(uVar5);
            uVar10 = 0xcc0;
            cVar3 = FUN_0000_dd55(uVar9);
            local_a = cVar2 + *(char *)0x4018;
            local_b = cVar3 + *(char *)0x4019;
          }
          uVar13 = 0xecb8;
          uVar4 = FUN_0000_e8ed(&stack0xfffe);
          if ((char)uVar4 != '\0') {
            uVar4 = (uint)local_b * 0x32;
            *(char *)((int)*(undefined4 *)0x71dc + uVar4 + (uint)local_a + 7) = local_8;
            if (local_9 != '\x06') {
              uVar4 = CONCAT11((char)(uVar4 >> 8),((undefined1 *)_local_1c)[6]) & 0xff01;
              if ((char)uVar4 == '\0') {
                local_a = local_a + 1;
              }
              else {
                local_b = local_b + 1;
              }
              if ((local_b < 0x19) && (local_a < 0x32)) {
                uVar4 = (uint)local_b * 0x32;
                *(char *)((int)*(undefined4 *)0x71dc + uVar4 + (uint)local_a + 7) = local_9;
              }
            }
          }
        }
      }
      uVar7 = (undefined1)(uVar4 >> 8);
      if (local_3 == param_1) break;
      local_3 = local_3 + '\x01';
    }
  }
  return;
}


