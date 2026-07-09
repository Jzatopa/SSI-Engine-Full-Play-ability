
void __stdcall16far FUN_3000_0e11(int *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  piVar1 = (int *)param_1;
  piVar1[7] = *param_1;
  piVar1[8] = piVar1[1];
  uVar3 = piVar1[2] - *param_1 >> 0xf;
  piVar1[5] = (piVar1[2] - *param_1 ^ uVar3) - uVar3;
  uVar3 = piVar1[3] - piVar1[1] >> 0xf;
  piVar1[6] = (piVar1[3] - piVar1[1] ^ uVar3) - uVar3;
  iVar2 = FUN_3000_0c71(piVar1[2] - *param_1);
  piVar1[9] = iVar2;
  iVar2 = FUN_3000_0c71(piVar1[3] - piVar1[1]);
  piVar1[10] = iVar2;
  piVar1[4] = 0;
  *(undefined1 *)(piVar1 + 0xb) = 0;
  return;
}


