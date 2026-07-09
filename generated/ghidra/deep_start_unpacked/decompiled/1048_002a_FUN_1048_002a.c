
/* WARNING: Instruction at (ram,0x0001060f) overlaps instruction at (ram,0x0001060e)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1048_002a(void)

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
  uint uVar11;
  int iVar12;
  char cVar16;
  int iVar13;
  uint uVar15;
  char cVar17;
  undefined2 in_CX;
  int iVar18;
  char extraout_DL;
  char extraout_DH;
  uint in_BX;
  char *pcVar19;
  undefined2 *puVar20;
  undefined2 *puVar21;
  undefined1 *puVar22;
  uint *unaff_BP;
  char *pcVar23;
  char *unaff_SI;
  int *piVar24;
  char *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 uVar25;
  undefined2 unaff_DS;
  undefined2 uVar26;
  undefined2 in_GS;
  bool bVar27;
  byte in_AF;
  longdouble in_ST0;
  undefined2 *in_stack_0000000c;
  undefined2 *puVar14;
  
  pcVar5 = (code *)swi(0x3f);
  uVar11 = (*pcVar5)();
  *(uint *)(unaff_SI + in_BX) = *(uint *)(unaff_SI + in_BX) | uVar11;
  in_AF = 9 < ((byte)uVar11 & 0xf) | in_AF;
  bVar8 = (byte)uVar11 + in_AF * -6 & 0xf;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar8;
  *(byte *)0x1 = *(byte *)0x1 | 0x96;
  *unaff_BP = *unaff_BP | (uint)unaff_DI;
  iVar12 = CONCAT11((char)(uVar11 >> 8) - in_AF,bVar8 - unaff_SI[in_BX]) + -1;
  bVar8 = (byte)iVar12;
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
  cVar16 = (char)((uint)iVar12 >> 8) - in_AF;
  *(uint *)(unaff_SI + in_BX) =
       *(uint *)(unaff_SI + in_BX) |
       CONCAT11((char)((uint)in_CX >> 8) + (char)in_CX * '\x02',(char)in_CX);
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  cVar17 = bVar8 - unaff_SI[in_BX];
  cVar16 = cVar16 + cVar17;
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
  pcVar23 = unaff_SI + 1;
  pcVar23[in_BX] = pcVar23[in_BX] + *unaff_SI;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  pcVar19 = (char *)(in_BX & 0xff00);
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = bVar8 + in_AF * -6 & 0xf;
  iVar12 = CONCAT11(cVar16 + cVar17,cVar17) + -1;
  cVar7 = (char)iVar12;
  cVar16 = (char)((uint)iVar12 >> 8) + cVar7;
  in_AF = 9 < bVar8 | in_AF;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + (bVar8 + in_AF * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  iVar13 = (*pcVar5)();
  iVar12 = *(int *)(pcVar19 + (int)unaff_DI);
  bVar8 = (byte)(iVar13 + iVar12);
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar6 = bVar8 + in_AF * -6 & 0xf;
  pcVar19[(int)unaff_DI] = (pcVar19[(int)unaff_DI] - bVar6) - in_AF;
  iVar18 = CONCAT11(cVar16 + cVar7 * '\x02',cVar7);
  bVar8 = 9 < bVar6 | in_AF;
  uVar26 = *in_stack_0000000c;
  puVar20 = in_stack_0000000c + 1;
  *(uint *)(pcVar19 + (int)pcVar23) =
       *(int *)(pcVar19 + (int)pcVar23) +
       (CONCAT11(((char)((uint)(iVar13 + iVar12) >> 8) - in_AF) - bVar8,bVar6 + bVar8 * -6) & 0xff0f
       );
  pcVar5 = (code *)swi(0x3f);
  iVar12 = (*pcVar5)();
  puVar2 = (uint *)(pcVar19 + (int)pcVar23);
  *puVar2 = *puVar2 + iVar12;
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
  pcVar19[(int)unaff_DI] = pcVar19[(int)unaff_DI];
  pcVar5 = (code *)swi(0x3f);
  iVar12 = (*pcVar5)();
  *(int *)(pcVar19 + (int)pcVar23) = *(int *)(pcVar19 + (int)pcVar23) + iVar12;
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
  cVar16 = (char)iVar18;
  cVar17 = (char)((uint)iVar18 >> 8) + cVar16;
  bVar8 = 9 < (cVar7 + *pcVar23 & 0xfU) | bVar8;
  pcVar5 = (code *)swi(0x3f);
  iVar12 = (*pcVar5)();
  uVar25 = *puVar20;
  bVar6 = (byte)(iVar12 + -0x3300);
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  iVar12 = (CONCAT11((char)((uint)(iVar12 + -0x3300) >> 8) - bVar8,bVar6 + bVar8 * -6) & 0xff0f) +
           0xcd00;
  bVar8 = 9 < ((byte)iVar12 & 0xf) | bVar8;
  pcVar23 = unaff_SI + 3;
  iVar12 = CONCAT11((char)((uint)iVar12 >> 8) - bVar8,unaff_SI[2]) + -0x3300;
  bVar6 = (byte)iVar12;
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  bVar10 = bVar6 + bVar8 * -6 & 0xf;
  *puVar20 = unaff_ES;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  pcVar19[(int)pcVar23] = pcVar19[(int)pcVar23] + bVar10;
  iVar13 = CONCAT11(cVar17 + cVar16,cVar16);
  bVar6 = 9 < bVar10 | bVar8;
  bVar10 = bVar10 + bVar6 * -6;
  bVar9 = bVar10 & 0xf;
  puVar14 = (undefined2 *)(CONCAT11(((char)((uint)iVar12 >> 8) - bVar8) - bVar6,bVar10) & 0xff0f);
  pbVar3 = (byte *)(pcVar19 + (int)pcVar23);
  bVar8 = *pbVar3;
  *pbVar3 = *pbVar3 + bVar9;
  cVar7 = (char)pcVar23;
  pcVar19[(int)unaff_DI] = (pcVar19[(int)unaff_DI] - cVar7) - CARRY1(bVar8,bVar9);
  pcVar1 = (char *)((int)unaff_BP + (int)puVar14 + 0x6849);
  *pcVar1 = *pcVar1 + extraout_DH;
  *(char *)((int)unaff_BP + (int)unaff_DI) = *(char *)((int)unaff_BP + (int)unaff_DI) + cVar16;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar19[(int)puVar14] = pcVar19[(int)puVar14] + cVar7;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  cVar7 = (char)(iVar13 + -1);
  cVar16 = (char)((uint)(iVar13 + -1) >> 8) + cVar7;
  bVar6 = 9 < ((byte)*puVar14 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  pcVar19[(int)(puVar14 + 1)] = pcVar19[(int)(puVar14 + 1)] + bVar8;
  cVar16 = cVar16 + cVar7 * '\x02';
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  bVar8 = bVar8 + bVar6 * -6 & 0xf;
  bVar6 = 9 < bVar8 | bVar6;
  *(uint *)(pcVar19 + (int)(puVar14 + 1)) =
       *(uint *)(pcVar19 + (int)(puVar14 + 1)) & CONCAT11(cVar16,cVar7);
  cVar16 = cVar16 + cVar7;
  bVar6 = 9 < (bVar8 + bVar6 * -6 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  cVar7 = cVar7 + *(char *)((int)unaff_BP + (int)unaff_DI);
  cVar16 = cVar16 + cVar7 * '\x05';
  bVar6 = 9 < (bVar8 & 0xf) | bVar6;
  bVar8 = bVar8 + bVar6 * -6 & 0xf;
  *(sqword *)((int)unaff_BP + (int)unaff_DI) = (sqword)in_ST0;
  bVar6 = 9 < bVar8 | bVar6;
  bVar8 = bVar8 + bVar6 * -6 & 0xf;
  pcVar23 = (char *)TaskRegister();
  bVar27 = (bool)(9 < bVar8 | bVar6);
  bVar6 = bVar8 + bVar27 * -6 & 0xf;
  bVar8 = 0;
  if (bVar27) {
    *unaff_DI = *unaff_DI + cVar16;
    cVar16 = cVar16 + cVar7;
    pcVar23 = *(char **)unaff_DI;
    bVar6 = ((((bVar6 - 6 & 0xf) - 0x35 & 0xf ^ 0x3c) - 6 & 0xf) - 6 & 0xf) - 6 & 0xf;
    if (SCARRY1(cVar16,cVar7) == (char)(cVar16 + cVar7) < '\0') {
      bVar8 = 1;
      bVar6 = bVar6 - 6 & 0xf;
    }
    else {
      bVar8 = 1;
      bVar6 = (bVar6 - 6 & 0xf) - 6 & 0xf;
      puVar21 = (undefined2 *)((int)puVar20 + -2);
      puVar20 = (undefined2 *)((int)puVar20 + -2);
      *puVar21 = pcVar19;
    }
  }
  piVar24 = puVar14 + 2;
  bVar8 = 9 < bVar6 | bVar8;
  cVar7 = cVar7 - (char)*(undefined2 *)(pcVar19 + (int)piVar24);
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  uVar4 = *(undefined2 *)0x26;
  bVar10 = (byte)uVar4;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar10;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar10;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar10;
  bVar8 = 9 < (bVar10 & 0xf) | 9 < (bVar6 & 0xf) | bVar8;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + (bVar10 + bVar8 * -6 & 0xf);
  uVar15 = CONCAT11((char)((uint)uVar4 >> 8) - bVar8,0x65);
  puVar2 = (uint *)(pcVar19 + (int)piVar24);
  uVar11 = *puVar2;
  *puVar2 = *puVar2 + uVar15;
  *pcVar19 = *pcVar19 + extraout_DL + CARRY2(uVar11,uVar15);
  *piVar24 = *piVar24 + uVar15 + 1;
  *pcVar23 = *pcVar23 + extraout_DL;
  cVar16 = (char)(uVar15 + 1);
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + cVar16;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  bVar8 = 9 < (bVar6 & 0xf) | bVar8;
  puVar22 = (undefined1 *)((int)puVar20 + -2);
  *(undefined2 **)(undefined1 *)((int)puVar20 + -2) = puVar20;
  bVar8 = 9 < ((bVar6 + bVar8 * -6 & 0xf) + bVar8 & 0xf) | bVar8;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  *(undefined2 *)(puVar22 + -1) = uVar25;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar6;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar6;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar6;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar6;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar6;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + bVar6;
  pcVar19[(int)piVar24] = pcVar19[(int)piVar24] + (bVar6 + (9 < (bVar6 & 0xf) | bVar8) * -6 & 0xf);
  pcVar23[1] = pcVar23[1] + (char)((uint)pcVar19 >> 8);
  *(char *)((int)puVar14 + 0x3f) = *(char *)((int)puVar14 + 0x3f) + cVar7;
  return;
}


