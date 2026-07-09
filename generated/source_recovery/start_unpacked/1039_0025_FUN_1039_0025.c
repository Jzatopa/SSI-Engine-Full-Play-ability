/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1039:0025
 * Ghidra name: FUN_1039_0025
 * Linear address: 0x103B5
 * Body addresses: 163
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void FUN_1039_0025(void)

{
  char *pcVar1;
  byte *pbVar2;
  char *pcVar3;
  byte bVar4;
  byte bVar5;
  code *pcVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  byte bVar10;
  undefined2 uVar11;
  uint uVar12;
  int iVar13;
  int in_BX;
  char cVar15;
  char *pcVar14;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  undefined2 in_stack_0000000c;
  
  pcVar6 = (code *)swi(0x3f);
  uVar11 = (*pcVar6)();
  bVar7 = (byte)uVar11;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar7;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar7;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar7;
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  bVar7 = bVar7 + in_AF * -6 & 0xf;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + bVar7;
  *(byte *)(unaff_BP + unaff_DI) = bVar7;
  bVar7 = bVar7 - 0x23;
  pcVar3 = (char *)(unaff_SI + 1);
  *(int *)(pcVar3 + unaff_BP) =
       *(int *)(pcVar3 + unaff_BP) + CONCAT11((char)((uint)uVar11 >> 8) - in_AF,bVar7);
  pcVar1 = (char *)(in_BX + unaff_DI + 1);
  *pcVar1 = *pcVar1 + (char)((uint)in_BX >> 8);
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  in_AF = 9 < (bVar7 + in_AF * -6 & 0xf) | in_AF;
  pcVar6 = (code *)swi(0x3f);
  uVar12 = (*pcVar6)();
  *(uint *)(pcVar3 + in_BX) = *(uint *)(pcVar3 + in_BX) & uVar12;
  cVar8 = (char)uVar12;
  pcVar3[in_BX] = pcVar3[in_BX] + cVar8;
  pcVar3[in_BX] = pcVar3[in_BX] + cVar8;
  pcVar3[in_BX] = pcVar3[in_BX] + cVar8;
  pcVar6 = (code *)swi(0x3f);
  iVar13 = (*pcVar6)();
  bVar7 = (byte)iVar13;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  cVar15 = (char)((uint)in_BX >> 8);
  pcVar3[in_BX + 0x1413] = pcVar3[in_BX + 0x1413] + cVar15;
  *(int *)(pcVar3 + unaff_BP + 1) = *(int *)(pcVar3 + unaff_BP + 1) + iVar13;
  *pcVar3 = *pcVar3 + cVar15;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  pcVar3[in_BX] = pcVar3[in_BX] + bVar7;
  in_AF = 9 < (bVar7 & 0xf) | in_AF;
  bVar7 = bVar7 + in_AF * -6 & 0xf;
  pcVar14 = (char *)CONCAT11(cVar15,0x13);
  bVar4 = 9 < bVar7 | in_AF;
  bVar7 = bVar7 + bVar4 * -6 & 0xf ^ pcVar14[unaff_DI + 1];
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar7;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar7;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar7;
  bVar5 = 9 < (bVar7 & 0xf) | bVar4;
  bVar9 = bVar7 + bVar5 * -6 & 0xf;
  pbVar2 = (byte *)(pcVar14 + (int)pcVar3);
  bVar7 = *pbVar2;
  *pbVar2 = *pbVar2 + bVar9;
  cVar8 = in(in_stack_0000000c);
  bVar9 = (cVar8 + '\n') - CARRY1(bVar7,bVar9);
  *pcVar3 = *pcVar3 + bVar9;
  *pcVar14 = *pcVar14 + cVar15;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar9;
  bVar7 = 9 < (bVar9 & 0xf) | bVar5;
  bVar9 = bVar9 + bVar7 * -6;
  bVar10 = bVar9 & 0xf;
  out(0x1c,CONCAT11(((((char)((uint)iVar13 >> 8) - in_AF) - bVar4) - bVar5) - bVar7,bVar9) & 0xff0f)
  ;
  bVar7 = bVar10 + (9 < bVar10 | bVar7) * -6 & 0xf;
  uVar11 = LocalDescriptorTableRegister();
  *(undefined2 *)(pcVar14 + (int)pcVar3) = uVar11;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar7;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar7;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + bVar7;
  pcVar6 = (code *)swi(0x3f);
  cVar8 = (*pcVar6)();
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + cVar8;
  pcVar14[(int)pcVar3] = pcVar14[(int)pcVar3] + cVar8;
  pcVar6 = (code *)swi(3);
  (*pcVar6)();
  return;
}


