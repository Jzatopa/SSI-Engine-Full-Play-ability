
undefined2 __stdcall16far FUN_0000_e8ed(int param_1)

{
  char cVar1;
  char cVar2;
  char extraout_AL;
  char extraout_AL_00;
  char extraout_AL_01;
  uint uVar3;
  undefined1 uVar5;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  int iVar4;
  undefined1 extraout_AH_01;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_6;
  char local_5;
  char local_4;
  char local_3;
  
  if (((undefined *)&DAT_0000_ffea)[param_1] == '\0') {
    FUN_0000_e892(param_1,*(undefined1 *)(param_1 + -9),*(undefined1 *)(param_1 + -8));
    uVar5 = extraout_AH;
    if (extraout_AL == '\0') {
      local_3 = '\0';
    }
    else if (*(char *)(param_1 + -7) == '\x06') {
      local_3 = '\x01';
    }
    else {
      iVar4 = (uint)*(byte *)(param_1 + 8) * 0xb;
      uVar3 = CONCAT11((char)((uint)iVar4 >> 8),*(undefined1 *)(iVar4 + 0x7cd)) & 0xff01;
      if ((char)uVar3 == '\0') {
        iVar4 = *(byte *)(param_1 + -8) + 1;
        FUN_0000_e892(param_1,CONCAT11((char)((uint)iVar4 >> 8),*(undefined1 *)(param_1 + -9)),iVar4
                     );
        uVar5 = extraout_AH_01;
        local_3 = extraout_AL_01;
      }
      else {
        FUN_0000_e892(param_1,*(byte *)(param_1 + -9) + 1,
                      CONCAT11((char)(uVar3 >> 8),*(undefined1 *)(param_1 + -8)));
        uVar5 = extraout_AH_00;
        local_3 = extraout_AL_00;
      }
    }
  }
  else {
    local_4 = '\x01';
    cVar1 = ((undefined *)&DAT_0000_ffea)[param_1];
    iVar4 = -(uint)(byte)((undefined *)&DAT_0000_ffea)[param_1];
    local_5 = (char)iVar4;
    if (local_5 <= cVar1) {
      do {
        cVar2 = ((undefined *)&DAT_0000_ffea)[param_1];
        uVar3 = -(uint)(byte)((undefined *)&DAT_0000_ffea)[param_1];
        local_6 = (char)uVar3;
        if (local_6 <= cVar2) {
          do {
            if (local_4 == '\0') {
LAB_0000_e97d:
              uVar3 = uVar3 & 0xff00;
            }
            else {
              uVar3 = FUN_0000_e892(param_1,(uint)*(byte *)(param_1 + -9) + (int)local_6,
                                    (uint)*(byte *)(param_1 + -8) + (int)local_5);
              if ((char)uVar3 == '\0') goto LAB_0000_e97d;
              uVar3 = CONCAT11((char)(uVar3 >> 8),1);
            }
            local_4 = (char)uVar3;
            uVar3 = CONCAT11((char)(uVar3 >> 8),local_6);
            if (local_6 == cVar2) break;
            local_6 = local_6 + '\x01';
          } while( true );
        }
        iVar4 = CONCAT11((char)(uVar3 >> 8),local_5);
        if (local_5 == cVar1) break;
        local_5 = local_5 + '\x01';
      } while( true );
    }
    uVar5 = (undefined1)((uint)iVar4 >> 8);
    local_3 = local_4;
  }
  return CONCAT11(uVar5,local_3);
}


