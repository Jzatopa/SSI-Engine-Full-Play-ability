/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1092:0020
 * Ghidra name: FUN_1092_0020
 * Linear address: 0x10940
 * Body addresses: 180
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x000109eb) overlaps instruction at (ram,0x000109e9)
    */
/* WARNING: Unable to track spacebase fully for stack */

void __cdecl16near FUN_1092_0020(void)

{
  char *pcVar1;
  uint *puVar2;
  code *pcVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  undefined2 uVar12;
  int iVar13;
  uint uVar14;
  byte in_CL;
  uint uVar15;
  int in_BX;
  int *piVar16;
  undefined2 *puVar17;
  undefined2 *unaff_BP;
  undefined2 uVar18;
  long *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte bVar19;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar20;
  
  pcVar3 = (code *)swi(0x3f);
  bVar4 = (*pcVar3)();
  uVar18 = *unaff_BP;
  *unaff_BP = 0x1092;
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  bVar4 = bVar4 + in_AF * -6 & 0xf;
  *unaff_SI = (long)in_ST0;
  in_AF = 9 < bVar4 | in_AF;
  bVar4 = bVar4 + in_AF * -6 & 0xf;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar4;
  uVar15 = (uint)in_CL;
  in_AF = 9 < bVar4 | in_AF;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + (bVar4 + in_AF * -6 & 0xf);
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  bVar19 = 0;
  pcVar3 = (code *)swi(0x3f);
  uVar12 = (*pcVar3)();
  bVar4 = (byte)uVar12;
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  iVar13 = CONCAT11((char)((uint)uVar12 >> 8),bVar4 + in_AF * '\x06' + (0x99 < bVar4 | bVar19) * '`'
                   ) + -0x3300;
  bVar4 = (byte)iVar13;
  in_AF = 9 < (bVar4 & 0xf) | in_AF;
  uVar14 = CONCAT11((char)((uint)iVar13 >> 8) - in_AF,bVar4 + in_AF * -6) & 0xff0f;
  bVar19 = 9 < ((byte)*(undefined2 *)0xcd00 & 0xf) | 9 < ((byte)uVar18 & 0xf) | in_AF;
  pcVar3 = (code *)swi(0x3f);
  bVar4 = (*pcVar3)();
  puVar2 = (uint *)(in_BX + unaff_DI + 2);
  iVar13 = (uVar15 & 3) - (*puVar2 & 3);
  *puVar2 = *puVar2 + (uint)(0 < iVar13) * iVar13;
  bVar19 = 9 < (bVar4 & 0xf) | bVar19;
  bVar4 = bVar4 + bVar19 * -6 & 0xf;
  pcVar1 = (char *)(uVar14 + unaff_DI + 2);
  *pcVar1 = *pcVar1 - (char)uVar15;
  bVar19 = 9 < bVar4 | bVar19;
  bVar5 = bVar4 + bVar19 * -6 & 0xf;
  bVar4 = 9 < bVar5 | bVar19;
  cVar6 = bVar5 + bVar4 * -6 + (0x99 < bVar5 | bVar19) * -0x60 + *(char *)(in_BX + (int)unaff_SI);
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + cVar6;
  pcVar3 = (code *)swi(0x3f);
  uVar20 = (*pcVar3)();
  bVar19 = (byte)uVar20;
  *(char *)(in_BX + (int)unaff_SI) = *(char *)(in_BX + (int)unaff_SI) + bVar19;
  uVar18 = *unaff_BP;
  puVar17 = unaff_BP + 1;
  cVar6 = (char)((ulong)uVar20 >> 8);
  piVar16 = (int *)CONCAT11((char)((uint)in_BX >> 8) + cVar6,(char)in_BX);
  bVar4 = 9 < (bVar19 & 0xf) | bVar4;
  bVar5 = bVar19 + bVar4 * '\x06' & 0xf;
  bVar19 = 9 < bVar5 | bVar4;
  bVar5 = bVar5 + bVar19 * -6 + (0x99 < bVar5 || bVar5 < *(byte *)(uVar14 + (int)unaff_SI)) * -0x60;
  *(char *)(uVar14 + (int)unaff_SI) =
       *(char *)(uVar14 + (int)unaff_SI) + (char)((ulong)uVar20 >> 0x10);
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  *(char *)((int)piVar16 + (int)unaff_SI) = *(char *)((int)piVar16 + (int)unaff_SI) + bVar5;
  bVar19 = 9 < (bVar5 & 0xf) | bVar19;
  bVar7 = bVar5 + bVar19 * -6 & 0xf;
  bVar5 = 9 < bVar7 | bVar19;
  bVar8 = bVar7 + bVar5 * -6 & 0xf;
  LOCK();
  *(undefined1 *)((int)piVar16 + (int)unaff_SI) = (char)((ulong)uVar20 >> 0x18);
  UNLOCK();
  bVar7 = 9 < bVar8 | bVar5;
  bVar9 = bVar8 + bVar7 * -6 & 0xf;
  bVar8 = 9 < bVar9 | bVar7;
  bVar10 = bVar9 + bVar8 * -6 & 0xf;
  bVar9 = 9 < bVar10 | bVar8;
  *(int *)((int)piVar16 + (int)unaff_SI) =
       *(int *)((int)piVar16 + (int)unaff_SI) +
       CONCAT11(((((cVar6 + bVar4) - bVar19) - bVar5) - bVar7) - bVar8,
                bVar10 + bVar9 * '\x06' + (0x99 < bVar10 | bVar8) * '`');
  pcVar3 = (code *)swi(0x3f);
  uVar12 = (*pcVar3)();
  bVar9 = 9 < ((byte)uVar12 & 0xf) | bVar9;
  bVar19 = (byte)uVar12 + bVar9 * -6 & 0xf;
  bVar4 = 9 < bVar19 | bVar9;
  bVar5 = bVar19 + bVar4 * -6 & 0xf;
  *(undefined2 *)((int)puVar17 + -2) = unaff_ES;
  bVar19 = 9 < bVar5 | bVar4;
  bVar7 = bVar5 + bVar19 * -6 & 0xf;
  bVar5 = 9 < bVar7 | bVar19;
  bVar8 = bVar7 + bVar5 * -6 & 0xf;
  bVar7 = 9 < bVar8 | bVar5;
  bVar10 = bVar8 + bVar7 * -6 & 0xf;
  *piVar16 = -0x3300;
  bVar8 = 9 < bVar10 | bVar7;
  bVar10 = bVar10 + bVar8 * -6;
  bVar11 = bVar10 & 0xf;
  cVar6 = ((((((char)((uint)uVar12 >> 8) - bVar9) - bVar4) - bVar19) - bVar5) - bVar7) - bVar8;
  *piVar16 = (*piVar16 - (CONCAT11(cVar6,bVar10) & 0xff0f)) - (uint)bVar8;
  bVar8 = 9 < bVar11 | bVar8;
  bVar19 = bVar11 + bVar8 * -6 & 0xf;
  bVar4 = 9 < bVar19 | bVar8;
  puVar2 = (uint *)((int)piVar16 + (int)unaff_SI + 1);
  *puVar2 = *puVar2 | CONCAT11((cVar6 - bVar8) - bVar4,bVar19 + bVar4 * -6) & 0xff0f;
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  pcVar3 = (code *)swi(0x3f);
  (*pcVar3)();
  return;
}


