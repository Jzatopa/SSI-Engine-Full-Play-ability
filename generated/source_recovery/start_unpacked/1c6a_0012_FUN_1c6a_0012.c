/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c6a:0012
 * Ghidra name: FUN_1c6a_0012
 * Linear address: 0x1C6B2
 * Body addresses: 215
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1c6a_0012(void)

{
  code *pcVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined2 unaff_DS;
  bool bVar7;
  undefined2 uStack_82;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  bVar7 = false;
  if (*(int *)0x3d94 != 0) {
    uVar2 = FUN_1c6a_00e9();
    if (bVar7) {
      uVar2 = FUN_1c6a_00f5();
      if (bVar7) {
        uVar2 = FUN_1c6a_0130();
        if (bVar7) {
          uVar2 = 0xfffe;
          goto LAB_1c6a_00e0;
        }
      }
    }
    uVar3 = 0;
    bVar7 = false;
    iVar6 = 0;
LAB_1c6a_004c:
    do {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      if (!bVar7) {
        uVar5 = 8;
        pcVar1 = (code *)swi(0x21);
        uVar4 = (*pcVar1)();
        if (!bVar7) {
          bVar7 = uVar4 < uVar5;
        }
      }
      if (bVar7) {
LAB_1c6a_003c:
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        break;
      }
      if (local_c == 0x5a4d) {
        uVar5 = (uint)((ulong)local_8 * 0x200 >> 0x10);
        uVar4 = (uint)((ulong)local_8 * 0x200);
        uVar3 = uVar4 - (-local_a & 0x1ffU);
        uVar4 = (uint)(uVar4 < (-local_a & 0x1ffU));
        bVar7 = uVar5 < uVar4;
        iVar6 = uVar5 - uVar4;
        goto LAB_1c6a_004c;
      }
      if (local_c != 0x4246) goto LAB_1c6a_003c;
      if (local_a == 0x564f) goto LAB_1c6a_00aa;
      uVar4 = uVar3 + local_8;
      uVar5 = iVar6 + local_6 + (uint)CARRY2(uVar3,local_8);
      uVar3 = uVar4 + 8;
      uVar4 = (uint)(0xfff7 < uVar4);
      bVar7 = CARRY2(uVar5,uVar4);
      iVar6 = uVar5 + uVar4;
    } while( true );
  }
  uVar2 = 0xffff;
  goto LAB_1c6a_00e0;
LAB_1c6a_00aa:
  *(undefined2 *)0x3da4 = uVar2;
  *(uint *)0x3d90 = uVar3;
  *(int *)0x3d92 = iVar6;
  *(undefined2 *)0x9f4a = 0x268;
  *(undefined2 *)0x9f4c = 0x1c6a;
  if (*(int *)0x3d98 == 0 && *(int *)0x3d9a == 0) {
    *(undefined2 *)0x3d98 = 0x2e5;
    *(undefined2 *)0x3d9a = 0x1c6a;
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  uVar2 = 0;
  unaff_DS = uStack_82;
LAB_1c6a_00e0:
  *(undefined2 *)0x3d84 = uVar2;
  return;
}


