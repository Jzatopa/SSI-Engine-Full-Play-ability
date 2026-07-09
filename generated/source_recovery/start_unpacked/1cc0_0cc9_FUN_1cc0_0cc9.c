/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0cc9
 * Ghidra name: FUN_1cc0_0cc9
 * Linear address: 0x1D8C9
 * Body addresses: 42
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_0cc9(uint param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  byte bVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  
  uVar7 = (undefined2)((ulong)param_3 >> 0x10);
  puVar6 = (undefined1 *)param_3;
  puVar5 = (undefined1 *)param_2;
  bVar4 = (byte)(param_1 >> 8);
  for (uVar3 = (uint)bVar4; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar1 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar1 = 0;
  }
  for (uVar3 = param_1 & 0xff; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  for (uVar3 = (uint)(byte)((' ' - (char)param_1) - bVar4); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar1 = puVar6;
    puVar6 = puVar6 + 1;
    *puVar1 = 0;
  }
  return;
}


