
void __stdcall16far FUN_1cc0_081a(undefined4 param_1)

{
  char cVar1;
  int in_BX;
  undefined1 in_ZF;
  
  FUN_1cc0_0776();
  if ((bool)in_ZF) {
    do {
      cVar1 = FUN_1cc0_079a();
      if (cVar1 == '\x1a') goto LAB_1cc0_083b;
      in_BX = in_BX + 1;
    } while (cVar1 != '\r');
    cVar1 = FUN_1cc0_079a();
    if (cVar1 == '\n') {
      in_BX = in_BX + 1;
    }
  }
LAB_1cc0_083b:
  *(int *)((int)param_1 + 8) = in_BX;
  FUN_1cc0_0879();
  return;
}


