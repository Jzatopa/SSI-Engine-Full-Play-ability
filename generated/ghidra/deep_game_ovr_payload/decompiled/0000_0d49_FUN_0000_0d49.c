
void __cdecl16far FUN_0000_0d49(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar1 = FUN_0000_06f8();
  *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP) = uVar1;
  if (*(byte *)0x76d6 < 0x80) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_06d5(0x6b,1);
  }
  func_0x00000707(0x6b,0x7818);
  return;
}


