/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:079a
 * Ghidra name: FUN_1cc0_079a
 * Linear address: 0x1D39A
 * Body addresses: 28
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __cdecl16near FUN_1cc0_079a(undefined4 param_1)

{
  int iVar1;
  int in_DX;
  int in_BX;
  int unaff_DI;
  undefined2 unaff_ES;
  
  if (in_BX == in_DX) {
    unaff_ES = (undefined2)((ulong)param_1 >> 0x10);
    unaff_DI = (int)param_1;
    iVar1 = FUN_1cc0_07e9();
    if (in_BX == iVar1) {
      return 0x1a;
    }
  }
  return *(undefined1 *)(in_BX + unaff_DI);
}


