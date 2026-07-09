
void __stdcall16far FUN_1000_83a6(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_3;
  
  for (local_3 = '\0';
      *(char *)((int)*(undefined4 *)(param_1 + -4) + (int)local_3 + 0x1e) =
           ((undefined *)&DAT_0000_3562)[local_3] -
           ((undefined *)&DAT_0000_351a)
           [*(char *)((int)*(undefined4 *)(param_1 + -4) + 0x27) * 8 + (int)local_3],
      local_3 != '\a'; local_3 = local_3 + '\x01') {
  }
  return;
}


