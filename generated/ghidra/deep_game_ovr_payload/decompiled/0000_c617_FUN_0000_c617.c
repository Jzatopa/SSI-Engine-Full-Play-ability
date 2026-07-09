
undefined2 __stdcall16far
FUN_0000_c617(undefined1 *param_1,byte param_2,byte param_3,undefined4 param_4)

{
  byte bVar1;
  undefined1 extraout_AH;
  int iVar2;
  undefined1 uVar4;
  uint uVar3;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined1 local_f;
  byte local_c;
  byte local_b;
  char local_a;
  undefined1 local_3;
  
  *param_1 = 0;
  local_f = 0;
  uVar6 = (undefined2)((ulong)param_4 >> 0x10);
  iVar5 = (int)param_4;
  bVar1 = *(byte *)((uint)*(byte *)((int)*(undefined4 *)(iVar5 + 0xf3) + 0x11) * 5 + (uint)param_3 +
                   0x6b0);
  func_0x00000e34();
  if (local_b == 0) {
    *param_1 = 1;
    uVar4 = extraout_AH;
  }
  else {
    uVar3 = (uint)local_b;
    if (((undefined *)&DAT_0000_26d8)[uVar3 * 4] == -1) {
      local_3 = 0;
      goto LAB_0000_c718;
    }
    if ((bool)((byte)((ulong)(long)(int)((uint)param_2 + (uint)bVar1) % 8) & 1)) {
      iVar2 = (uint)(byte)((undefined *)&DAT_0000_26d8)[(uint)local_b * 4] * 3;
      local_c = (byte)iVar2;
    }
    else {
      iVar2 = (uint)(byte)((undefined *)&DAT_0000_26d8)[(uint)local_b * 4] << 1;
      local_c = (byte)iVar2;
    }
    uVar4 = (undefined1)((uint)iVar2 >> 8);
    if (local_a == '\0') {
      if ((local_c < *(byte *)((int)*(undefined4 *)(iVar5 + 0xf3) + 3)) &&
         (local_c <= *(byte *)((int)*(undefined4 *)(iVar5 + 0xf3) + 3))) {
        local_f = 1;
      }
    }
  }
  uVar3 = CONCAT11(uVar4,local_f);
  local_3 = local_f;
LAB_0000_c718:
  return CONCAT11((char)(uVar3 >> 8),local_3);
}


