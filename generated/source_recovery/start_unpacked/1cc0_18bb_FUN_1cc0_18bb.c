/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:18bb
 * Ghidra name: FUN_1cc0_18bb
 * Linear address: 0x1E4BB
 * Body addresses: 37
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_18bb(uint *param_1)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  undefined1 in_ZF;
  
  FUN_1cc0_18e0();
  if ((bool)in_ZF) {
    bVar3 = *param_1 < 4;
    if (4 < *param_1) {
      pcVar1 = (code *)swi(0x21);
      uVar2 = (*pcVar1)();
      if (bVar3) {
        *(undefined2 *)0x3dce = uVar2;
      }
    }
    ((uint *)param_1)[1] = 0xd7b0;
  }
  return;
}


