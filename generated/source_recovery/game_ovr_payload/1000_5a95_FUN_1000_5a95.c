/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:5a95
 * Ghidra name: FUN_1000_5a95
 * Linear address: 0x15A95
 * Original GAME.OVR file offset: 88733
 * Body addresses: 115
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_1000_5a95(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  char cVar1;
  uint uVar2;
  undefined1 uVar3;
  bool bVar4;
  int iVar5;
  undefined2 uVar6;
  undefined1 local_3;
  
  iVar5 = (int)param_1;
  uVar6 = param_1._2_2_;
  uVar2 = func_0x00000dd5();
  uVar2 = (uint)*(byte *)((int)*(undefined4 *)((int)param_1 + 0xf3) + 7) - (uVar2 & 0xff);
  cVar1 = (char)uVar2;
  if ((*(byte *)((int)*(undefined4 *)((int)param_1 + 0xf3) + 0xd) < 2) ||
     (uVar2 = CONCAT11((char)(uVar2 >> 8),*(undefined1 *)((int)param_1 + 0x34)) & 0xff7f,
     1 < (byte)uVar2)) {
LAB_1000_5afb:
    uVar3 = (undefined1)(uVar2 >> 8);
    local_3 = 0;
  }
  else {
    bVar4 = cVar1 == -1;
    if (!bVar4) {
      uVar2 = FUN_0000_d977(0xdb,0x41e7,0xdb,CONCAT11((char)(uVar2 >> 8),cVar1),iVar5,uVar6,param_2,
                            param_3);
      if (bVar4) goto LAB_1000_5afb;
    }
    uVar3 = (undefined1)(uVar2 >> 8);
    local_3 = 1;
  }
  return CONCAT11(uVar3,local_3);
}


