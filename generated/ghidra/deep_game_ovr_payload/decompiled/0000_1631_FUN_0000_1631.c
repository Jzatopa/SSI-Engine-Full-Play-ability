
void __cdecl16far FUN_0000_1631(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  if (*(int *)0x7640 == 0 && *(int *)0x7642 == 0) {
    func_0x00000a86();
  }
  else {
    *(undefined2 *)0x4432 = *(undefined2 *)*(undefined4 *)0x7640;
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x7640 >> 0x10);
    iVar2 = (int)*(undefined4 *)0x7640;
    uVar1 = *(undefined2 *)(iVar2 + 4);
    *(undefined2 *)0x7644 = *(undefined2 *)(iVar2 + 2);
    *(undefined2 *)0x7646 = uVar1;
    FUN_0000_ce54();
    uVar1 = *(undefined2 *)0x7646;
    *(undefined2 *)0x7640 = *(undefined2 *)0x7644;
    *(undefined2 *)0x7642 = uVar1;
  }
  return;
}


