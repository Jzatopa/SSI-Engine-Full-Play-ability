/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0f50
 * Ghidra name: FUN_187b_0f50
 * Linear address: 0x19700
 * Body addresses: 67
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_0f50(void)

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
  
  uRam00010894 = 0;
  uRam00010896 = 0;
  puVar3 = (undefined2 *)0x9b8;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
  puVar3 = (undefined2 *)0x9f8;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0xffff;
  }
  puVar3 = (undefined2 *)0xa18;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    puVar1 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar1 = 0;
  }
                    /* WARNING: Call to offcut address within same function */
  func_0x0001973a(0x1000,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                         (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                         (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                         (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
  return;
}


