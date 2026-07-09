
bool __stdcall16far FUN_0000_e892(undefined2 param_1,char param_2,char param_3)

{
  undefined2 unaff_DS;
  bool local_3;
  
  if ((((param_3 < '\0') || ('1' < param_3)) || (param_2 < '\0')) || ('\x18' < param_2)) {
    local_3 = false;
  }
  else {
    local_3 = (int)*(undefined4 *)0x71dc + param_2 * 0x32 + (int)param_3 == 0;
    FUN_0000_d977();
    local_3 = !local_3;
  }
  return local_3;
}


