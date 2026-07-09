
void __stdcall16far FUN_2000_49cd(char param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  int local_6;
  int iStack_4;
  
  if ((*(char *)0x8d70 == '\0') || (*(char *)0x8d71 == '\0')) {
    if (*(int *)0x57fb == 0 && *(int *)0x57fd == 0) {
      uVar3 = *(undefined2 *)0x5801;
      *(undefined2 *)0x57fb = *(undefined2 *)0x57ff;
      *(undefined2 *)0x57fd = uVar3;
    }
    if (*(int *)0x57fb != 0 || *(int *)0x57fd != 0) {
      if (param_1 == 'H') {
        if ((*(int *)0x57fd == *(int *)0x5801) && (*(int *)0x57fb == *(int *)0x57ff)) {
          while (uVar3 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10),
                iVar2 = (int)*(undefined4 *)0x57fb,
                *(int *)(iVar2 + 0xff) != 0 || *(int *)(iVar2 + 0x101) != 0) {
            uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
            iVar2 = (int)*(undefined4 *)0x57fb;
            uVar3 = *(undefined2 *)(iVar2 + 0x101);
            *(undefined2 *)0x57fb = *(undefined2 *)(iVar2 + 0xff);
            *(undefined2 *)0x57fd = uVar3;
          }
        }
        else {
          iStack_4 = *(int *)0x5801;
          local_6 = *(int *)0x57ff;
          while ((local_6 != 0 || iStack_4 != 0 &&
                 ((*(int *)(local_6 + 0x101) != *(int *)0x57fd ||
                  (*(int *)(local_6 + 0xff) != *(int *)0x57fb))))) {
            piVar1 = (int *)(local_6 + 0xff);
            iStack_4 = *(int *)(local_6 + 0x101);
            local_6 = *piVar1;
          }
          *(int *)0x57fb = local_6;
          *(int *)0x57fd = iStack_4;
        }
      }
      else if (param_1 == 'P') {
        uVar3 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
        iVar2 = (int)*(undefined4 *)0x57fb;
        if (*(int *)(iVar2 + 0xff) == 0 && *(int *)(iVar2 + 0x101) == 0) {
          uVar3 = *(undefined2 *)0x5801;
          *(undefined2 *)0x57fb = *(undefined2 *)0x57ff;
          *(undefined2 *)0x57fd = uVar3;
        }
        else {
          uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
          iVar2 = (int)*(undefined4 *)0x57fb;
          uVar3 = *(undefined2 *)(iVar2 + 0x101);
          *(undefined2 *)0x57fb = *(undefined2 *)(iVar2 + 0xff);
          *(undefined2 *)0x57fd = uVar3;
        }
      }
    }
  }
  return;
}


