
void __cdecl16near FUN_1bdc_0143(void)

{
  code *pcVar1;
  undefined2 unaff_DS;
  undefined1 uVar2;
  
  if (*(char *)0x9f46 == '\0') {
    return;
  }
  *(undefined1 *)0x9f46 = 0;
  uVar2 = 0;
  while( true ) {
    pcVar1 = (code *)swi(0x16);
    (*pcVar1)();
    if ((bool)uVar2) break;
    pcVar1 = (code *)swi(0x16);
    (*pcVar1)();
  }
  FUN_1bdc_047c();
  FUN_1bdc_047c();
  FUN_1bdc_0475();
  pcVar1 = (code *)swi(0x23);
  (*pcVar1)();
  FUN_1bdc_0097();
  FUN_1bdc_00e5();
  *(undefined1 *)0x9f3a = *(undefined1 *)0x9f44;
  return;
}


