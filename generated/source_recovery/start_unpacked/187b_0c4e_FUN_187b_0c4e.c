/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0c4e
 * Ghidra name: FUN_187b_0c4e
 * Linear address: 0x193FE
 * Body addresses: 56
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

int __cdecl16far FUN_187b_0c4e(void)

{
  int *piVar1;
  int in_AX;
  uint in_BX;
  int *piVar2;
  int iVar3;
  
  if (in_BX < 0x10) {
    piVar1 = (int *)*(undefined4 *)(in_BX * 4 + 0x9b8);
    iVar3 = (int)((ulong)piVar1 >> 0x10);
    piVar2 = (int *)piVar1;
    if (iVar3 != 0 || piVar2 != (int *)0x0) {
      do {
        piVar1 = piVar2;
        if (*piVar1 == in_AX) {
          return piVar2[1];
        }
        piVar2 = piVar2 + 2;
      } while (*piVar1 != -1);
      return 0;
    }
  }
  return 0;
}


