
void __stdcall16far FUN_3000_1908(char param_1,char param_2,char param_3,char param_4)

{
  byte bVar1;
  byte bVar6;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar7;
  undefined2 unaff_DS;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  undefined4 local_a;
  byte local_6;
  byte local_3;
  
  param_3 = param_3 * '\x03';
  local_3 = *(byte *)((int)*(undefined4 *)0x71dc + param_1 * 0x32 + (int)param_2 + 7);
  if ((0x9a < local_3) || (local_3 == 0)) {
    local_3 = 0x15;
  }
  bVar1 = ((undefined *)&DAT_0000_26db)[(uint)local_3 * 4];
  bVar6 = param_3 >> 7;
  if (local_3 < 6) {
    local_3 = FUN_3000_2d11(param_1,param_2);
    if ((((local_3 == 1) || (local_3 == 2)) || (local_3 == 3)) || (local_3 == 4)) {
      local_a = (undefined2 *)CONCAT22(*(undefined2 *)0x748b,(undefined2 *)*(undefined2 *)0x7489);
      while( true ) {
        if ((undefined2 *)local_a == (undefined2 *)0x0 && local_a._2_2_ == 0) break;
        local_6 = 1;
        while( true ) {
          if (((*(char *)((int)(undefined2 *)local_a + local_6 + 0xc) != '\0') &&
              ((int)*(char *)((undefined2 *)local_a + 0xb) +
               (int)(char)((undefined *)&DAT_0000_26ca)[*(byte *)(local_6 + 0x3189)] == (int)param_2
              )) && ((int)*(char *)((int)(undefined2 *)local_a + 0x17) +
                     (int)(char)((undefined *)&DAT_0000_26d3)[*(byte *)(local_6 + 0x3189)] ==
                     (int)param_1)) {
            local_3 = *(byte *)((int)(undefined2 *)local_a + local_6 + 3);
          }
          if (local_6 == 9) break;
          local_6 = local_6 + 1;
        }
        local_a = (undefined2 *)CONCAT22(((undefined2 *)local_a)[1],(undefined2 *)*local_a);
      }
    }
    else if ((local_3 == 5) && (*(byte *)0x71db != 0)) {
      local_6 = 1;
      while( true ) {
        if ((*(char *)((uint)local_6 * 7 + 0x71a0) == param_2) &&
           (*(char *)((uint)local_6 * 7 + 0x71a1) == param_1)) {
          local_3 = *(byte *)((uint)local_6 * 7 + 0x71a2);
        }
        if (local_6 == *(byte *)0x71db) break;
        local_6 = local_6 + 1;
      }
    }
    if ((0x9a < local_3) || (local_3 == 0)) {
      local_3 = 0x15;
    }
    iVar2 = (int)(char)(param_4 * '\x03');
    iVar3 = (int)param_3;
    uVar4 = CONCAT11(bVar6,((undefined *)&DAT_0000_26db)[(uint)local_3 * 4]);
    iVar5 = (uint)bVar6 << 8;
    uVar11 = *(undefined2 *)0x68be;
    uVar10 = *(undefined2 *)0x68bc;
    uVar9 = *(undefined2 *)0x44cc;
    uVar8 = *(undefined2 *)0x44ca;
    FUN_0000_2d5d();
    iVar7 = ((bVar1 >> 1) + 0x21) * 8 + (uint)(bVar1 & 1) * 4;
    FUN_0000_2d5d(0x21a,*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)(iVar7 + 0x68c0),
                  *(undefined2 *)(iVar7 + 0x68c2),CONCAT11(bVar6,1),(uint)bVar6 << 8,(int)param_3,
                  (int)(char)(param_4 * '\x03'),uVar8,uVar9,uVar10,uVar11,iVar5,uVar4,iVar3,iVar2);
  }
  else {
    FUN_0000_2d5d();
  }
  return;
}


