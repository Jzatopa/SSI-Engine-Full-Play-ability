
void __stdcall16far FUN_2000_7e91(undefined2 param_1,undefined2 param_2)

{
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 1;
  while( true ) {
    FUN_2000_768a(0,0,*(undefined1 *)(local_3 + 0xdd5),param_1,param_2);
    if (local_3 == 4) break;
    local_3 = local_3 + 1;
  }
  return;
}


