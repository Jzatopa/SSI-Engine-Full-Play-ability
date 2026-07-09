
void __cdecl16near FUN_121a_381d(void)

{
  byte bVar1;
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
        *(undefined1 *)((int)*(undefined4 *)(unaff_BP + 0x14) + *(int *)(unaff_BP + -0x1c) + 0x1b) =
             *(undefined1 *)(iVar5 + 0x1b);
      }
      bVar1 = *(byte *)((int)*(undefined4 *)(unaff_BP + 8) + *(int *)(unaff_BP + -0xe) + 0x1b);
      *(byte *)(iVar5 + 0x1b) =
           *(byte *)(iVar5 + 0x1b) &
           *(byte *)((int)*(undefined4 *)(unaff_BP + -4) + *(int *)(unaff_BP + -0xe));
      *(byte *)(iVar5 + 0x1b) = *(byte *)(iVar5 + 0x1b) | bVar1;
      *(int *)(unaff_BP + -0xe) = *(int *)(unaff_BP + -0xe) + 1;
      *(int *)(unaff_BP + -0x1c) = *(int *)(unaff_BP + -0x1c) + 1;
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
    *(int *)(unaff_BP + -0x1c) = *(int *)(unaff_BP + -0x1c) + iVar4;
    in_BX = (in_BX & 0x7fff) + 1;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  return;
}


