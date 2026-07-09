/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0adc
 * Ghidra name: FUN_1cc0_0adc
 * Linear address: 0x1D6DC
 * Body addresses: 36
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_0adc(byte param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = (byte *)param_3;
  pbVar4 = (byte *)param_2;
  bVar1 = *param_3;
  if (param_1 < *param_3) {
    bVar1 = param_1;
  }
  *param_2 = bVar1;
  uVar2 = (uint)bVar1;
  while( true ) {
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    *pbVar4 = *pbVar3;
  }
  return;
}


