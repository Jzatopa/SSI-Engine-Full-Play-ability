
undefined2 __cdecl16far FUN_19e3_1294(void)

{
  code *pcVar1;
  undefined2 in_BX;
  undefined2 unaff_ES;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  pcVar1 = (code *)swi(0x21);
  uRam00011290 = in_BX;
  uRam00011292 = unaff_ES;
  (*pcVar1)();
  out(0x43,0xb6);
  out(0x40,0xb1);
  out(0x40,0x13);
  return 0x1313;
}


