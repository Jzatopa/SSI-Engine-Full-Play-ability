/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 187b:0132
 * Ghidra name: FUN_187b_0132
 * Linear address: 0x188E2
 * Body addresses: 315
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __stdcall16far FUN_187b_0132(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined1 extraout_AH;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  long lVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined2 uVar10;
  uint local_189;
  int local_187;
  undefined1 local_185 [2];
  undefined1 local_183 [128];
  undefined1 local_103 [256];
  undefined1 local_3;
  
  FUN_1cc0_0adc(0xff,local_103,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  FUN_1cc0_180c(local_103,unaff_SS,local_183,unaff_SS);
  FUN_1cc0_183a(1,local_183,unaff_SS);
  iVar1 = FUN_1cc0_04a2();
  if (iVar1 == 0) {
    lVar7 = FUN_1cc0_19d4(local_183,unaff_SS);
    if (lVar7 != 0) {
      iVar1 = FUN_1cc0_19d4(local_183,unaff_SS);
      *(int *)0x9ed8 = iVar1 + 0x40;
      uVar8 = FUN_1cc0_023f(*(undefined2 *)0x9ed8);
      *(undefined2 *)0x9eda = (int)uVar8;
      *(undefined2 *)0x9edc = (int)((ulong)uVar8 >> 0x10);
      local_187 = *(int *)0x9edc;
      for (local_189 = *(uint *)0x9eda; (local_189 & 0xf) != 0; local_189 = local_189 + 1) {
        local_187 = local_187 + (uint)(0xfffe < local_189);
      }
      iVar1 = 0;
      uVar2 = FUN_1cc0_0aa7();
      *(undefined2 *)0x9ede = 0;
      *(int *)0x9ee0 = iVar1 + local_187 + (uint)CARRY2(uVar2,local_189);
      puVar9 = local_183;
      uVar6 = (undefined2)((ulong)*(undefined4 *)0x9ede >> 0x10);
      uVar5 = (undefined2)*(undefined4 *)0x9ede;
      uVar10 = unaff_SS;
      uVar3 = FUN_1cc0_19d4(local_183,unaff_SS);
      FUN_1cc0_1925(local_185,unaff_SS,uVar3,uVar5,uVar6,puVar9,uVar10);
      FUN_1cc0_18bb(local_183,unaff_SS);
      local_3 = 1;
      uVar4 = extraout_AH;
      goto LAB_187b_0264;
    }
    iVar1 = 0;
  }
  uVar4 = (undefined1)((uint)iVar1 >> 8);
  local_3 = 0;
LAB_187b_0264:
  return CONCAT11(uVar4,local_3);
}


