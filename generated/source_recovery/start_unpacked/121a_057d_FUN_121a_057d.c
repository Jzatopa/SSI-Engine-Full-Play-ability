/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:057d
 * Ghidra name: FUN_121a_057d
 * Linear address: 0x1271D
 * Body addresses: 1600
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Removing unreachable block (ram,0x00012782) */
/* WARNING: Removing unreachable block (ram,0x000129fd) */
/* WARNING: Removing unreachable block (ram,0x00012a1d) */
/* WARNING: Removing unreachable block (ram,0x00012c3f) */
/* WARNING: Removing unreachable block (ram,0x000127a2) */

void __stdcall16far
FUN_121a_057d(int *param_1,byte param_2,undefined2 param_3,int *param_4,undefined4 param_5)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  undefined2 uVar9;
  int iVar10;
  int iVar11;
  undefined2 uVar12;
  undefined2 uVar13;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar14;
  byte local_19;
  byte local_18;
  char local_17;
  byte local_16;
  int local_14;
  int local_12;
  int local_10;
  int local_e;
  int local_c;
  byte local_a [8];
  
  if ((int *)param_1 != (int *)0x0 || param_1._2_2_ != 0) {
    local_12 = 0;
    local_14 = 0;
    cVar2 = *(char *)0x44c8;
    iVar10 = (int)param_5;
    uVar12 = (undefined2)((ulong)param_5 >> 0x10);
    if (cVar2 == '\0') {
      iVar5 = ((int *)param_1)[4];
      if (iVar5 != 0) {
        local_c = 1;
        while( true ) {
          iVar4 = *param_1;
          local_10 = 0;
          while( true ) {
            iVar3 = ((int *)param_1)[1];
            local_e = 0;
            while( true ) {
              FUN_1cc0_1aaf(8,local_a,unaff_SS,iVar10 + *param_4,uVar12);
              uVar7 = *(uint *)((int)(int *)param_1 + 0x17) | *(uint *)((int)(int *)param_1 + 0x19);
              if (uVar7 != 0) {
                bVar6 = FUN_121a_0000(local_a,unaff_SS,CONCAT11((char)(uVar7 >> 8),param_2));
                local_18 = 0x80;
                local_17 = '\x01';
                while( true ) {
                  local_16 = 4;
                  while( true ) {
                    if ((local_18 & bVar6) != 0) {
                      *(byte *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_14) =
                           *(byte *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_14) |
                           (byte)*(undefined2 *)((uint)local_16 * 2 + 0x22db);
                    }
                    local_18 = local_18 >> 1;
                    if (local_16 == 7) break;
                    local_16 = local_16 + 1;
                  }
                  local_14 = local_14 + 1;
                  if (local_17 == '\x02') break;
                  local_17 = local_17 + '\x01';
                }
              }
              local_16 = 0;
              while( true ) {
                uVar7 = (uint)local_16;
                uVar8 = FUN_121a_005e((int *)param_1 + 5,param_1._2_2_,local_a[local_16]);
                *(byte *)((int)(int *)param_1 + local_12 + 0x1b) =
                     *(byte *)((int)(int *)param_1 + local_12 + 0x1b) |
                     *(byte *)((uVar8 & 0xff) * 4 + uVar7 + 0x22f0);
                if (local_16 == 3) break;
                local_16 = local_16 + 1;
              }
              if (*(int *)((int)(int *)param_1 + 0x17) != 0 ||
                  *(int *)((int)(int *)param_1 + 0x19) != 0) {
                *(byte *)((int)(int *)param_1 + local_12 + 0x1b) =
                     *(byte *)((int)(int *)param_1 + local_12 + 0x1b) &
                     ~*(byte *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_14 + -2);
              }
              local_16 = 4;
              while( true ) {
                iVar11 = local_16 - 4;
                uVar7 = FUN_121a_005e((int *)param_1 + 5,param_1._2_2_,local_a[local_16]);
                *(byte *)((int)(int *)param_1 + local_12 + 0x1c) =
                     *(byte *)((int)(int *)param_1 + local_12 + 0x1c) |
                     *(byte *)((uVar7 & 0xff) * 4 + iVar11 + 0x22f0);
                if (local_16 == 7) break;
                local_16 = local_16 + 1;
              }
              if (*(int *)((int)(int *)param_1 + 0x17) != 0 ||
                  *(int *)((int)(int *)param_1 + 0x19) != 0) {
                *(byte *)((int)(int *)param_1 + local_12 + 0x1c) =
                     *(byte *)((int)(int *)param_1 + local_12 + 0x1c) &
                     ~*(byte *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_14 + -1);
              }
              local_12 = local_12 + 2;
              *param_4 = *param_4 + 8;
              if (local_e == iVar3 + -1) break;
              local_e = local_e + 1;
            }
            if (local_10 == iVar4 + -1) break;
            local_10 = local_10 + 1;
          }
          if (local_c == iVar5) break;
          local_c = local_c + 1;
        }
      }
    }
    else if (cVar2 == '\x01') {
      iVar5 = ((int *)param_1)[4];
      if (iVar5 != 0) {
        local_c = 1;
        while( true ) {
          iVar4 = *param_1;
          local_10 = 0;
          while( true ) {
            iVar3 = ((int *)param_1)[1];
            local_e = 0;
            while( true ) {
              FUN_1cc0_1aaf(8,local_a,unaff_SS,iVar10 + *param_4,uVar12);
              if (*(int *)((int)(int *)param_1 + 0x17) != 0 ||
                  *(int *)((int)(int *)param_1 + 0x19) != 0) {
                uVar13 = (undefined2)((ulong)*(undefined4 *)((int)(int *)param_1 + 0x17) >> 0x10);
                iVar11 = (int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_12;
                uVar14 = 4;
                uVar9 = FUN_121a_0000(local_a,unaff_SS,param_2);
                FUN_1cc0_1ad2(uVar9,uVar14,iVar11,uVar13);
              }
              local_18 = 0x80;
              local_16 = 0;
              while( true ) {
                bVar6 = *(byte *)(local_a[local_16] + 0x9cc7);
                local_19 = 0;
                while( true ) {
                  if ((*(byte *)(local_19 + 0x22ec) & bVar6) != 0) {
                    *(byte *)((int)(int *)param_1 + (uint)local_19 + local_12 + 0x1b) =
                         *(byte *)((int)(int *)param_1 + (uint)local_19 + local_12 + 0x1b) |
                         local_18;
                  }
                  if (local_19 == 3) break;
                  local_19 = local_19 + 1;
                }
                local_18 = local_18 >> 1;
                if (local_16 == 7) break;
                local_16 = local_16 + 1;
              }
              if (*(int *)((int)(int *)param_1 + 0x17) != 0 ||
                  *(int *)((int)(int *)param_1 + 0x19) != 0) {
                for (local_19 = 0;
                    *(byte *)((int)(int *)param_1 + (uint)local_19 + local_12 + 0x1b) =
                         *(byte *)((int)(int *)param_1 + (uint)local_19 + local_12 + 0x1b) &
                         ~*(byte *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_12),
                    local_19 != 3; local_19 = local_19 + 1) {
                }
              }
              local_12 = local_12 + 4;
              *param_4 = *param_4 + 8;
              if (local_e == iVar3 + -1) break;
              local_e = local_e + 1;
            }
            if (local_10 == iVar4 + -1) break;
            local_10 = local_10 + 1;
          }
          if (local_c == iVar5) break;
          local_c = local_c + 1;
        }
      }
    }
    else if (cVar2 == '\x02') {
      iVar5 = ((int *)param_1)[4];
      if (iVar5 != 0) {
        local_c = 1;
        while( true ) {
          iVar4 = ((int *)param_1)[9];
          local_e = 0;
          while( true ) {
            *(char *)((int)(int *)param_1 + local_12 + 0x1b) =
                 *(char *)(*(byte *)(iVar10 + *param_4) + 0x9cc7) * '\x10' +
                 *(char *)(*(byte *)(iVar10 + *param_4 + 1) + 0x9cc7);
            *param_4 = *param_4 + 2;
            if (local_e == iVar4 + -1) break;
            local_e = local_e + 1;
            local_12 = local_12 + 1;
          }
          if (*(int *)((int)(int *)param_1 + 0x17) != 0 || *(int *)((int)(int *)param_1 + 0x19) != 0
             ) {
            local_e = 0;
            while( true ) {
              if (*(byte *)((int)(int *)param_1 + local_e + 0x1b) >> 4 == param_2) {
                *(undefined1 *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_e) = 0xf0;
              }
              if ((*(byte *)((int)(int *)param_1 + local_e + 0x1b) & 0xf) == param_2) {
                pcVar1 = (char *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_e);
                *pcVar1 = *pcVar1 + '\x0f';
              }
              *(byte *)((int)(int *)param_1 + local_e + 0x1b) =
                   *(byte *)((int)(int *)param_1 + local_e + 0x1b) &
                   ~*(byte *)((int)*(undefined4 *)((int)(int *)param_1 + 0x17) + local_e);
              if (local_e == local_12) break;
              local_e = local_e + 1;
            }
          }
          if (local_c == iVar5) break;
          local_c = local_c + 1;
          local_12 = local_12 + 1;
        }
      }
    }
    else if ((cVar2 == '\x03') && (iVar5 = ((int *)param_1)[4], iVar5 != 0)) {
      local_c = 1;
      while( true ) {
        FUN_1cc0_1aaf(((int *)param_1)[9],(int)(int *)param_1 + local_12 + 0x1b,param_1._2_2_,
                      iVar10 + *param_4,uVar12);
        local_12 = local_12 + ((int *)param_1)[9];
        *param_4 = *param_4 + ((int *)param_1)[9];
        if (local_c == iVar5) break;
        local_c = local_c + 1;
      }
    }
  }
  return;
}


