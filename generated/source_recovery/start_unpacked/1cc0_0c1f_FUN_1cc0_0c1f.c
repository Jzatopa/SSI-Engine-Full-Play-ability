/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0c1f
 * Ghidra name: FUN_1cc0_0c1f
 * Linear address: 0x1D81F
 * Body addresses: 84
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far
FUN_1cc0_0c1f(int param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined1 local_202 [256];
  undefined1 local_102 [256];
  
  puVar4 = local_102;
  uVar2 = (undefined2)((ulong)param_3 >> 0x10);
  uVar1 = (undefined2)param_3;
  uVar5 = unaff_SS;
  FUN_1cc0_0b0e(param_1 + -1,1,uVar1,uVar2);
  FUN_1cc0_0b4f((int)param_4,(int)((ulong)param_4 >> 0x10));
  puVar3 = local_202;
  FUN_1cc0_0b0e(0xff,param_1,uVar1,uVar2);
  FUN_1cc0_0b4f(puVar3,unaff_SS);
  FUN_1cc0_0adc(param_2,uVar1,uVar2,puVar4,uVar5);
  return;
}


