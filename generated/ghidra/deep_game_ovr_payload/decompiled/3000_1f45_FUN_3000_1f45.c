
void __stdcall16far FUN_3000_1f45(byte param_1,char param_2,char param_3)

{
  char cVar1;
  undefined2 in_AX;
  undefined1 uVar3;
  int iVar2;
  undefined1 extraout_AH;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_8;
  char local_7;
  char local_6;
  char local_5;
  char local_4;
  char local_3;
  
  uVar3 = (undefined1)((uint)in_AX >> 8);
  if (param_1 == 0) {
    local_3 = param_3 + *(char *)((int)*(undefined4 *)0x71dc + 2);
    iVar2 = (int)param_2 + (int)*(char *)((int)*(undefined4 *)0x71dc + 3);
    local_4 = (char)iVar2;
    FUN_3000_1ed8(&local_8,unaff_SS,&param_1,unaff_SS,iVar2,
                  CONCAT11((char)((uint)iVar2 >> 8),local_3));
    uVar3 = extraout_AH;
  }
  if (param_1 == 0) {
    cVar1 = FUN_3000_209d(CONCAT11(uVar3,param_2),CONCAT11(uVar3,param_3));
    if (cVar1 != '\0') {
      FUN_3000_1908(local_4,local_3,param_2,param_3);
    }
  }
  else {
    param_3 = ((undefined *)&DAT_0000_6b10)[param_1];
    param_2 = ((undefined *)&DAT_0000_6b58)[param_1];
    local_3 = param_3 + *(char *)((int)*(undefined4 *)0x71dc + 2);
    local_4 = param_2 + *(char *)((int)*(undefined4 *)0x71dc + 3);
    uVar3 = ((undefined *)&DAT_0000_69f0)[(uint)param_1 * 4];
    local_7 = '\0';
    while( true ) {
      cVar1 = FUN_3000_181b(&local_6,unaff_SS,&local_5,unaff_SS,local_7,uVar3);
      if ((cVar1 != '\0') &&
         (cVar1 = FUN_3000_209d((int)param_2 + (int)local_6,(int)param_3 + (int)local_5),
         cVar1 != '\0')) {
        FUN_3000_1908((int)local_4 + (int)local_6,(int)local_3 + (int)local_5,
                      (int)param_2 + (int)local_6,(int)param_3 + (int)local_5);
      }
      if (local_7 == '\x03') break;
      local_7 = local_7 + '\x01';
    }
  }
  return;
}


