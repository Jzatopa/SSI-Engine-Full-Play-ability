
void FUN_0000_1c91(undefined2 param_1,char param_2)

{
  uint in_AX;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_4f [21];
  undefined1 local_3a;
  undefined1 local_7;
  
  if (param_2 != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x11f7,unaff_CS,local_4f,unaff_SS,in_AX & 0xff00);
  }
  *(undefined1 *)0x7457 = 1;
  local_7 = 0;
  local_3a = 0;
  func_0x000006da();
  return;
}


