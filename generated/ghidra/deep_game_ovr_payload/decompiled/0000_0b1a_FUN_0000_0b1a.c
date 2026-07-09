
void FUN_0000_0b1a(void)

{
  undefined2 in_AX;
  undefined2 uVar1;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  ((undefined *)&DAT_0000_7756)[in_BX + unaff_SI] =
       ((undefined *)&DAT_0000_7756)[in_BX + unaff_SI] + (char)((uint)in_AX >> 8);
  uVar1 = FUN_0000_06f8();
  *(undefined2 *)0x4432 = uVar1;
  return;
}


