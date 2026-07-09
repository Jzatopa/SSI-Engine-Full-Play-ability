/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1784:0026
 * Ghidra name: FUN_1784_0026
 * Linear address: 0x17866
 * Body addresses: 45
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1784_0026(undefined1 param_1)

{
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  
  if (*(char *)0x50cc != '\0') {
    if (*(char *)0x50d0 == '\x01') {
      FUN_19e3_0000(*(undefined2 *)0x2328);
    }
    FUN_1784_0053();
    FUN_187b_058f(CONCAT11(extraout_AH,param_1));
  }
  return;
}


