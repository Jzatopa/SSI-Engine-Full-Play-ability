
/* WARNING: Removing unreachable block (ram,0x0000f31e) */

void __cdecl16far FUN_0000_f2b4(void)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined4 uVar4;
  undefined2 local_6;
  undefined2 uStack_4;
  
  uStack_4 = *(int *)0x5801;
  local_6 = *(int *)0x57ff;
  while (local_6 != 0 || uStack_4 != 0) {
    FUN_0000_0a05(unaff_CS,local_6,uStack_4);
    uVar4 = FUN_0000_ce3f(0x99,0x12);
    *(undefined2 *)(local_6 + 0xf3) = (int)uVar4;
    *(undefined2 *)(local_6 + 0xf5) = (int)((ulong)uVar4 >> 0x10);
    iVar3 = (int)*(undefined4 *)(local_6 + 0xf3);
    uVar1 = (undefined2)((ulong)*(undefined4 *)(local_6 + 0xf3) >> 0x10);
    unaff_CS = 0xcc0;
    FUN_0000_e6d2(0);
    bVar2 = *(byte *)(iVar3 + 0xe7) & 0x7f;
    if (((*(char *)(iVar3 + 0xd6) == '\0') &&
        (*(char *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xf) == '\x01')) &&
       ((bVar2 == 0 || (0x66 < bVar2)))) {
      *(char *)(iVar3 + 0xe7) = *(char *)((int)*(undefined4 *)0x441c + 0x2c6) + -0x80;
    }
    uStack_4 = *(int *)(iVar3 + 0x101);
    local_6 = *(int *)(iVar3 + 0xff);
  }
  return;
}


