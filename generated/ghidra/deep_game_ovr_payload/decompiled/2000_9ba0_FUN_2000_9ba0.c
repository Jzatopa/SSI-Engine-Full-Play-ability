
undefined2 __stdcall16far FUN_2000_9ba0(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  *(undefined1 *)(iVar3 + 0xe5) = *(undefined1 *)(iVar3 + 0x36);
  uVar2 = FUN_2000_8cff(iVar3,uVar4);
  if (uVar2 >> 1 < *(uint *)(iVar3 + 0xe8)) {
    *(byte *)(iVar3 + 0xe5) = *(byte *)(iVar3 + 0xe5) >> 1;
  }
  *(undefined1 *)0x72c9 = *(undefined1 *)(iVar3 + 0xe5);
  if (*(char *)(iVar3 + 0xd6) == '\0') {
    *(char *)0x72c9 = *(char *)0x72c9 + *(char *)((int)*(undefined4 *)0x441c + 0x372);
  }
  bVar1 = *(byte *)0x72c9;
  *(undefined1 *)0x72c9 = (char)((uint)bVar1 << 1);
  return CONCAT11((char)(((uint)bVar1 << 1) >> 8),*(undefined1 *)0x72c9);
}


