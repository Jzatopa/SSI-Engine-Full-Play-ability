
void __stdcall16far FUN_2000_c618(int param_1,byte param_2)

{
  undefined1 uVar2;
  int iVar1;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  
  uVar3 = 0xb58;
  func_0x0000b5d1();
  local_4 = 1;
  local_5 = *(byte *)(param_1 + -0x24a);
  if ((*(char *)(param_1 + -0x213) != '\0') && (local_6 = *(byte *)(param_1 + -0x213), local_6 != 0)
     ) {
    local_4 = 1;
    local_3 = 1;
    uVar4 = uVar3;
    while( true ) {
      if (*(char *)(param_1 + (uint)local_3 + -0x200) == '@') {
        iVar1 = (uint)*(byte *)(param_1 + -0x214) + (uint)local_4 + -1;
        uVar2 = (undefined1)((uint)iVar1 >> 8);
        uVar3 = 0xec;
        func_0x00001140(uVar4,CONCAT11(uVar2,local_5),CONCAT11(uVar2,0x27),CONCAT11(uVar2,local_5),
                        iVar1);
        local_5 = local_5 + 1;
        local_4 = 1;
      }
      else {
        if (((local_3 < *(byte *)(param_1 + (uint)param_2 * 2 + -0x23e)) ||
            (*(byte *)(param_1 + (uint)param_2 * 2 + -0x23d) < local_3)) ||
           (*(char *)0x7481 == '\0')) {
          bVar5 = param_1 + (uint)local_3 == 0;
          FUN_0000_d977(uVar4,0x22a,uVar4,*(undefined1 *)(param_1 + (uint)local_3 + -0x200));
          if (bVar5) {
            local_3 = (byte)((uint)*(byte *)(param_1 + -0x214) + (uint)local_4 + -1 >> 8);
            local_4 = *(byte *)0x7480;
            local_6 = 0;
            FUN_0000_6283(1,*(undefined1 *)(param_1 + (uint)local_3 + -0x200),CONCAT11(local_3,1));
            local_5 = local_3;
          }
          else {
            local_3 = (byte)((uint)*(byte *)(param_1 + -0x214) + (uint)local_4 + -1 >> 8);
            local_4 = *(byte *)0x7481;
            local_6 = 0;
            FUN_0000_6283(1,*(undefined1 *)(param_1 + (uint)local_3 + -0x200),CONCAT11(local_3,1));
            local_5 = local_3;
          }
        }
        else {
          FUN_0000_6283(1,*(undefined1 *)(param_1 + (uint)local_3 + -0x200),
                        CONCAT11((char)((uint)*(byte *)(param_1 + -0x214) + (uint)local_4 + -1 >> 8)
                                 ,1));
        }
        uVar3 = 0x602;
        local_4 = local_4 + 1;
      }
      if (local_3 == local_6) break;
      local_3 = local_3 + 1;
      uVar4 = uVar3;
    }
  }
  uVar4 = uVar3;
  if ((int)((uint)*(byte *)(param_1 + -0x214) + (uint)local_4 + -1) < 0x28) {
    iVar1 = (uint)*(byte *)(param_1 + -0x214) + (uint)local_4 + -1;
    uVar2 = (undefined1)((uint)iVar1 >> 8);
    uVar4 = 0xec;
    func_0x00001140(uVar3,CONCAT11(uVar2,local_5),CONCAT11(uVar2,0x27),CONCAT11(uVar2,local_5),iVar1
                   );
  }
  FUN_0000_b5b0(uVar4);
  return;
}


