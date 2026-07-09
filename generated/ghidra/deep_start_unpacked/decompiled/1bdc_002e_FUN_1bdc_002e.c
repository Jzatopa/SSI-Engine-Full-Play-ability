
/* WARNING: Removing unreachable block (ram,0x0001be34) */

void __cdecl16near FUN_1bdc_002e(void)

{
  byte bVar1;
  byte extraout_AH;
  undefined2 unaff_DS;
  
  bVar1 = FUN_1bdc_0609();
  if ((bVar1 != 7) && (3 < bVar1)) {
    FUN_1bdc_0097();
  }
  FUN_1bdc_00e5();
  FUN_1bdc_0609();
  *(byte *)0x9f44 = extraout_AH & 0x7f;
  *(byte *)0x9f3a = extraout_AH & 0x7f;
  *(undefined1 *)0x9f35 = 0;
  *(undefined1 *)0x9f45 = 0;
  *(undefined1 *)0x9f46 = 0;
  *(undefined1 *)0x9f34 = 1;
  do {
  } while( true );
}


