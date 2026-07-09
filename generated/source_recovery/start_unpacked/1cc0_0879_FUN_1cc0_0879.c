/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0879
 * Ghidra name: FUN_1cc0_0879
 * Linear address: 0x1D479
 * Body addresses: 29
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

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


