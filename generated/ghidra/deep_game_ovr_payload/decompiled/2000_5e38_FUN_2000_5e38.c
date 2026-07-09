
void __stdcall16far FUN_2000_5e38(int param_1,char param_2,char param_3)

{
  int *piVar1;
  char cVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  cVar2 = FUN_2000_5507(param_2,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
  if (*(char *)(param_1 + 8) == '\0') {
    if ((uint)*(byte *)((int)*(undefined4 *)0x57fb + (uint)*(byte *)(param_1 + 10) + 0x4c) ==
        (int)param_3 - 1U) {
      *(char *)(*(int *)(param_1 + 6) + (int)param_2 + -0x15f) = cVar2;
      cVar2 = *(char *)((int)*(undefined4 *)0x57fb + (int)param_2 + 0x4c) - cVar2;
      if ('\0' < cVar2) {
        if (*(char *)0x40e8 == '\0') {
          piVar1 = (int *)(*(int *)(param_1 + 6) + -9);
          *piVar1 = *piVar1 + (int)cVar2;
          piVar1 = (int *)(*(int *)(param_1 + 6) + 0xc);
          *piVar1 = *piVar1 + (int)cVar2;
        }
        else {
          piVar1 = (int *)(*(int *)(param_1 + 6) + -9);
          *piVar1 = *piVar1 + (int)cVar2;
          piVar1 = (int *)(*(int *)(param_1 + 6) + 10);
          *piVar1 = *piVar1 + (int)cVar2;
        }
      }
      *(undefined1 *)((int)*(undefined4 *)0x57fb + (int)param_2 + 0x4c) = 0;
      *(undefined1 *)(param_1 + -2) = 1;
    }
  }
  else if ((uint)*(byte *)((int)*(undefined4 *)0x57fb + (uint)*(byte *)(param_1 + 10) + 0x4c) ==
           (int)param_3) {
    *(char *)((int)*(undefined4 *)0x57fb + (int)param_2 + 0x4c) = cVar2;
    *(char *)(*(int *)(param_1 + 6) + (int)param_2 + -0x15f) = cVar2;
    *(undefined1 *)(param_1 + -2) = 1;
  }
  return;
}


