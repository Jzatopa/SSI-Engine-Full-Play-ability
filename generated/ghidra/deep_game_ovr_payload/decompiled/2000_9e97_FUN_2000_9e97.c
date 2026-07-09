
void __stdcall16far FUN_2000_9e97(uint param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  int local_6;
  uint local_4;
  
  local_4 = 0;
  local_6 = 0;
  uVar3 = (undefined2)((ulong)param_2 >> 0x10);
  iVar2 = (int)param_2;
  if (*(uint *)(iVar2 + 0xe3) < param_1) {
    local_4 = param_1 - *(int *)(iVar2 + 0xe3);
  }
  else {
    local_6 = *(int *)(iVar2 + 0xe3) - param_1;
  }
  *(int *)(iVar2 + 0xe3) = local_6;
  if (local_4 < 0x1e) {
    if (local_4 < 10) {
      if (local_4 == 0) {
        if (local_6 != 0) {
          return;
        }
        *(undefined1 *)(iVar2 + 0xd4) = 5;
      }
      else {
        *(undefined1 *)(iVar2 + 0xd4) = 4;
        if (*(char *)0x4438 == '\x05') {
          *(undefined1 *)((int)*(undefined4 *)(iVar2 + 0xf3) + 0xc) = (undefined1)local_4;
        }
      }
    }
    else {
      *(undefined1 *)(iVar2 + 0xd4) = 8;
    }
  }
  else {
    *(undefined1 *)(iVar2 + 0xd4) = 3;
  }
  *(undefined1 *)(iVar2 + 0xd5) = 0;
  *(undefined2 *)(iVar2 + 0xe3) = 0;
  if (*(char *)0x4438 == '\x05') {
    pcVar1 = (char *)(*(char *)(iVar2 + 0xd6) + 0x72c2);
    *pcVar1 = *pcVar1 + -1;
    *(undefined1 *)((int)*(undefined4 *)(iVar2 + 0xf3) + 1) = 0;
  }
  return;
}


