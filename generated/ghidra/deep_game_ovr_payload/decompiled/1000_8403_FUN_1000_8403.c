
void __stdcall16far FUN_1000_8403(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar3 = (int)*(undefined4 *)0x57fb;
  local_3 = 1;
  while( true ) {
    cVar1 = *(char *)(iVar3 + 0x28);
    bVar2 = *(byte *)(cVar1 * 8 + (uint)local_3 + 0xfdb);
    uVar4 = FUN_0000_088a(unaff_CS,CONCAT11(cVar1 >> 7,bVar2),*(undefined2 *)0x57fb,
                          *(undefined2 *)0x57fd);
    *(undefined1 *)(iVar3 + (uint)bVar2 + 0x4c) = uVar4;
    if (local_3 == 8) break;
    local_3 = local_3 + 1;
    unaff_CS = 0x86;
  }
  return;
}


