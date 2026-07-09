/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:1350
 * Ghidra name: FUN_187b_1350
 * Linear address: 0x19B00
 * Body addresses: 171
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl16far
FUN_187b_1350(uint param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 in_DX;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  uVar2 = 0x187b;
  if (param_1 < 0x10) {
    DAT_1099_00b2 = -1;
    iVar1 = FUN_187b_1324(param_1,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                                  (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                                  (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                                  (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 |
                                  (uint)(in_CF & 1));
    iVar1 = *(int *)(iVar1 + 0x14);
    if (iVar1 != -1) {
      uVar2 = FUN_187b_0c4e();
      DAT_1099_00b2 = FUN_187b_0ff9(uVar2,in_DX);
      *(int *)(param_1 * 2 + 0x9f8) = DAT_1099_00b2;
      FUN_187b_11d7(DAT_1099_00b2,iVar1,0);
    }
    FUN_187b_0c86(param_1,param_2,param_3,param_4,param_5);
    *(undefined2 *)(param_1 * 2 + 0xa18) = 1;
    uVar2 = 0x1000;
    if (DAT_1099_00b2 != -1) {
      uVar2 = 0x1000;
      FUN_187b_10f6(DAT_1099_00b2);
    }
  }
                    /* WARNING: Call to offcut address within same function */
  func_0x00019ba1(uVar2);
  return;
}


