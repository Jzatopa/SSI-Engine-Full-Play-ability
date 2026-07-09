/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:0112
 * Ghidra name: FUN_1c3e_0112
 * Linear address: 0x1C4F2
 * Body addresses: 62
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1c3e_0112(void)

{
  byte *pbVar1;
  code *pcVar2;
  byte bVar3;
  byte *pbVar5;
  byte *pbVar6;
  undefined2 unaff_SS;
  byte *in_stack_0000000a;
  int iVar4;
  
  pbVar5 = (byte *)in_stack_0000000a;
  pbVar6 = &stack0xffae;
  bVar3 = *in_stack_0000000a;
  if (0x4e < bVar3) {
    bVar3 = 0x4f;
  }
  for (iVar4 = (int)(char)bVar3; pbVar5 = pbVar5 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    pbVar1 = pbVar6;
    pbVar6 = pbVar6 + 1;
    *pbVar1 = *pbVar5;
  }
  *pbVar6 = 0;
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  pcVar2 = (code *)swi(0x21);
  (*pcVar2)();
  FUN_1c3e_016a();
  return;
}


