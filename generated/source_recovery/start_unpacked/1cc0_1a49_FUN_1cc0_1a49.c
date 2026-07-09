/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1a49
 * Ghidra name: FUN_1cc0_1a49
 * Linear address: 0x1E649
 * Body addresses: 23
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_1a49(uint param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined2 in_stack_00000002;
  
  bVar3 = 0xffcf < param_1;
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)();
  if (bVar3) {
    *(undefined2 *)0x3dce = uVar2;
  }
  return;
}


