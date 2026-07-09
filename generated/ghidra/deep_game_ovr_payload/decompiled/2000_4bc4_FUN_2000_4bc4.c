
undefined2 __stdcall16far FUN_2000_4bc4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined4 uVar7;
  char local_c;
  char local_3;
  
  uVar6 = (undefined2)((ulong)param_1 >> 0x10);
  iVar5 = (int)param_1;
  iVar1 = *(int *)(iVar5 + 0xeb);
  iVar2 = *(int *)(iVar5 + 0xed);
  if (iVar1 == 0 && iVar2 == 0) {
    local_3 = '\x01';
    uVar4 = 0;
  }
  else {
    local_c = ((undefined *)&DAT_0000_5375)[(uint)*(byte *)(iVar1 + 0x2e) * 9];
    if ((local_c == '\0') || (local_c == -1)) {
      local_c = '\x01';
    }
    uVar3 = (uint)*(byte *)(iVar1 + 0x2e) * 9;
    if (((undefined *)&DAT_0000_5370)[uVar3] == '\b') {
      uVar7 = FUN_2000_3ea6(CONCAT11((char)(uVar3 >> 8),6),iVar5,uVar6);
      uVar3 = (uint)uVar7 | (uint)((ulong)uVar7 >> 0x10);
      if (uVar3 != 0) {
        local_c = '\f';
      }
    }
    uVar4 = (undefined1)(uVar3 >> 8);
    local_3 = local_c;
  }
  return CONCAT11(uVar4,local_3);
}


