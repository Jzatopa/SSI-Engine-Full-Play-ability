/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:3bf9
 * Ghidra name: FUN_121a_3bf9
 * Linear address: 0x15D99
 * Body addresses: 140
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_121a_3bf9(void)

{
  char cVar1;
  uint uVar2;
  int in_CX;
  int iVar3;
  uint in_BX;
  int iVar4;
  int unaff_BP;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    *(undefined1 *)(in_BX + 0x44e2) = 1;
    iVar4 = in_BX * 2;
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + *(int *)(unaff_BP + -0x18);
    *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + *(int *)(unaff_BP + -0x14);
    if (*(uint *)(unaff_BP + -0xc) < *(uint *)(iVar4 + 0x46da)) {
      *(uint *)(iVar4 + 0x46da) = *(uint *)(unaff_BP + -0xc);
      *(undefined2 *)(iVar4 + 0x458a) = *(undefined2 *)(unaff_BP + -6);
    }
    uVar6 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + 4) >> 0x10);
    iVar5 = (int)*(undefined4 *)(unaff_BP + 4) + *(int *)(unaff_BP + -0xc);
    iVar3 = *(int *)(unaff_BP + -0x10);
    do {
      if (*(char *)(unaff_BP + -0x1a) != '\0') {
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 0x16) + *(int *)(unaff_BP + -0x1e) + 0x1b) =
             *(undefined1 *)(iVar5 + 0x1b);
      }
      cVar1 = *(char *)((int)*(undefined4 *)(unaff_BP + 8) + *(int *)(unaff_BP + -0xe) + 0x1b);
      if (cVar1 != *(char *)(unaff_BP + -0x1c)) {
        *(char *)(iVar5 + 0x1b) = cVar1;
      }
      *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + 1;
      *(int *)(unaff_BP + -0x1e) = *(int *)(unaff_BP + -0x1e) + 1;
      *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + 1;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar2 = *(int *)(unaff_BP + -0xc) - 1;
    if (*(uint *)(iVar4 + 0x482a) < uVar2) {
      *(uint *)(iVar4 + 0x482a) = uVar2;
    }
    *(int *)(unaff_BP + -0xc) = *(int *)(unaff_BP + -0xc) + *(int *)(unaff_BP + -0x12);
    iVar4 = *(int *)(unaff_BP + -0x16);
    *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + iVar4;
    *(int *)(unaff_BP + -0x1e) = *(int *)(unaff_BP + -0x1e) + iVar4;
    in_BX = (in_BX & 0x7fff) + 1;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return;
}


