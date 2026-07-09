
char __stdcall16far FUN_0000_d18e(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar5;
  uint uVar4;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  undefined2 uVar7;
  byte local_5;
  char local_4;
  char local_3;
  
  if ((*(char *)((int)*(undefined4 *)(param_1 + -0x21) + 2) != '\0') &&
     (*(char *)((int)*(undefined4 *)(param_1 + -0x10) + 0x38) == '\0')) {
    return '\0';
  }
  local_4 = *(char *)((int)*(undefined4 *)(param_1 + -0x21) + 5) *
            *(char *)((int)*(undefined4 *)(param_1 + -0x21) + 4) +
            *(char *)((int)*(undefined4 *)(param_1 + -0x21) + 6) * '\x02';
  bVar6 = *(char *)((int)*(undefined4 *)(param_1 + -0x10) + 0x2e) == '\x0f';
  if (bVar6) {
    if (*(int *)(param_1 + -4) != 0 || *(int *)(param_1 + -2) != 0) {
      unaff_CS = 0x99;
      cVar1 = func_0x00000a96();
      if (cVar1 != '\0') {
        local_4 = '\0';
        goto LAB_0000_d2c5;
      }
    }
    local_4 = '\f';
  }
  else {
    unaff_CS = 0xcc0;
    FUN_0000_d977();
    if (!bVar6) {
      if ((*(char *)(param_1 + 10) != '\0') &&
         ((bVar6 = *(char *)((int)*(undefined4 *)(param_1 + 0xc) + 0xd6) == '\x01',
          uVar5 = extraout_AH, bVar6 ||
          (FUN_0000_d977(0xcc0,0x1450,0xcc0,
                         CONCAT11(extraout_AH,
                                  *(undefined1 *)((int)*(undefined4 *)(param_1 + -0x10) + 0x2e))),
          uVar5 = extraout_AH_00, bVar6)))) {
        uVar4 = CONCAT11(uVar5,*(undefined1 *)((int)*(undefined4 *)0x4418 + 0xe6)) & 0xff10;
        bVar6 = (char)uVar4 == '\0';
        if ((bVar6) ||
           (FUN_0000_d977(0xcc0,0x1450,0xcc0,
                          CONCAT11((char)(uVar4 >> 8),
                                   *(undefined1 *)((int)*(undefined4 *)(param_1 + -0x10) + 0x2e))),
           bVar6)) {
          unaff_CS = 0xcc0;
          local_4 = FUN_0000_c5b3(*(undefined2 *)(param_1 + -0x10),
                                  *(undefined2 *)((undefined *)&DAT_0000_fff2 + param_1),
                                  *(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe));
          goto LAB_0000_d2c5;
        }
      }
      unaff_CS = 0xcc0;
      local_4 = '\0';
    }
  }
LAB_0000_d2c5:
  cVar2 = FUN_0000_09e2(unaff_CS,*(undefined2 *)(param_1 + -0x10),
                        *(undefined2 *)((undefined *)&DAT_0000_fff2 + param_1),
                        *(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe));
  cVar1 = *(char *)((int)*(undefined4 *)(param_1 + -0x10) + 0x32);
  if (*(char *)((int)*(undefined4 *)(param_1 + -0x21) + 2) == '\0') {
    cVar3 = func_0x000009d8(0x99,*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe));
    uVar7 = *(undefined2 *)(param_1 + 0xc);
    cVar3 = func_0x000009dd(0x99,uVar7,*(undefined2 *)(param_1 + 0xe),(int)cVar3 << 1);
    cVar3 = cVar3 * '\x02' + (char)uVar7;
  }
  else {
    cVar3 = FUN_0000_09d3(0x99,*(undefined2 *)(param_1 + 0xc),*(undefined2 *)(param_1 + 0xe));
    cVar3 = cVar3 * '\x02';
  }
  local_4 = local_4 + cVar1 * '\x03' + cVar2 * '\x03' + cVar3;
  local_5 = *(byte *)((int)*(undefined4 *)(param_1 + -0x21) + 1) >> 1;
  if (local_5 == 0) {
    local_5 = 1;
  }
  if ((*(char *)(param_1 + 10) == '\0') &&
     (6 < *(byte *)((int)*(undefined4 *)(param_1 + -0x21) + 2))) {
    local_3 = '\0';
  }
  else {
    local_3 = local_4 * local_5;
  }
  return local_3;
}


