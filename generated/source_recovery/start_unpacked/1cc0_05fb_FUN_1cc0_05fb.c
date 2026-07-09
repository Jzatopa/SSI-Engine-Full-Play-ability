/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:05fb
 * Ghidra name: FUN_1cc0_05fb
 * Linear address: 0x1D1FB
 * Body addresses: 17
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1cc0_05fb(void)

{
  int iVar1;
  int in_BX;
  int unaff_DI;
  undefined2 unaff_DS;
  
  iVar1 = (*(code *)*(undefined2 *)(in_BX + unaff_DI))(0x1cc0);
  if (iVar1 != 0) {
    *(int *)0x3dce = iVar1;
  }
  return;
}


