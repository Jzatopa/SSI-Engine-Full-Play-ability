
void __cdecl16near FUN_1cc0_0879(void)

{
  int iVar1;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  if (*(int *)(unaff_DI + 0x1a) == 0) {
    return;
  }
  if (*(int *)0x3dce == 0) {
    iVar1 = (*(code *)*(undefined2 *)(unaff_DI + 0x18))(0x1cc0);
    if (iVar1 != 0) {
      *(int *)0x3dce = iVar1;
    }
  }
  return;
}


