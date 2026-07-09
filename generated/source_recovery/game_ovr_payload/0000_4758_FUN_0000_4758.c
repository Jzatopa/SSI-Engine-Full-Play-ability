/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4758
 * Ghidra name: FUN_0000_4758
 * Linear address: 0x04758
 * Original GAME.OVR file offset: 18272
 * Body addresses: 158
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_4758(undefined2 param_1,undefined1 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  char extraout_AL;
  undefined1 extraout_AH;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  local_3 = -1;
  local_5 = 0;
  uVar4 = (undefined2)((ulong)param_3 >> 0x10);
  iVar2 = (int)param_3;
  local_4 = '\0';
  while( true ) {
    FUN_0000_4652(param_1,local_4,param_2,iVar2,uVar4);
    uVar3 = extraout_AH;
    if ((extraout_AL == '\0') &&
       (iVar1 = (uint)(*(byte *)(iVar2 + local_4 * 6 + 0x3c) & 0x7f) * 0x22,
       uVar3 = (undefined1)((uint)iVar1 >> 8), local_5 < *(byte *)(iVar1 + 0x240b))) {
      local_3 = local_4;
      iVar1 = (uint)(*(byte *)(iVar2 + local_4 * 6 + 0x3c) & 0x7f) * 0x22;
      local_5 = *(byte *)(iVar1 + 0x240b);
      uVar3 = (undefined1)((uint)iVar1 >> 8);
    }
    if (local_4 == '\a') break;
    local_4 = local_4 + '\x01';
  }
  return CONCAT11(uVar3,local_3);
}


