/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 19e3:16c6
 * Ghidra name: FUN_19e3_16c6
 * Linear address: 0x1B4F6
 * Body addresses: 108
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __stdcall16far FUN_19e3_16c6(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 *puVar4;
  
  DAT_19e3_0117 = param_1;
  param_1 = param_1 * 8;
  DAT_19e3_00f1 = '\x04';
  puVar4 = (undefined2 *)0x2df;
  do {
    iVar1 = *(int *)(param_1 + 0x51f);
    if (iVar1 != 0) {
      iVar3 = 0x2e;
      do {
        *(undefined2 *)(iVar3 + (int)puVar4) = 0;
        bVar2 = 1 < iVar3;
        iVar3 = iVar3 + -2;
      } while (bVar2);
      puVar4[1] = iVar1;
      *(undefined1 *)((byte)(4 - DAT_19e3_00f1) + 0x121) = (char)DAT_19e3_0117;
      *puVar4 = 1;
    }
    puVar4 = puVar4 + 0x18;
    param_1 = param_1 + 2;
    DAT_19e3_00f1 = DAT_19e3_00f1 + -1;
  } while (DAT_19e3_00f1 != '\0');
  DAT_19e3_00f0 = 0;
  return in_AX;
}


