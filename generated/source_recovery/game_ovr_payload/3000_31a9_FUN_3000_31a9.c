/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:31a9
 * Ghidra name: FUN_3000_31a9
 * Linear address: 0x331A9
 * Original GAME.OVR file offset: 209329
 * Body addresses: 70
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far
FUN_3000_31a9(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  
  cVar1 = FUN_3000_256b(param_3,param_4);
  iVar2 = (int)cVar1;
  cVar1 = FUN_3000_2593(param_3,param_4);
  iVar3 = (int)cVar1;
  cVar1 = FUN_3000_256b(param_1,param_2);
  iVar4 = (int)cVar1;
  cVar1 = FUN_3000_2593(param_1,param_2);
  uVar5 = FUN_3000_2fb2((int)cVar1,iVar4,iVar3,iVar2);
  return uVar5;
}


