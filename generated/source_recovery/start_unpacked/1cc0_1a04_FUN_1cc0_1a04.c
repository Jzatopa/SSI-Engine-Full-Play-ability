/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1a04
 * Ghidra name: FUN_1cc0_1a04
 * Linear address: 0x1E604
 * Body addresses: 69
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __cdecl16near FUN_1cc0_1a04(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  
  if (*(int *)((int)param_3 + 2) == -0x284d) {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  *(undefined2 *)0x3dce = 0x67;
  return 0;
}


