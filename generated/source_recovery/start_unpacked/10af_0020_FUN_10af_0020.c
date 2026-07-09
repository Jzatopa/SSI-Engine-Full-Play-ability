/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10af:0020
 * Ghidra name: FUN_10af_0020
 * Linear address: 0x10B10
 * Body addresses: 184
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x00010bc9) overlaps instruction at (ram,0x00010bc8)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_10af_0020(undefined2 param_1,undefined2 param_2)

{
  byte *pbVar1;
  char *pcVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  byte bVar7;
  char cVar8;
  char cVar9;
  undefined2 uVar10;
  undefined2 in_CX;
  char cVar14;
  int iVar11;
  uint uVar12;
  int iVar13;
  char extraout_DL;
  char extraout_DH;
  undefined1 in_BL;
  int *piVar15;
  int unaff_BP;
  undefined1 *puVar16;
  undefined1 *unaff_SI;
  undefined1 *unaff_DI;
  char *pcVar17;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar18;
  byte in_AF;
  undefined1 *in_stack_0000001c;
  
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  cVar9 = (char)in_CX;
  cVar14 = (char)((uint)in_CX >> 8) + cVar9;
  in_AF = 9 < (in_AF * -6 & 0xf) | in_AF;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  piVar15 = (int *)CONCAT11(0x23,in_BL);
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  iVar11 = CONCAT11(cVar14 + cVar9,cVar9) + 1;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  cVar9 = (char)iVar11;
  cVar14 = (char)((uint)iVar11 >> 8) + cVar9;
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  bVar7 = bVar7 + in_AF * -6 & 0xf;
  *piVar15 = *piVar15 + CONCAT11(cVar14,cVar9) + (uint)in_AF;
  cVar14 = cVar14 + cVar9;
  in_AF = 9 < bVar7 | in_AF;
  bVar18 = (POPCOUNT(((bVar7 + in_AF * -6 & 0xf) - *(char *)((int)piVar15 + (int)unaff_SI)) - in_AF)
           & 1U) == 0;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  if (bVar18) {
    unaff_SI[unaff_BP] = unaff_SI[unaff_BP] + bVar7;
    *(char *)piVar15 = (char)*piVar15 + cVar14;
  }
  else {
    cVar14 = cVar14 + cVar9;
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    bVar7 = (*(code *)*piVar15)();
    cVar14 = cVar14 + cVar9;
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    bVar7 = bVar7 + in_AF * -6 & 0xf;
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
    pcVar5 = (code *)swi(0x3f);
    cVar8 = (*pcVar5)();
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + cVar8;
    puVar3 = unaff_SI;
    unaff_SI = unaff_SI + 1;
    *unaff_DI = *puVar3;
    bVar7 = cVar8 + *(char *)((int)piVar15 + (int)unaff_SI);
    unaff_DI = unaff_DI + 3;
    *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  }
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  *(char *)((int)piVar15 + (int)unaff_SI) = *(char *)((int)piVar15 + (int)unaff_SI) + bVar7;
  cVar14 = cVar14 + cVar9 * '\x02';
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  bVar7 = bVar7 + in_AF * -6 & 0xf;
  in_AF = 9 < bVar7 | in_AF;
  bVar7 = bVar7 + in_AF * -6 & 0xf;
  pcVar17 = unaff_DI + 1;
  puVar4 = unaff_SI + 1;
  *(char *)((int)piVar15 + (int)puVar4) = *(char *)((int)piVar15 + (int)puVar4) + bVar7;
  *(char *)((int)piVar15 + (int)puVar4) = *(char *)((int)piVar15 + (int)puVar4) + bVar7;
  *(char *)((int)piVar15 + (int)puVar4) = *(char *)((int)piVar15 + (int)puVar4) + bVar7;
  *(char *)((int)piVar15 + (int)puVar4) = *(char *)((int)piVar15 + (int)puVar4) + bVar7;
  pcVar5 = (code *)swi(0x3f);
  iVar11 = (*pcVar5)();
  *(char *)((int)piVar15 + (int)puVar4) = *(char *)((int)piVar15 + (int)puVar4) + (char)iVar11;
  bVar7 = (byte)piVar15 | 0xca;
  *pcVar17 = *pcVar17 + extraout_DH;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  puVar4[iVar11] = puVar4[iVar11] + bVar7;
  cVar14 = cVar14 + cVar9;
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  puVar16 = (undefined1 *)0xd;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  bVar7 = bVar7 & (byte)*(undefined2 *)(puVar4 + iVar11);
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  bVar7 = bVar7 + in_AF * -6 & 0xf;
  pbVar1 = unaff_SI + 0xe;
  *pbVar1 = *pbVar1 << 1 | (char)*pbVar1 < '\0';
  in_AF = 9 < bVar7 | in_AF;
  uVar12 = CONCAT11(cVar14 + cVar9 * '\x02',cVar9) ^ *(uint *)(unaff_DI + 0xe);
  cVar9 = (char)uVar12;
  iVar13 = CONCAT11((char)(uVar12 >> 8) + cVar9,cVar9);
  in_AF = 9 < (bVar7 + in_AF * -6 & 0xf) | in_AF;
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  bVar7 = (byte)uVar10;
  if (iVar13 == 0) {
    puVar4[iVar11] = puVar4[iVar11] + bVar7;
    puVar4[iVar11] = puVar4[iVar11] + bVar7;
    puVar4[iVar11] = puVar4[iVar11] + bVar7;
    pcVar2 = unaff_DI + -0x76;
    cVar9 = *pcVar2;
    *pcVar2 = *pcVar2 + extraout_DL;
    uVar12 = in(0x8b);
    if (*pcVar2 == '\0' || SCARRY1(cVar9,extraout_DL) != *pcVar2 < '\0') goto code_r0x00010bdc;
  }
  else {
    in_AF = 9 < (bVar7 & 0xf) | in_AF;
    uVar12 = CONCAT11((char)((uint)uVar10 >> 8) - in_AF,bVar7 + in_AF * -6) & 0xff0f;
    cVar9 = (char)in_stack_0000001c;
    puVar4[iVar11] = puVar4[iVar11] + cVar9;
    puVar4[iVar11] = puVar4[iVar11] + cVar9;
    puVar4[iVar11] = puVar4[iVar11] + cVar9;
    puVar4[iVar11] = puVar4[iVar11] + cVar9;
    puVar4[iVar11] = puVar4[iVar11] + cVar9;
    puVar4[iVar11] = puVar4[iVar11] + cVar9;
    in_stack_0000001c = (undefined1 *)(uVar12 - 2);
    puVar16 = (undefined1 *)(uVar12 - 2);
    *(undefined2 *)(uVar12 - 2) = 0xd;
    pcVar17 = (char *)*(undefined2 *)(uVar12 + 4);
  }
  uVar12 = (uint)(byte)pcVar17[6];
code_r0x00010bdc:
  *(undefined2 *)(in_stack_0000001c + -2) = *(undefined2 *)(uVar12 * 4 + 0x73a0);
  *(undefined2 *)(in_stack_0000001c + -4) = *(undefined2 *)(uVar12 * 4 + 0x739e);
  iVar11 = *(int *)(puVar16 + 6);
  *(undefined2 *)(in_stack_0000001c + -6) = *(undefined2 *)(iVar11 + -6);
  *(undefined2 *)(in_stack_0000001c + -8) = *(undefined2 *)(iVar11 + -8);
  *(undefined2 *)(in_stack_0000001c + -10) =
       *(undefined2 *)((uint)*(byte *)(*(int *)(puVar16 + 6) + 6) * 2 + 0x7388);
  *(undefined2 *)(in_stack_0000001c + -0xc) = 0x10af;
  *(undefined2 *)(in_stack_0000001c + -0xe) = 0xc0a;
  FUN_10b8_014f();
  iVar11 = *(int *)(puVar16 + 6);
  *(undefined2 *)(in_stack_0000001c + -2) = *(undefined2 *)(iVar11 + -6);
  *(undefined2 *)(in_stack_0000001c + -4) = *(undefined2 *)(iVar11 + -8);
  uVar6 = *(undefined4 *)0x73c2;
  *(int *)(in_stack_0000001c + -6) = (int)((ulong)uVar6 >> 0x10);
  *(int *)(in_stack_0000001c + -8) = (int)uVar6 + 0x1b;
  bVar7 = *(byte *)0x739a;
  *(undefined2 *)(in_stack_0000001c + -10) = *(undefined2 *)((uint)bVar7 * 4 + 0x73a0);
  *(undefined2 *)(in_stack_0000001c + -0xc) = *(undefined2 *)((uint)bVar7 * 4 + 0x739e);
  *(undefined2 *)(in_stack_0000001c + -0xe) = 0x1e40;
  *(undefined2 *)(in_stack_0000001c + -0x10) = 0x10af;
  *(undefined2 *)(in_stack_0000001c + -0x12) = 0xc3a;
  FUN_10b8_0127();
  return;
}


