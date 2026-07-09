/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 178b:08e8
 * Ghidra name: FUN_178b_08e8
 * Linear address: 0x18198
 * Body addresses: 412
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far
FUN_178b_08e8(undefined2 *param_1,undefined2 *param_2,char param_3,undefined4 param_4,
             undefined4 param_5)

{
  char cVar1;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  long lVar5;
  undefined4 uVar6;
  uint local_1af;
  undefined1 local_1ad [128];
  undefined1 local_12d [128];
  undefined1 local_ad [2];
  char local_ab;
  uint local_aa;
  int local_a8;
  undefined1 local_a6 [2];
  undefined1 local_a4 [81];
  undefined1 local_53 [81];
  
  FUN_1cc0_0adc(0x50,local_53,unaff_SS,(int)param_5,(int)((ulong)param_5 >> 0x10));
  FUN_1cc0_0adc(0x50,local_a4,unaff_SS,(int)param_4,(int)((ulong)param_4 >> 0x10));
  FUN_178b_0000();
  cVar1 = FUN_178b_07da(local_1ad,unaff_SS,local_12d,unaff_SS,&local_1af,unaff_SS,local_a4,unaff_SS,
                        local_53,unaff_SS);
  puVar2 = (undefined2 *)param_1;
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  if (cVar1 == '\0') {
    *param_2 = 0;
    *param_1 = 0;
    puVar2[1] = 0;
    FUN_178b_0020();
  }
  else {
    while( true ) {
      FUN_1cc0_1925(local_ad,unaff_SS,1,&local_ab,unaff_SS,local_1ad,unaff_SS);
      FUN_1cc0_1925(local_ad,unaff_SS,4,&local_aa,unaff_SS,local_1ad,unaff_SS);
      uVar4 = (undefined2)((ulong)param_2 >> 0x10);
      FUN_1cc0_1925(local_ad,unaff_SS,2,(undefined2 *)param_2,uVar4,local_1ad,unaff_SS);
      FUN_1cc0_1925(local_ad,unaff_SS,2,local_a6,unaff_SS,local_1ad,unaff_SS);
      if (local_ab == param_3) break;
      lVar5 = FUN_1cc0_19bd(local_1ad,unaff_SS);
      if ((0xffff < lVar5) || ((-1 < lVar5 && (local_1af <= (uint)lVar5)))) break;
    }
    if (local_ab == param_3) {
      uVar6 = FUN_1cc0_023f(*param_2);
      *param_1 = (int)uVar6;
      puVar2[1] = (int)((ulong)uVar6 >> 0x10);
      FUN_1cc0_198d(local_1af + local_aa,local_a8 + (uint)CARRY2(local_1af,local_aa),local_12d,
                    unaff_SS);
      FUN_178b_071e(local_12d,unaff_SS,(undefined2 *)param_2,uVar4,puVar2,uVar3);
      FUN_178b_08cd(local_1ad,unaff_SS,local_12d,unaff_SS);
      FUN_178b_0020();
    }
    else {
      *param_2 = 0;
      *param_1 = 0;
      puVar2[1] = 0;
      FUN_178b_08cd(local_1ad,unaff_SS,local_12d,unaff_SS);
      FUN_178b_0020();
    }
  }
  return;
}


