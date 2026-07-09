
void FUN_2000_a929(undefined2 param_1,char param_2,char param_3,int param_4,int param_5)

{
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_17 [9];
  undefined1 local_e;
  undefined1 local_c;
  byte local_b;
  undefined1 local_a;
  
  if ((param_2 < '\0') && (param_3 == '\0')) {
    unaff_CS = 0x602;
    func_0x00006e59();
  }
  local_e = 0;
  if (param_3 == '\0') {
    local_a = 0x1d;
    local_b = 0xf;
    local_c = 2;
  }
  else {
    local_a = 1;
    local_b = 0xe;
    if ((param_5 != *(int *)0x534c) || (param_4 != *(int *)0x534a)) {
      local_e = 3;
    }
    local_c = 3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x23fc,unaff_CS,local_17,unaff_SS,CONCAT11((char)(local_b - 1 >> 8),8));
}


