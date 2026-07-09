/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1602:113c
 * Ghidra name: FUN_1602_113c
 * Linear address: 0x1715C
 * Body addresses: 263
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __stdcall16far FUN_1602_113c(undefined4 param_1,undefined1 param_2)

{
  undefined1 uVar4;
  int iVar1;
  undefined2 uVar2;
  undefined1 extraout_AH;
  undefined2 uVar3;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar5;
  undefined1 local_204 [256];
  int local_104;
  byte local_102 [256];
  
  FUN_1cc0_0adc(0xff,local_102,unaff_SS,(int)param_1,(int)((ulong)param_1 >> 0x10));
  uVar4 = 0;
  if ((int)(((uint)*(byte *)0x687c - (uint)*(byte *)0x687a) + 1) < (int)(uint)local_102[0]) {
    iVar1 = *(byte *)0x687c - 1;
    for (local_104 = iVar1; local_102[local_104] != 0x20; local_104 = local_104 + -1) {
    }
    if (local_104 < 0) {
      iVar1 = *(byte *)0x687c - 1;
      local_104 = iVar1;
    }
    uVar2 = CONCAT11((char)((uint)iVar1 >> 8),param_2);
    puVar5 = local_204;
    uVar3 = unaff_SS;
    FUN_1cc0_0b0e(local_104 + -1,0,local_102,unaff_SS);
    FUN_1602_113c(puVar5,uVar3,uVar2);
    uVar3 = CONCAT11(extraout_AH,param_2);
    puVar5 = local_204;
    FUN_1cc0_0b0e((uint)local_102[0] - local_104,local_104 + 1,local_102,unaff_SS);
    FUN_1602_113c(puVar5,unaff_SS,uVar3);
  }
  else {
    if ((*(byte *)0x687b < *(byte *)0x5357) && (*(char *)0x5358 == '\0')) {
      FUN_1602_10e5();
      uVar4 = extraout_AH_00;
    }
    else if (*(byte *)0x687d < *(byte *)0x5357) {
      if (*(char *)0x5358 != '\0') {
        FUN_1602_1243();
      }
      FUN_1602_10e5();
      uVar4 = extraout_AH_01;
    }
    FUN_1602_041a(local_102,unaff_SS,CONCAT11(uVar4,*(undefined1 *)0x687e),CONCAT11(uVar4,param_2),
                  CONCAT11(uVar4,*(undefined1 *)0x5357),CONCAT11(uVar4,*(undefined1 *)0x5356));
    *(undefined1 *)0x5358 = 1;
    *(char *)0x5357 = *(char *)0x5357 + '\x01';
  }
  return;
}


