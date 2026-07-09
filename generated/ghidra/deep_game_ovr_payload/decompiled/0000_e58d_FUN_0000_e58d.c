
void __stdcall16far FUN_0000_e58d(void)

{
  char cVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    FUN_0000_db35();
    do {
      if (*(char *)(unaff_BP + -1) == '\x06') {
        if (*(char *)(unaff_BP + -2) == '\x01') {
          if (*(char *)0x4006 == '\x03') {
            FUN_0000_db35();
            if (*(char *)0x4007 == '\0') {
              FUN_0000_db35();
            }
            else {
              FUN_0000_db35();
            }
            cVar1 = FUN_0000_e281();
            if (cVar1 == '\0') {
              FUN_0000_db35();
            }
            else {
              FUN_0000_db35();
            }
            FUN_0000_db35();
          }
          cVar1 = FUN_0000_e281();
          if (cVar1 == '\x03') {
            if (*(char *)0x4006 == '\0') {
              FUN_0000_db35();
            }
            else {
              FUN_0000_db35();
            }
          }
          return;
        }
        *(char *)(unaff_BP + -2) = *(char *)(unaff_BP + -2) + '\x01';
        *(undefined1 *)(unaff_BP + -1) = 5;
      }
      else {
        *(char *)(unaff_BP + -1) = *(char *)(unaff_BP + -1) + '\x01';
      }
    } while (*(char *)((uint)*(byte *)(unaff_BP + -3) * 4 + (uint)*(byte *)(unaff_BP + -2) * 2 +
                       (uint)*(byte *)(unaff_BP + -1) + 0x78d) == -1);
  } while( true );
}


