
void __stdcall16far FUN_1000_ea58(undefined4 param_1)

{
  undefined2 unaff_BP;
  undefined2 uVar1;
  undefined4 uVar2;
  
  func_0x0000dd51();
  FUN_0000_dd3d(unaff_BP);
  uVar2 = FUN_0000_dd55();
  uVar1 = (undefined2)((ulong)param_1 >> 0x10);
  *(undefined2 *)((int)param_1 + 0x2b) = (int)uVar2;
  *(undefined2 *)((int)param_1 + 0x2d) = (int)((ulong)uVar2 >> 0x10);
  return;
}


