/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1045:0020
 * Ghidra name: FUN_1045_0020
 * Linear address: 0x10470
 * Body addresses: 48
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x0001060f) overlaps instruction at (ram,0x0001060e)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1045_0020(void)

{
  char *pcVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined2 uVar4;
  code *pcVar5;
  byte bVar6;
  undefined1 uVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  byte bVar11;
  undefined2 uVar12;
  undefined1 uVar17;
  uint uVar13;
  int iVar14;
  char cVar18;
  int iVar15;
  uint uVar16;
  undefined2 in_CX;
  char cVar20;
  int iVar19;
  char extraout_DL;
  char extraout_DH;
  uint in_BX;
  char *pcVar21;
  undefined1 *puVar22;
  undefined2 *puVar23;
  undefined2 *puVar24;
  undefined2 *puVar25;
  undefined2 *puVar26;
  undefined1 *puVar27;
  uint *unaff_BP;
  char *pcVar28;
  char *unaff_SI;
  int *piVar29;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar30;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool bVar31;
  byte in_AF;
  longdouble in_ST0;
  longdouble in_ST1;
  
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  *(uint *)0xcd00 = *(uint *)0xcd00 ^ (uint)&stack0x0004;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  unaff_SI[in_BX] = unaff_SI[in_BX];
  unaff_SI[in_BX] = unaff_SI[in_BX];
  unaff_SI[in_BX] = unaff_SI[in_BX];
  pcVar5 = (code *)swi(0x3f);
  uVar12 = (*pcVar5)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + (byte)uVar12;
  uVar17 = (undefined1)((uint)uVar12 >> 8);
  *(int *)(unaff_SI + in_BX) =
       *(int *)(unaff_SI + in_BX) +
       CONCAT11(uVar17,(byte)uVar12 | *(byte *)((int)unaff_BP + (int)unaff_SI));
  uVar7 = in(0xb);
  puVar22 = (undefined1 *)CONCAT11(uVar17,uVar7);
  cVar9 = (char)&stack0x0008;
  *(char *)((int)unaff_BP + (int)unaff_DI) = *(char *)((int)unaff_BP + (int)unaff_DI) + cVar9;
  *unaff_DI = *unaff_DI + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  pcVar5 = (code *)swi(0x3f);
  uVar12 = (*pcVar5)();
  *(int *)((int)unaff_BP + (int)unaff_DI) = (int)in_ST0;
  cVar9 = (char)in_CX;
  cVar20 = (char)((uint)in_CX >> 8) + cVar9;
  in_AF = 9 < ((byte)uVar12 & 0xf) | in_AF;
  puVar23 = (undefined2 *)(puVar22 + -2);
  *(undefined2 *)(puVar22 + -2) = 0x1045;
  *(uint *)(unaff_SI + in_BX) =
       *(int *)(unaff_SI + in_BX) +
       (CONCAT11((char)((uint)uVar12 >> 8) - in_AF,(byte)uVar12 + in_AF * -6) & 0xff0f);
  pcVar5 = (code *)swi(0x3f);
  uVar13 = (*pcVar5)();
  *(uint *)(unaff_SI + in_BX) = *(uint *)(unaff_SI + in_BX) | uVar13;
  in_AF = 9 < ((byte)uVar13 & 0xf) | in_AF;
  bVar6 = (byte)uVar13 + in_AF * -6 & 0xf;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  *(byte *)0x1 = *(byte *)0x1 | 0x96;
  *unaff_BP = *unaff_BP | (uint)unaff_DI;
  iVar14 = CONCAT11((char)(uVar13 >> 8) - in_AF,bVar6 - unaff_SI[in_BX]) + -1;
  bVar6 = (byte)iVar14;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar6;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  cVar18 = (char)((uint)iVar14 >> 8) - in_AF;
  *(uint *)(unaff_SI + in_BX) =
       *(uint *)(unaff_SI + in_BX) | CONCAT11(cVar20 + cVar9 * '\x02',cVar9);
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  cVar20 = bVar6 - unaff_SI[in_BX];
  cVar18 = cVar18 + cVar20;
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  unaff_SI[in_BX] = unaff_SI[in_BX] + (bVar8 + in_AF * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  cVar9 = (*pcVar5)();
  puVar24 = (undefined2 *)*puVar23;
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar9;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  unaff_SI[in_BX] = unaff_SI[in_BX];
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar28 = unaff_SI + 1;
  pcVar28[in_BX] = pcVar28[in_BX] + *unaff_SI;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  pcVar21 = (char *)(in_BX & 0xff00);
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  iVar14 = CONCAT11(cVar18 + cVar20,cVar20) + -1;
  cVar9 = (char)iVar14;
  cVar18 = (char)((uint)iVar14 >> 8) + cVar9;
  in_AF = 9 < bVar6 | in_AF;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + (bVar6 + in_AF * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  iVar15 = (*pcVar5)();
  iVar14 = *(int *)(pcVar21 + (int)unaff_DI);
  bVar6 = (byte)(iVar15 + iVar14);
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar8 = bVar6 + in_AF * -6 & 0xf;
  pcVar21[(int)unaff_DI] = (pcVar21[(int)unaff_DI] - bVar8) - in_AF;
  iVar19 = CONCAT11(cVar18 + cVar9 * '\x02',cVar9);
  bVar6 = 9 < bVar8 | in_AF;
  uVar12 = *puVar24;
  puVar25 = puVar24 + 1;
  *(uint *)(pcVar21 + (int)pcVar28) =
       *(int *)(pcVar21 + (int)pcVar28) +
       (CONCAT11(((char)((uint)(iVar15 + iVar14) >> 8) - in_AF) - bVar6,bVar8 + bVar6 * -6) & 0xff0f
       );
  pcVar5 = (code *)swi(0x3f);
  iVar14 = (*pcVar5)();
  puVar2 = (uint *)(pcVar21 + (int)pcVar28);
  *puVar2 = *puVar2 + iVar14;
  bVar31 = (POPCOUNT(*puVar2 & 0xff) & 1U) == 0;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  if (bVar31) {
    pcVar5 = (code *)swi(0x3f);
    (*pcVar5)();
  }
  else {
    iVar19 = CONCAT11((char)((uint)iVar19 >> 8) + (char)iVar19,(char)iVar19);
    bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  }
  pcVar21[(int)unaff_DI] = pcVar21[(int)unaff_DI];
  pcVar5 = (code *)swi(0x3f);
  iVar14 = (*pcVar5)();
  *(int *)(pcVar21 + (int)pcVar28) = *(int *)(pcVar21 + (int)pcVar28) + iVar14;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  iVar19 = iVar19 + -1;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  *(char *)((int)unaff_BP + (int)unaff_DI) = *(char *)((int)unaff_BP + (int)unaff_DI);
  pcVar5 = (code *)swi(0x3f);
  cVar9 = (*pcVar5)();
  cVar18 = (char)iVar19;
  cVar20 = (char)((uint)iVar19 >> 8) + cVar18;
  bVar6 = 9 < (cVar9 + *pcVar28 & 0xfU) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  iVar14 = (*pcVar5)();
  uVar30 = *puVar25;
  bVar8 = (byte)(iVar14 + -0x3300);
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  iVar14 = (CONCAT11((char)((uint)(iVar14 + -0x3300) >> 8) - bVar6,bVar8 + bVar6 * -6) & 0xff0f) +
           0xcd00;
  bVar6 = 9 < ((byte)iVar14 & 0xf) | bVar6;
  pcVar28 = unaff_SI + 3;
  iVar14 = CONCAT11((char)((uint)iVar14 >> 8) - bVar6,unaff_SI[2]) + -0x3300;
  bVar8 = (byte)iVar14;
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  bVar11 = bVar8 + bVar6 * -6 & 0xf;
  *puVar25 = unaff_ES;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  pcVar21[(int)pcVar28] = pcVar21[(int)pcVar28] + bVar11;
  iVar15 = CONCAT11(cVar20 + cVar18,cVar18);
  bVar8 = 9 < bVar11 | bVar6;
  bVar11 = bVar11 + bVar8 * -6;
  bVar10 = bVar11 & 0xf;
  puVar24 = (undefined2 *)(CONCAT11(((char)((uint)iVar14 >> 8) - bVar6) - bVar8,bVar11) & 0xff0f);
  pbVar3 = (byte *)(pcVar21 + (int)pcVar28);
  bVar6 = *pbVar3;
  *pbVar3 = *pbVar3 + bVar10;
  cVar9 = (char)pcVar28;
  pcVar21[(int)unaff_DI] = (pcVar21[(int)unaff_DI] - cVar9) - CARRY1(bVar6,bVar10);
  pcVar1 = (char *)((int)unaff_BP + (int)puVar24 + 0x6849);
  *pcVar1 = *pcVar1 + extraout_DH;
  *(char *)((int)unaff_BP + (int)unaff_DI) = *(char *)((int)unaff_BP + (int)unaff_DI) + cVar18;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar21[(int)puVar24] = pcVar21[(int)puVar24] + cVar9;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  cVar9 = (char)(iVar15 + -1);
  cVar18 = (char)((uint)(iVar15 + -1) >> 8) + cVar9;
  bVar8 = 9 < ((byte)*puVar24 & 0xf) | bVar8;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  pcVar21[(int)(puVar24 + 1)] = pcVar21[(int)(puVar24 + 1)] + bVar6;
  cVar18 = cVar18 + cVar9 * '\x02';
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  bVar6 = bVar6 + bVar8 * -6 & 0xf;
  bVar8 = 9 < bVar6 | bVar8;
  *(uint *)(pcVar21 + (int)(puVar24 + 1)) =
       *(uint *)(pcVar21 + (int)(puVar24 + 1)) & CONCAT11(cVar18,cVar9);
  cVar18 = cVar18 + cVar9;
  bVar8 = 9 < (bVar6 + bVar8 * -6 & 0xf) | bVar8;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  cVar9 = cVar9 + *(char *)((int)unaff_BP + (int)unaff_DI);
  cVar18 = cVar18 + cVar9 * '\x05';
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  bVar6 = bVar6 + bVar8 * -6 & 0xf;
  *(sqword *)((int)unaff_BP + (int)unaff_DI) = (sqword)in_ST1;
  bVar8 = 9 < bVar6 | bVar8;
  bVar6 = bVar6 + bVar8 * -6 & 0xf;
  pcVar28 = (char *)TaskRegister();
  bVar31 = (bool)(9 < bVar6 | bVar8);
  bVar8 = bVar6 + bVar31 * -6 & 0xf;
  bVar6 = 0;
  if (bVar31) {
    *unaff_DI = *unaff_DI + cVar18;
    cVar18 = cVar18 + cVar9;
    pcVar28 = *(char **)unaff_DI;
    bVar8 = ((((bVar8 - 6 & 0xf) - 0x35 & 0xf ^ 0x3c) - 6 & 0xf) - 6 & 0xf) - 6 & 0xf;
    if (SCARRY1(cVar18,cVar9) == (char)(cVar18 + cVar9) < '\0') {
      bVar6 = 1;
      bVar8 = bVar8 - 6 & 0xf;
    }
    else {
      bVar6 = 1;
      bVar8 = (bVar8 - 6 & 0xf) - 6 & 0xf;
      puVar26 = (undefined2 *)((int)puVar25 + -2);
      puVar25 = (undefined2 *)((int)puVar25 + -2);
      *puVar26 = pcVar21;
    }
  }
  piVar29 = puVar24 + 2;
  bVar6 = 9 < bVar8 | bVar6;
  cVar9 = cVar9 - (char)*(undefined2 *)(pcVar21 + (int)piVar29);
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  uVar4 = *(undefined2 *)0x26;
  bVar11 = (byte)uVar4;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar11;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar11;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar11;
  bVar6 = 9 < (bVar11 & 0xf) | 9 < (bVar8 & 0xf) | bVar6;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + (bVar11 + bVar6 * -6 & 0xf);
  uVar16 = CONCAT11((char)((uint)uVar4 >> 8) - bVar6,0x65);
  puVar2 = (uint *)(pcVar21 + (int)piVar29);
  uVar13 = *puVar2;
  *puVar2 = *puVar2 + uVar16;
  *pcVar21 = *pcVar21 + extraout_DL + CARRY2(uVar13,uVar16);
  *piVar29 = *piVar29 + uVar16 + 1;
  *pcVar28 = *pcVar28 + extraout_DL;
  cVar18 = (char)(uVar16 + 1);
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + cVar18;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  puVar27 = (undefined1 *)((int)puVar25 + -2);
  *(undefined2 **)(undefined1 *)((int)puVar25 + -2) = puVar25;
  bVar6 = 9 < ((bVar8 + bVar6 * -6 & 0xf) + bVar6 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  *(undefined2 *)(puVar27 + -1) = uVar30;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar8;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar8;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar8;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar8;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar8;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + bVar8;
  pcVar21[(int)piVar29] = pcVar21[(int)piVar29] + (bVar8 + (9 < (bVar8 & 0xf) | bVar6) * -6 & 0xf);
  pcVar28[1] = pcVar28[1] + (char)((uint)pcVar21 >> 8);
  *(char *)((int)puVar24 + 0x3f) = *(char *)((int)puVar24 + 0x3f) + cVar9;
  return;
}


