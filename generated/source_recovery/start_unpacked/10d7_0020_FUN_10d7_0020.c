/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10d7:0020
 * Ghidra name: FUN_10d7_0020
 * Linear address: 0x10D90
 * Body addresses: 498
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Unable to track spacebase fully for stack */

void __stdcall16far FUN_10d7_0020(void)

{
  uint *puVar1;
  int *piVar2;
  undefined2 uVar3;
  code *pcVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  int *piVar9;
  uint uVar10;
  undefined2 uVar11;
  undefined2 extraout_var;
  byte in_CL;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  uint in_BX;
  char *pcVar12;
  undefined2 *puVar13;
  int *piVar14;
  undefined1 *puVar15;
  int *piVar16;
  int iVar17;
  byte *unaff_SI;
  byte *pbVar18;
  int unaff_DI;
  int iVar19;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  byte in_AF;
  longdouble in_ST0;
  undefined4 uVar20;
  ulong uVar21;
  undefined2 in_stack_00000014;
  undefined2 *in_stack_00000022;
  undefined4 in_stack_0000004c;
  
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  iVar19 = unaff_DI + 1;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  in(extraout_DX);
  pcVar4 = (code *)swi(0x3f);
  bVar5 = (*pcVar4)();
  puVar1 = (uint *)(unaff_SI + in_BX);
  *puVar1 = *puVar1 >> 1 | (uint)((*puVar1 & 1) != 0) << 0xf;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = bVar5 + in_AF * -6 & 0xf;
  unaff_SI[in_BX] = unaff_SI[in_BX] + bVar5;
  pcVar12 = (char *)(in_BX & *(uint *)(unaff_SI + in_BX));
  bVar5 = bVar5 + (char)*(undefined2 *)(pcVar12 + (int)unaff_SI);
  *(float *)(pcVar12 + iVar19) = (float)in_ST0;
  bVar6 = bVar5 - pcVar12[(int)unaff_SI];
  pcVar12[(int)unaff_SI] = (pcVar12[(int)unaff_SI] - bVar6) - (bVar5 < (byte)pcVar12[(int)unaff_SI])
  ;
  bVar5 = *(byte *)ZEXT24(pcVar12 + bVar6);
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  pcVar12[(int)unaff_SI] = pcVar12[(int)unaff_SI] + bVar5;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar5 = (bVar5 + in_AF * -6 & 0xf) % 0x19;
  in_AF = 9 < (bVar5 & 0xf) | in_AF;
  bVar6 = bVar5 + in_AF * -6 & 0xf;
  uVar3 = *(undefined2 *)(pcVar12 + iVar19);
  bVar5 = 9 < bVar6 | in_AF;
  piVar9 = (int *)(CONCAT11(-bVar5 - in_AF,bVar6 + bVar5 * -6) & 0xff0f);
  bVar5 = 9 < ((byte)iVar19 & 0xf) | bVar5;
  bVar6 = (byte)iVar19 + bVar5 * -6 & 0xf;
  *unaff_SI = ~*unaff_SI;
  bVar5 = 9 < bVar6 | bVar5;
  bVar6 = bVar6 + bVar5 * -6 & 0xf;
  pbVar18 = unaff_SI + -1;
  bVar5 = 9 < bVar6 | bVar5;
  bVar6 = bVar6 + bVar5 * -6 & 0xf;
  pcVar12[(int)pbVar18] = pcVar12[(int)pbVar18] + bVar6;
  bVar5 = 9 < bVar6 | bVar5;
  bVar5 = 9 < (bVar6 + bVar5 * -6 & 0xf) | bVar5;
  pcVar4 = (code *)swi(0x3f);
  bVar6 = (*pcVar4)();
  bVar5 = 9 < bVar6 % 4 | bVar5;
  bVar5 = 9 < (bVar6 % 4 + bVar5 * -6 & 0xf) | bVar5;
  pcVar4 = (code *)swi(0x3f);
  cVar7 = (*pcVar4)();
  bVar5 = 9 < (cVar7 - *pcVar12 & 0xfU) | bVar5;
  pcVar12[(int)pbVar18] = pcVar12[(int)pbVar18];
  pcVar4 = (code *)swi(0x3f);
  bVar6 = (*pcVar4)();
  iVar19 = CONCAT11((char)((uint)pcVar12 >> 8),8);
  bVar5 = 9 < (bVar6 & 0xf) | bVar5;
  pcVar4 = (code *)swi(0x3f);
  (*pcVar4)();
  pcVar4 = (code *)swi(0x3f);
  uVar20 = (*pcVar4)();
  uVar11 = (undefined2)((ulong)uVar20 >> 0x10);
  uVar10 = (uint)uVar20 | 0xcd00;
  bVar5 = 9 < ((byte)uVar20 & 0xf) | bVar5;
  bVar6 = (byte)uVar20 + bVar5 * -6 & 0xf;
  cVar7 = (char)(uVar10 >> 8) - bVar5;
  if (-1 < (int)uVar10) {
    bVar5 = 9 < bVar6 | bVar5;
    pcVar4 = (code *)swi(0x3f);
    uVar20 = (*pcVar4)();
    uVar11 = (undefined2)((ulong)uVar20 >> 0x10);
    puVar13 = (undefined2 *)((int)&stack0x004c + 1);
    in_stack_0000004c._1_2_ = in_stack_00000022;
    cVar7 = '\f';
    do {
      in_stack_00000022 = in_stack_00000022 + -1;
      puVar13 = puVar13 + -1;
      *puVar13 = *in_stack_00000022;
      cVar7 = cVar7 + -1;
    } while ('\0' < cVar7);
    bVar5 = 9 < ((byte)uVar20 & 0xf) | bVar5;
    bVar6 = (byte)uVar20 + bVar5 * -6 & 0xf;
    cVar7 = (char)((ulong)uVar20 >> 8) - bVar5;
  }
  bVar5 = 9 < bVar6 | bVar5;
  uVar10 = CONCAT11(cVar7 - bVar5,bVar6 + bVar5 * -6) & 0xff0f;
  piVar16 = (int *)TaskRegister();
  bVar5 = 9 < ((byte)pbVar18 & 0xf) | bVar5;
  bVar6 = (byte)pbVar18 + bVar5 * -6;
  bVar8 = bVar6 & 0xf;
  uVar21 = CONCAT22(uVar11,CONCAT11((char)((uint)pbVar18 >> 8) - bVar5,bVar6)) & 0xffffff0f;
  if (!(bool)bVar5 && (in_CL & *(byte *)0xcd00) != 0) {
    bVar5 = 9 < bVar8 | bVar5;
    piVar2 = piVar9;
    piVar9 = (int *)((int)piVar9 + 1);
    cVar7 = in(uVar11);
    *(char *)piVar2 = cVar7;
    cVar7 = (bVar8 + bVar5 * -6 & 0xf) + bVar5;
    *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
    *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
    *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
    *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
    pcVar4 = (code *)swi(0x3f);
    uVar21 = (*pcVar4)();
    *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + (char)uVar21;
  }
  bVar6 = (byte)uVar21 ^ *(byte *)((int)piVar16 + (int)piVar9);
  *(char *)0x5605 = *(char *)0x5605 + (char)iVar19;
  *(byte *)piVar9 = (char)*piVar9 + bVar6;
  iVar19 = CONCAT11((char)((uint)iVar19 >> 8),(char)iVar19 * '\x02');
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  bVar5 = 9 < (bVar6 & 0xf) | bVar5;
  bVar6 = bVar6 + bVar5 * -6;
  bVar8 = bVar6 & 0xf;
  *piVar9 = (*piVar9 - (CONCAT11((char)(uVar21 >> 8) - bVar5,bVar6) & 0xff0f)) - (uint)bVar5;
  bVar5 = 9 < bVar8 | bVar5;
  bVar5 = 9 < (bVar8 + bVar5 * -6 & 0xf & *(byte *)(iVar19 + uVar10)) | bVar5;
  uVar11 = in((int)(uVar21 >> 0x10));
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + (char)uVar11;
  pcVar4 = (code *)swi(0x3f);
  uVar11 = (*pcVar4)();
  *(long *)(iVar19 + uVar10) = *(long *)(iVar19 + uVar10) + CONCAT22(extraout_var,uVar11);
  pcVar4 = (code *)swi(0x3f);
  cVar7 = (*pcVar4)();
  iVar17 = *piVar16;
  bVar6 = cVar7 + (char)*(undefined2 *)(iVar19 + uVar10);
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  bVar5 = 9 < (bVar6 & 0xf) | bVar5;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + (bVar6 + bVar5 * -6 & 0xf);
  *piVar16 = 0x10d7;
  uVar11 = 0x200;
  piVar14 = piVar16 + -1;
  piVar16[-1] = 0xe99;
  bVar6 = func_0x00002337();
  *(int *)(iVar17 + uVar10) = *(int *)(iVar17 + uVar10) + iVar19;
  *(char *)(iVar17 + uVar10) = *(char *)(iVar17 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + bVar6;
  *(char *)(iVar19 + uVar10) =
       *(char *)(iVar19 + uVar10) + (bVar6 + (9 < (bVar6 & 0xf) | bVar5) * -6 & 0xf);
  pcVar4 = (code *)swi(0x3f);
  cVar7 = (*pcVar4)();
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
  *(char *)(iVar19 + uVar10) = *(char *)(iVar19 + uVar10) + cVar7;
  *(char *)((int)piVar9 + -0x77) = *(char *)((int)piVar9 + -0x77) + (char)extraout_DX_00;
  in(0x83);
  in(extraout_DX_00);
  *(undefined2 *)((int)piVar14 + -2) = unaff_ES;
  puVar15 = (undefined1 *)((int)piVar14 + -4);
  *(undefined2 *)((int)piVar14 + -4) = in_stack_00000014;
  *(undefined1 *)(iVar17 + -7) = 0;
  do {
    if (*(char *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7)) == -2) {
      *(undefined1 *)0x7816 = 1;
    }
    else {
      *(undefined1 *)(iVar17 + -1) =
           *(undefined1 *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7));
      *(char *)(iVar17 + -7) = *(char *)(iVar17 + -7) + '\x01';
      *(undefined1 *)(iVar17 + -2) =
           *(undefined1 *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7));
      *(char *)(iVar17 + -7) = *(char *)(iVar17 + -7) + '\x01';
      *(undefined1 *)(iVar17 + -3) =
           *(undefined1 *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7));
      *(char *)(iVar17 + -7) = *(char *)(iVar17 + -7) + '\x01';
      *(undefined1 *)(iVar17 + -4) =
           *(undefined1 *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7));
      *(char *)(iVar17 + -7) = *(char *)(iVar17 + -7) + '\x01';
      *(undefined1 *)(iVar17 + -5) =
           *(undefined1 *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7));
      *(char *)(iVar17 + -7) = *(char *)(iVar17 + -7) + '\x01';
      *(undefined1 *)(iVar17 + -6) =
           *(undefined1 *)((int)*(undefined4 *)(iVar17 + 6) + (uint)*(byte *)(iVar17 + -7));
      *(char *)(iVar17 + -7) = *(char *)(iVar17 + -7) + '\x01';
      *(uint *)(puVar15 + -2) = (uint)*(byte *)(iVar17 + -1);
      *(uint *)(puVar15 + -4) = (uint)*(byte *)(iVar17 + -2);
      *(uint *)(puVar15 + -6) = (uint)*(byte *)(iVar17 + -3);
      *(uint *)(puVar15 + -8) = (uint)*(byte *)(iVar17 + -4);
      *(uint *)(puVar15 + -10) = (uint)*(byte *)(iVar17 + -5);
      *(uint *)(puVar15 + -0xc) = (uint)*(byte *)(iVar17 + -6);
      *(undefined2 *)(puVar15 + -0xe) = uVar11;
      uVar11 = 0x1139;
      *(undefined2 *)(puVar15 + -0x10) = 0xf76;
      FUN_1139_002f();
      puVar15 = puVar15 + -8;
    }
  } while (*(char *)0x7816 == '\0');
  return;
}


