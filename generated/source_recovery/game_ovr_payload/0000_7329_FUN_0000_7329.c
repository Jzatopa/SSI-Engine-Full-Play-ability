/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:7329
 * Ghidra name: FUN_0000_7329
 * Linear address: 0x07329
 * Original GAME.OVR file offset: 29489
 * Body addresses: 21
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x00007391) overlaps instruction at (ram,0x00007390)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0000735e) */
/* WARNING: Removing unreachable block (ram,0x00007336) */
/* WARNING: Removing unreachable block (ram,0x00007338) */
/* WARNING: Removing unreachable block (ram,0x0000733c) */
/* WARNING: Removing unreachable block (ram,0x00007343) */
/* WARNING: Removing unreachable block (ram,0x00007365) */
/* WARNING: Removing unreachable block (ram,0x00007346) */
/* WARNING: Removing unreachable block (ram,0x00007348) */
/* WARNING: Removing unreachable block (ram,0x0000734f) */
/* WARNING: Removing unreachable block (ram,0x00007351) */
/* WARNING: Removing unreachable block (ram,0x000073c2) */
/* WARNING: Removing unreachable block (ram,0x0000736a) */
/* WARNING: Removing unreachable block (ram,0x0000736d) */
/* WARNING: Removing unreachable block (ram,0x0000738f) */
/* WARNING: Removing unreachable block (ram,0x00007391) */
/* WARNING: Removing unreachable block (ram,0x000073a1) */
/* WARNING: Removing unreachable block (ram,0x000073b0) */
/* WARNING: Removing unreachable block (ram,0x000073b6) */
/* WARNING: Removing unreachable block (ram,0x0000736f) */
/* WARNING: Removing unreachable block (ram,0x000073d6) */
/* WARNING: Removing unreachable block (ram,0x00007371) */
/* WARNING: Removing unreachable block (ram,0x00007374) */
/* WARNING: Removing unreachable block (ram,0x00007376) */
/* WARNING: Removing unreachable block (ram,0x000073de) */
/* WARNING: Removing unreachable block (ram,0x00007379) */
/* WARNING: Removing unreachable block (ram,0x0000737b) */
/* WARNING: Removing unreachable block (ram,0x0000737d) */
/* WARNING: Removing unreachable block (ram,0x0000738b) */
/* WARNING: Removing unreachable block (ram,0x00007390) */
/* WARNING: Removing unreachable block (ram,0x000073ec) */
/* WARNING: Removing unreachable block (ram,0x000073ee) */
/* WARNING: Removing unreachable block (ram,0x000073e8) */
/* WARNING: Removing unreachable block (ram,0x000073f0) */
/* WARNING: Removing unreachable block (ram,0x000073e3) */
/* WARNING: Removing unreachable block (ram,0x000073e6) */

void FUN_0000_7329(undefined2 *param_1,int param_2,undefined2 param_3,int param_4,undefined2 param_5
                  ,char param_6,char param_7)

{
  char *pcVar1;
  undefined2 *puVar2;
  uint3 uVar3;
  byte bVar4;
  undefined1 uVar5;
  uint uVar6;
  byte extraout_AH;
  byte bVar7;
  undefined2 uVar8;
  int iVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_ZF;
  int in_stack_00000000;
  
  puVar2 = (undefined2 *)((long)*(int *)(in_stack_00000000 + 0x73) * 0x20);
  puVar10 = (undefined2 *)puVar2;
  out(*param_1,param_5);
  if ((undefined2 *)(long)(int)puVar10 != puVar2 || in_ZF) {
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_6;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_6;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    pcVar1 = (char *)((int)param_1 + param_4 + 2);
    *pcVar1 = *pcVar1 + param_7;
    ((undefined *)&DAT_0000_ff89)[in_stack_00000000] =
         ((undefined *)&DAT_0000_ff89)[in_stack_00000000] + (char)param_5;
    in(0x81);
    in(param_5);
    puVar10[-1] = unaff_SS;
    *(int *)((int)puVar10 + -5) = param_4;
    *(undefined2 *)((int)puVar10 + -7) = *(undefined2 *)0x534a;
    *(undefined2 *)((int)puVar10 + -9) = unaff_CS;
    puVar11 = (undefined2 *)((int)puVar10 + -0xb);
    *(undefined2 *)((int)puVar10 + -0xb) = 0x73c3;
    uVar5 = func_0x00000a91();
    *(undefined1 *)(param_2 + -0x106) = uVar5;
    unaff_CS = 0x99;
    uVar8 = *(undefined2 *)0x5801;
    *(undefined2 *)(param_2 + -4) = *(undefined2 *)0x57ff;
    *(undefined2 *)(param_2 + -2) = uVar8;
    puVar16 = (undefined2 *)*(undefined2 *)(param_2 + 6);
  }
  else {
    if ((undefined2 *)(long)(int)puVar10 != puVar2) {
      puVar15 = (undefined2 *)*puVar10;
      iVar14 = puVar10[1];
      param_2 = puVar10[2];
      iVar9 = puVar10[4];
      uVar8 = puVar10[5];
      bVar7 = (byte)puVar10[6];
      bVar4 = (byte)puVar10[7];
    }
    else {
      puVar15 = (undefined2 *)*puVar10;
      iVar14 = puVar10[1];
      param_2 = puVar10[2];
      iVar9 = puVar10[4];
      uVar8 = puVar10[5];
      bVar7 = (byte)puVar10[6];
      bVar4 = (byte)puVar10[7];
    }
    puVar11 = puVar10 + 8;
    puVar16 = puVar15 + 1;
    uVar8 = in(uVar8);
    *puVar15 = uVar8;
    *(byte *)(param_2 + iVar14) = *(byte *)(param_2 + iVar14) & bVar4;
    *(byte *)(iVar9 + iVar14) = *(byte *)(iVar9 + iVar14) & bVar7;
    pcVar1 = (char *)((int)puVar16 + param_2 + 0x67e);
    *pcVar1 = *pcVar1 + -1;
  }
  *(undefined1 *)((int)puVar16 + -5) = 0;
  uVar6 = *(uint *)(param_2 + -4) | *(uint *)(param_2 + -2);
  if (uVar6 == 0) {
    FUN_0000_792f();
    return;
  }
  if (((undefined *)&DAT_0000_fffa)[*(int *)(param_2 + 6)] != '\0') {
    FUN_0000_792f();
    return;
  }
  if (*(char *)((int)*(undefined4 *)(param_2 + -4) + 0xd4) != '\x01') {
    FUN_0000_7919();
    return;
  }
  *(undefined1 *)(param_2 + -0x105) = 0;
  uVar3 = (uint3)(byte)(uVar6 >> 8);
  *(uint *)((int)puVar11 + -2) = uVar6 & 0xff00;
  *(undefined2 *)((int)puVar11 + -4) = (int)CONCAT31(uVar3,0x17);
  *(undefined2 *)((int)puVar11 + -6) = (int)CONCAT31(uVar3,0x27);
  *(undefined2 *)((int)puVar11 + -8) = (int)CONCAT31(uVar3,0x18);
  *(undefined2 *)((int)puVar11 + -10) = unaff_CS;
  puVar12 = (undefined1 *)((int)puVar11 + -0xc);
  *(undefined2 *)((int)puVar11 + -0xc) = 0x7418;
  func_0x00001140();
  *(uint *)(puVar12 + -2) = (uint)extraout_AH << 8;
  *(int *)(puVar12 + -4) = param_2;
  *(undefined2 *)(puVar12 + -6) = 0xec;
  puVar13 = puVar12 + -8;
  *(undefined2 *)(puVar12 + -8) = 0x7420;
  func_0x00006e7f();
  *(undefined2 *)(puVar13 + -2) = unaff_SS;
  *(int *)(puVar13 + -4) = param_2 + -0x116;
  *(undefined2 *)(puVar13 + -6) = 0xec;
  *(undefined2 *)(puVar13 + -8) = 0x2fb4;
                    /* WARNING: Subroutine does not return */
  *(undefined2 *)(puVar13 + -10) = 0xec;
  *(undefined2 *)(puVar13 + -0xc) = 0x7430;
  FUN_0000_d6c2();
}


