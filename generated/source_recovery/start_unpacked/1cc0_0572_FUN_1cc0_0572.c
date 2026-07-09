/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0572
 * Ghidra name: FUN_1cc0_0572
 * Linear address: 0x1D172
 * Body addresses: 73
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_0572(undefined4 param_1)

{
  int iVar1;
  undefined2 in_DX;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  bool bVar4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 2);
  if ((iVar1 == -0x284f) || (iVar1 == -0x284e)) {
    FUN_1cc0_05bf(iVar2,uVar3);
  }
  else if (iVar1 != -0x2850) {
    *(undefined2 *)0x3dce = 0x66;
    return;
  }
  bVar4 = true;
  *(undefined2 *)(iVar2 + 2) = in_DX;
  *(undefined2 *)(iVar2 + 8) = 0;
  *(undefined2 *)(iVar2 + 10) = 0;
  FUN_1cc0_05fb();
  if (!bVar4) {
    *(undefined2 *)(iVar2 + 2) = 0xd7b0;
  }
  return;
}


