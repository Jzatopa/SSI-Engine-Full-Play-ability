/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0ff9
 * Ghidra name: FUN_187b_0ff9
 * Linear address: 0x197A9
 * Body addresses: 154
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16far FUN_187b_0ff9(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 unaff_DS;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  
  uVar2 = 0;
  do {
    if (*(int *)(uVar2 + 0x8fe) == 0) {
      uVar1 = uVar2 >> 1;
      *(undefined2 *)(uVar2 + 0x8fe) = 1;
      *(undefined2 *)(uVar2 + 0x8dc) = unaff_DS;
      *(undefined2 *)(uVar2 * 2 + 0x898) = (int)param_1;
      *(undefined2 *)(uVar2 * 2 + 0x89a) = (int)((ulong)param_1 >> 0x10);
      iRam00010894 = iRam00010894 + 1;
      if (iRam00010894 == 1) {
        FUN_187b_0d75(uVar1,(uint)(in_NT & 1) * 0x4000 | (uint)(in_OF & 1) * 0x800 |
                            (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
                            (uint)(in_SF & 1) * 0x80 | (uint)(in_ZF & 1) * 0x40 |
                            (uint)(in_AF & 1) * 0x10 | (uint)(in_PF & 1) * 4 | (uint)(in_CF & 1));
        FUN_187b_0db8();
        FUN_187b_1182(0x10,0xd68d);
        FUN_187b_10f6(0x10);
        *(undefined2 *)(uVar1 * 2 + 0x8fe) = 1;
      }
      break;
    }
    uVar2 = uVar2 + 2;
  } while (uVar2 < 0x20);
                    /* WARNING: Call to offcut address within same function */
  func_0x00019839(0x1000);
  return;
}


