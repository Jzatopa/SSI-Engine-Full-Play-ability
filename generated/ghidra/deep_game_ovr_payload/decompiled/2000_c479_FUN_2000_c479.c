
void __stdcall16far FUN_2000_c479(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte local_4;
  char local_3;
  
  local_3 = '\0';
  local_4 = *(byte *)(param_1 + -0x200);
  if (local_4 != 0) {
    for (; local_3 = local_3 + *(char *)(param_1 + (uint)local_4 + -0x200), local_4 != 1;
        local_4 = local_4 - 1) {
    }
  }
  if ((local_3 != *(char *)0x7482) && (*(char *)0x7482 != -1)) {
    *(undefined1 *)0x7457 = 1;
  }
  *(char *)0x7482 = local_3;
  return;
}


