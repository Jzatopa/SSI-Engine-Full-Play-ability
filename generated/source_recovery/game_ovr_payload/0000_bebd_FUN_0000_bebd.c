/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:bebd
 * Ghidra name: FUN_0000_bebd
 * Linear address: 0x0BEBD
 * Original GAME.OVR file offset: 48837
 * Body addresses: 415
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_0000_bebd(char *param_1,char param_2,undefined4 param_3)

{
  char *pcVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  char cStack_37;
  undefined1 auStack_35 [4];
  char local_31 [4];
  uint uStack_2d;
  undefined1 uStack_2b;
  byte bStack_2a;
  char cStack_29;
  byte bStack_28;
  char cStack_27;
  char local_26;
  char local_25;
  char local_24;
  char local_23;
  char cStack_22;
  char cStack_21;
  byte bStack_20;
  byte bStack_1f;
  byte bStack_1e;
  byte bStack_1d;
  byte bStack_1c;
  byte bStack_1b;
  char cStack_1a;
  char cStack_19;
  byte bStack_18;
  byte bStack_17;
  char cStack_16;
  char cStack_15;
  char local_14;
  char local_13;
  int local_12;
  int local_10;
  int local_e;
  int iStack_c;
  byte local_a;
  byte local_9;
  byte local_8;
  undefined4 uStack_7;
  undefined1 local_3;
  
  local_3 = 0;
  *param_1 = '\0';
  if ((int)param_3 != 0 || param_3._2_2_ != 0) {
    local_e = *(int *)((int)param_3 + 0xeb);
    iStack_c = *(int *)((int)param_3 + 0xed);
    if (local_e != 0 || iStack_c != 0) {
      cVar6 = ((undefined *)&DAT_0000_5370)[(uint)*(byte *)(local_e + 0x2e) * 9];
      if (cVar6 == '\a') {
        local_8 = 2;
      }
      else if (cVar6 == '\b') {
        local_8 = 1;
      }
      else {
        if (cVar6 != '\t') {
          return 0;
        }
        local_8 = 3;
      }
      local_12 = 0;
      local_10 = 0;
      uVar10 = 0x7e;
      iVar12 = (int)param_3;
      iVar13 = param_3._2_2_;
      uVar7 = func_0x00000814();
      iVar8 = (uint)local_8 + (uVar7 & 0xff);
      local_9 = (byte)iVar8;
      bVar11 = local_9 == 9;
      if (9 < local_9) {
        local_9 = 9;
        uVar10 = 0xcc0;
        FUN_0000_d977(0x7e,0x17f,0x7e,
                      CONCAT11((char)((uint)iVar8 >> 8),*(undefined1 *)(local_e + 0x2e)),iVar12,
                      iVar13);
        if (bVar11) {
          uVar9 = (undefined2)((ulong)*(undefined4 *)((int)param_3 + 0xf3) >> 0x10);
          iVar8 = (int)*(undefined4 *)((int)param_3 + 0xf3);
          local_12 = *(int *)(iVar8 + 8);
          local_10 = *(int *)(iVar8 + 10);
        }
      }
      iVar8 = (uint)local_9 - (uint)local_8;
      bVar11 = iVar8 == 0;
      local_a = (byte)iVar8;
      FUN_0000_d977(uVar10,0x17f,uVar10,
                    CONCAT11((char)((uint)iVar8 >> 8),*(undefined1 *)(local_e + 0x2e)),iVar12,iVar13
                   );
      if (bVar11) {
        if (*(char *)((int)param_3 + 0xd6) == '\0') {
          local_31[0] = -0xc;
          local_31[1] = 1;
        }
        else {
          local_31[0] = '\x01';
          local_31[1] = 0xfe;
        }
      }
      else if (*(char *)((int)param_3 + 0xd6) == '\0') {
        local_31[0] = '\x04';
        local_31[1] = 1;
      }
      else {
        local_31[0] = '\x01';
        local_31[1] = 4;
      }
      if (local_12 == 0 && local_10 == 0) {
        local_12 = (int)param_3;
        local_10 = param_3._2_2_;
      }
      local_13 = FUN_0000_0e20(0xcc0,local_12,local_10);
      local_14 = FUN_0000_0e25(local_12,local_10);
      local_26 = local_13 - local_9;
      local_24 = local_13 + local_9;
      local_25 = local_14 - local_9;
      local_23 = local_14 + local_9;
      bStack_2a = local_13 - local_a;
      bStack_28 = local_13 + local_a;
      cStack_29 = local_14 - local_a;
      cStack_27 = local_14 + local_a;
      uStack_7 = FUN_0000_ce3f(0xdb,0x169);
      iVar12 = 0x169;
      uVar10 = 0xcc0;
      uVar14 = uStack_7;
      FUN_0000_e6d2(0x100);
      local_10 = *(int *)0x5801;
      local_12 = *(int *)0x57ff;
      while (uVar9 = (undefined2)((ulong)uVar14 >> 0x10), local_12 != 0 || local_10 != 0) {
        cStack_15 = FUN_0000_0e20(uVar10,local_12,local_10,iVar12,uVar14);
        uVar10 = 0xdb;
        iVar12 = local_12;
        iVar13 = local_10;
        cStack_16 = FUN_0000_0e25();
        if ((((*(char *)(local_12 + 0xd5) != '\0') && (local_26 <= cStack_15)) &&
            (cStack_15 <= local_24)) && ((local_25 <= cStack_16 && (cStack_16 <= local_23)))) {
          cStack_21 = local_31[*(char *)(local_12 + 0xd6)];
          cVar6 = *(char *)(local_e + 0x2e);
          if ((cVar6 == '%') || (cVar6 == '&')) {
            uVar10 = 0xdb;
            func_0x00000e02(0xdb,local_31 + 2);
            if ((local_31[2] == '\x01') || (local_31[2] == '\x04')) {
              cStack_21 = -1;
            }
          }
          else if (cVar6 == '#') {
            cVar6 = func_0x00000a96(0xdb,auStack_35);
            if ((cVar6 != '\0') || (cVar6 = func_0x000009ce(0x99,local_12,local_10), cVar6 != '\0'))
            {
              cStack_21 = '\0';
            }
            uVar10 = 0x99;
          }
          else if (cVar6 == '\"') {
            uVar10 = 0x99;
            cVar6 = func_0x000009ce(0xdb,local_12,local_10);
            if (cVar6 != '\0') {
              cStack_21 = '\0';
            }
          }
          bStack_1f = -local_8;
          bStack_20 = local_8;
          if ((int)(char)bStack_1f + (int)cStack_16 < (int)cStack_29) {
            bStack_1f = cStack_29 - cStack_16;
          }
          if ((int)cStack_27 < (int)(char)local_8 + (int)cStack_16) {
            bStack_20 = cStack_27 - cStack_16;
          }
          if ((char)bStack_1f <= (char)bStack_20) {
            bStack_1c = bStack_1f;
            while( true ) {
              bStack_1d = cStack_15 - *(char *)((char)bStack_1c * 3 + (uint)local_8 + 0x6dc);
              bStack_1e = cStack_15 + *(char *)((char)bStack_1c * 3 + (uint)local_8 + 0x6dc);
              if ((char)bStack_1d < (char)bStack_2a) {
                bStack_1d = bStack_2a;
              }
              if ((char)bStack_28 < (char)bStack_1e) {
                bStack_1e = bStack_28;
              }
              if ((char)bStack_1d <= (char)bStack_1e) {
                for (bStack_1b = bStack_1d;
                    pcVar1 = (char *)((int)uStack_7 + ((int)(char)bStack_1b - (int)local_13) * 0x13
                                      + (((int)(char)bStack_1c + (int)cStack_16) - (int)local_14) +
                                     0xb4), *pcVar1 = *pcVar1 + cStack_21, bStack_1b != bStack_1e;
                    bStack_1b = bStack_1b + 1) {
                }
              }
              if (bStack_1c == bStack_20) break;
              bStack_1c = bStack_1c + 1;
            }
          }
        }
        uVar14 = CONCAT22(uVar9,iVar13);
        piVar2 = (int *)(local_12 + 0xff);
        local_10 = *(int *)(local_12 + 0x101);
        local_12 = *piVar2;
      }
      cStack_19 = FUN_0000_0e20(uVar10,(int)param_3,param_3._2_2_,iVar12,uVar14);
      uVar10 = 0xdb;
      cStack_1a = FUN_0000_0e25((int)param_3,param_3._2_2_);
      bVar3 = local_a;
      cStack_22 = '\0';
      bVar5 = -local_a;
      if ((char)-local_a <= (char)local_a) {
        do {
          bStack_1b = bVar5;
          bVar5 = local_a;
          bVar4 = -local_a;
          if ((char)-local_a <= (char)local_a) {
            do {
              bStack_1c = bVar4;
              cStack_21 = *(char *)((int)uStack_7 + (char)bStack_1b * 0x13 + (int)(char)bStack_1c +
                                   0xb4);
              uVar9 = uVar10;
              if (cStack_22 < cStack_21) {
LAB_0000_c3a1:
                cStack_15 = cStack_19;
                cStack_16 = cStack_1a;
                uVar10 = 0x7e;
                uStack_2d = func_0x00000814(uVar9,(int)param_3,param_3._2_2_);
                uStack_2d = uStack_2d & 0xff;
                *(undefined1 *)0x4137 = 1;
                if ((((-1 < (int)local_13 + (int)(char)bStack_1b) &&
                     ((int)local_13 + (int)(char)bStack_1b < 0x32)) &&
                    (-1 < (int)local_14 + (int)(char)bStack_1c)) &&
                   ((int)local_14 + (int)(char)bStack_1c < 0x18)) {
                  uVar10 = 0xd7;
                  cVar6 = FUN_0000_0da4(0x7e,&uStack_2d);
                  if ((cVar6 != '\0') && (*(char *)0x4134 == '\0')) {
                    bStack_17 = bStack_1b;
                    bStack_18 = bStack_1c;
                    cStack_22 = cStack_21;
                  }
                }
              }
              else if ((cStack_21 == cStack_22) && ('\0' < cStack_21)) {
                uVar10 = 0x99;
                cVar6 = FUN_0000_09b5(CONCAT11((char)((uint)((char)bStack_1b * 0x13) >> 8),0x19));
                uVar9 = uVar10;
                if (cVar6 != '\0') goto LAB_0000_c3a1;
              }
              if (bStack_1c == bVar5) break;
              bVar4 = bStack_1c + 1;
            } while( true );
          }
          if (bStack_1b == bVar3) break;
          bVar5 = bStack_1b + 1;
        } while( true );
      }
      uVar9 = 0xcc0;
      FUN_0000_ce54(uVar10,0x169,(undefined2)uStack_7,uStack_7._2_2_);
      if (param_2 == '\0') {
        if ('\0' < cStack_22) {
          cVar6 = *(char *)(local_e + 0x2e);
          if (cVar6 == '%') {
            uVar9 = 0x99;
            FUN_0000_09ba(0xcc0,6,1);
          }
          else if (cVar6 == '&') {
            uVar9 = 0x99;
            FUN_0000_09ba(0xcc0,6,1);
          }
          else if ((cVar6 != '!') && (cVar6 != '\"')) {
            if (cVar6 == '$') {
              uVar9 = 0x99;
              FUN_0000_09ba(0xcc0,10,1);
            }
            else if (cVar6 == '#') {
              uVar9 = 0x99;
              FUN_0000_09ba(0xcc0,10,1);
            }
          }
          uVar7 = func_0x0000d612(uVar9);
          if (uVar7 < 0x81) {
            cStack_37 = (char)uVar7;
            *param_1 = cStack_37;
          }
          else {
            *param_1 = (char)(uVar7 >> 4) + 'x';
          }
        }
      }
      else if (cStack_22 < '\x01') {
        FUN_0000_d3bf(0xcc0,&uStack_2b);
        local_3 = uStack_2b;
      }
      else {
        FUN_0000_0585(0xcc0,&uStack_2b);
        local_3 = FUN_0000_0a28(0x56,(int)param_3,param_3._2_2_);
      }
    }
  }
  return local_3;
}


