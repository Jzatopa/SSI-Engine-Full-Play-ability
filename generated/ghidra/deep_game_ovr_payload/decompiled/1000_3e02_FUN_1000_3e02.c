
undefined1 __stdcall16far FUN_1000_3e02(byte param_1,byte param_2)

{
  undefined1 local_3;
  
  if (param_1 < 2) {
    local_3 = 0;
  }
  else if ((uint)param_1 * 3 >> 2 < (uint)param_2) {
    local_3 = 5;
  }
  else if (param_1 >> 1 < param_2) {
    local_3 = 2;
  }
  else {
    local_3 = 0;
  }
  return local_3;
}


