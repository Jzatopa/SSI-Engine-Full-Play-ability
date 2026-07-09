/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b0d9
 * Ghidra name: FUN_2000_b0d9
 * Linear address: 0x2B0D9
 * Original GAME.OVR file offset: 176353
 * Body addresses: 67
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

uint __stdcall16far FUN_2000_b0d9(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  uVar1 = 0;
  if ((*(int *)(iVar2 + 0xeb) == 0 && *(int *)(iVar2 + 0xed) == 0) ||
     (uVar1 = (uint)*(byte *)((int)*(undefined4 *)(iVar2 + 0xeb) + 0x2e) * 9,
     (byte)((undefined *)&DAT_0000_5375)[uVar1] < 2)) {
    uVar1 = uVar1 & 0xff00;
  }
  else {
    uVar1 = CONCAT11((char)(uVar1 >> 8),1);
  }
  return uVar1;
}


