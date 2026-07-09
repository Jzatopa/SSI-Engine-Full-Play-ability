
void __stdcall16far FUN_3000_1ed8(undefined1 *param_1,undefined1 *param_2,char param_3,char param_4)

{
  undefined2 unaff_DS;
  
  if ((((param_4 < '\0') || ('1' < param_4)) || (param_3 < '\0')) || ('\x18' < param_3)) {
    *param_2 = 0;
    *param_1 = 0;
  }
  else {
    *param_1 = *(undefined1 *)((int)*(undefined4 *)0x71dc + param_3 * 0x32 + (int)param_4 + 7);
    *param_2 = ((undefined *)&DAT_0000_6ba1)[param_3 * 0x32 + (int)param_4];
  }
  return;
}


