
undefined2 __cdecl16far FUN_19e3_12c9(void)

{
  code *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  out(0x40,0xff);
  out(0x40,0xff);
  uVar2 = in(0x61);
  uVar3 = CONCAT11(0xff,uVar2) & 0xfffc;
  out(0x61,(char)uVar3);
  out(0xc0,0x9f);
  out(0xc0,0xbf);
  out(0xc0,0xdf);
  out(0xc0,0xff);
  return CONCAT11((char)(uVar3 >> 8),0xff);
}


