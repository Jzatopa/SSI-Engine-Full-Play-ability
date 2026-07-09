
/* WARNING: Instruction at (ram,0x0001060f) overlaps instruction at (ram,0x0001060e)
    */

void FUN_1056_0020(void)

{
  uint *puVar1;
  uint uVar2;
  undefined2 uVar3;
  bool bVar4;
  code *pcVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  char cVar10;
  int in_CX;
  char cVar11;
  char extraout_DL;
  char *in_BX;
  int unaff_BP;
  char *pcVar12;
  undefined2 *unaff_SI;
  int *piVar13;
  char *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  byte in_AF;
  longdouble in_ST0;
  
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  cVar10 = (char)(in_CX + -1);
  cVar11 = (char)((uint)(in_CX + -1) >> 8) + cVar10;
  in_AF = 9 < ((byte)*unaff_SI & 0xf) | in_AF;
  pcVar5 = (code *)swi(0x3f);
  (*pcVar5)();
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  in_BX[(int)(unaff_SI + 1)] = in_BX[(int)(unaff_SI + 1)] + bVar6;
  cVar11 = cVar11 + cVar10 * '\x02';
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  in_AF = 9 < bVar6 | in_AF;
  *(uint *)(in_BX + (int)(unaff_SI + 1)) =
       *(uint *)(in_BX + (int)(unaff_SI + 1)) & CONCAT11(cVar11,cVar10);
  cVar11 = cVar11 + cVar10;
  in_AF = 9 < (bVar6 + in_AF * -6 & 0xf) | in_AF;
  pcVar5 = (code *)swi(0x3f);
  bVar6 = (*pcVar5)();
  cVar10 = cVar10 + unaff_DI[unaff_BP];
  cVar11 = cVar11 + cVar10 * '\x05';
  in_AF = 9 < (bVar6 & 0xf) | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  *(sqword *)(unaff_DI + unaff_BP) = (sqword)in_ST0;
  in_AF = 9 < bVar6 | in_AF;
  bVar6 = bVar6 + in_AF * -6 & 0xf;
  pcVar12 = (char *)TaskRegister();
  bVar4 = (bool)(9 < bVar6 | in_AF);
  bVar7 = bVar6 + bVar4 * -6 & 0xf;
  bVar6 = 0;
  if (bVar4) {
    *unaff_DI = *unaff_DI + cVar11;
    cVar11 = cVar11 + cVar10;
    pcVar12 = *(char **)unaff_DI;
    bVar7 = ((((bVar7 - 6 & 0xf) - 0x35 & 0xf ^ 0x3c) - 6 & 0xf) - 6 & 0xf) - 6 & 0xf;
    if (SCARRY1(cVar11,cVar10) == (char)(cVar11 + cVar10) < '\0') {
      bVar6 = 1;
      bVar7 = bVar7 - 6 & 0xf;
    }
    else {
      bVar6 = 1;
      bVar7 = (bVar7 - 6 & 0xf) - 6 & 0xf;
    }
  }
  piVar13 = unaff_SI + 2;
  bVar6 = 9 < bVar7 | bVar6;
  cVar10 = cVar10 - (char)*(undefined2 *)(in_BX + (int)piVar13);
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  uVar3 = *(undefined2 *)0x26;
  bVar8 = (byte)uVar3;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar8;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar8;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar8;
  bVar6 = 9 < (bVar8 & 0xf) | 9 < (bVar7 & 0xf) | bVar6;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + (bVar8 + bVar6 * -6 & 0xf);
  uVar9 = CONCAT11((char)((uint)uVar3 >> 8) - bVar6,0x65);
  puVar1 = (uint *)(in_BX + (int)piVar13);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar9;
  *in_BX = *in_BX + extraout_DL + CARRY2(uVar2,uVar9);
  *piVar13 = *piVar13 + uVar9 + 1;
  *pcVar12 = *pcVar12 + extraout_DL;
  cVar11 = (char)(uVar9 + 1);
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + cVar11;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  bVar6 = 9 < (bVar7 & 0xf) | bVar6;
  bVar6 = 9 < ((bVar7 + bVar6 * -6 & 0xf) + bVar6 & 0xf) | bVar6;
  pcVar5 = (code *)swi(0x3f);
  bVar7 = (*pcVar5)();
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar7;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar7;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar7;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar7;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar7;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + bVar7;
  in_BX[(int)piVar13] = in_BX[(int)piVar13] + (bVar7 + (9 < (bVar7 & 0xf) | bVar6) * -6 & 0xf);
  pcVar12[1] = pcVar12[1] + (char)((uint)in_BX >> 8);
  *(char *)((int)unaff_SI + 0x3f) = *(char *)((int)unaff_SI + 0x3f) + cVar10;
  return;
}


