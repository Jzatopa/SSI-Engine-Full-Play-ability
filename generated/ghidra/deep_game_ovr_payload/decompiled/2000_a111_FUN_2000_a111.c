
byte __stdcall16far FUN_2000_a111(int param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 unaff_DS;
  undefined1 *puVar3;
  byte local_301;
  undefined1 local_300 [765];
  byte local_3;
  
  puVar3 = local_300;
  FUN_0000_e6af(0xd8);
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 6) = 1;
  uVar1 = FUN_0000_0e20(0xcc0,param_3,param_4,puVar3);
  uVar1 = FUN_0000_0e25(param_3,param_4,uVar1);
  uVar1 = func_0x00000e2a(0xdb,param_3,param_4,0xff,0xff,uVar1);
  func_0x00000da9(0xdb,uVar1);
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 6) = 0;
  for (local_301 = 1;
      ((iVar2 = (uint)*(byte *)((uint)local_301 * 3 + 0x71de) * 4,
       *(int *)((undefined *)&DAT_0000_7081 + iVar2) != param_2 ||
       (*(int *)((undefined *)&DAT_0000_707f + iVar2) != param_1)) && (local_301 < *(byte *)0x71e0))
      ; local_301 = local_301 + 1) {
  }
  local_3 = *(byte *)((uint)local_301 * 3 + 0x71df) >> 1;
  FUN_0000_e6af(0xd8);
  return local_3;
}


