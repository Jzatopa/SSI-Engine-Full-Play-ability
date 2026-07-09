
void FUN_0000_d3bf(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 unaff_DS;
  undefined4 in_stack_0000000a;
  int iVar9;
  int iVar10;
  sbyte local_31;
  sbyte local_30;
  sbyte local_2f;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a [4];
  undefined1 local_26;
  byte local_25;
  byte local_24;
  char *local_23;
  undefined4 local_1a;
  int local_12;
  int iStack_10;
  
  uVar6 = (undefined2)((ulong)in_stack_0000000a >> 0x10);
  iVar4 = (int)in_stack_0000000a;
  uVar7 = (undefined2)((ulong)*(undefined4 *)(iVar4 + 0xf3) >> 0x10);
  iVar5 = (int)*(undefined4 *)(iVar4 + 0xf3);
  iVar2 = *(int *)(iVar5 + 8);
  iVar5 = *(int *)(iVar5 + 10);
  local_1a = 0;
  local_24 = *(char *)(iVar4 + 0x3f) * *(char *)(iVar4 + 0x3d) + *(char *)(iVar4 + 0x41) * '\x02';
  local_2f = 0;
  local_30 = 0;
  local_31 = 0;
  if (iVar2 == 0 && iVar5 == 0) goto LAB_0000_d504;
  iVar9 = iVar2;
  iVar10 = iVar5;
  local_2b = FUN_0000_0e20();
  local_2c = FUN_0000_0e25(iVar2,iVar5,iVar9,iVar10);
  local_2e = 0xff;
  uVar7 = FUN_0000_0e20(0xdb,iVar4,uVar6);
  FUN_0000_0e25(iVar4,uVar6,uVar7);
  uVar7 = 0xd7;
  local_26 = FUN_0000_0da4(0xdb,&local_2e);
  if (*(char *)0x4135 == '\0') {
    uVar7 = 0x99;
    cVar3 = func_0x00000a96(0xd7,local_2a);
    if (cVar3 != '\0') goto LAB_0000_d4a3;
  }
  else {
LAB_0000_d4a3:
    local_2f = 3;
  }
  uVar8 = uVar7;
  if (*(char *)0x4134 == '\0') {
    if ((*(byte *)(iVar2 + 0x48) & 0x10) == 0) {
      uVar8 = 0x99;
      cVar3 = func_0x00000a96(uVar7,local_2a);
      if (cVar3 == '\0') goto LAB_0000_d4dc;
    }
    local_31 = 2;
  }
  else {
    local_31 = 3;
  }
LAB_0000_d4dc:
  if (((*(byte *)(iVar2 + 0x48) & 0x40) != 0) ||
     (cVar3 = func_0x00000a96(uVar8,local_2a), cVar3 != '\0')) {
    local_30 = 3;
  }
LAB_0000_d504:
  iStack_10 = *(int *)(iVar4 + 0xf9);
  local_12 = *(int *)(iVar4 + 0xf7);
  while (local_12 != 0 || iStack_10 != 0) {
    iVar2 = (uint)*(byte *)(local_12 + 0x2e) * 9;
    _local_23 = (char *)CONCAT22(unaff_DS,(undefined *)&DAT_0000_536e + iVar2);
    if (*_local_23 == '\0') {
      local_25 = FUN_0000_d18e(&stack0xfffe);
      cVar3 = ((char *)_local_23)[2];
      if (cVar3 == '\x02') {
        local_25 = local_25 >> local_31;
      }
      else if (cVar3 == '\x03') {
        local_25 = local_25 >> local_2f;
      }
      else if (cVar3 == '\x04') {
        local_25 = local_25 >> local_30;
      }
      if (local_24 < local_25) {
        local_24 = local_25;
      }
    }
    else if (*_local_23 == '\x01') {
      if (((int)local_1a == 0 && local_1a._2_2_ == 0) ||
         ((int)((uint)(byte)((undefined *)&DAT_0000_5370)[(uint)*(byte *)((int)local_1a + 0x2e) * 9]
               + (int)*(char *)((int)local_1a + 0x32)) <
          (int)((uint)(byte)((undefined *)&DAT_0000_5370)[iVar2] + (int)*(char *)(local_12 + 0x32)))
         ) {
        local_1a = CONCAT22(iStack_10,local_12);
      }
    }
    piVar1 = (int *)(local_12 + 0x2a);
    iStack_10 = *(int *)(local_12 + 0x2c);
    local_12 = *piVar1;
  }
  FUN_0000_d64a();
  return;
}


