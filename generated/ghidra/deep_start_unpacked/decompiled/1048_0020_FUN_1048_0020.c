
/* WARNING: Instruction at (ram,0x0001060f) overlaps instruction at (ram,0x0001060e)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1048_0020(void)

{
  char *pcVar1;
  uint *puVar2;
  byte *pbVar3;
  undefined2 uVar4;
  code *pcVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  char cVar17;
  int iVar14;
  uint uVar16;
  undefined2 in_CX;
  char cVar19;
  int iVar18;
  char extraout_DL;
  char extraout_DH;
  uint in_BX;
  char *pcVar20;
  undefined2 *puVar21;
  undefined2 *puVar22;
  undefined1 *puVar23;
  uint *unaff_BP;
  char *pcVar24;
  char *unaff_SI;
  int *piVar25;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar26;
  undefined2 unaff_DS;
  undefined2 in_GS;
  bool bVar27;
  byte in_AF;
  longdouble in_ST0;
  longdouble in_ST1;
  undefined2 *in_stack_0000000e;
  undefined2 *puVar15;
  
  pcVar5 = (code *)swi(0x3f);
  uVar11 = (*pcVar5)();
  *(int *)((int)unaff_BP + (int)unaff_DI) = (int)in_ST0;
  cVar7 = (char)in_CX;
  cVar19 = (char)((uint)in_CX >> 8) + cVar7;
  in_AF = 9 < ((byte)uVar11 & 0xf) | in_AF;
  *(uint *)(unaff_SI + in_BX) =
       *(int *)(unaff_SI + in_BX) +
       (CONCAT11((char)((uint)uVar11 >> 8) - in_AF,(byte)uVar11 + in_AF * -6) & 0xff0f);
  pcVar5 = (code *)swi(0x3f);
  uVar12 = (*pcVar5)();
  *(uint *)(unaff_SI + in_BX) = *(uint *)(unaff_SI + in_BX) | uVar12;
  in_AF = 9 < ((byte)uVar12 & 0xf) | in_AF;
  bVar8 = (byte)uVar12 + in_AF * -6 & 0xf;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  *(byte *)0x1 = *(byte *)0x1 | 0x96;
  *unaff_BP = *unaff_BP | (uint)unaff_DI;
  iVar13 = CONCAT11((char)(uVar12 >> 8) - in_AF,bVar8 - unaff_SI[in_BX]) + -1;
  bVar8 = (byte)iVar13;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = bVar8 + in_AF * -6 & 0xf;
  cVar17 = (char)((uint)iVar13 >> 8) - in_AF;
  *(uint *)(unaff_SI + in_BX) =
       *(uint *)(unaff_SI + in_BX) | CONCAT11(cVar19 + cVar7 * '\x02',cVar7);
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  cVar19 = bVar8 - unaff_SI[in_BX];
  cVar17 = cVar17 + cVar19;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  unaff_SI[in_BX] = unaff_SI[in_BX] + (bVar6 + in_AF * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  cVar7 = (*pcVar5)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + cVar7;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  unaff_SI[in_BX] = unaff_SI[in_BX];
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar24 = unaff_SI + 1;
  pcVar24[in_BX] = pcVar24[in_BX] + *unaff_SI;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  pcVar20 = (char *)(in_BX & 0xff00);
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = bVar8 + in_AF * -6 & 0xf;
  iVar13 = CONCAT11(cVar17 + cVar19,cVar19) + -1;
  cVar7 = (char)iVar13;
  cVar17 = (char)((uint)iVar13 >> 8) + cVar7;
  in_AF = 9 < bVar8 | in_AF;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + (bVar8 + in_AF * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  iVar14 = (*pcVar5)();
  iVar13 = *(int *)(pcVar20 + (int)unaff_DI);
  bVar8 = (byte)(iVar14 + iVar13);
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar6 = bVar8 + in_AF * -6 & 0xf;
  pcVar20[(int)unaff_DI] = (pcVar20[(int)unaff_DI] - bVar6) - in_AF;
  iVar18 = CONCAT11(cVar17 + cVar7 * '\x02',cVar7);
  bVar8 = 9 < bVar6 | in_AF;
  uVar11 = *in_stack_0000000e;
  puVar21 = in_stack_0000000e + 1;
  *(uint *)(pcVar20 + (int)pcVar24) =
       *(int *)(pcVar20 + (int)pcVar24) +
       (CONCAT11(((char)((uint)(iVar14 + iVar13) >> 8) - in_AF) - bVar8,bVar6 + bVar8 * -6) & 0xff0f
       );
  pcVar5 = (code *)swi(0x3f);
  iVar13 = (*pcVar5)();
  puVar2 = (uint *)(pcVar20 + (int)pcVar24);
  *puVar2 = *puVar2 + iVar13;
  bVar27 = (POPCOUNT(*puVar2 & 0xff) & 1U) == 0;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  if (bVar27) {
    pcVar5 = (code *)swi(0x3f);
    (*pcVar5)();
  }
  else {
    iVar18 = CONCAT11((char)((uint)iVar18 >> 8) + (char)iVar18,(char)iVar18);
    bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  }
  pcVar20[(int)unaff_DI] = pcVar20[(int)unaff_DI];
  pcVar5 = (code *)swi(0x3f);
  iVar13 = (*pcVar5)();
  *(int *)(pcVar20 + (int)pcVar24) = *(int *)(pcVar20 + (int)pcVar24) + iVar13;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  iVar18 = iVar18 + -1;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  *(char *)((int)unaff_BP + (int)unaff_DI) = *(char *)((int)unaff_BP + (int)unaff_DI);
  pcVar5 = (code *)swi(0x3f);
  cVar7 = (*pcVar5)();
  cVar17 = (char)iVar18;
  cVar19 = (char)((uint)iVar18 >> 8) + cVar17;
  bVar8 = 9 < (cVar7 + *pcVar24 & 0xfU) | bVar8;
  pcVar5 = (code *)swi(0x3f);
  iVar13 = (*pcVar5)();
  uVar26 = *puVar21;
  bVar6 = (byte)(iVar13 + -0x3300);
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  iVar13 = (CONCAT11((char)((uint)(iVar13 + -0x3300) >> 8) - bVar8,bVar6 + bVar8 * -6) & 0xff0f) +
           0xcd00;
  bVar8 = 9 < ((byte)iVar13 & 0xf) | bVar8;
  pcVar24 = unaff_SI + 3;
  iVar13 = CONCAT11((char)((uint)iVar13 >> 8) - bVar8,unaff_SI[2]) + -0x3300;
  bVar6 = (byte)iVar13;
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  bVar10 = bVar6 + bVar8 * -6 & 0xf;
  *puVar21 = unaff_ES;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  pcVar20[(int)pcVar24] = pcVar20[(int)pcVar24] + bVar10;
  iVar14 = CONCAT11(cVar19 + cVar17,cVar17);
  bVar6 = 9 < bVar10 | bVar8;
  bVar10 = bVar10 + bVar6 * -6;
  bVar9 = bVar10 & 0xf;
  puVar15 = (undefined2 *)(CONCAT11(((char)((uint)iVar13 >> 8) - bVar8) - bVar6,bVar10) & 0xff0f);
  pbVar3 = (byte *)(pcVar20 + (int)pcVar24);
  bVar8 = *pbVar3;
  *pbVar3 = *pbVar3 + bVar9;
  cVar7 = (char)pcVar24;
  pcVar20[(int)unaff_DI] = (pcVar20[(int)unaff_DI] - cVar7) - CARRY1(bVar8,bVar9);
  pcVar1 = (char *)((int)unaff_BP + (int)puVar15 + 0x6849);
  *pcVar1 = *pcVar1 + extraout_DH;
  *(char *)((int)unaff_BP + (int)unaff_DI) = *(char *)((int)unaff_BP + (int)unaff_DI) + cVar17;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar20[(int)puVar15] = pcVar20[(int)puVar15] + cVar7;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  cVar7 = (char)(iVar14 + -1);
  cVar17 = (char)((uint)(iVar14 + -1) >> 8) + cVar7;
  bVar6 = 9 < ((byte)*puVar15 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  pcVar20[(int)(puVar15 + 1)] = pcVar20[(int)(puVar15 + 1)] + bVar8;
  cVar17 = cVar17 + cVar7 * '\x02';
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  bVar8 = bVar8 + bVar6 * -6 & 0xf;
  bVar6 = 9 < bVar8 | bVar6;
  *(uint *)(pcVar20 + (int)(puVar15 + 1)) =
       *(uint *)(pcVar20 + (int)(puVar15 + 1)) & CONCAT11(cVar17,cVar7);
  cVar17 = cVar17 + cVar7;
  bVar6 = 9 < (bVar8 + bVar6 * -6 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  cVar7 = cVar7 + *(char *)((int)unaff_BP + (int)unaff_DI);
  cVar17 = cVar17 + cVar7 * '\x05';
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  bVar8 = bVar8 + bVar6 * -6 & 0xf;
  *(sqword *)((int)unaff_BP + (int)unaff_DI) = (sqword)in_ST1;
  bVar6 = 9 < bVar8 | bVar6;
  bVar8 = bVar8 + bVar6 * -6 & 0xf;
  pcVar24 = (char *)TaskRegister();
  bVar27 = (bool)(9 < bVar8 | bVar6);
  bVar6 = bVar8 + bVar27 * -6 & 0xf;
  bVar8 = 0;
  if (bVar27) {
    *unaff_DI = *unaff_DI + cVar17;
    cVar17 = cVar17 + cVar7;
    pcVar24 = *(char **)unaff_DI;
    bVar6 = ((((bVar6 - 6 & 0xf) - 0x35 & 0xf ^ 0x3c) - 6 & 0xf) - 6 & 0xf) - 6 & 0xf;
    if (SCARRY1(cVar17,cVar7) == (char)(cVar17 + cVar7) < '\0') {
      bVar8 = 1;
      bVar6 = bVar6 - 6 & 0xf;
    }
    else {
      bVar8 = 1;
      bVar6 = (bVar6 - 6 & 0xf) - 6 & 0xf;
      puVar22 = (undefined2 *)((int)puVar21 + -2);
      puVar21 = (undefined2 *)((int)puVar21 + -2);
      *puVar22 = pcVar20;
    }
  }
  piVar25 = puVar15 + 2;
  bVar8 = 9 < bVar6 | bVar8;
  cVar7 = cVar7 - (char)*(undefined2 *)(pcVar20 + (int)piVar25);
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  uVar4 = *(undefined2 *)0x26;
  bVar10 = (byte)uVar4;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar10;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar10;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar10;
  bVar8 = 9 < (bVar10 & 0xf) | 9 < (bVar6 & 0xf) | bVar8;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + (bVar10 + bVar8 * -6 & 0xf);
  uVar16 = CONCAT11((char)((uint)uVar4 >> 8) - bVar8,0x65);
  puVar2 = (uint *)(pcVar20 + (int)piVar25);
  uVar12 = *puVar2;
  *puVar2 = *puVar2 + uVar16;
  *pcVar20 = *pcVar20 + extraout_DL + CARRY2(uVar12,uVar16);
  *piVar25 = *piVar25 + uVar16 + 1;
  *pcVar24 = *pcVar24 + extraout_DL;
  cVar17 = (char)(uVar16 + 1);
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + cVar17;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  puVar23 = (undefined1 *)((int)puVar21 + -2);
  *(undefined2 **)(undefined1 *)((int)puVar21 + -2) = puVar21;
  bVar8 = 9 < ((bVar6 + bVar8 * -6 & 0xf) + bVar8 & 0xf) | bVar8;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  *(undefined2 *)(puVar23 + -1) = uVar26;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar6;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar6;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar6;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar6;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar6;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + bVar6;
  pcVar20[(int)piVar25] = pcVar20[(int)piVar25] + (bVar6 + (9 < (bVar6 & 0xf) | bVar8) * -6 & 0xf);
  pcVar24[1] = pcVar24[1] + (char)((uint)pcVar20 >> 8);
  *(char *)((int)puVar15 + 0x3f) = *(char *)((int)puVar15 + 0x3f) + cVar7;
  return;
}


