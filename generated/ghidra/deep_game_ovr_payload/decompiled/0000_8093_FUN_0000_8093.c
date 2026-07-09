
undefined1 __stdcall16far FUN_0000_8093(undefined2 param_1,char param_2)

{
  undefined1 local_3;
  
  if (param_2 == '\a') {
    local_3 = 8;
  }
  else if (((param_2 == '\x02') || (param_2 == '\x04')) || (param_2 == '\b')) {
    local_3 = 7;
  }
  else {
    local_3 = 6;
  }
  return local_3;
}


