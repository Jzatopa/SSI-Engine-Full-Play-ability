/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1078:0020
 * Ghidra name: FUN_1078_0020
 * Linear address: 0x107A0
 * Body addresses: 96
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */

void FUN_1078_0020(void)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  byte bVar5;
  uint *puVar6;
  undefined2 uVar7;
  char in_CL;
  char in_CH;
  uint extraout_DX;
  uint *in_BX;
  byte bVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  char cVar11;
  byte in_AF;
  undefined4 uVar12;
  
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  bVar5 = bVar5 < *(byte *)((int)in_BX + unaff_SI);
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  puVar9 = (undefined1 *)0x3;
  pcVar4 = (code *)swi(0x3f);
  uVar12 = (*pcVar4)();
  *in_BX = (*in_BX - (int)uVar12) - (uint)bVar5;
  in_CH = in_CH + in_CL * '\x02';
  in_AF = 9 < ((byte)uVar12 & 0xf) | in_AF;
  bVar5 = (byte)uVar12 + in_AF * -6 & 0xf;
  uVar1 = in((int)((ulong)uVar12 >> 0x10));
  *unaff_DI = uVar1;
  puVar10 = puVar9 + 2;
  in_AF = 9 < bVar5 | in_AF;
  cVar11 = '\0';
  *(byte *)((int)in_BX + unaff_SI) = *(byte *)((int)in_BX + unaff_SI) | bVar5 + in_AF * -6 & 0xf;
  pcVar4 = (code *)swi(0x3f);
  puVar6 = (uint *)(*pcVar4)();
  *(char *)((int)in_BX + (int)puVar6) =
       *(char *)((int)in_BX + (int)puVar6) + (char)unaff_SI + cVar11;
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  *in_BX = *in_BX & extraout_DX;
  in_CH = in_CH + in_CL;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x3f);
  uVar7 = (*pcVar4)();
  *puVar6 = *puVar6 ^ (uint)puVar10;
  in_AF = 9 < ((byte)uVar7 & 0xf) | in_AF;
  bVar5 = (byte)uVar7 + in_AF * -6;
  if ((POPCOUNT(in_CH + in_CL) & 1U) == 0) {
    bVar2 = 9 < (bVar5 & 0xf) | in_AF;
    bVar5 = (bVar5 & 0xf) + bVar2 * -6 & 0xf;
    *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
    *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
    bVar3 = 9 < bVar5 | bVar2;
    bVar5 = bVar5 + bVar3 * -6 & 0xf;
    *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
    bVar5 = bVar5 + *(char *)((int)in_BX + (int)puVar6);
    bVar8 = 9 < (bVar5 & 0xf) | bVar3;
    bVar5 = bVar5 + bVar8 * '\x06';
    bVar8 = (byte)((uint)in_BX >> 8) ^
            ((((char)((uint)uVar7 >> 8) - in_AF) - bVar2) - bVar3) + bVar8;
    in_BX = (uint *)CONCAT11(bVar8,(char)in_BX);
    *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar8;
  }
  bVar5 = bVar5 & 0xf;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  *(char *)((int)in_BX + (int)puVar6) = *(char *)((int)in_BX + (int)puVar6) + bVar5;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  *(char *)in_BX = (char)*in_BX;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  *puVar6 = *puVar6;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


