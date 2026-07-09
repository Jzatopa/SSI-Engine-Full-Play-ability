/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:00e2
 * Ghidra name: FUN_1cc0_00e2
 * Linear address: 0x1CCE2
 * Body addresses: 4
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void __cdecl16far FUN_1cc0_00e2(void)

{
  code *pcVar1;
  undefined2 in_AX;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int in_stack_00000000;
  int in_stack_00000002;
  
  DAT_1e87_3dc4 = in_AX;
  iVar2 = DAT_1e87_3da2;
  if (in_stack_00000000 != 0 || in_stack_00000002 != 0) {
    for (; (iVar3 = in_stack_00000002, iVar2 != 0 &&
           (iVar3 = iVar2, in_stack_00000002 != *(int *)0x10)); iVar2 = *(int *)0x14) {
    }
    in_stack_00000002 = (iVar3 - DAT_1e87_3dca) + -0x10;
  }
  DAT_1e87_3dc6 = in_stack_00000000;
  DAT_1e87_3dc8 = in_stack_00000002;
  pcVar4 = (char *)_DAT_1e87_3dc0;
  if ((int)((ulong)_DAT_1e87_3dc0 >> 0x10) == 0 && pcVar4 == (char *)0x0) {
    FUN_1cc0_05bf();
    FUN_1cc0_05bf();
    iVar2 = 0x13;
    do {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (DAT_1e87_3dc6 != 0 || DAT_1e87_3dc8 != 0) {
      FUN_1cc0_01a5();
      FUN_1cc0_01b3();
      FUN_1cc0_01a5();
      FUN_1cc0_01cd();
      FUN_1cc0_01e7();
      FUN_1cc0_01cd();
      pcVar4 = (char *)0x215;
      FUN_1cc0_01a5();
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    for (; *pcVar4 != '\0'; pcVar4 = pcVar4 + 1) {
      FUN_1cc0_01e7();
    }
    return;
  }
  _DAT_1e87_3dc0 = (char *)0x0;
  DAT_1e87_3dce = 0;
  return;
}


