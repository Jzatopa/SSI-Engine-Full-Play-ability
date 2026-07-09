/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1bdc:030d
 * Ghidra name: FUN_1bdc_030d
 * Linear address: 0x1C0CD
 * Body addresses: 34
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_1bdc_030d(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  
  cVar2 = *(char *)0x9f45;
  *(undefined1 *)0x9f45 = 0;
  if (cVar2 == '\0') {
    pcVar1 = (code *)swi(0x16);
    cVar2 = (*pcVar1)();
    if (cVar2 == '\0') {
      *(undefined1 *)0x9f45 = extraout_AH;
    }
  }
  FUN_1bdc_0143();
  return;
}


