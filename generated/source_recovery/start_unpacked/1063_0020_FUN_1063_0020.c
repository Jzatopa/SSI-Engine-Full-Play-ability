/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1063:0020
 * Ghidra name: FUN_1063_0020
 * Linear address: 0x10650
 * Body addresses: 5
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000106f7) overlaps instruction at (ram,0x000106f5)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void FUN_1063_0020(void)

{
  byte *pbVar1;
  uint *puVar2;
  undefined1 uVar3;
  code *pcVar4;
  code *pcVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  undefined2 uVar10;
  undefined2 *puVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  char cVar16;
  int iVar15;
  char extraout_DH;
  uint extraout_DX;
  int in_BX;
  char *pcVar17;
  uint *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  int unaff_BP;
  byte *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 uVar25;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char cVar26;
  byte bVar27;
  byte bVar28;
  byte in_AF;
  byte bVar29;
  byte bVar30;
  byte in_TF;
  byte in_IF;
  byte bVar31;
  byte in_NT;
  undefined4 uVar32;
  
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  iVar9 = (*pcVar5)();
  iVar15 = unaff_DI + 2;
  *(undefined1 *)(unaff_DI + 1) = (char)iVar9;
  *(int *)(unaff_SI + in_BX) = *(int *)(unaff_SI + in_BX) + iVar9;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  pcVar17 = (char *)CONCAT11((char)((uint)in_BX >> 8),unaff_SI[in_BX]);
  bVar8 = (byte)uVar10;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar8;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar8;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar8;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar8;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar8;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar8;
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar7 = bVar8 + in_AF * -6 & 0xf;
  pbVar1 = (byte *)(pcVar17 + (int)unaff_SI);
  bVar8 = *pbVar1;
  *pbVar1 = *pbVar1 + bVar7;
  puVar19 = (undefined1 *)0xffff;
  *(int *)0xffff = unaff_BP;
  cVar6 = bVar7 + *(char *)0x401 + CARRY1(bVar8,bVar7);
  *(char *)(unaff_BP + iVar15) = *(char *)(unaff_BP + iVar15) + ((char)((uint)uVar10 >> 8) - in_AF);
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6;
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  puVar20 = puVar19 + -2;
  *(undefined2 *)(puVar19 + -2) = uVar10;
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  in_AF = 9 < ((byte)uVar10 & 0xf) | in_AF;
  bVar8 = (byte)uVar10 + in_AF * -6;
  bVar7 = bVar8 & 0xf;
  cVar6 = (char)((uint)uVar10 >> 8) - in_AF;
  *(int *)(unaff_BP + iVar15) = *(int *)(unaff_BP + iVar15) + (CONCAT11(cVar6,bVar8) & 0xff0f);
  in_AF = 9 < bVar7 | in_AF;
  bVar27 = bVar7 + in_AF * -6 & 0xf;
  bVar8 = *unaff_SI;
  bVar7 = bVar27 | bVar8;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  bVar8 = 9 < (bVar27 | bVar8 & 0xf) | in_AF;
  bVar7 = bVar7 + bVar8 * -6;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + (bVar7 & 0xf);
  iVar9 = (CONCAT11((cVar6 - in_AF) - bVar8,bVar7) & 0xff0f) + 0x1220;
  *(char **)(pcVar17 + (int)unaff_SI) = pcVar17 + *(int *)(pcVar17 + (int)unaff_SI);
  *pcVar17 = *pcVar17 + (char)((uint)iVar9 >> 8);
  bVar7 = (byte)iVar9;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  pbVar1 = (byte *)(pcVar17 + (int)unaff_SI);
  cVar26 = CARRY1(*pbVar1,bVar7);
  *pbVar1 = *pbVar1 + bVar7;
  pcVar5 = (code *)swi(0x3f);
  iVar9 = iVar15;
  uVar10 = (*pcVar5)();
  cVar6 = (char)((uint)uVar10 >> 8);
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + cVar6 + cVar26;
  cVar26 = (char)iVar9;
  cVar16 = (char)((uint)iVar9 >> 8) + cVar26;
  bVar8 = 9 < ((byte)uVar10 & 0xf) | bVar8;
  puVar11 = (undefined2 *)(CONCAT11(cVar6 - bVar8,(byte)uVar10 + bVar8 * -6) & 0xff0f);
  *(int *)(pcVar17 + (int)unaff_SI) = *(int *)(pcVar17 + (int)unaff_SI) + iVar15;
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  bVar7 = (byte)uVar10;
  pcVar17[(int)unaff_SI] = pcVar17[(int)unaff_SI] + bVar7;
  cVar16 = cVar16 + cVar26 * '\x03';
  bVar8 = 9 < (bVar7 & 0xf) | bVar8;
  bVar7 = (bVar7 + bVar8 * -6 & 0xf) + ((char)((uint)uVar10 >> 8) - bVar8) * '\x02';
  bVar8 = 9 < (bVar7 & 0xf) | bVar8;
  uVar12 = CONCAT11(-bVar8,bVar7 + bVar8 * -6) & 0xff04;
  bVar7 = (byte)uVar12;
  bVar8 = 9 < bVar7 | bVar8;
  bVar7 = bVar7 + bVar8 * -6;
  bVar27 = bVar7 & 0xf;
  out(4,CONCAT11((char)(uVar12 >> 8) - bVar8,bVar7) & 0xff0f);
  cVar6 = cVar16 + cVar26;
  bVar8 = 9 < bVar27 | bVar8;
  bVar7 = bVar27 + bVar8 * -6 & 0xf;
  if (SCARRY1(cVar16,cVar26) != cVar6 < '\0') {
    cVar6 = cVar6 + cVar26;
  }
  cVar6 = cVar6 + cVar26 * '\x03';
  bVar8 = 9 < bVar7 | bVar8;
  bVar7 = bVar7 + bVar8 * -6 & 0xf;
  *(char *)0xcd00 = *(char *)0xcd00 + bVar7 + bVar8;
  bVar8 = 9 < bVar7 | bVar8;
  *(undefined2 *)(puVar20 + -2) = unaff_SS;
  uVar25 = *(undefined2 *)(puVar20 + -2);
  bVar7 = 9 < (bVar7 + bVar8 * -6 & 0xf) | bVar8 | 1;
  *puVar11 = *puVar11;
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  *(undefined2 *)0xf = uVar10;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  puVar21 = puVar20 + -2;
  *(undefined2 *)(puVar20 + -2) = 0x1a;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  *(int *)(unaff_SI + unaff_BP) = -*(int *)(unaff_SI + unaff_BP);
  cVar6 = cVar6 + cVar26 * '\x02';
  bVar7 = 9 < (bVar8 & 0xf) | bVar7;
  bVar7 = 9 < ((bVar8 + bVar7 * -6 & 0xf) - 0x1b & 0xf) | bVar7;
  uVar10 = ((undefined2 *)(unaff_BP + (int)puVar11))[1];
  pcVar4 = (code *)*(undefined2 *)(unaff_BP + (int)puVar11);
  *(undefined2 *)(puVar21 + -2) = 0x1063;
  puVar22 = puVar21 + -4;
  *(undefined2 *)(puVar21 + -4) = 0x738;
  bVar8 = (*pcVar4)();
  cVar6 = cVar6 + cVar26 * '\x02';
  bVar7 = 9 < (bVar8 & 0xf) | bVar7;
  bVar8 = (bVar8 + bVar7 * -6 & 0xf) - bVar7;
  bVar7 = 9 < (bVar8 & 0xf) | bVar7;
  puVar18 = *(uint **)pcVar17;
  bVar7 = 9 < (bVar8 + bVar7 * -6 & 0xf) | bVar7;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + 0x1e;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + 0x1e;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + 0x1e;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + 0x1e;
  pcVar5 = (code *)swi(0x3f);
  uVar13 = (*pcVar5)();
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + (char)uVar13;
  LOCK();
  puVar2 = (uint *)((int)puVar18 + (int)unaff_SI);
  uVar12 = *puVar2;
  *puVar2 = *puVar2 + uVar13;
  UNLOCK();
  bVar8 = ((char)uVar13 + -1) - CARRY2(uVar12,uVar13);
  *(char *)(unaff_BP + (int)puVar11) = *(char *)(unaff_BP + (int)puVar11) + bVar8;
  *(char *)(unaff_BP + (int)puVar11) = *(char *)(unaff_BP + (int)puVar11) + cVar6;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  pbVar1 = (byte *)((int)puVar18 + (int)unaff_SI);
  cVar16 = CARRY1(*pbVar1,bVar8);
  *pbVar1 = *pbVar1 + bVar8;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  *(char *)((int)puVar18 + (int)puVar11) = (*(char *)((int)puVar18 + (int)puVar11) - bVar8) - cVar16
  ;
  bVar7 = 9 < (bVar8 & 0xf) | bVar7;
  bVar8 = bVar8 + bVar7 * -6 & 0xf;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  iVar15 = CONCAT11(cVar6 + cVar26 * '\x02',cVar26);
  bVar7 = 9 < bVar8 | bVar7;
  *(byte *)((int)puVar18 + (int)unaff_SI) =
       *(byte *)((int)puVar18 + (int)unaff_SI) + (bVar8 + bVar7 * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  bVar8 = (byte)uVar10;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + 0x7e1b) = *(char *)((int)puVar18 + 0x7e1b) + (char)((uint)uVar10 >> 8);
  iVar15 = iVar15 + *(int *)unaff_SI;
  *(char *)0x1f1 = *(char *)0x1f1 + extraout_DH;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(byte *)((int)puVar18 + (int)unaff_SI) = *(byte *)((int)puVar18 + (int)unaff_SI) + bVar8;
  pbVar1 = (byte *)((int)puVar18 + (int)unaff_SI);
  bVar27 = CARRY1(*pbVar1,bVar8);
  bVar31 = SCARRY1(*pbVar1,bVar8);
  *pbVar1 = *pbVar1 + bVar8;
  bVar30 = (char)*pbVar1 < '\0';
  bVar29 = *pbVar1 == 0;
  bVar28 = (POPCOUNT(*pbVar1) & 1U) == 0;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  *(uint *)(puVar22 + -2) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar31 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar30 & 1) * 0x80 | (uint)(bVar29 & 1) * 0x40 |
       (uint)(bVar7 & 1) * 0x10 | (uint)(bVar28 & 1) * 4 | (uint)(bVar27 & 1);
  bVar8 = bVar8 < *(byte *)((int)puVar18 + (int)unaff_SI);
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  puVar23 = (undefined1 *)0x3;
  pcVar5 = (code *)swi(0x3f);
  uVar32 = (*pcVar5)();
  *puVar18 = (*puVar18 - (int)uVar32) - (uint)bVar8;
  cVar6 = (char)iVar15;
  cVar26 = (char)((uint)iVar15 >> 8) + cVar6 * '\x02';
  bVar7 = 9 < ((byte)uVar32 & 0xf) | bVar7;
  bVar8 = (byte)uVar32 + bVar7 * -6 & 0xf;
  uVar3 = in((int)((ulong)uVar32 >> 0x10));
  *(undefined1 *)0x1f1 = uVar3;
  puVar24 = puVar23 + 2;
  bVar7 = 9 < bVar8 | bVar7;
  cVar16 = '\0';
  *(byte *)((int)puVar18 + (int)unaff_SI) =
       *(byte *)((int)puVar18 + (int)unaff_SI) | bVar8 + bVar7 * -6 & 0xf;
  pcVar5 = (code *)swi(0x3f);
  puVar14 = (uint *)(*pcVar5)();
  *(char *)((int)puVar18 + (int)puVar14) =
       *(char *)((int)puVar18 + (int)puVar14) + (char)unaff_SI + cVar16;
  pcVar5 = (code *)swi(0x3f);
  bVar8 = (*pcVar5)();
  *puVar18 = *puVar18 & extraout_DX;
  cVar26 = cVar26 + cVar6;
  bVar7 = 9 < (bVar8 & 0xf) | bVar7;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  uVar10 = (*pcVar5)();
  *puVar14 = *puVar14 ^ (uint)puVar24;
  bVar7 = 9 < ((byte)uVar10 & 0xf) | bVar7;
  bVar8 = (byte)uVar10 + bVar7 * -6;
  if ((POPCOUNT(cVar26 + cVar6) & 1U) == 0) {
    bVar28 = 9 < (bVar8 & 0xf) | bVar7;
    bVar8 = (bVar8 & 0xf) + bVar28 * -6 & 0xf;
    *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
    *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
    bVar29 = 9 < bVar8 | bVar28;
    bVar8 = bVar8 + bVar29 * -6 & 0xf;
    *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
    bVar8 = bVar8 + *(char *)((int)puVar18 + (int)puVar14);
    bVar27 = 9 < (bVar8 & 0xf) | bVar29;
    bVar8 = bVar8 + bVar27 * '\x06';
    bVar7 = (byte)((uint)puVar18 >> 8) ^
            ((((char)((uint)uVar10 >> 8) - bVar7) - bVar28) - bVar29) + bVar27;
    puVar18 = (uint *)CONCAT11(bVar7,(char)puVar18);
    *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar7;
  }
  bVar8 = bVar8 & 0xf;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  *(char *)((int)puVar18 + (int)puVar14) = *(char *)((int)puVar18 + (int)puVar14) + bVar8;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  *(char *)puVar18 = (char)*puVar18;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  *puVar14 = *puVar14;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


