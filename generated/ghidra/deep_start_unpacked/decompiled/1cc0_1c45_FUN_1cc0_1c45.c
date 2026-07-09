
void __cdecl16near FUN_1cc0_1c45(undefined2 param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if ((bool)in_CF) {
    *(undefined2 *)0x3dce = uVar2;
  }
  return;
}


