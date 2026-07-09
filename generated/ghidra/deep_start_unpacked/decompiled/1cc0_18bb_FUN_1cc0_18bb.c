
void __stdcall16far FUN_1cc0_18bb(uint *param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  undefined1 in_ZF;
  
  FUN_1cc0_18e0();
  if ((bool)in_ZF) {
    bVar3 = *param_1 < 4;
    if (4 < *param_1) {
      pcVar1 = (code *)swi(0x21);
      uVar2 = (*pcVar1)();
      if (bVar3) {
        *(undefined2 *)0x3dce = uVar2;
      }
    }
    ((uint *)param_1)[1] = 0xd7b0;
  }
  return;
}


