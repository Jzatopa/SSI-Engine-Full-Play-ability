/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:1ae6
 * Ghidra name: FUN_1cc0_1ae6
 * Linear address: 0x1E6E6
 * Body addresses: 79
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __stdcall16far FUN_1cc0_1ae6(int param_1,char *param_2)

{
  char *pcVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  undefined2 in_CX;
  char *unaff_SI;
  char *pcVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  if (param_1 == 0) {
    pcVar2 = (code *)swi(0x21);
    bVar3 = (*pcVar2)();
    iVar4 = 0;
    if (2 < bVar3) {
      unaff_ES = *(undefined2 *)0x2c;
      pcVar5 = (char *)0x0;
LAB_1cc0_1b0c:
      if (*pcVar5 != '\0') {
        iVar4 = -1;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          pcVar1 = pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (*pcVar1 != '\0');
        goto LAB_1cc0_1b0c;
      }
      unaff_SI = pcVar5 + 3;
      iVar4 = 0x100;
      pcVar5 = unaff_SI;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar1 = pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar1 != '\0');
      in_CX = 0;
      iVar4 = CONCAT11((char)((uint)iVar4 >> 8),~(byte)iVar4);
    }
  }
  else {
    iVar4 = FUN_1cc0_1b3c();
  }
  pcVar5 = (char *)param_2;
  *param_2 = (char)iVar4;
  for (; pcVar5 = pcVar5 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar1 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *pcVar5 = *pcVar1;
  }
  return in_CX;
}


