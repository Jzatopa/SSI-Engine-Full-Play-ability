/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0385
 * Ghidra name: FUN_0000_0385
 * Linear address: 0x00385
 * Original GAME.OVR file offset: 909
 * Body addresses: 42
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - credits (anchor), next candidate, distance 516 byte(s), source offset 393
 */

/* WARNING: Instruction at (ram,0x000003c6) overlaps instruction at (ram,0x000003c3)
    */
/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */
/* WARNING: Removing unreachable block (ram,0x000003a6) */
/* WARNING: Removing unreachable block (ram,0x000003cb) */
/* WARNING: Removing unreachable block (ram,0x00000399) */

void FUN_0000_0385(void)

{
  int in_AX;
  byte bVar1;
  byte extraout_AH;
  undefined2 in_DX;
  int iVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  ulong in_ESP;
  undefined2 *unaff_BP;
  undefined2 *unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  bool in_ZF;
  bool in_SF;
  
  if (in_SF) {
    iVar2 = (int)in_ESP;
    *(undefined2 *)(iVar2 + -2) = unaff_DI;
    if (in_CF) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    puVar3 = (undefined2 *)(iVar2 + -4);
    *(undefined2 *)(iVar2 + -4) = 0x6972;
    if ((byte)in_AX < 0x43) {
      *(undefined2 *)(iVar2 + -6) = unaff_DI;
      unaff_BP = (undefined2 *)*(undefined2 *)(iVar2 + -2);
      bVar1 = (byte)((uint)*(undefined2 *)(iVar2 + 8) >> 8);
      *(undefined2 *)(iVar2 + 8) = unaff_ES;
      *(undefined2 *)(iVar2 + 6) = CONCAT11(bVar1,0x15);
      *(undefined2 *)(iVar2 + 4) = CONCAT11(bVar1,3);
      in_ESP = (ulong)(iVar2 + 2);
      *(undefined2 *)(iVar2 + 2) = CONCAT11(bVar1,0xf);
      in_AX = (uint)bVar1 << 8;
LAB_0000_0418:
      iVar7 = (int)in_ESP;
      *(int *)(iVar7 + -2) = in_AX;
      *(undefined2 *)(iVar7 + -4) = unaff_SS;
      *(int *)(iVar7 + -6) = (int)((int)unaff_BP + -0xd);
      *(undefined2 *)(iVar7 + -8) = unaff_CS;
      *(undefined2 *)(iVar7 + -10) = 0xe6;
                    /* WARNING: Subroutine does not return */
      *(undefined2 *)(iVar7 + -0xc) = unaff_CS;
      *(undefined2 *)(iVar7 + -0xe) = 0x428;
      FUN_0000_d6c2();
    }
  }
  else {
    out(*unaff_SI,in_DX);
    if (!in_ZF) goto LAB_0000_0418;
    *(undefined2 *)(in_ESP - 2) = unaff_BP;
    unaff_BP = (undefined2 *)(undefined2 *)(in_ESP - 2);
    puVar3 = unaff_BP + -0x14;
    unaff_BP[-0x14] = 0x10;
  }
  *(undefined2 *)((int)puVar3 + -2) = 0x10;
  *(undefined2 *)((int)puVar3 + -4) = unaff_DS;
  *(undefined2 *)((int)puVar3 + -6) = 0x96c7;
  *(undefined2 *)((int)puVar3 + -8) = unaff_CS;
  puVar4 = (undefined1 *)((int)puVar3 + -10);
  *(undefined2 *)((int)puVar3 + -10) = 0x3c3;
  FUN_0000_49de();
  *(undefined2 *)(puVar4 + 6) = 0x21a;
  puVar5 = puVar4 + 4;
  *(undefined2 *)(puVar4 + 4) = 0x3c8;
  FUN_0000_6d0d();
  *(undefined2 *)(puVar5 + -2) = 0x602;
  puVar6 = puVar5 + -4;
  *(undefined2 *)(puVar5 + -4) = 0x3cd;
  FUN_0000_0fdb();
  *(uint *)(puVar6 + -2) = CONCAT11(extraout_AH,2);
  *(uint *)(puVar6 + -4) = CONCAT11(extraout_AH,1);
  *(uint *)(puVar6 + -6) = CONCAT11(extraout_AH,0xe);
  *(uint *)(puVar6 + -8) = (uint)extraout_AH << 8;
  *(undefined2 *)(puVar6 + -10) = unaff_SS;
  *(undefined1 **)(puVar6 + -0xc) = (undefined1 *)((int)unaff_BP + -0x25);
  *(undefined2 *)(puVar6 + -0xe) = 0xec;
  *(undefined2 *)(puVar6 + -0x10) = 0xaf;
                    /* WARNING: Subroutine does not return */
  *(undefined2 *)(puVar6 + -0x12) = 0xec;
  *(undefined2 *)(puVar6 + -0x14) = 1000;
  FUN_0000_d6c2();
}


