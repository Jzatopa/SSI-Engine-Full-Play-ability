
bool __stdcall16far FUN_2000_4c57(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 unaff_DS;
  int iVar11;
  int iVar12;
  undefined1 local_b [4];
  int local_7;
  int iStack_5;
  
  *(undefined1 *)0x40e6 = 0;
  iVar11 = (int)param_1;
  iVar12 = param_1._2_2_;
  cVar2 = FUN_0000_0e20();
  uVar9 = 0xdb;
  iVar8 = param_1._2_2_;
  cVar3 = FUN_0000_0e25((int)param_1,param_1._2_2_,iVar11,iVar12);
  iStack_5 = *(int *)0x5801;
  local_7 = *(int *)0x57ff;
  do {
    cVar6 = (char)iVar8;
    if (local_7 == 0 && iStack_5 == 0) {
      return *(char *)0x40e6 != '\0';
    }
    cVar4 = FUN_0000_0e20(uVar9,local_7,iStack_5,(int)cVar2);
    iVar8 = (int)cVar3;
    uVar9 = 0xdb;
    iVar11 = local_7;
    cVar5 = FUN_0000_0e25(local_7,iStack_5);
    cVar5 = (char)(cVar5 - iVar11);
    if (((*(char *)(local_7 + 0xd6) == '\0') &&
        (*(char *)((int)*(undefined4 *)(local_7 + 0xf3) + 0xf) == '\0')) &&
       ((*(char *)0x4438 != '\x05' ||
        ((((-2 < (char)(cVar4 - cVar6) && ((char)(cVar4 - cVar6) < '\x02')) && (-2 < cVar5)) &&
         (cVar5 < '\x02')))))) {
      if ((*(char *)(local_7 + 0xd4) == '\x04') &&
         ((uVar10 = uVar9, *(char *)((int)param_1 + 0x59) != '\0' ||
          (*(char *)((int)param_1 + 0x5d) != '\0')))) {
LAB_2000_4d71:
        *(char *)0x40e6 = *(char *)0x40e6 + '\x01';
        uVar9 = 0xdb;
        uVar7 = func_0x00000e2f(uVar10,local_7,iStack_5);
        ((undefined *)&DAT_0000_40dd)[*(byte *)0x40e6] = uVar7;
      }
      else if (*(char *)(local_7 + 0xd5) != '\0') {
        cVar6 = func_0x00000a96(0xdb,local_b);
        if (cVar6 == '\0') {
          uVar9 = 0x99;
          cVar6 = func_0x00000a96(0x99,local_b);
          if (cVar6 == '\0') goto LAB_2000_4d8d;
        }
        uVar9 = 0x99;
        uVar10 = uVar9;
        if (*(char *)((int)param_1 + 0x61) != '\0') goto LAB_2000_4d71;
      }
    }
LAB_2000_4d8d:
    piVar1 = (int *)(local_7 + 0xff);
    iStack_5 = *(int *)(local_7 + 0x101);
    local_7 = *piVar1;
  } while( true );
}


