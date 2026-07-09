
void __stdcall16far FUN_2000_8517(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  iVar2 = *(int *)(iVar5 + 0xeb);
  iVar3 = *(int *)(iVar5 + 0xed);
  if (iVar2 != 0 || iVar3 != 0) {
    bVar1 = *(byte *)(iVar2 + 0x2e);
    *(undefined1 *)(iVar5 + 0xd8) = *(undefined1 *)(iVar5 + 0x33);
    *(undefined1 *)(iVar5 + 0xe1) = ((undefined *)&DAT_0000_5374)[(uint)bVar1 * 9];
    if (((undefined *)&DAT_0000_5370)[(uint)bVar1 * 9] == '\0') {
      cVar4 = FUN_2000_8cbd(iVar5,uVar6);
      *(char *)(iVar5 + 0xd8) = *(char *)(iVar5 + 0xd8) + cVar4;
      cVar4 = FUN_2000_8cde(iVar5,uVar6);
      *(char *)(iVar5 + 0xe1) = *(char *)(iVar5 + 0xe1) + cVar4;
    }
    else {
      cVar4 = FUN_2000_8c9c(iVar5,uVar6);
      *(char *)(iVar5 + 0xd8) = *(char *)(iVar5 + 0xd8) + cVar4;
    }
    cVar4 = FUN_2000_8c30(iVar2,iVar3,iVar5,uVar6);
    cVar4 = *(char *)(iVar2 + 0x32) + cVar4;
    if (bVar1 != 0xf) {
      *(char *)(iVar5 + 0xe1) = *(char *)(iVar5 + 0xe1) + cVar4;
    }
    *(char *)(iVar5 + 0xd8) = *(char *)(iVar5 + 0xd8) + cVar4;
    *(undefined1 *)(iVar5 + 0xdd) = ((undefined *)&DAT_0000_5372)[(uint)bVar1 * 9];
    *(undefined1 *)(iVar5 + 0xdf) = ((undefined *)&DAT_0000_5373)[(uint)bVar1 * 9];
  }
  return;
}


