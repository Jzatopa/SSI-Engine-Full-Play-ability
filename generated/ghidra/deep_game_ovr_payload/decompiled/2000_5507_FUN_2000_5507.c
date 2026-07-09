
undefined1 __stdcall16far FUN_2000_5507(char param_1,undefined4 param_2)

{
  char cVar1;
  undefined1 local_3;
  
  local_3 = 0;
  cVar1 = FUN_0000_0a78(param_1,(int)param_2,param_2._2_2_);
  if ((cVar1 != '\0') &&
     ((((*(char *)((int)param_2 + 0x28) == '\x01' && ('2' < param_1)) && (param_1 < '<')) ||
      ((*(char *)((int)param_2 + 0x28) == '\x05' &&
       ((((param_1 == '\a' || (param_1 == '\b')) ||
         ((param_1 == '>' || ((param_1 == '?' || (param_1 == '=')))))) ||
        ((param_1 == 'A' ||
         ((((param_1 == 'K' || (param_1 == 'R')) || (param_1 == 'S')) || (param_1 == 'L'))))))))))))
  {
    local_3 = 10;
  }
  return local_3;
}


