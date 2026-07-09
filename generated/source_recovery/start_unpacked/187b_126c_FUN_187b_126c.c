/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:126c
 * Ghidra name: FUN_187b_126c
 * Linear address: 0x19A1C
 * Body addresses: 137
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_126c(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 uVar3;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  iRam00010a3c = 0;
  do {
    iVar1 = iRam00010a3c * 4;
    if (*(int *)(iVar1 + 0x9b8) == 0 && *(int *)(iVar1 + 0x9ba) == 0) {
      uVar3 = (undefined2)((ulong)param_1 >> 0x10);
      piVar2 = (int *)param_1;
      if ((piVar2[1] == 0x6f43) && (piVar2[2] == 0x7970)) {
        *(int *)(iVar1 + 0x9b8) = (int)piVar2 + *param_1;
        *(undefined2 *)(iVar1 + 0x9ba) = uVar3;
        FUN_187b_1324(iRam00010a3c,
                      (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                      (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                      (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 | (uint)(in_AF & 1) * 0x10
                      | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
      }
      break;
    }
    iRam00010a3c = iRam00010a3c + 1;
  } while (iRam00010a3c != 0x10);
                    /* WARNING: Call to offcut address within same function */
  func_0x00019a9b(0x1000);
  return;
}


