/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1086:0020
 * Ghidra name: FUN_1086_0020
 * Linear address: 0x10880
 * Body addresses: 128
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x000109eb) overlaps instruction at (ram,0x000109e9)
    */

void __cdecl16near FUN_1086_0020(void)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  char *pcVar4;
  code *pcVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  undefined2 uVar14;
  int iVar15;
  uint uVar16;
  byte in_CL;
  uint uVar17;
  char *in_BX;
  int *piVar18;
  int unaff_BP;
  long *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar19;
  byte bVar20;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar21;
  undefined2 in_stack_00000016;
  
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  uVar21 = *(undefined4 *)unaff_DI;
  uVar19 = (undefined2)((ulong)uVar21 >> 0x10);
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  *(byte *)0xcd00 = *(byte *)0xcd00 & in_CL;
  in_AF = 9 < bVar6 | in_AF;
  bVar7 = bVar6 + in_AF * -6 & 0xf;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar7;
  in_AF = 9 < bVar7 | in_AF;
  LOCK();
  bVar6 = in_BX[(int)unaff_SI];
  in_BX[(int)unaff_SI] = bVar7 + in_AF * -6 & 0xf;
  UNLOCK();
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  LOCK();
  piVar1 = (int *)((int)unaff_DI + unaff_BP + 2);
  pcVar4 = (char *)*piVar1;
  *piVar1 = unaff_BP;
  UNLOCK();
  bVar6 = bVar6 + 4;
  pcVar4[(int)unaff_DI] = pcVar4[(int)unaff_DI] + bVar6;
  *pcVar4 = *pcVar4 + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar6;
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  in((int)uVar21);
  pcVar5 = (code *)swi(0x3f);
  uVar14 = (*pcVar5)();
  in_AF = 9 < ((byte)uVar14 & 0xf) | in_AF;
  bVar7 = (byte)uVar14 + in_AF * -6 & 0xf;
  bVar6 = 9 < bVar7 | in_AF;
  bVar7 = bVar7 + bVar6 * -6 & 0xf;
  pcVar2 = in_BX + (int)unaff_SI;
  cVar8 = *pcVar2;
  *pcVar2 = *pcVar2 + bVar7;
  if (SCARRY1(cVar8,bVar7) == *pcVar2 < '\0') {
    cVar8 = bVar7 + in_BX[(int)unaff_SI];
    *unaff_DI = *unaff_DI ^ CONCAT11(((char)((uint)uVar14 >> 8) - in_AF) - bVar6,cVar8);
    *in_BX = *in_BX + cVar8;
    pcVar4[(int)unaff_SI] = pcVar4[(int)unaff_SI] + '\x03';
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
    pcVar5 = (code *)swi(0x3f);
    (*pcVar5)();
    return;
  }
  bVar6 = 9 < bVar7 | bVar6;
  bVar7 = bVar7 + bVar6 * -6 & 0xf;
  *unaff_SI = (long)in_ST0;
  bVar6 = 9 < bVar7 | bVar6;
  bVar7 = bVar7 + bVar6 * -6 & 0xf;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar7;
  uVar17 = 3;
  bVar6 = 9 < bVar7 | bVar6;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + (bVar7 + bVar6 * -6 & 0xf);
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  bVar20 = 0;
  pcVar5 = (code *)swi(0x3f);
  uVar14 = (*pcVar5)();
  bVar7 = (byte)uVar14;
  bVar6 = 9 < (bVar7 & 0xf) | bVar6;
  iVar15 = CONCAT11((char)((uint)uVar14 >> 8),bVar7 + bVar6 * '\x06' + (0x99 < bVar7 | bVar20) * '`'
                   ) + -0x3300;
  bVar7 = (byte)iVar15;
  bVar6 = 9 < (bVar7 & 0xf) | bVar6;
  uVar16 = CONCAT11((char)((uint)iVar15 >> 8) - bVar6,bVar7 + bVar6 * -6) & 0xff0f;
  bVar7 = 9 < ((byte)*(undefined2 *)0xcd00 & 0xf) | 9 < ((byte)pcVar4 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  puVar3 = (uint *)(in_BX + (int)(unaff_DI + 1));
  iVar15 = (uVar17 & 3) - (*puVar3 & 3);
  *puVar3 = *puVar3 + (uint)(0 < iVar15) * iVar15;
  bVar7 = 9 < (bVar6 & 0xf) | bVar7;
  bVar6 = bVar6 + bVar7 * -6 & 0xf;
  pcVar2 = (char *)(uVar16 + (int)(unaff_DI + 1));
  *pcVar2 = *pcVar2 - (char)uVar17;
  bVar7 = 9 < bVar6 | bVar7;
  bVar20 = bVar6 + bVar7 * -6 & 0xf;
  bVar6 = 9 < bVar20 | bVar7;
  cVar8 = bVar20 + bVar6 * -6 + (0x99 < bVar20 | bVar7) * -0x60 + in_BX[(int)unaff_SI];
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + cVar8;
  pcVar5 = (code *)swi(0x3f);
  uVar21 = (*pcVar5)();
  bVar7 = (byte)uVar21;
  in_BX[(int)unaff_SI] = in_BX[(int)unaff_SI] + bVar7;
  cVar8 = (char)((ulong)uVar21 >> 8);
  piVar18 = (int *)CONCAT11((char)((uint)in_BX >> 8) + cVar8,(char)in_BX);
  bVar6 = 9 < (bVar7 & 0xf) | bVar6;
  bVar20 = bVar7 + bVar6 * '\x06' & 0xf;
  bVar7 = 9 < bVar20 | bVar6;
  bVar20 = bVar20 + bVar7 * -6 +
           (0x99 < bVar20 || bVar20 < *(byte *)(uVar16 + (int)unaff_SI)) * -0x60;
  *(char *)(uVar16 + (int)unaff_SI) =
       *(char *)(uVar16 + (int)unaff_SI) + (char)((ulong)uVar21 >> 0x10);
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  *(char *)((int)piVar18 + (int)unaff_SI) = *(char *)((int)piVar18 + (int)unaff_SI) + bVar20;
  bVar7 = 9 < (bVar20 & 0xf) | bVar7;
  bVar9 = bVar20 + bVar7 * -6 & 0xf;
  bVar20 = 9 < bVar9 | bVar7;
  bVar10 = bVar9 + bVar20 * -6 & 0xf;
  LOCK();
  *(undefined1 *)((int)piVar18 + (int)unaff_SI) = (char)((ulong)uVar21 >> 0x18);
  UNLOCK();
  bVar9 = 9 < bVar10 | bVar20;
  bVar11 = bVar10 + bVar9 * -6 & 0xf;
  bVar10 = 9 < bVar11 | bVar9;
  bVar12 = bVar11 + bVar10 * -6 & 0xf;
  bVar11 = 9 < bVar12 | bVar10;
  *(int *)((int)piVar18 + (int)unaff_SI) =
       *(int *)((int)piVar18 + (int)unaff_SI) +
       CONCAT11(((((cVar8 + bVar6) - bVar7) - bVar20) - bVar9) - bVar10,
                bVar12 + bVar11 * '\x06' + (0x99 < bVar12 | bVar10) * '`');
  pcVar5 = (code *)swi(0x3f);
  uVar14 = (*pcVar5)();
  bVar11 = 9 < ((byte)uVar14 & 0xf) | bVar11;
  bVar7 = (byte)uVar14 + bVar11 * -6 & 0xf;
  bVar6 = 9 < bVar7 | bVar11;
  bVar20 = bVar7 + bVar6 * -6 & 0xf;
  bVar7 = 9 < bVar20 | bVar6;
  bVar9 = bVar20 + bVar7 * -6 & 0xf;
  bVar20 = 9 < bVar9 | bVar7;
  bVar10 = bVar9 + bVar20 * -6 & 0xf;
  bVar9 = 9 < bVar10 | bVar20;
  bVar12 = bVar10 + bVar9 * -6 & 0xf;
  *piVar18 = -0x3300;
  bVar10 = 9 < bVar12 | bVar9;
  bVar12 = bVar12 + bVar10 * -6;
  bVar13 = bVar12 & 0xf;
  cVar8 = ((((((char)((uint)uVar14 >> 8) - bVar11) - bVar6) - bVar7) - bVar20) - bVar9) - bVar10;
  *piVar18 = (*piVar18 - (CONCAT11(cVar8,bVar12) & 0xff0f)) - (uint)bVar10;
  bVar10 = 9 < bVar13 | bVar10;
  bVar7 = bVar13 + bVar10 * -6 & 0xf;
  bVar6 = 9 < bVar7 | bVar10;
  puVar3 = (uint *)((int)piVar18 + (int)unaff_SI + 1);
  *puVar3 = *puVar3 | CONCAT11((cVar8 - bVar10) - bVar6,bVar7 + bVar6 * -6) & 0xff0f;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  return;
}


