
void __stdcall16far FUN_0000_dbe2(undefined2 param_1,undefined1 param_2,byte param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  bool bVar3;
  
  iVar1 = *(char *)0x4004 * 6 + *(char *)0x4005 * 5 + 0x15 + (uint)param_4;
  iVar2 = *(char *)0x4005 * 5 + 10 + (uint)param_3;
  if ((((-1 < iVar1) && (iVar2 < 0x32)) && (-1 < iVar2)) && (iVar2 < 0x19)) {
    bVar3 = (int)*(undefined4 *)0x71dc + iVar2 * 0x32 + iVar1 == 0;
    FUN_0000_d977();
    if (!bVar3) {
      FUN_0000_db35(CONCAT11(extraout_AH,param_2),CONCAT11(extraout_AH,param_3),
                    CONCAT11(extraout_AH,param_4));
    }
  }
  return;
}


