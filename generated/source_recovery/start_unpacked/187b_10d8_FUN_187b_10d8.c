/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:10d8
 * Ghidra name: FUN_187b_10d8
 * Linear address: 0x19888
 * Body addresses: 29
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_10d8(void)

{
  bool bVar1;
  int iVar2;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  uint uVar3;
  
  uVar3 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
          (uint)(in_TF & 1) * 0x100 | (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
          (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1);
  iVar2 = 0xf;
  do {
    FUN_187b_1094(iVar2,uVar3);
    bVar1 = 0 < iVar2;
    iVar2 = iVar2 + -1;
  } while (bVar1);
                    /* WARNING: Call to offcut address within same function */
  func_0x0001989c(0x187b);
  return;
}


