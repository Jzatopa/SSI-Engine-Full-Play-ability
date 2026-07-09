/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:239c
 * Ghidra name: FUN_121a_239c
 * Linear address: 0x1453C
 * Body addresses: 116
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_121a_239c(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  piVar2 = (int *)param_1;
  if (*param_1 != 0 || piVar2[1] != 0) {
    uVar4 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
    iVar1 = (int)*(undefined4 *)param_1;
    if (*(int *)(iVar1 + 0x17) != 0 || *(int *)(iVar1 + 0x19) != 0) {
      FUN_1cc0_0254(*(int *)(iVar1 + 0x12) * *(int *)(iVar1 + 8),*(undefined2 *)(iVar1 + 0x17),
                    *(undefined2 *)(iVar1 + 0x19));
    }
    FUN_1cc0_0254(*(undefined2 *)(iVar1 + 0x14),*param_1,piVar2[1]);
    *param_1 = 0;
    piVar2[1] = 0;
  }
  return;
}


