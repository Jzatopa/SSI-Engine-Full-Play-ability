/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 178b:00a3
 * Ghidra name: FUN_178b_00a3
 * Linear address: 0x17953
 * Body addresses: 112
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far
FUN_178b_00a3(undefined4 param_1,undefined1 param_2,undefined1 param_3,char param_4)

{
  undefined1 extraout_AH;
  undefined1 uVar1;
  undefined1 extraout_AH_00;
  undefined2 unaff_SS;
  byte local_104;
  byte local_102 [256];
  
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  if (local_102[0] != 0) {
    local_104 = 1;
    uVar1 = extraout_AH;
    while( true ) {
      FUN_178b_0037(local_102[local_104],CONCAT11(uVar1,1),CONCAT11(uVar1,param_2),
                    CONCAT11(uVar1,param_3),CONCAT11(uVar1,param_4));
      param_4 = param_4 + '\x01';
      if (local_104 == local_102[0]) break;
      local_104 = local_104 + 1;
      uVar1 = extraout_AH_00;
    }
  }
  return;
}


