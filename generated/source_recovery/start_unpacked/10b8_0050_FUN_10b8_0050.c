/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10b8:0050
 * Ghidra name: FUN_10b8_0050
 * Linear address: 0x10BD0
 * Body addresses: 110
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_10b8_0050(int param_1)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar1 = (uint)*(byte *)(param_1 + 6) * 4;
  FUN_10b8_014f(*(undefined2 *)((uint)*(byte *)(param_1 + 6) * 2 + 0x7388),
                *(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -6),
                *(undefined2 *)(iVar1 + 0x739e),*(undefined2 *)(iVar1 + 0x73a0));
  FUN_10b8_0127(0x1e40,*(undefined2 *)((uint)*(byte *)0x739a * 4 + 0x739e),
                *(undefined2 *)((uint)*(byte *)0x739a * 4 + 0x73a0),
                (int)*(undefined4 *)0x73c2 + 0x1b,(int)((ulong)*(undefined4 *)0x73c2 >> 0x10),
                *(undefined2 *)(param_1 + -8),*(undefined2 *)(param_1 + -6));
  return;
}


