
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x000106f7) overlaps instruction at (ram,0x000106f5)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void FUN_106b_0020(void)

{
  uint *puVar1;
  byte *pbVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  code *pcVar7;
  byte bVar8;
  undefined2 uVar9;
  undefined2 *puVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  undefined2 in_CX;
  char cVar15;
  char cVar16;
  int iVar14;
  char cVar17;
  char extraout_DH;
  uint extraout_DX;
  undefined2 *in_BX;
  uint *puVar18;
  undefined1 *puVar20;
  undefined1 *puVar21;
  int unaff_BP;
  int *unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  byte in_AF;
  undefined4 uVar22;
  byte bVar19;
  
  pcVar7 = (code *)swi(0x3f);
  uVar9 = (*pcVar7)();
  cVar16 = (char)((uint)uVar9 >> 8);
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar16 + in_CF;
  cVar17 = (char)in_CX;
  cVar15 = (char)((uint)in_CX >> 8) + cVar17;
  in_AF = 9 < ((byte)uVar9 & 0xf) | in_AF;
  puVar10 = (undefined2 *)(CONCAT11(cVar16 - in_AF,(byte)uVar9 + in_AF * -6) & 0xff0f);
  *(int *)((int)in_BX + (int)unaff_SI) = *(int *)((int)in_BX + (int)unaff_SI) + unaff_DI;
  pcVar7 = (code *)swi(0x3f);
  uVar9 = (*pcVar7)();
  bVar8 = (byte)uVar9;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + bVar8;
  cVar15 = cVar15 + cVar17 * '\x03';
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = (bVar8 + in_AF * -6 & 0xf) + ((char)((uint)uVar9 >> 8) - in_AF) * '\x02';
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  uVar11 = CONCAT11(-in_AF,bVar8 + in_AF * -6) & 0xff04;
  bVar8 = (byte)uVar11;
  in_AF = 9 < bVar8 | in_AF;
  bVar8 = bVar8 + in_AF * -6;
  bVar19 = bVar8 & 0xf;
  out(4,CONCAT11((char)(uVar11 >> 8) - in_AF,bVar8) & 0xff0f);
  cVar16 = cVar15 + cVar17;
  in_AF = 9 < bVar19 | in_AF;
  bVar8 = bVar19 + in_AF * -6 & 0xf;
  if (SCARRY1(cVar15,cVar17) != cVar16 < '\0') {
    cVar16 = cVar16 + cVar17;
  }
  cVar16 = cVar16 + cVar17 * '\x03';
  in_AF = 9 < bVar8 | in_AF;
  bVar8 = bVar8 + in_AF * -6 & 0xf;
  *(char *)0xcd00 = *(char *)0xcd00 + bVar8 + in_AF;
  in_AF = 9 < bVar8 | in_AF;
  bVar19 = 9 < (bVar8 + in_AF * -6 & 0xf) | in_AF | 1;
  *puVar10 = *puVar10;
  pcVar7 = (code *)swi(0x3f);
  uVar9 = (*pcVar7)();
  *(undefined2 *)0xf = uVar9;
  pcVar7 = (code *)swi(0x3f);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x3f);
  bVar8 = (*pcVar7)();
  *(int *)(unaff_BP + (int)unaff_SI) = -*(int *)(unaff_BP + (int)unaff_SI);
  cVar16 = cVar16 + cVar17 * '\x02';
  bVar19 = 9 < (bVar8 & 0xf) | bVar19;
  bVar19 = 9 < ((bVar8 + bVar19 * -6 & 0xf) - 0x1b & 0xf) | bVar19;
  bVar8 = (*(code *)*(undefined2 *)(unaff_BP + (int)puVar10))();
  cVar16 = cVar16 + cVar17 * '\x02';
  bVar19 = 9 < (bVar8 & 0xf) | bVar19;
  bVar8 = (bVar8 + bVar19 * -6 & 0xf) - bVar19;
  bVar19 = 9 < (bVar8 & 0xf) | bVar19;
  puVar18 = (uint *)*in_BX;
  bVar19 = 9 < (bVar8 + bVar19 * -6 & 0xf) | bVar19;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + '\x1e';
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + '\x1e';
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + '\x1e';
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + '\x1e';
  pcVar7 = (code *)swi(0x3f);
  uVar12 = (*pcVar7)();
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + (char)uVar12;
  LOCK();
  puVar1 = (uint *)((int)puVar18 + (int)unaff_SI);
  uVar11 = *puVar1;
  *puVar1 = *puVar1 + uVar12;
  UNLOCK();
  bVar8 = ((char)uVar12 + -1) - CARRY2(uVar11,uVar12);
  *(char *)(unaff_BP + (int)puVar10) = *(char *)(unaff_BP + (int)puVar10) + bVar8;
  *(char *)(unaff_BP + (int)puVar10) = *(char *)(unaff_BP + (int)puVar10) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  pbVar2 = (byte *)((int)puVar18 + (int)unaff_SI);
  cVar15 = CARRY1(*pbVar2,bVar8);
  *pbVar2 = *pbVar2 + bVar8;
  pcVar7 = (code *)swi(0x3f);
  bVar8 = (*pcVar7)();
  *(char *)((int)puVar18 + (int)puVar10) = (*(char *)((int)puVar18 + (int)puVar10) - bVar8) - cVar15
  ;
  bVar19 = 9 < (bVar8 & 0xf) | bVar19;
  bVar8 = bVar8 + bVar19 * -6 & 0xf;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + bVar8;
  iVar14 = CONCAT11(cVar16 + cVar17 * '\x02',cVar17);
  bVar19 = 9 < bVar8 | bVar19;
  *(char *)((int)puVar18 + (int)unaff_SI) =
       *(char *)((int)puVar18 + (int)unaff_SI) + (bVar8 + bVar19 * -6 & 0xf);
  pcVar7 = (code *)swi(0x3f);
  uVar9 = (*pcVar7)();
  cVar16 = (char)uVar9;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + 0x7e1b) = *(char *)((int)puVar18 + 0x7e1b) + (char)((uint)uVar9 >> 8);
  iVar14 = iVar14 + *unaff_SI;
  *(char *)0x1f1 = *(char *)0x1f1 + extraout_DH;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  *(char *)((int)puVar18 + (int)unaff_SI) = *(char *)((int)puVar18 + (int)unaff_SI) + cVar16;
  pcVar7 = (code *)swi(0x3f);
  bVar8 = (*pcVar7)();
  bVar8 = bVar8 < *(byte *)((int)puVar18 + (int)unaff_SI);
  pcVar7 = (code *)swi(0x3f);
  (*pcVar7)();
  puVar20 = (undefined1 *)0x3;
  pcVar7 = (code *)swi(0x3f);
  uVar22 = (*pcVar7)();
  *puVar18 = (*puVar18 - (int)uVar22) - (uint)bVar8;
  cVar16 = (char)iVar14;
  cVar17 = (char)((uint)iVar14 >> 8) + cVar16 * '\x02';
  bVar19 = 9 < ((byte)uVar22 & 0xf) | bVar19;
  bVar8 = (byte)uVar22 + bVar19 * -6 & 0xf;
  uVar3 = in((int)((ulong)uVar22 >> 0x10));
  *(undefined1 *)0x1f1 = uVar3;
  puVar21 = puVar20 + 2;
  bVar19 = 9 < bVar8 | bVar19;
  cVar15 = '\0';
  *(byte *)((int)puVar18 + (int)unaff_SI) =
       *(byte *)((int)puVar18 + (int)unaff_SI) | bVar8 + bVar19 * -6 & 0xf;
  pcVar7 = (code *)swi(0x3f);
  puVar13 = (uint *)(*pcVar7)();
  *(char *)((int)puVar18 + (int)puVar13) =
       *(char *)((int)puVar18 + (int)puVar13) + (char)unaff_SI + cVar15;
  pcVar7 = (code *)swi(0x3f);
  bVar8 = (*pcVar7)();
  *puVar18 = *puVar18 & extraout_DX;
  cVar17 = cVar17 + cVar16;
  bVar19 = 9 < (bVar8 & 0xf) | bVar19;
  pcVar7 = (code *)swi(0x3f);
  (*pcVar7)();
  pcVar7 = (code *)swi(0x3f);
  uVar9 = (*pcVar7)();
  *puVar13 = *puVar13 ^ (uint)puVar21;
  bVar19 = 9 < ((byte)uVar9 & 0xf) | bVar19;
  bVar8 = (byte)uVar9 + bVar19 * -6;
  if ((POPCOUNT(cVar17 + cVar16) & 1U) == 0) {
    bVar5 = 9 < (bVar8 & 0xf) | bVar19;
    bVar8 = (bVar8 & 0xf) + bVar5 * -6 & 0xf;
    *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
    *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
    bVar6 = 9 < bVar8 | bVar5;
    bVar8 = bVar8 + bVar6 * -6 & 0xf;
    *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
    bVar8 = bVar8 + *(char *)((int)puVar18 + (int)puVar13);
    bVar4 = 9 < (bVar8 & 0xf) | bVar6;
    bVar8 = bVar8 + bVar4 * '\x06';
    bVar19 = (byte)((uint)puVar18 >> 8) ^
             ((((char)((uint)uVar9 >> 8) - bVar19) - bVar5) - bVar6) + bVar4;
    puVar18 = (uint *)CONCAT11(bVar19,(char)puVar18);
    *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar19;
  }
  bVar8 = bVar8 & 0xf;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  *(char *)((int)puVar18 + (int)puVar13) = *(char *)((int)puVar18 + (int)puVar13) + bVar8;
  pcVar7 = (code *)swi(0x3f);
  (*pcVar7)();
  *(char *)puVar18 = (char)*puVar18;
  pcVar7 = (code *)swi(0x3f);
  (*pcVar7)();
  *puVar13 = *puVar13;
  pcVar7 = (code *)swi(0x3f);
  (*pcVar7)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


