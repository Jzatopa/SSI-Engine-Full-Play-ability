/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1075:0020
 * Ghidra name: FUN_1075_0020
 * Linear address: 0x10770
 * Body addresses: 48
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void FUN_1075_0020(void)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  byte bVar5;
  char cVar6;
  undefined2 uVar7;
  uint *puVar8;
  undefined2 in_CX;
  int iVar9;
  char cVar10;
  char extraout_DH;
  uint extraout_DX;
  uint *in_BX;
  byte bVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int *unaff_SI;
  int unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  char in_CF;
  char cVar14;
  byte in_AF;
  undefined4 uVar15;
  
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  *(char *)((int)in_BX + unaff_DI) = (*(char *)((int)in_BX + unaff_DI) - bVar5) - in_CF;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = bVar5 + in_AF * -6 & 0xf;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + bVar5;
  iVar9 = CONCAT11((char)((uint)in_CX >> 8) + (char)in_CX * '\x02',(char)in_CX);
  in_AF = 9 < bVar5 | in_AF;
  *(char *)((int)in_BX + (int)unaff_SI) =
       *(char *)((int)in_BX + (int)unaff_SI) + (bVar5 + in_AF * -6 & 0xf);
  pcVar4 = (code *)swi(0x3f);
  uVar7 = (*pcVar4)();
  cVar6 = (char)uVar7;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + 0x7e1b) = *(char *)((int)in_BX + 0x7e1b) + (char)((uint)uVar7 >> 8);
  iVar9 = iVar9 + *unaff_SI;
  *(char *)0x1f1 = *(char *)0x1f1 + extraout_DH;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  *(char *)((int)in_BX + (int)unaff_SI) = *(char *)((int)in_BX + (int)unaff_SI) + cVar6;
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  bVar5 = bVar5 < *(byte *)((int)in_BX + (int)unaff_SI);
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  puVar12 = (undefined1 *)0x3;
  pcVar4 = (code *)swi(0x3f);
  uVar15 = (*pcVar4)();
  *in_BX = (*in_BX - (int)uVar15) - (uint)bVar5;
  cVar6 = (char)iVar9;
  cVar10 = (char)((uint)iVar9 >> 8) + cVar6 * '\x02';
  in_AF = 9 < ((byte)uVar15 & 0xf) | in_AF;
  bVar5 = (byte)uVar15 + in_AF * -6 & 0xf;
  uVar1 = in((int)((ulong)uVar15 >> 0x10));
  *(undefined1 *)0x1f1 = uVar1;
  puVar13 = puVar12 + 2;
  in_AF = 9 < bVar5 | in_AF;
  cVar14 = '\0';
  *(byte *)((int)in_BX + (int)unaff_SI) =
       *(byte *)((int)in_BX + (int)unaff_SI) | bVar5 + in_AF * -6 & 0xf;
  pcVar4 = (code *)swi(0x3f);
  puVar8 = (uint *)(*pcVar4)();
  *(char *)((int)in_BX + (int)puVar8) =
       *(char *)((int)in_BX + (int)puVar8) + (char)unaff_SI + cVar14;
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  *in_BX = *in_BX & extraout_DX;
  cVar10 = cVar10 + cVar6;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x3f);
  uVar7 = (*pcVar4)();
  *puVar8 = *puVar8 ^ (uint)puVar13;
  in_AF = 9 < ((byte)uVar7 & 0xf) | in_AF;
  bVar5 = (byte)uVar7 + in_AF * -6;
  if ((POPCOUNT(cVar10 + cVar6) & 1U) == 0) {
    bVar2 = 9 < (bVar5 & 0xf) | in_AF;
    bVar5 = (bVar5 & 0xf) + bVar2 * -6 & 0xf;
    *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
    *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
    bVar3 = 9 < bVar5 | bVar2;
    bVar5 = bVar5 + bVar3 * -6 & 0xf;
    *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
    bVar5 = bVar5 + *(char *)((int)in_BX + (int)puVar8);
    bVar11 = 9 < (bVar5 & 0xf) | bVar3;
    bVar5 = bVar5 + bVar11 * '\x06';
    bVar11 = (byte)((uint)in_BX >> 8) ^
             ((((char)((uint)uVar7 >> 8) - in_AF) - bVar2) - bVar3) + bVar11;
    in_BX = (uint *)CONCAT11(bVar11,(char)in_BX);
    *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar11;
  }
  bVar5 = bVar5 & 0xf;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  *(char *)((int)in_BX + (int)puVar8) = *(char *)((int)in_BX + (int)puVar8) + bVar5;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  *(char *)in_BX = (char)*in_BX;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  *puVar8 = *puVar8;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


