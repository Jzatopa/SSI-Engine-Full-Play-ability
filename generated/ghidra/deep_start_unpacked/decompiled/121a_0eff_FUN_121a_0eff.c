
/* WARNING: Removing unreachable block (ram,0x00013133) */

void __stdcall16far FUN_121a_0eff(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 local_11;
  byte local_f;
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  if ((int *)param_2 != (int *)0x0 || param_2._2_2_ != 0) {
    if ((int)param_1 != 0 || param_1._2_2_ != 0) {
      FUN_1cc0_1aaf(8,(int)param_1 + 10,param_1._2_2_,(int *)param_2 + 5,param_2._2_2_);
      cVar1 = *(char *)0x44c8;
      if (cVar1 == '\0') {
        local_a = ((int *)param_2)[1] * 2;
        local_6 = local_a + -2;
        local_4 = 0;
        iVar2 = *param_2;
        if (iVar2 != 0) {
          local_e = 1;
          while( true ) {
            local_8 = local_4;
            iVar5 = ((int *)param_2)[1];
            local_c = 0;
            while( true ) {
              FUN_1cc0_1aaf(2,&local_11,unaff_SS,
                            (int)(int *)param_2 + (local_6 - local_4) + local_8 + 0x1b,param_2._2_2_
                           );
              local_11 = FUN_121a_0e41(local_11);
              FUN_1cc0_1aaf(2,(int)param_1 + local_4 + 0x1b,param_1._2_2_,&local_11,unaff_SS);
              if (*(int *)((int)(int *)param_2 + 0x17) != 0 ||
                  *(int *)((int)(int *)param_2 + 0x19) != 0) {
                FUN_1cc0_1aaf(2,&local_11,unaff_SS,
                              (int)*(undefined4 *)((int)(int *)param_2 + 0x17) +
                              (local_6 - local_4) + local_8,
                              (int)((ulong)*(undefined4 *)((int)(int *)param_2 + 0x17) >> 0x10));
                local_11 = FUN_121a_0e41(local_11);
                FUN_1cc0_1aaf(2,(int)*(undefined4 *)((int)param_1 + 0x17) + local_4,
                              (int)((ulong)*(undefined4 *)((int)param_1 + 0x17) >> 0x10),&local_11,
                              unaff_SS);
              }
              local_4 = local_4 + 2;
              if (local_c == iVar5 + -1) break;
              local_c = local_c + 1;
            }
            local_6 = local_6 + local_a;
            if (local_e == iVar2) break;
            local_e = local_e + 1;
          }
        }
      }
      else if (cVar1 == '\x01') {
        local_a = ((int *)param_2)[1] * 4;
        local_6 = local_a + -4;
        local_4 = 0;
        iVar2 = *param_2;
        if (iVar2 != 0) {
          local_e = 1;
          while( true ) {
            local_8 = local_4;
            iVar5 = ((int *)param_2)[1];
            if (iVar5 != 0) {
              local_c = 1;
              while( true ) {
                local_f = 0;
                while( true ) {
                  iVar4 = (local_6 - local_4) + local_8 + (uint)local_f;
                  uVar3 = FUN_121a_0dbc(CONCAT11((char)((uint)iVar4 >> 8),
                                                 *(undefined1 *)((int)(int *)param_2 + iVar4 + 0x1b)
                                                ));
                  *(undefined1 *)((int)param_1 + (uint)local_f + local_4 + 0x1b) = uVar3;
                  if (*(int *)((int)(int *)param_2 + 0x17) != 0 ||
                      *(int *)((int)(int *)param_2 + 0x19) != 0) {
                    iVar4 = (local_6 - local_4) + local_8 + (uint)local_f;
                    uVar3 = FUN_121a_0dbc(CONCAT11((char)((uint)iVar4 >> 8),
                                                   *(undefined1 *)
                                                    ((int)*(undefined4 *)
                                                           ((int)(int *)param_2 + 0x17) + iVar4)));
                    *(undefined1 *)
                     ((int)*(undefined4 *)((int)param_1 + 0x17) + (uint)local_f + local_4) = uVar3;
                  }
                  if (local_f == 3) break;
                  local_f = local_f + 1;
                }
                local_4 = local_4 + 4;
                if (local_c == iVar5) break;
                local_c = local_c + 1;
              }
            }
            local_6 = local_6 + local_a;
            if (local_e == iVar2) break;
            local_e = local_e + 1;
          }
        }
      }
      else if (cVar1 == '\x02') {
        local_a = ((int *)param_2)[1] * 4;
        local_6 = local_a + -1;
        local_4 = 0;
        iVar2 = *param_2;
        if (iVar2 != 0) {
          local_e = 1;
          while( true ) {
            iVar5 = local_a;
            local_8 = local_4;
            if (local_a != 0) {
              local_c = 1;
              while( true ) {
                iVar4 = (local_6 - local_4) + local_8;
                uVar3 = FUN_121a_0ece(CONCAT11((char)((uint)iVar4 >> 8),
                                               *(undefined1 *)((int)(int *)param_2 + iVar4 + 0x1b)))
                ;
                *(undefined1 *)((int)param_1 + local_4 + 0x1b) = uVar3;
                if (*(int *)((int)(int *)param_2 + 0x17) != 0 ||
                    *(int *)((int)(int *)param_2 + 0x19) != 0) {
                  iVar4 = (local_6 - local_4) + local_8;
                  uVar3 = FUN_121a_0ece(CONCAT11((char)((uint)iVar4 >> 8),
                                                 *(undefined1 *)
                                                  ((int)*(undefined4 *)((int)(int *)param_2 + 0x17)
                                                  + iVar4)));
                  *(undefined1 *)((int)*(undefined4 *)((int)param_1 + 0x17) + local_4) = uVar3;
                }
                local_4 = local_4 + 1;
                if (local_c == iVar5) break;
                local_c = local_c + 1;
              }
            }
            local_6 = local_6 + local_a;
            if (local_e == iVar2) break;
            local_e = local_e + 1;
          }
        }
      }
      else if (cVar1 == '\x03') {
        iVar5 = ((int *)param_2)[1] * 8;
        local_6 = iVar5 + -1;
        local_4 = 0;
        iVar2 = *param_2;
        if (iVar2 != 0) {
          local_e = 1;
          while( true ) {
            iVar4 = local_4;
            if (iVar5 != 0) {
              local_c = 1;
              while( true ) {
                *(undefined1 *)((int)param_1 + local_4 + 0x1b) =
                     *(undefined1 *)((int)(int *)param_2 + (local_6 - local_4) + iVar4 + 0x1b);
                local_4 = local_4 + 1;
                if (local_c == iVar5) break;
                local_c = local_c + 1;
              }
            }
            local_6 = local_6 + iVar5;
            if (local_e == iVar2) break;
            local_e = local_e + 1;
          }
        }
      }
    }
  }
  return;
}


