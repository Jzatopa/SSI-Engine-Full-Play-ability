/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10b8:00be
 * Ghidra name: FUN_10b8_00be
 * Linear address: 0x10C3E
 * Body addresses: 105
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_10b8_00be(byte param_1)

{
  undefined4 uVar1;
  undefined2 unaff_DS;
  undefined4 uVar2;
  
  if (*(int *)0x739e != 0 || *(int *)0x73a0 != 0) {
    uVar2 = FUN_1cc0_023f(0x1e40);
    if (param_1 == *(byte *)0x739a) {
      uVar1 = *(undefined4 *)((uint)param_1 * 4 + 0x739e);
      FUN_1cc0_1aaf(0x1e40,(int)*(undefined4 *)0x73c2 + 0x1b,
                    (int)((ulong)*(undefined4 *)0x73c2 >> 0x10),(int)uVar1,
                    (int)((ulong)uVar1 >> 0x10));
    }
    else {
      FUN_10b8_0050(&stack0xfffe);
    }
    FUN_1cc0_0254(0x1e40,uVar2);
  }
  return;
}


