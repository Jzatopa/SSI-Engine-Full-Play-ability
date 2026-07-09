/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1bdc:02fb
 * Ghidra name: FUN_1bdc_02fb
 * Linear address: 0x1C0BB
 * Body addresses: 18
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined1 __cdecl16far FUN_1bdc_02fb(void)

{
  code *pcVar1;
  undefined2 unaff_DS;
  bool bVar2;
  
  bVar2 = *(char *)0x9f45 == '\0';
  if (bVar2) {
    pcVar1 = (code *)swi(0x16);
    (*pcVar1)();
    if (bVar2) {
      return 0;
    }
  }
  return 1;
}


