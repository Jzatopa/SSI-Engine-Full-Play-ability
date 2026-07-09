
void __stdcall16far
FUN_1000_a0fa(int param_1,char param_2,undefined1 param_3,undefined2 param_4,char param_5,
             undefined1 param_6,undefined1 param_7)

{
  int iVar1;
  undefined1 extraout_AH;
  byte extraout_AH_00;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_15;
  undefined1 local_14 [16];
  undefined1 local_4;
  undefined1 local_3;
  
  if (param_2 == '\0') {
    if (*"" == '\0') {
      local_15 = '\b';
    }
    else {
      local_15 = '\b';
    }
  }
  else if (*"" == '\0') {
    local_15 = '\x0f';
  }
  else if (*"" == '\x02') {
    local_15 = '\a';
  }
  else {
    local_15 = -1;
  }
  if (local_15 < '\0') {
    uVar3 = 0xe5;
    func_0x00000e84();
  }
  else {
    uVar3 = 0x21a;
    func_0x000045b0();
  }
  uVar2 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar1 = (int)*(undefined4 *)0x57fb;
  local_3 = *(undefined1 *)(iVar1 + 0xb8);
  func_0x0000d5f6(uVar3,0x10,local_14);
  local_4 = *(undefined1 *)(iVar1 + 0xb9);
  *(undefined1 *)(iVar1 + 0xb9) = *(undefined1 *)(param_1 + -0x11d);
  if (param_5 == -1) {
    *(undefined1 *)(iVar1 + 0xb8) = ((undefined *)&DAT_0000_ffee)[param_1];
  }
  else if (param_5 != -2) {
    *(char *)(iVar1 + 0xb8) = param_5;
  }
  FUN_1000_9f1b(param_1,CONCAT11(extraout_AH,*(undefined1 *)(iVar1 + 0xb8)));
  func_0x00000e84(0xcc0,CONCAT11(extraout_AH_00,*(undefined1 *)(param_1 + -0x11d)),
                  CONCAT11(extraout_AH_00,param_3),(uint)extraout_AH_00 << 8,
                  CONCAT11(extraout_AH_00,param_6),CONCAT11(extraout_AH_00,param_7));
  *(undefined1 *)(iVar1 + 0xb8) = local_3;
  func_0x0000d5f6(0xe5,0x10,iVar1 + 0xc4,uVar2,local_14);
  *(undefined1 *)(iVar1 + 0xb9) = local_4;
  return;
}


