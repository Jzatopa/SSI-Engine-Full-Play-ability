/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1836:011e
 * Ghidra name: FUN_1836_011e
 * Linear address: 0x1847E
 * Body addresses: 127
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1836_011e(int param_1)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined2 *)(param_1 + -8) = 0;
  *(undefined1 *)(param_1 + -10) = 0;
  while ((cVar1 = FUN_1bdc_02fb(), cVar1 == '\0' && (*(char *)(param_1 + -10) == '\0'))) {
    FUN_1b58_0072(0x8d75,unaff_DS,0x8d73,unaff_DS,param_1 + -8,unaff_SS);
    if (*(int *)(param_1 + -8) != 0) {
      if (*(int *)(param_1 + -8) == 1) {
        *(undefined1 *)(param_1 + -2) = 0xd;
      }
      else if (*(int *)(param_1 + -8) == 2) {
        *(undefined1 *)(param_1 + -2) = 0x1b;
      }
      *(undefined1 *)0x8d71 = 1;
      *(undefined1 *)(param_1 + -10) = 1;
    }
  }
  return;
}


