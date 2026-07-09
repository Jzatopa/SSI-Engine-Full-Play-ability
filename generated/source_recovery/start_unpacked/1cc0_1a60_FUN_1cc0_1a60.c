/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1a60
 * Ghidra name: FUN_1cc0_1a60
 * Linear address: 0x1E660
 * Body addresses: 79
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_1a60(byte *param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  byte *pbVar3;
  code *pcVar4;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  byte *pbVar8;
  char *pcVar9;
  byte *pbVar10;
  char *pcVar11;
  undefined2 unaff_SS;
  bool bVar12;
  undefined2 uStack_50;
  
  pbVar8 = (byte *)param_1;
  pbVar10 = &stack0xffae;
  bVar5 = *param_1;
  if (0x4f < bVar5) {
    bVar5 = 0x4f;
  }
  for (uVar7 = (uint)bVar5; pbVar8 = pbVar8 + 1, uVar7 != 0; uVar7 = uVar7 - 1) {
    pbVar3 = pbVar10;
    pbVar10 = pbVar10 + 1;
    *pbVar3 = *pbVar8;
  }
  *pbVar10 = 0;
  bVar12 = 0xffcf < (uint)param_2;
  pcVar4 = (code *)swi(0x21);
  uVar6 = (*pcVar4)();
  if (bVar12) {
    *(undefined2 *)0x3dce = uVar6;
  }
  else {
    pcVar9 = &stack0xffae;
    pcVar11 = (char *)((uint)param_2 + 0x30);
    do {
      pcVar1 = pcVar9;
      pcVar9 = pcVar9 + 1;
      cVar2 = *pcVar1;
      pcVar1 = pcVar11;
      pcVar11 = pcVar11 + 1;
      *pcVar1 = cVar2;
    } while (cVar2 != '\0');
  }
  return;
}


