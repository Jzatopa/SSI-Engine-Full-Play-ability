
void __stdcall16far FUN_1000_28ef(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  char extraout_AL;
  undefined2 uVar5;
  undefined1 uVar6;
  undefined1 extraout_AH;
  undefined2 unaff_CS;
  undefined2 uVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint local_b;
  char local_7;
  char local_6;
  char local_5;
  byte local_4;
  
  local_b = 0xff;
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 6) = 1;
  local_6 = '\0';
  while( true ) {
    local_7 = '\0';
    while( true ) {
      cVar1 = *(char *)0x72d0 + local_6 + -3;
      cVar2 = *(char *)&DAT_0000_72d1 + local_7 + -3;
      if ((((-1 < cVar1) && (cVar1 < '2')) && (-1 < cVar2)) && (cVar2 < '\x19')) {
        *(uint *)(param_1 + -0xe0) = (uint)*(byte *)((uint)*(byte *)(param_1 + 6) * 5 + 0x9e1);
        cVar3 = FUN_0000_0da4(unaff_CS,param_1 + -0xe0);
        if (cVar3 == '\0') {
          unaff_CS = 0xd7;
          if (*(int *)(param_1 + -0xe4) != 0 || *(int *)(param_1 + -0xe2) != 0) {
            cVar1 = *(char *)0x72d0;
            cVar2 = *(char *)&DAT_0000_72d1;
            *(undefined2 *)(param_1 + -0xe0) = 0xff;
            func_0x00000e02(0xd7,param_1 + -0xde);
            unaff_CS = 0xdb;
            if ((*(char *)(param_1 + -0xdd) == '\0') &&
               (((undefined *)&DAT_0000_26d8)[(uint)*(byte *)(param_1 + -0xde) * 4] != -1)) {
              unaff_CS = 0xd7;
              cVar3 = FUN_0000_0da4(0xdb,param_1 + -0xe0);
              if ((cVar3 != '\0') && (*(uint *)(param_1 + -0xe0) < local_b)) {
                local_b = *(uint *)(param_1 + -0xe0);
                *(char *)(param_1 + -0xe5) = cVar1 + local_6 + -3;
                *(char *)(param_1 + -0xe6) = cVar2 + local_7 + -3;
              }
            }
          }
        }
        else {
          uVar7 = 0xdb;
          bVar4 = FUN_0000_0ddf(0xd7,cVar2,cVar1);
          local_4 = ((undefined *)&DAT_0000_26da)[(uint)bVar4 * 4];
          uVar6 = 0;
          if (local_4 != 0) {
            local_5 = '\0';
            if ((0xf9 < local_4) && (local_4 < 0xfe)) {
              uVar7 = 0x99;
              uVar5 = FUN_0000_09b5(0x19);
              uVar6 = (undefined1)((uint)uVar5 >> 8);
              if ((char)uVar5 == '\0') {
                if (local_4 == 0xfa) {
                  local_4 = 0x98;
                }
                else if (local_4 == 0xfb) {
                  local_4 = 0x95;
                }
                else if (local_4 == 0xfc) {
                  local_4 = 0x96;
                }
              }
              else {
                local_4 = 0x92;
                uVar7 = 0x99;
                FUN_0000_09b5(CONCAT11(uVar6,0x19));
                uVar6 = extraout_AH;
                if (extraout_AL == '\0') {
                  local_5 = -0x67;
                }
                else {
                  local_5 = -0x6d;
                }
              }
            }
            FUN_0000_0de4(uVar7,CONCAT11(uVar6,local_4),CONCAT11(uVar6,cVar2),CONCAT11(uVar6,cVar1))
            ;
            if (local_5 != '\0') {
              FUN_0000_0de4(0xdb,CONCAT11((char)((uint)(cVar2 + 1) >> 8),local_5),cVar2 + 1,cVar1);
            }
          }
          unaff_CS = 0xdb;
        }
      }
      if (local_7 == '\x06') break;
      local_7 = local_7 + '\x01';
    }
    if (local_6 == '\x06') break;
    local_6 = local_6 + '\x01';
  }
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 6) = 0;
  return;
}


