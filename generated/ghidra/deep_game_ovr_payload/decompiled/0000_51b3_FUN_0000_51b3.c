
undefined2 __stdcall16far
FUN_0000_51b3(undefined2 param_1,undefined4 param_2,byte param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  char local_4;
  
  iVar1 = (int)param_5;
  iVar2 = (int)((ulong)param_5 >> 0x10);
  if ((int)param_2 == 0 && param_2._2_2_ == 0) {
    local_4 = *(char *)(iVar1 + 0x35);
  }
  else {
    local_4 = FUN_0000_09d3();
    local_4 = *(char *)((int)param_2 + 0x33) + local_4;
    if (*(char *)((int)param_2 + 0x28) == '\x01') {
      local_4 = local_4 + *(char *)((int)param_2 + 0x29);
    }
  }
  if ((iVar2 == *(int *)0x534c) && (iVar1 == *(int *)0x534a)) {
    local_4 = local_4 + '\x03';
  }
  local_4 = local_4 + *(char *)((uint)(*(byte *)(iVar1 + (uint)param_3 * 6 + 0x3c) & 0x7f) * 0x22 +
                               0x240c);
  if (*(char *)0x5359 < '\x05') {
    if ('\x02' < *(char *)0x5359) {
      local_4 = local_4 + -2;
    }
  }
  else {
    local_4 = local_4 + -5;
  }
  if (*(int *)(iVar1 + 0x1a) == 0) {
    local_4 = local_4 + -5;
  }
  uVar3 = (undefined2)((ulong)param_4 >> 0x10);
  iVar1 = (int)param_4;
  if (*(int *)(iVar1 + 0x1a) == 0) {
    local_4 = local_4 + '\x03';
  }
  iVar1 = (0x3c - (uint)*(byte *)(iVar1 + 0x32)) - (int)(char)(local_4 + *(char *)(iVar1 + 0x38));
  local_4 = (char)iVar1;
  if ('\x14' < local_4) {
    local_4 = '\x14';
  }
  return CONCAT11((char)((uint)iVar1 >> 8),local_4);
}


