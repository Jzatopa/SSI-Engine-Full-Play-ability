
void FUN_2000_a22f(undefined2 param_1,char param_2,undefined2 param_3,char param_4,int param_5,
                  int param_6)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte *pbVar1;
  undefined1 local_117 [256];
  char local_17;
  byte local_16 [7];
  undefined1 local_f [7];
  undefined1 local_8 [6];
  
  local_f[0] = 0;
  if ((((param_4 == '\x03') && (param_6 == *(int *)0x5350)) && (param_5 == *(int *)0x534e)) &&
     (*(char *)0x535b == '\0')) {
    func_0x0000d6dc();
    return;
  }
  pbVar1 = local_16;
  FUN_0000_e390(6);
  local_17 = (char)(5 - (uint)local_16[0]);
  if (local_17 != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(local_f,unaff_SS,local_117,unaff_SS,pbVar1);
  }
  if (param_2 < '\0') {
    param_2 = '\b';
  }
  if (param_4 == '\x01') {
    func_0x0000d6dc(0xcc0,5,local_8);
    return;
  }
  if (param_4 == '\x02') {
    func_0x0000d6dc(0xcc0,5,local_8);
    return;
  }
  local_8[0] = 0;
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(local_f,unaff_SS,local_117,unaff_SS,
                CONCAT11((char)(5 - (uint)local_16[0] >> 8),param_2));
}


