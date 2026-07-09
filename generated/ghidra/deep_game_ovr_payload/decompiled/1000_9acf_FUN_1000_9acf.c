
void __stdcall16far FUN_1000_9acf(char param_1,char param_2)

{
  int *piVar1;
  char *pcVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  int local_6;
  int iStack_4;
  
  if (*(int *)0x57ff != 0 || *(int *)0x5801 != 0) {
    local_6 = *(int *)0x57ff;
    iStack_4 = *(int *)0x5801;
    if ((iStack_4 == *(int *)0x57fd) && (local_6 == *(int *)0x57fb)) {
      if (param_1 != '\0') {
        FUN_0000_0e7a();
      }
      uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
      iVar4 = (int)*(undefined4 *)0x57fb;
      uVar3 = *(undefined2 *)(iVar4 + 0x101);
      *(undefined2 *)0x57ff = *(undefined2 *)(iVar4 + 0xff);
      *(undefined2 *)0x5801 = uVar3;
      uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
      iVar4 = (int)*(undefined4 *)0x57fb;
      uVar3 = *(undefined2 *)(iVar4 + 0xff);
      uVar5 = *(undefined2 *)(iVar4 + 0x101);
      FUN_1000_7e0d(0x57fb,unaff_DS);
      *(undefined2 *)0x57fb = uVar3;
      *(undefined2 *)0x57fd = uVar5;
      if (param_2 == '\0') {
        pcVar2 = (char *)((int)*(undefined4 *)0x441c + 0x33e);
        *pcVar2 = *pcVar2 + -1;
      }
    }
    else {
      while (((*(int *)(local_6 + 0x101) != *(int *)0x57fd ||
              (*(int *)(local_6 + 0xff) != *(int *)0x57fb)) &&
             (*(int *)(local_6 + 0xff) != 0 || *(int *)(local_6 + 0x101) != 0))) {
        piVar1 = (int *)(local_6 + 0xff);
        iStack_4 = *(int *)(local_6 + 0x101);
        local_6 = *piVar1;
      }
      if (*(int *)(local_6 + 0xff) != 0 || *(int *)(local_6 + 0x101) != 0) {
        if (param_1 != '\0') {
          FUN_0000_0e7a();
        }
        uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
        iVar4 = (int)*(undefined4 *)0x57fb;
        uVar3 = *(undefined2 *)(iVar4 + 0x101);
        *(undefined2 *)(local_6 + 0xff) = *(undefined2 *)(iVar4 + 0xff);
        *(undefined2 *)(local_6 + 0x101) = uVar3;
        FUN_1000_7e0d(0x57fb,unaff_DS);
        *(int *)0x57fb = local_6;
        *(int *)0x57fd = iStack_4;
        if (param_2 == '\0') {
          pcVar2 = (char *)((int)*(undefined4 *)0x441c + 0x33e);
          *pcVar2 = *pcVar2 + -1;
        }
      }
    }
    if (*(int *)0x57fb == 0 && *(int *)0x57fd == 0) {
      uVar3 = *(undefined2 *)0x5801;
      *(undefined2 *)0x57fb = *(undefined2 *)0x57ff;
      *(undefined2 *)0x57fd = uVar3;
    }
  }
  return;
}


