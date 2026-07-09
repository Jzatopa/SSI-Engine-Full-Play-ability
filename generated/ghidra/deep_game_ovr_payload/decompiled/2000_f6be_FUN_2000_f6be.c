
void __cdecl16far FUN_2000_f6be(void)

{
  char cVar1;
  undefined2 unaff_CS;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  if ((*"" == '\x03') && (*"n!\x0eShip Character\x01" == '\0')) {
    cVar1 = *"";
    if (-1 < cVar1) {
      *(undefined1 *)0x7817 = 0;
      while( true ) {
        uVar2 = unaff_CS;
        if (*(int *)(*(char *)0x7817 * 4 + 0x739e) != 0 ||
            *(int *)(*(char *)0x7817 * 4 + 0x73a0) != 0) {
          if ((int)*(char *)0x7817 == (uint)*(byte *)0x739a) {
            uVar2 = 0xcc0;
            FUN_0000_ce54(unaff_CS,0x1e40,*(undefined2 *)(*(char *)0x7817 * 4 + 0x739e),
                          *(undefined2 *)(*(char *)0x7817 * 4 + 0x73a0));
          }
          else {
            uVar2 = 0xcc0;
            FUN_0000_ce54(unaff_CS,*(undefined2 *)(*(char *)0x7817 * 2 + 0x7388),
                          *(undefined2 *)(*(char *)0x7817 * 4 + 0x739e),
                          *(undefined2 *)(*(char *)0x7817 * 4 + 0x73a0));
          }
        }
        if (*(char *)0x7817 == cVar1) break;
        *(char *)0x7817 = *(char *)0x7817 + '\x01';
        unaff_CS = uVar2;
      }
    }
    FUN_0000_453c(0x73c2);
    FUN_0000_e6d2(0);
  }
  else {
    cVar1 = *"";
    if (-1 < cVar1) {
      *(undefined1 *)0x7817 = 0;
      while (FUN_0000_453c(*(char *)0x7817 * 4 + 0x73c6), *(char *)0x7817 != cVar1) {
        *(char *)0x7817 = *(char *)0x7817 + '\x01';
      }
    }
    FUN_0000_e6d2(0);
  }
  *(undefined1 *)0x7436 = 0;
  *(undefined1 *)0x7448 = 0xff;
  return;
}


