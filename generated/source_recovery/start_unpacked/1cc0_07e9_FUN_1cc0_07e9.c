/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:07e9
 * Ghidra name: FUN_1cc0_07e9
 * Linear address: 0x1D3E9
 * Body addresses: 49
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined4 __cdecl16near FUN_1cc0_07e9(void)

{
  int iVar1;
  undefined2 in_BX;
  int unaff_DI;
  undefined2 unaff_ES;
  
  *(undefined2 *)(unaff_DI + 8) = in_BX;
  iVar1 = (*(code *)*(undefined2 *)(unaff_DI + 0x14))(0x1cc0);
  if (iVar1 != 0) {
    DAT_1e87_3dce = iVar1;
  }
  return CONCAT22(*(undefined2 *)(unaff_DI + 4),*(undefined2 *)(unaff_DI + 10));
}


