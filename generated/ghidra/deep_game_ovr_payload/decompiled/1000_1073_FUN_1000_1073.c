
void __stdcall16far FUN_1000_1073(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar3 = (int)*(undefined4 *)0x57fb;
  iVar1 = *(int *)(iVar3 + 0xeb);
  iVar3 = *(int *)(iVar3 + 0xed);
  if ((iVar1 != 0 || iVar3 != 0) &&
     ((uVar2 = (uint)*(byte *)(iVar1 + 0x2e) * 9, ((undefined *)&DAT_0000_5370)[uVar2] == '\x06' ||
      (*(char *)(iVar1 + 0x2e) == '#')))) {
    FUN_1000_0e7a(uVar2 & 0xff00);
  }
  return;
}


