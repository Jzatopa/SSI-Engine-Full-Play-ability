/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0bc7
 * Ghidra name: FUN_1cc0_0bc7
 * Linear address: 0x1D7C7
 * Body addresses: 43
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_0bc7(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = (byte *)param_2;
  pbVar4 = (byte *)param_1;
  bVar1 = *param_2;
  if (*param_1 < *param_2) {
    bVar1 = *param_1;
  }
  if (bVar1 != 0) {
    uVar2 = (uint)bVar1;
    do {
      pbVar4 = pbVar4 + 1;
      pbVar3 = pbVar3 + 1;
      if (uVar2 == 0) {
        return;
      }
      uVar2 = uVar2 - 1;
    } while (*pbVar3 == *pbVar4);
  }
  return;
}


