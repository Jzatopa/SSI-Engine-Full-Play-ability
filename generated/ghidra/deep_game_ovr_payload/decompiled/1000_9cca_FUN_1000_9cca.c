
void __stdcall16far FUN_1000_9cca(int param_1)

{
  undefined1 local_4;
  undefined1 local_3;
  
  local_3 = 0;
  while( true ) {
    local_4 = 0;
    while( true ) {
      FUN_0000_453c(param_1 + (uint)local_3 * 8 + (uint)local_4 * 4);
      if (local_4 == 1) break;
      local_4 = local_4 + 1;
    }
    if (local_3 == 0x23) break;
    local_3 = local_3 + 1;
  }
  return;
}


