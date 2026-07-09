
void __stdcall16far FUN_2000_87f5(char param_1,undefined2 param_2,undefined2 param_3)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  char local_d;
  char local_c;
  undefined1 local_b;
  int local_6;
  int iStack_4;
  
  if (((*(char *)0x4438 != '\t') && (*(char *)0x4438 != '\x03')) && (*(char *)0x443d == '\0')) {
    if (*(int *)0x57f7 == 0 && *(int *)0x57f9 == 0) {
      *(undefined2 *)0x57f7 = param_2;
      *(undefined2 *)0x57f9 = param_3;
    }
    if (*(char *)0x4438 == '\0') {
      local_b = 1;
    }
    else {
      local_b = 0x11;
    }
    *(undefined1 *)0x7479 = local_b;
    *(undefined1 *)0x747b = 4;
    *(undefined1 *)0x747a = 0x26;
    *(undefined1 *)0x747c = 3;
    local_c = '\x04';
    iStack_4 = *(int *)0x5801;
    local_6 = *(int *)0x57ff;
    while (local_6 != 0 || iStack_4 != 0) {
      *(char *)0x747c = *(char *)0x747c + '\x01';
      if ((iStack_4 == *(int *)0x57f9) && (local_6 == *(int *)0x57f7)) {
        bVar3 = (byte)((uint)local_6 >> 8);
        if (param_1 != '\0') {
                    /* WARNING: Subroutine does not return */
          FUN_0000_643a(unaff_CS,local_6,iStack_4,(uint)bVar3 << 8,CONCAT11(bVar3,0xf),
                        CONCAT11(bVar3,local_c),CONCAT11(bVar3,local_b));
        }
        FUN_0000_0b15(unaff_CS,(uint)bVar3 << 8,CONCAT11(bVar3,local_c),CONCAT11(bVar3,local_b),
                      local_6,iStack_4);
        bVar3 = *(byte *)(local_6 + 0xd9);
        if (bVar3 < 0x33) {
          local_d = '\x01';
        }
        else if ((bVar3 < 0x33) || (0x3c < bVar3)) {
          if ((bVar3 < 0x3d) || (0x45 < bVar3)) {
            local_d = '\0';
          }
          else {
            local_d = '\x01';
          }
        }
        else {
          local_d = '\x02';
        }
        FUN_0000_0b1f(local_c,local_d + ' ',local_6,iStack_4);
        uVar2 = *(uint *)(local_6 + 0xe3);
        if (uVar2 < 10) {
          local_d = '\x02';
        }
        else if ((uVar2 < 10) || (99 < uVar2)) {
          local_d = '\0';
        }
        else {
          local_d = '\x01';
        }
        unaff_CS = 0xaf;
        func_0x00000b24(0xaf,0,0,local_c,local_d + '$',local_6,iStack_4);
      }
      local_c = local_c + '\x01';
      piVar1 = (int *)(local_6 + 0xff);
      iStack_4 = *(int *)(local_6 + 0x101);
      local_6 = *piVar1;
    }
    func_0x00001140(unaff_CS,local_c,0x26,local_c,local_b);
    *(undefined2 *)0x57f7 = 0;
    *(undefined2 *)0x57f9 = 0;
  }
  return;
}


