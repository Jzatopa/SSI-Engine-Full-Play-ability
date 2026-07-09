
void __stdcall16far FUN_0000_e1ea(void)

{
  uint uVar1;
  int iVar2;
  undefined2 in_AX;
  int unaff_BP;
  undefined2 unaff_SS;
  
  do {
    FUN_0000_dbe2(unaff_BP,0x43,in_AX);
    do {
      while( true ) {
        while( true ) {
          do {
            if (*(char *)(unaff_BP + -1) == '\x06') {
              return;
            }
            *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
            uVar1 = FUN_0000_e1ea();
          } while (7 < uVar1);
          iVar2 = FUN_0000_e1ea();
          if (iVar2 != 0) break;
          FUN_0000_dbe2(unaff_BP,0x3e,2);
        }
        if (iVar2 != 1) break;
        FUN_0000_dbe2(unaff_BP,0x42,2);
      }
    } while (iVar2 != 2);
    in_AX = 2;
  } while( true );
}


