/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:05bf
 * Ghidra name: FUN_1cc0_05bf
 * Linear address: 0x1D1BF
 * Body addresses: 60
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_05bf(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  uVar2 = (undefined2)((ulong)param_1 >> 0x10);
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 2) != -0x284f) {
    if (*(int *)(iVar1 + 2) != -0x284e) {
      *(undefined2 *)0x3dce = 0x67;
      return;
    }
    FUN_1cc0_05fb();
  }
  FUN_1cc0_05fb();
  *(undefined2 *)(iVar1 + 2) = 0xd7b0;
  return;
}


