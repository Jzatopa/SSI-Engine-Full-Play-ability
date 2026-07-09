
void __stdcall16far FUN_1000_103a(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  
  uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar4 = (int)*(undefined4 *)0x57fb;
  uVar1 = *(uint *)(iVar4 + 0xeb);
  uVar2 = *(uint *)(iVar4 + 0xed);
  uVar3 = uVar1 | uVar2;
  if ((uVar3 != 0) && (*(char *)(uVar1 + 0x2e) == '$')) {
    FUN_1000_0e7a(uVar3 & 0xff00);
  }
  return;
}


