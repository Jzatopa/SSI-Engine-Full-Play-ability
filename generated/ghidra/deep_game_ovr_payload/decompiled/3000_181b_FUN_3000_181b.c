
undefined1 __stdcall16far FUN_3000_181b(undefined1 *param_1,char *param_2,byte param_3,byte param_4)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  if (param_4 != 0) {
    *param_2 = ((undefined *)&DAT_0000_293c)[(uint)param_4 * 8 + (uint)param_3 * 2];
    *param_1 = ((undefined *)&DAT_0000_293d)[(uint)param_4 * 8 + (uint)param_3 * 2];
    if (-1 < *param_2) {
      local_3 = 1;
    }
  }
  return local_3;
}


