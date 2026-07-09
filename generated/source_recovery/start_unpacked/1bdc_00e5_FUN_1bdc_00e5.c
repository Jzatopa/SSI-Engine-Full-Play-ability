/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1bdc:00e5
 * Ghidra name: FUN_1bdc_00e5
 * Linear address: 0x1BEA5
 * Body addresses: 72
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1bdc_00e5(void)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  byte extraout_DL;
  byte bVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  
  uVar1 = FUN_1bdc_0609();
  FUN_1bdc_0609();
  uVar3 = 0;
  bVar4 = extraout_DL;
  if ((extraout_DL == 0) && (bVar4 = 0x18, (byte)uVar1 < 4)) {
    uVar3 = 1;
  }
  uVar5 = CONCAT11(bVar4,(char)(uVar1 >> 8) + -1);
  uVar2 = uVar1 & 0xff;
  if (0x18 < bVar4) {
    uVar2 = CONCAT11(1,(byte)uVar1);
  }
  *(uint *)0x9f38 = uVar2;
  *(undefined2 *)0x9f42 = uVar5;
  *(undefined1 *)0x9f37 = uVar3;
  *(undefined1 *)0x9f36 = 1;
  *(undefined2 *)0x9f3c = 0;
  *(undefined2 *)0x9f3e = uVar5;
  return;
}


