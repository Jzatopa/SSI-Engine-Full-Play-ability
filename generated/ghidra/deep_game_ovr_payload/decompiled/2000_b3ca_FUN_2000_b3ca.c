
undefined1 __stdcall16far FUN_2000_b3ca(uint *param_1,char param_2,char param_3,undefined1 param_4)

{
  undefined1 uVar2;
  uint uVar1;
  uint *puVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  bool bVar7;
  uint local_e;
  uint local_c;
  uint local_a;
  undefined1 local_8;
  uint local_5;
  
  local_a = 0xd8f0;
  bVar7 = false;
  puVar3 = (uint *)param_1;
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  if (param_2 == '\0') {
    if (*param_1 == 0 && puVar3[1] == 0) {
      uVar1 = *(uint *)0x57fd;
      *param_1 = *(uint *)0x57fb;
      puVar3[1] = uVar1;
    }
  }
  else {
    uVar1 = *(uint *)0x5801;
    *param_1 = *(uint *)0x57ff;
    puVar3[1] = uVar1;
  }
  while (((*param_1 | puVar3[1]) != 0 && (!bVar7))) {
    uVar1 = FUN_2000_b375(CONCAT11((char)((*param_1 | puVar3[1]) >> 8),param_4),*param_1,puVar3[1]);
    local_5 = uVar1 & 0xff;
    uVar1 = 0;
    if (param_3 == '\0') {
      uVar1 = local_5 << 2;
      local_5 = uVar1;
    }
    else if (param_3 == '\x01') {
      uVar1 = local_5 << 1;
      local_5 = uVar1;
    }
    else if (param_3 == '\x03') {
      uVar1 = local_5 >> 1;
      local_5 = uVar1;
    }
    else if (param_3 == '\x04') {
      uVar1 = local_5 >> 2;
      local_5 = uVar1;
    }
    uVar2 = (undefined1)(uVar1 >> 8);
    uVar1 = FUN_2000_b552(CONCAT11(uVar2,100),CONCAT11(uVar2,1));
    uVar1 = local_5 - (uVar1 & 0xff);
    if ((int)local_a < (int)uVar1) {
      local_e = *param_1;
      local_c = puVar3[1];
      local_a = uVar1;
    }
    uVar6 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
    iVar4 = (int)*(undefined4 *)param_1;
    uVar1 = *(uint *)(iVar4 + 0x101);
    *param_1 = *(uint *)(iVar4 + 0xff);
    puVar3[1] = uVar1;
    bVar7 = param_2 == '\0';
  }
  uVar1 = (int)local_a >> 0xf;
  if ((int)local_a < 0) {
    uVar1 = (local_a ^ uVar1) - uVar1;
    bVar7 = -1 < (int)uVar1 >> 0xf;
    if (((int)uVar1 < 0 && bVar7) || ((bVar7 && (local_5 < uVar1)))) {
      local_8 = 0;
    }
    else {
      local_8 = 1;
    }
  }
  else if (((int)uVar1 < 0) || ((-1 < (int)local_a && (local_a < local_5 >> 1)))) {
    local_8 = 2;
  }
  else {
    local_8 = 3;
  }
  *param_1 = local_e;
  puVar3[1] = local_c;
  return local_8;
}


