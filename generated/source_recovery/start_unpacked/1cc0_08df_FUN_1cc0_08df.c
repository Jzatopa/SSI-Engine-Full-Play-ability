/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:08df
 * Ghidra name: FUN_1cc0_08df
 * Linear address: 0x1D4DF
 * Body addresses: 56
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1cc0_08df(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int in_BX;
  char *pcVar3;
  undefined2 uVar4;
  undefined1 in_ZF;
  
  FUN_1cc0_0776();
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  pcVar3 = (char *)param_2;
  iVar2 = 0;
  if ((bool)in_ZF) {
    do {
      cVar1 = FUN_1cc0_079a();
      if ((cVar1 == '\r') || (cVar1 == '\x1a')) break;
      in_BX = in_BX + 1;
      iVar2 = iVar2 + 1;
      pcVar3 = pcVar3 + 1;
      *pcVar3 = cVar1;
    } while (iVar2 != param_1);
  }
  pcVar3[-iVar2] = (char)iVar2;
  *(int *)((int)param_3 + 8) = in_BX;
  return;
}


