/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:77a7
 * Ghidra name: FUN_2000_77a7
 * Linear address: 0x277A7
 * Original GAME.OVR file offset: 161711
 * Body addresses: 62
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_77a7(undefined1 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  byte bVar2;
  undefined2 local_6;
  undefined2 uStack_4;
  
  uVar1 = func_0x00000a96();
  bVar2 = (byte)((uint)uVar1 >> 8);
  if ((char)uVar1 != '\0') {
    FUN_2000_77e5((uint)bVar2 << 8,local_6,uStack_4,(int)param_2,(int)((ulong)param_2 >> 0x10),
                  CONCAT11(bVar2,param_1));
  }
  return;
}


