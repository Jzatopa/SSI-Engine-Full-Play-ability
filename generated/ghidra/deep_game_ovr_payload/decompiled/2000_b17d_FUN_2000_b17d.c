
bool __stdcall16far FUN_2000_b17d(byte param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 uVar2;
  bool local_4;
  
  local_4 = false;
  uVar2 = (undefined2)((ulong)param_2 >> 0x10);
  iVar1 = (int)param_2;
  if (param_1 == 3) {
    local_4 = 9 < *(byte *)(iVar1 + 0x4e);
  }
  else if (param_1 == 4) {
    if ((0x1d < *(byte *)(iVar1 + 0x4d)) && (0x18 < *(byte *)(iVar1 + 0x4e))) {
      local_4 = true;
    }
  }
  else if (param_1 == 5) {
    local_4 = 9 < *(byte *)(iVar1 + 0x4e);
  }
  else if (param_1 == 6) {
    if ((9 < *(byte *)(iVar1 + 0x4d)) && (9 < *(byte *)(iVar1 + 0x4e))) {
      local_4 = true;
    }
  }
  else if (param_1 == 0xf) {
    local_4 = 0x27 < *(byte *)(iVar1 + 0x4d);
  }
  else if ((param_1 < 0x10) || (0x17 < param_1)) {
    if (param_1 == 0x1a) {
      if (((0x13 < *(byte *)(iVar1 + 0x99)) || (0x13 < *(byte *)(iVar1 + 0x90))) ||
         (0x13 < *(byte *)(iVar1 + 0x72))) {
        local_4 = true;
      }
    }
    else if (param_1 == 0x2b) {
      local_4 = 9 < *(byte *)(iVar1 + 0x67);
    }
    else if (param_1 == 0x2e) {
      if ((0x13 < *(byte *)(iVar1 + 0x70)) && (0x18 < *(byte *)(iVar1 + 0x67))) {
        local_4 = true;
      }
    }
    else if (param_1 == 0x2f) {
      if ((0xe < *(byte *)(iVar1 + 0x70)) && (0x18 < *(byte *)(iVar1 + 0x67))) {
        local_4 = true;
      }
    }
    else if (param_1 == 0x4b) {
      local_4 = 0x13 < *(byte *)(iVar1 + 0x96);
    }
    else if (param_1 == 0x54) {
      local_4 = 9 < *(byte *)(iVar1 + 0x6a);
    }
    else {
      local_4 = true;
    }
  }
  else if (*(char *)(iVar1 + 0x28) == '\x02') {
    if (param_1 == 0x12) {
      local_4 = 0x1d < *(byte *)(iVar1 + 0x5d);
    }
    else if (param_1 == 0x13) {
      local_4 = 0x27 < *(byte *)(iVar1 + 0x5e);
    }
    else if (param_1 == 0x14) {
      local_4 = 0xe < *(byte *)(iVar1 + 99);
    }
    else if (param_1 == 0x16) {
      local_4 = 0x18 < *(byte *)(iVar1 + 99);
    }
    else {
      local_4 = true;
    }
  }
  return local_4;
}


