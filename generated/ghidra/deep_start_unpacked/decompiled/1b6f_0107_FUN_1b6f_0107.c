
bool __stdcall16far FUN_1b6f_0107(char param_1,char param_2)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte local_9;
  undefined1 local_8 [2];
  undefined1 local_6 [2];
  byte local_4;
  bool local_3;
  
  local_3 = false;
  if (*(char *)0x8db8 != '\0') {
    local_4 = 0;
    local_9 = 0;
    cVar1 = FUN_1b6f_060d(&local_9,unaff_SS,local_8,unaff_SS,local_6,unaff_SS,param_2);
    if (cVar1 != '\0') {
      if (param_2 == '\x01') {
        if (param_1 == '\x01') {
          local_4 = 1;
        }
        else if (param_1 == '\x02') {
          local_4 = 2;
        }
      }
      else if (param_2 == '\x02') {
        if (param_1 == '\x01') {
          local_4 = 4;
        }
        else if (param_1 == '\x02') {
          local_4 = 8;
        }
      }
    }
    local_3 = (local_9 & local_4) != 0;
  }
  return local_3;
}


