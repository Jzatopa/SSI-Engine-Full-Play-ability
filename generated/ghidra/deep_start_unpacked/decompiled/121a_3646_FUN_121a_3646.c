
void FUN_121a_3646(uint *param_1,uint *param_2,byte param_3,undefined2 param_4,uint param_5,
                  uint param_6)

{
  uint *puVar1;
  uint *puVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint local_1a;
  uint local_18;
  uint local_10;
  uint local_e;
  uint local_c;
  
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  puVar1 = (uint *)param_2;
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  puVar2 = (uint *)param_1;
  if (param_6 < 0x8001) {
    local_1a = 0;
  }
  else {
    local_1a = -param_6;
  }
  if (puVar2[1] < param_6 + puVar1[1]) {
    local_18 = (param_6 + puVar1[1]) - puVar2[1];
  }
  else {
    local_18 = 0;
  }
  if (param_5 < 0x8001) {
    local_10 = 0;
    local_e = param_5 * 8 * puVar2[1];
    if (*param_1 < param_5 * 8 + *param_2) {
      local_c = *param_1 + param_5 * -8;
    }
    else {
      local_c = *param_2;
    }
  }
  else {
    local_c = *param_2 + param_5 * 8;
    local_10 = param_5 * -8 * puVar1[1];
    local_e = 0;
  }
  if ((((local_1a <= puVar1[1]) && (local_18 <= puVar1[1])) && (local_10 <= puVar1[9])) &&
     ((local_e <= puVar2[9] && (local_c <= *param_2)))) {
    if ((param_3 & 1) == 0) {
      FUN_121a_37be();
      return;
    }
    FUN_121a_381d();
    return;
  }
  return;
}


