/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:08b5
 * Ghidra name: FUN_1cc0_08b5
 * Linear address: 0x1D4B5
 * Body addresses: 42
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_08b5(int param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 in_BX;
  undefined1 in_ZF;
  
  FUN_1cc0_07b6();
  if ((bool)in_ZF) {
    iVar1 = param_1 + -1;
    if (iVar1 != 0 && 0 < param_1) {
      do {
        FUN_1cc0_07da();
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    FUN_1cc0_07da();
  }
  *(undefined2 *)((int)param_3 + 8) = in_BX;
  return;
}


