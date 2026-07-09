/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:02a8
 * Ghidra name: FUN_1c3e_02a8
 * Linear address: 0x1C688
 * Body addresses: 18
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1c3e_02a8(void)

{
  undefined1 *puVar1;
  uint in_AX;
  uint in_BX;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  if (in_BX <= in_AX) {
    in_AX = in_BX;
  }
  *unaff_DI = (char)in_AX;
  for (; unaff_DI = unaff_DI + 1, in_AX != 0; in_AX = in_AX - 1) {
    puVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *unaff_DI = *puVar1;
  }
  return;
}


