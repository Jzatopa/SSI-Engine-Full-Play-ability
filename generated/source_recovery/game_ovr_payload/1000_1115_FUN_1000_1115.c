/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:1115
 * Ghidra name: FUN_1000_1115
 * Linear address: 0x11115
 * Original GAME.OVR file offset: 69917
 * Body addresses: 70
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_1115(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar3 = (int)*(undefined4 *)0x57fb;
  iVar1 = *(int *)(iVar3 + 0xeb);
  iVar3 = *(int *)(iVar3 + 0xed);
  if ((iVar1 != 0 || iVar3 != 0) &&
     (uVar2 = (uint)*(byte *)(iVar1 + 0x2e) * 9, ((undefined *)&DAT_0000_5370)[uVar2] == '\x03')) {
    FUN_1000_0e7a(uVar2 & 0xff00);
  }
  return;
}


