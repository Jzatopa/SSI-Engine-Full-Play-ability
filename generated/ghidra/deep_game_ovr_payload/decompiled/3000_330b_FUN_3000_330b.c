
void __stdcall16far FUN_3000_330b(byte param_1)

{
  undefined2 unaff_DS;
  
  if (*(int *)((uint)param_1 * 8 + 0x68c0) != 0 || *(int *)((uint)param_1 * 8 + 0x68c2) != 0) {
    FUN_0000_453c((uint)param_1 * 8 + 0x68c0);
  }
  if (*(int *)((uint)param_1 * 8 + 0x68c4) != 0 || *(int *)((uint)param_1 * 8 + 0x68c6) != 0) {
    FUN_0000_453c((uint)param_1 * 8 + 0x68c4);
  }
  return;
}


