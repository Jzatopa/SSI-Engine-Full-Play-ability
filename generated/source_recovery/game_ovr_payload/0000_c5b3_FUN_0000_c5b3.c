/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:c5b3
 * Ghidra name: FUN_0000_c5b3
 * Linear address: 0x0C5B3
 * Original GAME.OVR file offset: 50619
 * Body addresses: 100
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_c5b3(uint param_1,undefined2 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined1 local_4 [2];
  
  uVar4 = (undefined2)((ulong)param_3 >> 0x10);
  iVar3 = (int)param_3;
  uVar1 = *(undefined2 *)(iVar3 + 0xeb);
  uVar2 = *(undefined2 *)(iVar3 + 0xed);
  *(uint *)(iVar3 + 0xeb) = param_1;
  *(undefined2 *)(iVar3 + 0xed) = param_2;
  FUN_0000_bebd(local_4,unaff_SS,param_1 & 0xff00,iVar3,uVar4);
  *(undefined2 *)(iVar3 + 0xeb) = uVar1;
  *(undefined2 *)(iVar3 + 0xed) = uVar2;
  return CONCAT11((char)((uint)uVar1 >> 8),local_4[0]);
}


