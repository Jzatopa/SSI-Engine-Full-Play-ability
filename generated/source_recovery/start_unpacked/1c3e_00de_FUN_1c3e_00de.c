/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c3e:00de
 * Ghidra name: FUN_1c3e_00de
 * Linear address: 0x1C4BE
 * Body addresses: 25
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

long __stdcall16far FUN_1c3e_00de(void)

{
  code *pcVar1;
  long lVar2;
  int iVar3;
  int in_CX;
  uint in_BX;
  
  pcVar1 = (code *)swi(0x21);
  iVar3 = (*pcVar1)();
  lVar2 = CONCAT22(iVar3,iVar3);
  if (iVar3 != -1) {
    lVar2 = (ulong)(uint)(iVar3 * in_CX) * (ulong)in_BX;
  }
  return lVar2;
}


