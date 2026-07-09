/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:12f6
 * Ghidra name: FUN_187b_12f6
 * Linear address: 0x19AA6
 * Body addresses: 46
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_12f6(uint param_1)

{
  undefined2 uVar1;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  uVar1 = 0x187b;
  if (param_1 < 0x10) {
    *(undefined2 *)(param_1 * 4 + 0x9b8) = 0;
    uVar1 = 0x1000;
    *(undefined2 *)(param_1 * 4 + 0x9ba) = 0;
  }
                    /* WARNING: Call to offcut address within same function */
  func_0x00019ac9(uVar1,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                        (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                        (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                        (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
  return;
}


