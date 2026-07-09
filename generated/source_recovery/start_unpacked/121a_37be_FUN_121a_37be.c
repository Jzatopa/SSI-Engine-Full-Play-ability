/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:37be
 * Ghidra name: FUN_121a_37be
 * Linear address: 0x1595E
 * Body addresses: 95
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_121a_37be(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int in_CX;
  int iVar6;
  uint in_BX;
  int iVar7;
  int unaff_BP;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    *(undefined1 *)(in_BX + 0x44e2) = 1;
    iVar7 = in_BX * 2;
    *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + *(int *)(unaff_BP + -0x14);
    if (*(uint *)(unaff_BP + -0xc) <= *(uint *)(iVar7 + 0x46da)) {
      *(uint *)(iVar7 + 0x46da) = *(uint *)(unaff_BP + -0xc);
      *(undefined2 *)(iVar7 + 0x458a) = *(undefined2 *)(unaff_BP + -6);
    }
    uVar3 = *(undefined4 *)(unaff_BP + 8);
    uVar4 = *(undefined4 *)(unaff_BP + 4);
    puVar8 = (undefined1 *)((int)uVar3 + 0x1b + *(int *)(unaff_BP + -0xe));
    puVar9 = (undefined1 *)((int)uVar4 + 0x1b + *(int *)(unaff_BP + -0xc));
    for (iVar6 = *(int *)(unaff_BP + -0x10); iVar6 != 0; iVar6 = iVar6 + -1) {
      puVar2 = puVar9;
      puVar9 = puVar9 + 1;
      puVar1 = puVar8;
      puVar8 = puVar8 + 1;
      *puVar2 = *puVar1;
    }
    iVar6 = *(int *)(unaff_BP + -0x10);
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + iVar6;
    *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + iVar6;
    uVar5 = *(int *)(unaff_BP + -0xc) - 1;
    if (*(uint *)(iVar7 + 0x482a) <= uVar5) {
      *(uint *)(iVar7 + 0x482a) = uVar5;
    }
    *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + *(int *)(unaff_BP + -0x12);
    in_BX = (in_BX & 0x7fff) + 1;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return;
}


