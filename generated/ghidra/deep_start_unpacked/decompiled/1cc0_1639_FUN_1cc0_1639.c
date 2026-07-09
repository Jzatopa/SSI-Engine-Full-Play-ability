
void __cdecl16near FUN_1cc0_1639(void)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  iVar1 = *(int *)0x3dd2;
  lVar2 = (ulong)*(uint *)0x3dd0 * (ulong)DAT_113d_029f;
  uVar3 = (uint)lVar2;
  iVar5 = *(uint *)0x3dd0 << 3;
  cVar4 = (char)iVar5;
  iVar5 = (int)((ulong)lVar2 >> 0x10) + CONCAT11((char)((uint)iVar5 >> 8) + cVar4,cVar4) + iVar1 * 5
  ;
  *(int *)0x3dd0 = uVar3 + 1;
  *(int *)0x3dd2 =
       CONCAT11((char)((uint)iVar5 >> 8) + (char)iVar1 * '\x04' + (char)(iVar1 << 7),(char)iVar5) +
       (uint)(0xfffe < uVar3);
  return;
}


