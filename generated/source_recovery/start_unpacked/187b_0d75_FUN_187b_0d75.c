/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0d75
 * Ghidra name: FUN_187b_0d75
 * Linear address: 0x19525
 * Body addresses: 59
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_0d75(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  uRam000109a8 = 0xffff;
  uRam000109aa = 0xffff;
  puVar3 = (undefined2 *)0x8fe;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
  puVar3 = (undefined2 *)0x920;
  for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
  puVar3 = (undefined2 *)0x964;
  for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
                    /* WARNING: Call to offcut address within same function */
  func_0x00019557(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                         (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                         (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
  return;
}


