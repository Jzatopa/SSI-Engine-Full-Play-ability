
ulong __stdcall16far FUN_1000_dd22(char param_1,uint param_2)

{
  byte bVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  ulong uVar2;
  undefined1 local_e;
  uint local_d;
  char local_8;
  char local_7;
  
  if ((param_1 == '\0') || (param_1 == '\x01')) {
    local_e = 1;
  }
  else if ((param_1 == '\x02') || (param_1 == '\x03')) {
    local_e = 2;
  }
  else if ((param_1 == '\x04') || (param_1 == '\x05')) {
    local_e = 4;
  }
  local_d = 0;
  uVar2 = 0;
  local_7 = FUN_1000_d6c3(param_2);
  local_8 = '\0';
  if (local_7 == '\0') {
    if (param_2 == 0x4bea) {
      local_d = (uint)*(byte *)0x736b;
    }
    else {
      FUN_0000_e6af(local_e);
    }
    uVar2 = (ulong)local_d;
  }
  else if (local_7 == '\x01') {
    uVar2 = FUN_1000_d71e(&local_8,unaff_SS,local_e,param_2);
    if (local_8 == '\0') {
      uVar2 = 0;
      FUN_0000_e6af(local_e);
    }
  }
  else if (local_7 == '\x02') {
    FUN_0000_e6af(local_e);
    uVar2 = 0;
  }
  else if (local_7 == '\x03') {
    FUN_0000_e6af(local_e);
    uVar2 = 0;
  }
  else if (local_7 == '\x04') {
    if (param_2 < 0xc04b) {
      if (param_2 == 0x33d) {
        local_d = (uint)*(byte *)0x736b;
      }
      uVar2 = (ulong)local_d;
    }
    else if (param_2 == 0xc04b) {
      uVar2 = (long)(int)*"s\x15 at sensor operation!\x0eShip Character\x01";
    }
    else if (param_2 == 0xc04c) {
      uVar2 = (long)(int)*"\x15 at sensor operation!\x0eShip Character\x01";
    }
    else if (param_2 == 0xc04d) {
      if ((*(byte *)((int)*(undefined4 *)0x4418 + 0xe6) & 0x20) == 0) {
        bVar1 = *(byte *)0x736b >> 1;
      }
      else {
        bVar1 = *(byte *)0x736b;
      }
      uVar2 = (ulong)bVar1;
    }
    else if (param_2 == 0xc04e) {
      uVar2 = (ulong)*(byte *)0x736c;
    }
    else {
      uVar2 = 0;
      if (param_2 == 0xc04f) {
        uVar2 = (ulong)*(byte *)0x736d;
      }
    }
  }
  return uVar2;
}


