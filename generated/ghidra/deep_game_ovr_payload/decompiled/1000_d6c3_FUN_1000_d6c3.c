
undefined1 __stdcall16far FUN_1000_d6c3(uint param_1)

{
  undefined1 local_3;
  
  local_3 = 4;
  if ((0x4aff < param_1) && (param_1 < 0x4f00)) {
    local_3 = 0;
  }
  if ((0x7bff < param_1) && (param_1 < 0x8000)) {
    local_3 = 1;
  }
  if ((0x79ff < param_1) && (param_1 < 0x7c00)) {
    local_3 = 2;
  }
  if ((0x7fff < param_1) && (param_1 < 0xa401)) {
    local_3 = 3;
  }
  return local_3;
}


