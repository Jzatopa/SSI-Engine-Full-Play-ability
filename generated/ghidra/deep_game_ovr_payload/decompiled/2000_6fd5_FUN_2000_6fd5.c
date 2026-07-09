
void __stdcall16far FUN_2000_6fd5(byte param_1)

{
  int *piVar1;
  undefined2 unaff_DS;
  undefined2 local_6;
  undefined2 uStack_4;
  
  FUN_2000_6f30(4,param_1);
  uStack_4 = *(int *)0x5801;
  local_6 = *(int *)0x57ff;
  while (local_6 != 0 || uStack_4 != 0) {
    if (*(char *)(local_6 + 0xd4) == '\x05') {
      *(undefined1 *)(local_6 + 0xd4) = 1;
    }
    if (*(char *)(local_6 + 0xd4) == '\x01') {
      *(undefined1 *)(local_6 + 0xd5) = 1;
      *(int *)(local_6 + 0xe3) = *(int *)(local_6 + 0xe3) + (uint)param_1;
      if (*(uint *)(local_6 + 0x45) < *(uint *)(local_6 + 0xe3)) {
        *(undefined2 *)(local_6 + 0xe3) = *(undefined2 *)(local_6 + 0x45);
      }
    }
    piVar1 = (int *)(local_6 + 0xff);
    uStack_4 = *(int *)(local_6 + 0x101);
    local_6 = *piVar1;
  }
  return;
}


