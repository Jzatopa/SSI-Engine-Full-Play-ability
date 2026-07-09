/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:04a9
 * Ghidra name: FUN_1602_04a9
 * Linear address: 0x164C9
 * Body addresses: 124
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_04a9(int param_1)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  while (*(byte *)(param_1 + -0x103) <= *(byte *)(param_1 + -0x104)) {
    FUN_1602_0263(1,*(undefined1 *)(param_1 + (uint)*(byte *)(param_1 + -0x103) + -0x100),1,
                  *(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0xe),
                  *(undefined1 *)0x6879,*(undefined1 *)0x6878);
    if (*(char *)0x4448 != '\0') {
      FUN_1bdc_029c((uint)*(byte *)((int)*(undefined4 *)0x4418 + 0xfc) * 3);
    }
    *(char *)(param_1 + -0x103) = *(char *)(param_1 + -0x103) + '\x01';
    *(char *)0x6878 = *(char *)0x6878 + '\x01';
  }
  return;
}


