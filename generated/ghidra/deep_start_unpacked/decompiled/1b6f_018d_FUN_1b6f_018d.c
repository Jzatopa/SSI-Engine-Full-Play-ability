
void __stdcall16far FUN_1b6f_018d(undefined1 *param_1,undefined2 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  *param_2 = 0;
  cVar1 = FUN_1b6f_0107(2,1);
  if (cVar1 == '\0') {
    cVar1 = FUN_1b6f_0107(1,1);
    if (cVar1 != '\0') {
      *param_2 = 1;
    }
  }
  else {
    *param_2 = 2;
  }
  uVar2 = FUN_1b6f_003b(1);
  *param_1 = uVar2;
  return;
}


