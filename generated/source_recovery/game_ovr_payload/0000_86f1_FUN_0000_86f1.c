/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:86f1
 * Ghidra name: FUN_0000_86f1
 * Linear address: 0x086F1
 * Original GAME.OVR file offset: 34553
 * Body addresses: 62
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_86f1(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int unaff_BP;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_CS;
  undefined2 uVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  
  if (((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0) &&
      (uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
      *(char *)((int)uVar3 + 0xf) != '\x01')) && (*(char *)0x3de5 == '\0')) {
    if (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x06') {
      *(undefined1 *)0x3de5 = 1;
    }
    uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
    uVar7 = *(undefined2 *)(iVar5 + 0x101);
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar5 + 0xff);
    *(undefined2 *)(unaff_BP + -2) = uVar7;
    FUN_0000_86f1();
    return;
  }
  uVar7 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
  *(undefined2 *)(unaff_BP + -2) = uVar7;
  *(undefined1 *)(unaff_BP + -7) = 0;
  while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
         (*(char *)(unaff_BP + -7) == '\0'))) {
    if (((*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) == '\0') ||
        ((uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
         *(char *)((int)uVar3 + 0xf) == '\x01' ||
         (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd6) != '\0')))) ||
       (*(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0x4c) != '\0')) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    *(undefined1 *)(unaff_BP + -7) = uVar4;
    uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
    uVar7 = *(undefined2 *)(iVar5 + 0x101);
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar5 + 0xff);
    *(undefined2 *)(unaff_BP + -2) = uVar7;
  }
  if (*(char *)(unaff_BP + -7) != '\0') {
    *(undefined1 *)0x4446 = 0;
  }
  *(undefined1 *)0x8c2c = 0;
  uVar7 = *(undefined2 *)0x5801;
  *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
  *(undefined2 *)(unaff_BP + -2) = uVar7;
  if ((*(char *)0x8c26 == '\0') && (*(char *)0x443a == '\0')) {
    while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
           (uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
           *(char *)((int)uVar3 + 0xf) != '\x01'))) {
      uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
      uVar7 = *(undefined2 *)(iVar5 + 0x101);
      *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) = *(undefined2 *)(iVar5 + 0xff);
      *(undefined2 *)(unaff_BP + -9) = uVar7;
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
      uVar7 = unaff_CS;
      while( true ) {
        unaff_CS = 0x92;
        func_0x0000094f(uVar7,0,0,
                        *(undefined1 *)((byte)((undefined *)&DAT_0000_fffa)[unaff_BP] + 0x2964),
                        *(undefined2 *)(unaff_BP + -4),*(undefined2 *)(unaff_BP + -2));
        if (((undefined *)&DAT_0000_fffa)[unaff_BP] == '\x05') break;
        ((undefined *)&DAT_0000_fffa)[unaff_BP] = ((undefined *)&DAT_0000_fffa)[unaff_BP] + '\x01';
        uVar7 = unaff_CS;
      }
      uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
      iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
      uVar7 = *(undefined2 *)(iVar5 + 0x101);
      *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar5 + 0xff);
      *(undefined2 *)(unaff_BP + -2) = uVar7;
    }
    if (*(char *)0x8c2c != '\0') {
      FUN_0000_83df(unaff_CS,0x8c28);
      FUN_0000_85d1(*(undefined2 *)0x8c28,*(undefined2 *)0x8c2a);
    }
    uVar7 = *(undefined2 *)0x5801;
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
    *(undefined2 *)(unaff_BP + -2) = uVar7;
    if (*(char *)0x4446 == '\0') {
      while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
             (uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3),
             *(char *)((int)uVar3 + 0xf) != '\x01'))) {
        uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
        iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
        uVar7 = *(undefined2 *)(iVar5 + 0x101);
        *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) = *(undefined2 *)(iVar5 + 0xff);
        *(undefined2 *)(unaff_BP + -9) = uVar7;
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
            uVar7 = *(undefined2 *)(unaff_BP + -2);
            *(uint *)0x57fb = uVar2;
            *(undefined2 *)0x57fd = uVar7;
            FUN_0000_065a(unaff_CS,CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00);
            unaff_CS = 99;
          }
        }
        uVar7 = *(undefined2 *)(unaff_BP + -9);
        *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
        *(undefined2 *)(unaff_BP + -2) = uVar7;
      }
    }
    else {
      uVar7 = *(undefined2 *)0x5801;
      *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57ff;
      *(undefined2 *)(unaff_BP + -2) = uVar7;
      *(undefined1 *)(unaff_BP + -5) = 0;
      while ((*(int *)(unaff_BP + -4) != 0 || *(int *)(unaff_BP + -2) != 0 &&
             (*(char *)(unaff_BP + -5) == '\0'))) {
        uVar3 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + -4) + 0xf3);
        if (*(char *)((int)uVar3 + 0xf) == '\x01') {
          *(undefined1 *)(unaff_BP + -5) = 1;
        }
        else {
          uVar2 = *(uint *)(unaff_BP + -4);
          uVar7 = *(undefined2 *)(unaff_BP + -2);
          *(uint *)0x57fb = uVar2;
          *(undefined2 *)0x57fd = uVar7;
          FUN_0000_065a(unaff_CS,CONCAT11((char)(uVar2 >> 8),1),uVar2 & 0xff00);
          unaff_CS = 99;
        }
        uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
        iVar5 = (int)*(undefined4 *)(unaff_BP + -4);
        uVar7 = *(undefined2 *)(iVar5 + 0x101);
        *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar5 + 0xff);
        *(undefined2 *)(unaff_BP + -2) = uVar7;
      }
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x33e) = 0;
    }
  }
  else {
    uVar7 = *(undefined2 *)0x57fd;
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)0x57fb;
    *(undefined2 *)(unaff_BP + -2) = uVar7;
    bVar8 = *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd5) == '\x01';
    if (((bVar8) && (bVar8 = *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd4) == '\x01', bVar8)
        ) && (bVar8 = true, *(char *)((int)*(undefined4 *)(unaff_BP + -4) + 0xd6) != '\x01')) {
      *(undefined1 *)0x8c2c = 1;
      FUN_0000_83df();
      FUN_0000_85d1(*(undefined2 *)0x8c28,*(undefined2 *)0x8c2a);
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c7) = 0;
    }
    else {
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c7) = 0x80;
      FUN_0000_d977();
      if (!bVar8) {
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


