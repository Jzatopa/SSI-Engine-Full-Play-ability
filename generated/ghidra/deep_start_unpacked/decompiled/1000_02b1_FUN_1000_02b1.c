
void FUN_1000_02b1(void)

{
  char in_AL;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar1;
  byte extraout_AH_01;
  int unaff_BP;
  undefined2 uVar2;
  undefined2 unaff_DS;
  int iVar3;
  
  do {
    in_AL = in_AL + '\x01';
    do {
      *(char *)0x443a = in_AL;
      FUN_1784_0000(*(undefined2 *)0x232a);
      do {
        FUN_1784_0053();
        if (*(char *)0x443a == '\0') {
          *(undefined1 *)0x50d2 = 1;
        }
        else {
          *(undefined1 *)0x50d2 = 1;
          *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xfc) = 9;
        }
        uVar1 = extraout_AH;
        if (*(char *)0x443a == '\0') {
          FUN_1063_0025(0x1784);
          uVar2 = 0x1039;
          FUN_1039_0025(0x1063);
          *(undefined1 *)0x3dd8 = 1;
          while( true ) {
            if (*(char *)(*(byte *)0x3dd8 + 0x8d68) == '\0') {
              uVar2 = 0x1836;
              FUN_1836_0000();
            }
            if (*(char *)0x3dd8 == '\x04') break;
            *(char *)0x3dd8 = *(char *)0x3dd8 + '\x01';
          }
          FUN_1099_009d(uVar2);
          uVar1 = extraout_AH_00;
        }
        FUN_10d1_0025(CONCAT11(uVar1,*(undefined1 *)0x7367),CONCAT11(uVar1,*(undefined1 *)0x7366),
                      CONCAT11(uVar1,*(undefined1 *)0x7365),CONCAT11(uVar1,*(undefined1 *)0x7364));
        func_0x00010355();
        FUN_1048_002a();
      } while (*(char *)0x443a == '\0');
      FUN_1784_0000(*(undefined2 *)0x2328);
      func_0x00010325(0x1784);
      FUN_1836_03cf();
      *(undefined2 *)0x7459 = 3000;
      *(undefined2 *)0x745b = 0;
      *(undefined1 *)0x745d = 0x44;
      *(undefined2 *)0x736e = 0;
      FUN_1cc0_0ac2(0x1d,0x1836);
      iVar3 = unaff_BP + -0x1c;
      FUN_1cc0_0ac2(0x13,0x1cc0);
      func_0x00010b2e(0x1cc0,(uint)extraout_AH_01 << 8,(uint)extraout_AH_01 << 8,iVar3);
      *(undefined1 *)0x3dd6 = *(undefined1 *)0x7483;
      FUN_121a_283e(0x96c7,unaff_DS,0x10,0x10);
      *(undefined2 *)0x7459 = 0;
      *(undefined2 *)0x745b = 0;
      *(undefined1 *)0x745d = 0;
      in_AL = '\0';
    } while (*(char *)0x3dd6 != 'D');
  } while( true );
}


