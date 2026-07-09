
void __cdecl16far FUN_187b_13fc(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 < 0x10) {
    LOCK();
    piVar1 = (int *)(param_1 * 2 + 0xa18);
    iVar2 = *piVar1;
    *piVar1 = 0;
    UNLOCK();
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 * 2 + 0x9f8);
      if (iVar2 != -1) {
        FUN_187b_1094(iVar2);
      }
      FUN_187b_0c86();
      return;
    }
  }
  return;
}


