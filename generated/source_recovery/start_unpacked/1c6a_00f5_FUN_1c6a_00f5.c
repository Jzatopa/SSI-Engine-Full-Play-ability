/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c6a:00f5
 * Ghidra name: FUN_1c6a_00f5
 * Linear address: 0x1C795
 * Body addresses: 59
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1c6a_00f5(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  code *pcVar4;
  byte bVar5;
  int unaff_BP;
  char *pcVar6;
  char *pcVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  pcVar4 = (code *)swi(0x21);
  bVar5 = (*pcVar4)();
  if (2 < bVar5) {
    uVar3 = *(undefined2 *)0x2c;
    pcVar7 = (char *)0x0;
    do {
      do {
        pcVar6 = pcVar7;
        pcVar7 = pcVar6 + 1;
      } while (*pcVar6 != '\0');
      pcVar7 = pcVar6 + 2;
    } while (pcVar6[1] != '\0');
    pcVar6 = pcVar6 + 4;
    pcVar7 = (char *)(unaff_BP + -0x82);
    do {
      pcVar1 = pcVar6;
      pcVar6 = pcVar6 + 1;
      cVar2 = *pcVar1;
      pcVar1 = pcVar7;
      pcVar7 = pcVar7 + 1;
      *pcVar1 = cVar2;
    } while (cVar2 != '\0');
    FUN_1c6a_0188();
  }
  return;
}


