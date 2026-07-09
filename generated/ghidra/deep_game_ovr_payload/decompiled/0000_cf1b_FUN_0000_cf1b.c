
bool __stdcall16far FUN_0000_cf1b(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  char local_8;
  int local_7;
  int iStack_5;
  bool local_3;
  
  local_3 = false;
  cVar3 = FUN_0000_8695();
  if (cVar3 != '\0') {
    local_8 = FUN_0000_8527(0x836);
    if (local_8 == '\0') {
      local_8 = FUN_0000_8527(0x836);
    }
    if (local_8 == ' ') {
      iStack_5 = *(int *)0x5801;
      local_7 = *(int *)0x57ff;
      while (local_7 != 0 || iStack_5 != 0) {
        if (((*(char *)(local_7 + 0xd6) == '\0') && (*(char *)(local_7 + 0x4c) == '\0')) &&
           (*(char *)((int)*(undefined4 *)(local_7 + 0xf3) + 0xf) == '\0')) {
          *(undefined1 *)(local_7 + 0xd7) = 0;
        }
        piVar1 = (int *)(local_7 + 0xff);
        iStack_5 = *(int *)(local_7 + 0x101);
        local_7 = *piVar1;
      }
      uVar4 = (undefined2)((ulong)param_1 >> 0x10);
      local_3 = *(char *)((int)param_1 + 0xd7) == '\0';
      if (local_3) {
        uVar2 = *(undefined4 *)((int)param_1 + 0xf3);
        *(undefined1 *)((int)uVar2 + 1) = 0x14;
      }
    }
    else if (local_8 == '-') {
      FUN_0000_05cb(0x836);
    }
  }
  FUN_0000_872f();
  return local_3;
}


