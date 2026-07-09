
void __cdecl16far FUN_1000_eb60(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 unaff_DS;
  
  uVar2 = (undefined1)((uint)*(int *)0x4432 >> 8);
  *(undefined1 *)0x764f = *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x8000);
  bVar1 = *(byte *)0x764f;
  if (((((((bVar1 == 1) || (bVar1 == 2)) || (bVar1 == 10)) || ((bVar1 == 0xe || (bVar1 == 0x11))))
       || ((bVar1 == 0x12 || ((bVar1 == 0x20 || (bVar1 == 0x2d)))))) || (bVar1 == 0x32)) ||
     ((((bVar1 == 0x34 || (bVar1 == 0x36)) || (bVar1 == 0x38)) ||
      (((bVar1 == 0x39 || (bVar1 == 0x3c)) ||
       ((bVar1 == 0x43 || ((bVar1 == 0x48 || (bVar1 == 0x4b)))))))))) {
    FUN_1000_cf61(CONCAT11(uVar2,1));
  }
  else if (((bVar1 == 3) || (((bVar1 == 8 || (bVar1 == 9)) || (bVar1 == 0xf)))) ||
          ((((bVar1 == 0x10 || (bVar1 == 0x1f)) ||
            (((bVar1 == 0x41 || ((bVar1 == 0x40 || (bVar1 == 0x1d)))) || (bVar1 == 0x3f)))) ||
           (((bVar1 == 0x45 || (bVar1 == 0x46)) || (bVar1 == 0x4c)))))) {
    FUN_1000_cf61(CONCAT11(uVar2,2));
  }
  else if ((((bVar1 < 4) || (7 < bVar1)) && ((bVar1 != 0xb && ((bVar1 != 0xc && (bVar1 != 0x21))))))
          && ((bVar1 != 0x28 &&
              (((((bVar1 != 0x2a && (bVar1 != 0x2f)) && (bVar1 != 0x30)) &&
                ((bVar1 != 0x35 && (bVar1 != 0x37)))) &&
               ((bVar1 != 0x3b && ((bVar1 != 0x22 && (bVar1 != 0x23)))))))))) {
    if (bVar1 == 0x14) {
      FUN_1000_cf61(CONCAT11(uVar2,4));
    }
    else if (bVar1 == 0x2e) {
      FUN_1000_cf61(CONCAT11(uVar2,5));
    }
    else if ((bVar1 == 0x1e) || (bVar1 == 0x49)) {
      FUN_1000_cf61(CONCAT11(uVar2,6));
    }
    else {
      *(int *)0x4432 = *(int *)0x4432 + 1;
    }
  }
  else {
    FUN_1000_cf61(CONCAT11(uVar2,3));
  }
  return;
}


