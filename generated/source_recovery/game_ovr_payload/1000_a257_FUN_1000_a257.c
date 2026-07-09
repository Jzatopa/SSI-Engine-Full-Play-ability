/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:a257
 * Ghidra name: FUN_1000_a257
 * Linear address: 0x1A257
 * Original GAME.OVR file offset: 107103
 * Body addresses: 92
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_a257(undefined2 param_1,undefined1 param_2,byte param_3)

{
  undefined2 in_AX;
  byte bVar2;
  int iVar1;
  undefined2 unaff_DS;
  
  bVar2 = (byte)((uint)in_AX >> 8);
  iVar1 = (uint)bVar2 * 0x100;
  if (*"" != '\0') {
    iVar1 = iVar1 + 1;
  }
  FUN_1000_a0fa(param_1,iVar1,(uint)bVar2 << 8,CONCAT11(bVar2,0xfe),CONCAT11(bVar2,0xfe),
                CONCAT11(bVar2,param_2),CONCAT11(bVar2,param_3));
  FUN_0000_39b7();
  bVar2 = (byte)(param_3 + 3 >> 8);
  iVar1 = (uint)bVar2 * 0x100;
  if (*"" != '\0') {
    iVar1 = iVar1 + 1;
  }
  FUN_1000_a0fa(param_1,iVar1,CONCAT11(bVar2,1),CONCAT11(bVar2,0xfe),CONCAT11(bVar2,0xfe),
                CONCAT11(bVar2,param_2),param_3 + 3);
  FUN_0000_39b7();
  return;
}


