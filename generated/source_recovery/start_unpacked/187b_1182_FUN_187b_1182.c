/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:1182
 * Ghidra name: FUN_187b_1182
 * Linear address: 0x19932
 * Body addresses: 84
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_1182(int param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  undefined2 uVar2;
  
  uVar2 = *(undefined2 *)(param_1 * 2 + 0x8fe);
  *(undefined2 *)(param_1 * 2 + 0x8fe) = 1;
  iVar1 = param_1 * 4;
  *(undefined2 *)(iVar1 + 0x964) = param_2;
  *(undefined2 *)(iVar1 + 0x966) = param_3;
  *(undefined2 *)(iVar1 + 0x920) = 0;
  *(undefined2 *)(iVar1 + 0x922) = 0;
  FUN_187b_0ebb(uVar2,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                      (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                      (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 | (uint)(in_AF & 1) * 0x10
                      | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
  *(undefined2 *)(param_1 * 2 + 0x8fe) = uVar2;
                    /* WARNING: Call to offcut address within same function */
  func_0x0001997c(0x1000);
  return;
}


