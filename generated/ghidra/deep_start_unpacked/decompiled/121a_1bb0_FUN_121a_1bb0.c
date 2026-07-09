
void __stdcall16far
FUN_121a_1bb0(undefined2 *param_1,char param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined2 uVar11;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int *local_3c;
  byte local_38;
  byte local_37;
  byte local_36;
  int local_35;
  byte local_33;
  byte local_31;
  byte abStack_30 [4];
  byte local_2c;
  int local_2b;
  int local_29;
  byte local_27;
  int local_26;
  int local_24;
  byte local_22 [16];
  byte local_12 [16];
  
  FUN_1cc0_09f6(0x10,local_12,unaff_SS,(int)param_5,(int)((ulong)param_5 >> 0x10));
  FUN_1cc0_09f6(0x10,local_22,unaff_SS,(int)param_4,(int)((ulong)param_4 >> 0x10));
  if ((undefined2 *)param_1 != (undefined2 *)0x0 || param_1._2_2_ != 0) {
    if (param_3 < 0) {
      param_3 = 0;
      local_27 = *(byte *)((undefined2 *)param_1 + 4);
    }
    else {
      local_27 = 1;
    }
    local_24 = FUN_1cc0_0a12();
    local_26 = 0;
    FUN_121a_22ad(&local_3c,unaff_SS,0,local_27,((undefined2 *)param_1)[1],*param_1);
    FUN_1cc0_09f6(8,(int *)local_3c + 5,(int)((ulong)local_3c >> 0x10),(undefined2 *)param_1 + 5,
                  param_1._2_2_);
    uVar11 = (undefined2)((ulong)local_3c >> 0x10);
    piVar9 = (int *)local_3c;
    FUN_1cc0_1aaf(piVar9[9] * piVar9[4],(int)piVar9 + local_26 + 0x1b,uVar11,
                  (int)(undefined2 *)param_1 + local_24 + 0x1b,param_1._2_2_);
    local_38 = 0;
    while( true ) {
      if (param_3 < 0) {
        param_3 = 0;
        local_27 = *(byte *)((undefined2 *)param_1 + 4);
      }
      else {
        local_27 = 1;
      }
      local_24 = FUN_1cc0_0a12();
      piVar1 = local_3c;
      local_26 = 0;
      if (local_12[local_38] != local_22[local_38]) {
        uVar11 = (undefined2)((ulong)local_3c >> 0x10);
        piVar9 = (int *)local_3c;
        cVar4 = *(char *)0x44c8;
        if (cVar4 == '\0') {
          local_35 = piVar9[1] << 1;
          cVar4 = (char)((uint)local_27 + param_3 + -1);
          if ((char)param_3 <= cVar4) {
            *(char *)0x7817 = (char)param_3;
            while( true ) {
              iVar8 = *piVar1;
              if (iVar8 != 0) {
                local_2b = 1;
                while( true ) {
                  iVar10 = local_35;
                  if (local_35 != 0) {
                    local_29 = 1;
                    while( true ) {
                      local_33 = 0;
                      while( true ) {
                        uVar5 = (uint)local_33;
                        uVar6 = FUN_121a_005e(piVar9 + 5,uVar11,local_12[local_38]);
                        if ((((uint)*(byte *)((int)(undefined2 *)param_1 + local_24 + 0x1b) &
                             *(uint *)((local_33 + 4) * 2 + 0x22db)) ==
                             (uint)*(byte *)((uVar6 & 0xff) * 4 + uVar5 + 0x22f0)) &&
                           ((param_2 == '\0' ||
                            ((param_2 != '\0' && (iVar7 = FUN_1cc0_15ea(4), iVar7 == 0)))))) {
                          uVar5 = (uint)local_33;
                          uVar6 = FUN_121a_005e(piVar9 + 5,uVar11,local_22[local_38]);
                          *(byte *)((int)piVar9 + local_26 + 0x1b) =
                               *(byte *)((int)piVar9 + local_26 + 0x1b) &
                               ~(byte)*(undefined2 *)((local_33 + 4) * 2 + 0x22db) |
                               *(byte *)((uVar6 & 0xff) * 4 + uVar5 + 0x22f0);
                        }
                        if (local_33 == 3) break;
                        local_33 = local_33 + 1;
                      }
                      local_24 = local_24 + 1;
                      local_26 = local_26 + 1;
                      if (local_29 == iVar10) break;
                      local_29 = local_29 + 1;
                    }
                  }
                  if (local_2b == iVar8) break;
                  local_2b = local_2b + 1;
                }
              }
              if (*(char *)0x7817 == cVar4) break;
              *(char *)0x7817 = *(char *)0x7817 + '\x01';
            }
          }
        }
        else if (cVar4 == '\x01') {
          local_31 = 0;
          while( true ) {
            if ((local_12[local_38] & *(byte *)(local_31 + 0x22ec)) == 0) {
              abStack_30[local_31] = 0xff;
            }
            else {
              abStack_30[local_31] = 0;
            }
            if (local_31 == 3) break;
            local_31 = local_31 + 1;
          }
          cVar4 = (char)((uint)local_27 + param_3 + -1);
          if ((char)param_3 <= cVar4) {
            *(char *)0x7817 = (char)param_3;
            while( true ) {
              iVar8 = *piVar1;
              if (iVar8 != 0) {
                local_2b = 1;
                while( true ) {
                  iVar10 = piVar9[1];
                  if (iVar10 != 0) {
                    local_29 = 1;
                    while( true ) {
                      if (param_2 == '\0') {
                        local_2c = 0xff;
                      }
                      else {
                        bVar2 = FUN_1cc0_15ea(0x100);
                        bVar3 = FUN_1cc0_15ea(0x100);
                        local_2c = bVar3 & bVar2;
                      }
                      local_31 = 0;
                      while( true ) {
                        local_2c = (*(byte *)((int)(undefined2 *)param_1 +
                                             (uint)local_31 + local_24 + 0x1b) ^
                                   abStack_30[local_31]) & local_2c;
                        if (local_31 == 3) break;
                        local_31 = local_31 + 1;
                      }
                      local_31 = 0;
                      while( true ) {
                        if ((local_22[local_38] & *(byte *)(local_31 + 0x22ec)) == 0) {
                          *(byte *)((int)piVar9 + (uint)local_31 + local_26 + 0x1b) =
                               *(byte *)((int)piVar9 + (uint)local_31 + local_26 + 0x1b) & ~local_2c
                          ;
                        }
                        else {
                          *(byte *)((int)piVar9 + (uint)local_31 + local_26 + 0x1b) =
                               *(byte *)((int)piVar9 + (uint)local_31 + local_26 + 0x1b) | local_2c;
                        }
                        if (local_31 == 3) break;
                        local_31 = local_31 + 1;
                      }
                      local_24 = local_24 + 4;
                      local_26 = local_26 + 4;
                      if (local_29 == iVar10) break;
                      local_29 = local_29 + 1;
                    }
                  }
                  if (local_2b == iVar8) break;
                  local_2b = local_2b + 1;
                }
              }
              if (*(char *)0x7817 == cVar4) break;
              *(char *)0x7817 = *(char *)0x7817 + '\x01';
            }
          }
        }
        else if (cVar4 == '\x02') {
          local_35 = piVar9[1] << 2;
          local_36 = local_12[local_38] << 4;
          local_37 = local_22[local_38] << 4;
          cVar4 = (char)((uint)local_27 + param_3 + -1);
          if ((char)param_3 <= cVar4) {
            *(char *)0x7817 = (char)param_3;
            while( true ) {
              iVar8 = *piVar1;
              if (iVar8 != 0) {
                local_2b = 1;
                while( true ) {
                  iVar10 = local_35;
                  if (local_35 != 0) {
                    local_29 = 1;
                    while( true ) {
                      if (((*(byte *)((int)(undefined2 *)param_1 + local_24 + 0x1b) & 0xf0) ==
                           local_36) &&
                         ((param_2 == '\0' ||
                          ((param_2 != '\0' && (iVar7 = FUN_1cc0_15ea(4), iVar7 == 0)))))) {
                        *(byte *)((int)piVar9 + local_26 + 0x1b) =
                             *(byte *)((int)piVar9 + local_26 + 0x1b) & 0xf | local_37;
                      }
                      if (((*(byte *)((int)(undefined2 *)param_1 + local_24 + 0x1b) & 0xf) ==
                           local_12[local_38]) &&
                         ((param_2 == '\0' ||
                          ((param_2 != '\0' && (iVar7 = FUN_1cc0_15ea(4), iVar7 == 0)))))) {
                        *(byte *)((int)piVar9 + local_26 + 0x1b) =
                             *(byte *)((int)piVar9 + local_26 + 0x1b) & 0xf0 | local_22[local_38];
                      }
                      local_24 = local_24 + 1;
                      local_26 = local_26 + 1;
                      if (local_29 == iVar10) break;
                      local_29 = local_29 + 1;
                    }
                  }
                  if (local_2b == iVar8) break;
                  local_2b = local_2b + 1;
                }
              }
              if (*(char *)0x7817 == cVar4) break;
              *(char *)0x7817 = *(char *)0x7817 + '\x01';
            }
          }
        }
        else if (cVar4 == '\x03') {
          local_35 = piVar9[1] << 3;
          cVar4 = (char)((uint)local_27 + param_3 + -1);
          if ((char)param_3 <= cVar4) {
            *(char *)0x7817 = (char)param_3;
            while( true ) {
              iVar8 = *local_3c;
              if (iVar8 != 0) {
                local_2b = 1;
                while( true ) {
                  if (local_35 != 0) {
                    local_29 = 1;
                    while( true ) {
                      if ((*(byte *)((int)piVar9 + local_24 + 0x1b) == local_12[local_38]) &&
                         (local_12[local_38] != *(byte *)(piVar9 + 0xb))) {
                        *(byte *)((int)piVar9 + local_26 + 0x1b) = local_22[local_38];
                      }
                      local_24 = local_24 + 1;
                      local_26 = local_26 + 1;
                      if (local_29 == local_35) break;
                      local_29 = local_29 + 1;
                    }
                  }
                  if (local_2b == iVar8) break;
                  local_2b = local_2b + 1;
                }
              }
              if (*(char *)0x7817 == cVar4) break;
              *(char *)0x7817 = *(char *)0x7817 + '\x01';
            }
          }
        }
      }
      if (local_38 == 0xf) break;
      local_38 = local_38 + 1;
    }
    uVar11 = (undefined2)((ulong)local_3c >> 0x10);
    iVar10 = (int)(int *)local_3c + 0x1b;
    iVar8 = FUN_1cc0_0a12(iVar10,uVar11);
    FUN_1cc0_1aaf((uint)local_27 * ((undefined2 *)param_1)[9],
                  (int)(undefined2 *)param_1 + iVar8 + 0x1b,param_1._2_2_,iVar10,uVar11);
    FUN_121a_239c(&local_3c,unaff_SS);
  }
  return;
}


