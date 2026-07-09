/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c6a:0188
 * Ghidra name: FUN_1c6a_0188
 * Linear address: 0x1C828
 * Body addresses: 27
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1c6a_0188(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte *pbVar3;
  uint uVar4;
  int unaff_BP;
  byte *pbVar5;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  
  pbVar3 = (byte *)*(undefined4 *)(unaff_BP + 6);
  pbVar5 = (byte *)pbVar3;
  for (uVar4 = (uint)*pbVar3; pbVar5 = pbVar5 + 1, uVar4 != 0; uVar4 = uVar4 - 1) {
    pbVar1 = unaff_DI;
    unaff_DI = unaff_DI + 1;
    *pbVar1 = *pbVar5;
  }
  *unaff_DI = 0;
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  return;
}


