
void __stdcall16far FUN_0000_db35(char param_1,char param_2,char param_3)

{
  undefined2 unaff_DS;
  
  param_3 = *(char *)0x4004 * '\x06' + *(char *)0x4005 * '\x05' + '\x15' + param_3;
  param_2 = *(char *)0x4005 * '\x05' + '\n' + param_2;
  if ((((-1 < param_3) && (param_3 < '2')) && (-1 < param_2)) && (param_2 < '\x19')) {
    *(char *)((int)*(undefined4 *)0x71dc + param_2 * 0x32 + (int)param_3 + 7) = param_1 + '\x01';
  }
  return;
}


