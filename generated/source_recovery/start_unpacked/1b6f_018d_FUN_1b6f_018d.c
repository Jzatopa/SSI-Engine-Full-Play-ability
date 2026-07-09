/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1b6f:018d
 * Ghidra name: FUN_1b6f_018d
 * Linear address: 0x1B87D
 * Body addresses: 74
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1b6f_018d(undefined1 *param_1,undefined2 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  *param_2 = 0;
  cVar1 = FUN_1b6f_0107(2,1);
  if (cVar1 == '\0') {
    cVar1 = FUN_1b6f_0107(1,1);
    if (cVar1 != '\0') {
      *param_2 = 1;
    }
  }
  else {
    *param_2 = 2;
  }
  uVar2 = FUN_1b6f_003b(1);
  *param_1 = uVar2;
  return;
}


