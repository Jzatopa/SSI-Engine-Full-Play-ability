/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 178b:02e6
 * Ghidra name: FUN_178b_02e6
 * Linear address: 0x17B96
 * Body addresses: 565
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined2 __stdcall16far
FUN_178b_02e6(undefined4 param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 uVar3;
  undefined1 extraout_AH_01;
  undefined1 extraout_AH_02;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 local_348 [256];
  undefined1 local_248 [256];
  undefined1 local_148 [5];
  undefined1 local_143 [9];
  char local_13a;
  byte local_139;
  undefined1 local_f6 [80];
  char local_a6;
  undefined1 local_a5 [81];
  undefined1 local_54 [82];
  
  FUN_1cc0_0adc(0x50,local_54,unaff_SS,(int)param_4,(int)((ulong)param_4 >> 0x10));
  FUN_1cc0_0adc(0x50,local_a5,unaff_SS,(int)param_3,(int)((ulong)param_3 >> 0x10));
  FUN_1c3e_0256(local_148,unaff_SS,local_143,unaff_SS,&local_13a,unaff_SS,local_54,unaff_SS);
  if ((local_139 < 0x43) && (*(char *)0x50d0 == '\x02')) {
    FUN_187b_02c3();
  }
  if (local_13a == '\0') {
    FUN_1cc0_0adc(0x43,&local_13a,unaff_SS,0x4370,unaff_DS);
  }
  do {
    puVar8 = local_248;
    uVar1 = unaff_SS;
    FUN_1cc0_0ac2(&local_13a,unaff_SS);
    FUN_1cc0_0b4f(local_143,unaff_SS);
    FUN_1cc0_0b4f(local_148,unaff_SS);
    uVar1 = FUN_178b_051b(puVar8,uVar1);
    local_a6 = (char)uVar1;
    bVar6 = local_a6 == '\0';
    if ((bVar6) && (uVar1 = FUN_1cc0_0bc7(0x4370,unaff_DS,&local_13a,unaff_SS), bVar6)) {
      FUN_1cc0_0adc(0x4f,local_f6,unaff_SS,0x4370,unaff_DS);
      FUN_1cc0_0adc(0x4f,0x4370,unaff_DS,0x43c0,unaff_DS);
      FUN_1cc0_0adc(0x4f,0x43c0,unaff_DS,local_f6,unaff_SS);
      FUN_1cc0_0adc(0x43,&local_13a,unaff_SS,0x4370,unaff_DS);
      puVar8 = local_248;
      uVar1 = unaff_SS;
      FUN_1cc0_0ac2(&local_13a,unaff_SS);
      FUN_1cc0_0b4f(local_143,unaff_SS);
      FUN_1cc0_0b4f(local_148,unaff_SS);
      uVar1 = FUN_178b_051b(puVar8,uVar1);
      local_a6 = (char)uVar1;
    }
    uVar4 = (undefined1)((uint)uVar1 >> 8);
    if ((local_a6 == '\0') && (param_2 == '\0')) {
      if (local_139 < 0x43) {
        uVar2 = CONCAT11(uVar4,0xe);
        puVar8 = local_348;
        uVar3 = unaff_SS;
        FUN_1cc0_0ac2(local_a5,unaff_SS);
        puVar7 = local_248;
        uVar1 = unaff_SS;
        FUN_1cc0_0bf2(CONCAT11(extraout_AH,*(undefined1 *)0x4410));
        FUN_1cc0_0b4f(puVar7,uVar1);
        FUN_1cc0_0b4f(700,0x1cc0);
        FUN_178b_0131(puVar8,uVar3,uVar2);
        uVar4 = extraout_AH_00;
      }
      else {
        uVar3 = CONCAT11(uVar4,0xe);
        puVar8 = local_248;
        uVar1 = unaff_SS;
        FUN_1cc0_0ac2(0x2c6,0x1cc0);
        FUN_1cc0_0b4f(local_143,unaff_SS);
        FUN_1cc0_0b4f(local_148,unaff_SS);
        FUN_1cc0_0b4f(0x2d5,0x1cc0);
        FUN_178b_0131(puVar8,uVar1,uVar3);
        FUN_1836_0000();
        uVar4 = extraout_AH_01;
      }
    }
  } while ((local_a6 == '\0') && (param_2 == '\0'));
  if (local_a6 != '\0') {
    uVar5 = (undefined2)((ulong)param_1 >> 0x10);
    puVar8 = local_248;
    uVar1 = unaff_SS;
    uVar3 = (int)param_1;
    uVar2 = uVar5;
    FUN_1cc0_0ac2(&local_13a,unaff_SS);
    FUN_1cc0_0b4f(local_143,unaff_SS);
    FUN_1cc0_0b4f(local_148,unaff_SS);
    FUN_1cc0_180c(puVar8,uVar1,uVar3,uVar2);
    FUN_1cc0_183a(1,(int)param_1,uVar5);
    uVar4 = extraout_AH_02;
  }
  return CONCAT11(uVar4,local_a6);
}


