
void __stdcall16far FUN_1cc0_198d(uint param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  undefined1 in_ZF;
  
  uVar2 = (undefined2)((ulong)param_3 >> 0x10);
  FUN_1cc0_18e0();
  if ((bool)in_ZF) {
    bVar3 = CARRY2(param_2 * *(int *)((int)param_3 + 4),
                   (uint)((ulong)param_1 * (ulong)*(uint *)((int)param_3 + 4) >> 0x10));
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    if (bVar3) {
      *(undefined2 *)0x3dce = uVar2;
    }
  }
  return;
}


