
void __cdecl16far FUN_187b_0db8(void)

{
  code *pcVar1;
  undefined2 in_BX;
  undefined2 unaff_ES;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  uRam000108d8 = 0xdb1;
  uRam000108da = 0x1000;
  DAT_108d_004e = 1;
  pcVar1 = (code *)swi(0x21);
  uRam000109ac = in_BX;
  uRam000109ae = unaff_ES;
  (*pcVar1)();
                    /* WARNING: Call to offcut address within same function */
  func_0x0001959d(0x1000);
  return;
}


