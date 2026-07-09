
undefined2 __stdcall16far FUN_0000_232e(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 unaff_DS;
  bool local_8;
  int iStack_5;
  
  local_8 = false;
  iStack_5 = *(int *)0x5801;
  iVar2 = *(int *)0x57ff;
  while ((iVar3 = iVar2, local_8 == false && (iVar3 = 0, iVar2 != 0 || iStack_5 != 0))) {
    local_8 = *(char *)(iVar2 + 0xd6) == '\x01';
    piVar1 = (int *)(iVar2 + 0xff);
    iStack_5 = *(int *)(iVar2 + 0x101);
    iVar2 = *piVar1;
  }
  return CONCAT11((char)((uint)iVar3 >> 8),local_8);
}


