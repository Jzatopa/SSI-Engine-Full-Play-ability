/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 102d:0020
 * Ghidra name: FUN_102d_0020
 * Linear address: 0x102F0
 * Body addresses: 190
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x00010389) overlaps instruction at (ram,0x00010387)
    */

void FUN_102d_0020(void)

{
  char *pcVar1;
  byte *pbVar2;
  char *pcVar3;
  byte bVar4;
  byte bVar5;
  ulong uVar6;
  code *pcVar7;
  byte bVar8;
  char cVar9;
  byte bVar10;
  byte bVar11;
  undefined2 uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  char cVar17;
  undefined2 in_CX;
  char cVar18;
  char extraout_DH;
  char extraout_DH_00;
  int in_BX;
  int *piVar19;
  char *pcVar20;
  int unaff_BP;
  uint unaff_SI;
  char *unaff_DI;
  uint uVar21;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  byte bVar22;
  undefined4 uVar23;
  undefined2 in_stack_0000001c;
  
  pcVar7 = (code *)swi(0x3f);
  bVar8 = (*pcVar7)();
  cVar17 = (char)in_CX;
  cVar18 = (char)((uint)in_CX >> 8) + cVar17;
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = bVar8 + in_AF * -6 & 0xf;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  pcVar7 = (code *)swi(0x3f);
  cVar9 = (*pcVar7)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar9;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar9;
  uVar12 = FUN_1cc0_0313();
  bVar8 = (byte)uVar12;
  *(char *)(unaff_BP + unaff_SI) = *(char *)(unaff_BP + unaff_SI) + bVar8;
  *unaff_DI = *unaff_DI + cVar18;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  iVar16 = CONCAT11(cVar18 + cVar17,cVar17);
  in_AF = 9 < (bVar8 & 0xf) | in_AF;
  bVar8 = bVar8 + in_AF * -6 & 0xf;
  if (iVar16 == 0) {
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    pcVar7 = (code *)swi(0x3f);
    uVar13 = (*pcVar7)();
    cVar9 = extraout_DH_00;
  }
  else {
    bVar22 = 9 < bVar8 | in_AF;
    uVar15 = CONCAT11(((char)((uint)uVar12 >> 8) - in_AF) - bVar22,bVar8 + bVar22 * -6) & 0xff0f;
    bVar8 = (byte)unaff_SI;
    *(char *)(in_BX + uVar15) = *(char *)(in_BX + uVar15) + bVar8;
    *(char *)(in_BX + uVar15) = *(char *)(in_BX + uVar15) + bVar8;
    *(char *)(in_BX + uVar15) = *(char *)(in_BX + uVar15) + bVar8;
    iVar16 = CONCAT11(cVar18 + cVar17 + cVar17 * '\x02',cVar17);
    in_AF = 9 < (bVar8 & 0xf) | bVar22;
    uVar13 = CONCAT11((char)(unaff_SI >> 8) - in_AF,bVar8 + in_AF * -6) & 0xff0f;
    unaff_SI = uVar15;
    cVar9 = extraout_DH;
  }
  bVar8 = (byte)uVar13;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  pcVar1 = (char *)(in_BX + unaff_SI);
  cVar17 = *pcVar1;
  *pcVar1 = *pcVar1 + bVar8;
  if (SCARRY1(cVar17,bVar8) == *pcVar1 < '\0') {
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    in_AF = 9 < (bVar8 & 0xf) | in_AF;
    bVar8 = bVar8 + in_AF * -6 & 0xf;
    cVar9 = (char)(uVar13 >> 8) - in_AF;
  }
  else {
    iVar14 = uVar13 + *(int *)(unaff_BP + unaff_SI);
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar9;
    bVar8 = (byte)iVar14;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    in_AF = 9 < (bVar8 & 0xf) | in_AF;
    bVar8 = bVar8 + in_AF * -6 & 0xf;
    cVar9 = (char)((uint)iVar14 >> 8) - in_AF;
    if ((char)((char)((uint)iVar16 >> 8) + (char)iVar16) < '\0') {
      *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
    }
  }
  in_AF = 9 < bVar8 | in_AF;
  uVar13 = CONCAT11(cVar9 - in_AF,bVar8 + in_AF * -6) & 0xff0f;
  bVar8 = (byte)unaff_BP ^ *(byte *)(in_BX + unaff_SI);
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar8;
  pcVar7 = (code *)swi(0x3f);
  cVar9 = (*pcVar7)();
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar9;
  piVar19 = (int *)(in_BX + 1);
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + cVar9;
  *(char *)(uVar13 + unaff_SI) = *(char *)(uVar13 + unaff_SI) - (char)((uint)piVar19 >> 8);
  bVar8 = cVar9 + *(char *)((int)piVar19 + unaff_SI) ^
          (byte)*(undefined2 *)((int)piVar19 + unaff_SI);
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  pcVar7 = (code *)swi(0x3f);
  uVar23 = (*pcVar7)();
  uVar21 = (uint)unaff_DI & *(uint *)(uVar13 + unaff_SI);
  in_AF = 9 < ((byte)uVar23 & 0xf) | in_AF;
  bVar8 = (byte)uVar23 + in_AF * -6 & 0xf;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  bVar22 = 9 < bVar8 | in_AF;
  bVar8 = bVar8 + bVar22 * -6;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + (bVar8 & 0xf);
  iVar16 = *piVar19;
  uVar6 = CONCAT22((int)((ulong)uVar23 >> 0x10),
                   CONCAT11(((char)((ulong)uVar23 >> 8) - in_AF) - bVar22,bVar8)) & 0xffffff0f;
  *(char *)(uVar21 + 3) = *(char *)(uVar21 + 3) + (char)((long)uVar6 % (long)iVar16);
  bVar8 = (char)((long)uVar6 / (long)iVar16) + *(char *)((int)piVar19 + unaff_SI);
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  bVar22 = 9 < (bVar8 & 0xf) | bVar22;
  pcVar7 = (code *)swi(0x3f);
  uVar12 = (*pcVar7)();
  bVar8 = (byte)uVar12;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  bVar22 = 9 < (bVar8 & 0xf) | bVar22;
  bVar8 = bVar8 + bVar22 * -6 & 0xf;
  *(char *)((int)piVar19 + unaff_SI) = *(char *)((int)piVar19 + unaff_SI) + bVar8;
  *(byte *)(uVar13 + uVar21) = bVar8;
  bVar8 = bVar8 - 0x23;
  pcVar3 = (char *)(unaff_SI + 1);
  *(int *)(pcVar3 + uVar13) =
       *(int *)(pcVar3 + uVar13) + CONCAT11((char)((uint)uVar12 >> 8) - bVar22,bVar8);
  pcVar1 = (char *)((int)piVar19 + uVar21 + 1);
  *pcVar1 = *pcVar1 + (char)((uint)piVar19 >> 8);
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  bVar22 = 9 < (bVar8 & 0xf) | bVar22;
  bVar22 = 9 < (bVar8 + bVar22 * -6 & 0xf) | bVar22;
  pcVar7 = (code *)swi(0x3f);
  uVar15 = (*pcVar7)();
  *(uint *)((int)piVar19 + (int)pcVar3) = *(uint *)((int)piVar19 + (int)pcVar3) & uVar15;
  cVar9 = (char)uVar15;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + cVar9;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + cVar9;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + cVar9;
  pcVar7 = (code *)swi(0x3f);
  iVar16 = (*pcVar7)();
  bVar8 = (byte)iVar16;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  cVar17 = (char)((uint)piVar19 >> 8);
  ((char *)((int)piVar19 + (int)pcVar3))[0x1413] =
       ((char *)((int)piVar19 + (int)pcVar3))[0x1413] + cVar17;
  *(int *)(pcVar3 + uVar13 + 1) = *(int *)(pcVar3 + uVar13 + 1) + iVar16;
  *pcVar3 = *pcVar3 + cVar17;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  *(char *)((int)piVar19 + (int)pcVar3) = *(char *)((int)piVar19 + (int)pcVar3) + bVar8;
  bVar22 = 9 < (bVar8 & 0xf) | bVar22;
  bVar8 = bVar8 + bVar22 * -6 & 0xf;
  pcVar20 = (char *)CONCAT11(cVar17,0x13);
  bVar4 = 9 < bVar8 | bVar22;
  bVar8 = bVar8 + bVar4 * -6 & 0xf ^ pcVar20[uVar21 + 1];
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar8;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar8;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar8;
  bVar5 = 9 < (bVar8 & 0xf) | bVar4;
  bVar10 = bVar8 + bVar5 * -6 & 0xf;
  pbVar2 = (byte *)(pcVar20 + (int)pcVar3);
  bVar8 = *pbVar2;
  *pbVar2 = *pbVar2 + bVar10;
  cVar9 = in(in_stack_0000001c);
  bVar10 = (cVar9 + '\n') - CARRY1(bVar8,bVar10);
  *pcVar3 = *pcVar3 + bVar10;
  *pcVar20 = *pcVar20 + cVar17;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar10;
  bVar8 = 9 < (bVar10 & 0xf) | bVar5;
  bVar10 = bVar10 + bVar8 * -6;
  bVar11 = bVar10 & 0xf;
  out(0x1c,CONCAT11(((((char)((uint)iVar16 >> 8) - bVar22) - bVar4) - bVar5) - bVar8,bVar10) &
           0xff0f);
  bVar8 = bVar11 + (9 < bVar11 | bVar8) * -6 & 0xf;
  uVar12 = LocalDescriptorTableRegister();
  *(undefined2 *)(pcVar20 + (int)pcVar3) = uVar12;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar8;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar8;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + bVar8;
  pcVar7 = (code *)swi(0x3f);
  cVar9 = (*pcVar7)();
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + cVar9;
  pcVar20[(int)pcVar3] = pcVar20[(int)pcVar3] + cVar9;
  pcVar7 = (code *)swi(3);
  (*pcVar7)();
  return;
}


