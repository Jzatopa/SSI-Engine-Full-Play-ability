/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:9ff1
 * Ghidra name: FUN_2000_9ff1
 * Linear address: 0x29FF1
 * Original GAME.OVR file offset: 172025
 * Body addresses: 288
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_2000_9ff1(undefined1 param_1,undefined2 param_2,undefined2 param_3)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 uVar5;
  undefined2 unaff_DS;
  undefined2 uVar6;
  byte local_6;
  byte local_5;
  byte local_4;
  
  uVar4 = param_2;
  uVar6 = param_3;
  uVar3 = FUN_0000_0e20();
  uVar4 = FUN_0000_0e25(param_2,param_3,uVar3,uVar4,uVar6);
  uVar4 = func_0x00000e2a(0xdb,param_2,param_3,0xff,param_1,uVar4);
  func_0x00000da9(0xdb,uVar4);
  bVar1 = *(byte *)0x71e0;
  local_5 = 0;
  uVar5 = extraout_AH;
  if (bVar1 == 0) {
    local_4 = 0;
  }
  else {
    if (bVar1 != 0) {
      local_6 = 1;
      while( true ) {
        cVar2 = FUN_2000_9f75(param_2,param_3);
        uVar5 = 0;
        if (*(char *)((int)*(undefined4 *)
                            ((undefined *)&DAT_0000_707f +
                            (uint)*(byte *)((uint)local_6 * 3 + 0x71de) * 4) + 0xd6) == cVar2) {
          local_5 = local_5 + 1;
          FUN_0000_e6af(3);
          uVar5 = extraout_AH_00;
        }
        if (local_6 == bVar1) break;
        local_6 = local_6 + 1;
      }
    }
    local_4 = local_5;
    *(byte *)0x71e0 = local_5;
  }
  if (local_4 != 0) {
    local_6 = 1;
    while( true ) {
      ((undefined *)&DAT_0000_74ba)[local_6] = *(undefined1 *)((uint)local_6 * 3 + 0x71de);
      uVar5 = 0;
      if (local_6 == local_4) break;
      local_6 = local_6 + 1;
    }
  }
  return CONCAT11(uVar5,local_4);
}


