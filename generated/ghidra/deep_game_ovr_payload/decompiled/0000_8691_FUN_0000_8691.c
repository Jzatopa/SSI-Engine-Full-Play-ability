
void FUN_0000_8691(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined1 uVar5;
  int unaff_BP;
  int iVar6;
  undefined2 uVar7;
  undefined2 unaff_CS;
  undefined2 uVar8;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  bool bVar10;
  
  bVar10 = *(int *)(unaff_BP + -4) == 0;
  bVar4 = *(int *)(unaff_BP + -2) == 0;
  bVar9 = bVar10 && bVar4;
  if (!bVar10 || !bVar4) {
    FUN_0000_d977();
    if (!bVar9) {
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
      *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
    }
    uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
    uVar8 = *(undefined2 *)(iVar6 + 0x101);
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar6 + 0xff);
    *(undefined2 *)(unaff_BP + -2) = uVar8;
    FUN_0000_8691();
    return;
  }
  *(undefined1 *)0x8c27 = 0;
  *(undefined1 *)0x4446 = 1;
  *(undefined1 *)0x3de5 = 0;
  uVar8 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
  *(undefined2 *)(unaff_BP + -2) = uVar8;
  if (((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0) &&
      (uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
      *(char *)((int)uVar3 + 0xf) != '\x01')) && (*(char *)0x3de5 == '\0')) {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x06') {
      *(undefined1 *)0x3de5 = 1;
    }
    uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
    uVar8 = *(undefined2 *)(iVar6 + 0x101);
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar6 + 0xff);
    *(undefined2 *)(unaff_BP + -2) = uVar8;
    FUN_0000_86f1();
    return;
  }
  uVar8 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
  *(undefined2 *)(unaff_BP + -2) = uVar8;
  *(undefined1 *)(unaff_BP + -7) = 0;
  while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
         (*(char *)(unaff_BP + -7) == '\0'))) {
    if (((*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) == '\0') ||
        ((uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
         *(char *)((int)uVar3 + 0xf) == '\x01' ||
         (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd6) != '\0')))) ||
       (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0x4c) != '\0')) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    *(undefined1 *)(unaff_BP + -7) = uVar5;
    uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
    uVar8 = *(undefined2 *)(iVar6 + 0x101);
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar6 + 0xff);
    *(undefined2 *)(unaff_BP + -2) = uVar8;
  }
  if (*(char *)(unaff_BP + -7) != '\0') {
    *(undefined1 *)0x4446 = 0;
  }
  *(undefined1 *)0x8c2c = 0;
  uVar8 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
  *(undefined2 *)(unaff_BP + -2) = uVar8;
  if ((*(char *)0x8c26 == '\0') && (*(char *)0x443a == '\0')) {
    while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
           (uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
           *(char *)((int)uVar3 + 0xf) != '\x01'))) {
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
      uVar8 = *(undefined2 *)(iVar6 + 0x101);
      *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) = *(undefined2 *)(iVar6 + 0xff);
      *(undefined2 *)(unaff_BP + -9) = uVar8;
      if ((*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x06') ||
         (((*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x01' &&
           (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd6) == '\0')) &&
          (*(byte *)((int)*(undefined4 *)(unaff_BP + -4) + 0xe7) < 0x80)))) {
        *(undefined1 *)0x4446 = 0;
      }
      if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x01') {
        *(undefined1 *)0x8c2c = 1;
        *(undefined1 *)0x3de5 = 0;
      }
      if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) == '\0') {
        *(char *)0x8c27 = *(char *)0x8c27 + '\x01';
      }
      ((undefined *)&DAT_0000_fffa)[unaff_BP] = 1;
      uVar8 = unaff_CS;
      while( true ) {
        unaff_CS = 0x92;
        func_0x0000094f(uVar8,0,0,
                        *(undefined1 *)((byte)((undefined *)&DAT_0000_fffa)[unaff_BP] + 0x2964),
                        *(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2));
        if (((undefined *)&DAT_0000_fffa)[unaff_BP] == '\x05') break;
        ((undefined *)&DAT_0000_fffa)[unaff_BP] = ((undefined *)&DAT_0000_fffa)[unaff_BP] + '\x01';
        uVar8 = unaff_CS;
      }
      uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
      uVar8 = *(undefined2 *)(iVar6 + 0x101);
      *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar6 + 0xff);
      *(undefined2 *)(unaff_BP + -2) = uVar8;
    }
    if (*(char *)0x8c2c != '\0') {
      FUN_0000_83df(unaff_CS,0x8c28);
      FUN_0000_85d1(*(undefined2 *)0x8c28,*(undefined2 *)0x8c2a);
    }
    uVar8 = *(undefined2 *)0x5801;
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
    *(undefined2 *)(unaff_BP + -2) = uVar8;
    if (*(char *)0x4446 == '\0') {
      while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
             (uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
             *(char *)((int)uVar3 + 0xf) != '\x01'))) {
        uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
        iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
        uVar8 = *(undefined2 *)(iVar6 + 0x101);
        *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) = *(undefined2 *)(iVar6 + 0xff);
        *(undefined2 *)(unaff_BP + -9) = uVar8;
        if (*(char *)0x3de5 == '\0') {
          cVar1 = *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4);
          if (cVar1 == '\x06') {
            *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
            *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
          }
          else if (cVar1 == '\x04') {
            if (*(char *)((int)*(undefined4 *)0x441c + 0x2e6) == '\0') {
              *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 5;
            }
            else {
              *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
              *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
              *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xe3) = 1;
            }
          }
          else if (cVar1 == '\x05') {
            if (*(int *)((int)*(undefined4 *)(unaff_BP + -4) + 0xe3) == 0) {
              if (*(char *)((int)*(undefined4 *)0x441c + 0x2e6) != '\0') {
                *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
                *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
                *(undefined2 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xe3) = 1;
              }
            }
            else {
              *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
              *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
            }
          }
        }
        else {
          *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c7) = 0x81;
          if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x06') {
            *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
            *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
          }
          else {
            uVar2 = *(uint *)(unaff_BP + -4);
            uVar8 = *(undefined2 *)(unaff_BP + -2);
            *(uint *)0x57fb = uVar2;
            *(undefined2 *)0x57fd = uVar8;
            FUN_0000_065a(unaff_CS,CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00);
            unaff_CS = 99;
          }
        }
        uVar8 = *(undefined2 *)(unaff_BP + -9);
        *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
        *(undefined2 *)(unaff_BP + -2) = uVar8;
      }
    }
    else {
      uVar8 = *(undefined2 *)0x5801;
      *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
      *(undefined2 *)(unaff_BP + -2) = uVar8;
      *(undefined1 *)(unaff_BP + -5) = 0;
      while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
             (*(char *)(unaff_BP + -5) == '\0'))) {
        uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3);
        if (*(char *)((int)uVar3 + 0xf) == '\x01') {
          *(undefined1 *)(unaff_BP + -5) = 1;
        }
        else {
          uVar2 = *(uint *)(unaff_BP + -4);
          uVar8 = *(undefined2 *)(unaff_BP + -2);
          *(uint *)0x57fb = uVar2;
          *(undefined2 *)0x57fd = uVar8;
          FUN_0000_065a(unaff_CS,CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00);
          unaff_CS = 99;
        }
        uVar7 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
        iVar6 = (int)*(undefined4 *)(unaff_BP + -4);
        uVar8 = *(undefined2 *)(iVar6 + 0x101);
        *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar6 + 0xff);
        *(undefined2 *)(unaff_BP + -2) = uVar8;
      }
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x33e) = 0;
    }
  }
  else {
    uVar8 = *(undefined2 *)0x57fd;
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57fb;
    *(undefined2 *)(unaff_BP + -2) = uVar8;
    bVar10 = *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) == '\x01';
    if (((bVar10) &&
        (bVar10 = *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x01', bVar10)) &&
       (bVar10 = true, *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd6) != '\x01')) {
      *(undefined1 *)0x8c2c = 1;
      FUN_0000_83df();
      FUN_0000_85d1(*(undefined2 *)0x8c28,*(undefined2 *)0x8c2a);
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c7) = 0;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c7) = 0x80;
      FUN_0000_d977();
      if (!bVar10) {
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 5;
      }
      if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x06') {
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) = 1;
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) = 1;
      }
    }
  }
  return;
}


