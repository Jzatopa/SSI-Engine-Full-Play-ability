/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:49de
 * Ghidra name: FUN_0000_49de
 * Linear address: 0x049DE
 * Original GAME.OVR file offset: 18918
 * Body addresses: 61
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_49de(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x44ce);
  FUN_0000_453c(0x44ce);
  if (*(char *)0x7817 != '\0') {
    FUN_0000_4913();
    return;
  }
  FUN_0000_39b7();
  uVar1 = *(undefined2 *)(unaff_BP + -9);
  *(undefined2 *)0x44ce = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
  *(undefined2 *)0x44d0 = uVar1;
  return;
}


