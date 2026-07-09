
void __cdecl16far FUN_1bdc_030d(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  
  cVar2 = *(char *)0x9f45;
  *(undefined1 *)0x9f45 = 0;
  if (cVar2 == '\0') {
    pcVar1 = (code *)swi(0x16);
    cVar2 = (*pcVar1)();
    if (cVar2 == '\0') {
      *(undefined1 *)0x9f45 = extraout_AH;
    }
  }
  FUN_1bdc_0143();
  return;
}


