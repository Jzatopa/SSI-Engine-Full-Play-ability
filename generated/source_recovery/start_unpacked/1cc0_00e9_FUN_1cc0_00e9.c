/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:00e9
 * Ghidra name: FUN_1cc0_00e9
 * Linear address: 0x1CCE9
 * Body addresses: 188
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Removing unreachable block (ram,0x0001ccfc) */
/* WARNING: Removing unreachable block (ram,0x0001ccff) */
/* WARNING: Removing unreachable block (ram,0x0001cd03) */
/* WARNING: Removing unreachable block (ram,0x0001cd12) */
/* WARNING: Removing unreachable block (ram,0x0001cd0c) */
/* WARNING: Removing unreachable block (ram,0x0001cd14) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl16far FUN_1cc0_00e9(void)

{
  code *pcVar1;
  undefined2 in_AX;
  int iVar2;
  char *pcVar3;
  undefined2 uVar4;
  
  uVar4 = 0x1e87;
  DAT_1e87_3dc4 = in_AX;
  DAT_1e87_3dc6 = 0;
  DAT_1e87_3dc8 = 0;
  pcVar3 = (char *)_DAT_1e87_3dc0;
  if ((int)((ulong)_DAT_1e87_3dc0 >> 0x10) == 0 && pcVar3 == (char *)0x0) {
    FUN_1cc0_05bf(0x9f4e,0x1e87);
    FUN_1cc0_05bf(0xa04e,0x1e87);
    iVar2 = 0x13;
    do {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (*(int *)0x3dc6 != 0 || *(int *)0x3dc8 != 0) {
      FUN_1cc0_01a5();
      FUN_1cc0_01b3();
      FUN_1cc0_01a5();
      FUN_1cc0_01cd();
      FUN_1cc0_01e7();
      FUN_1cc0_01cd();
      pcVar3 = (char *)0x215;
      FUN_1cc0_01a5();
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    for (; *pcVar3 != '\0'; pcVar3 = pcVar3 + 1) {
      FUN_1cc0_01e7();
    }
    return;
  }
  _DAT_1e87_3dc0 = (char *)0x0;
  DAT_1e87_3dce = 0;
  return;
}


