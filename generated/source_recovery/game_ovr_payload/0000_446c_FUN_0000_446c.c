/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:446c
 * Ghidra name: FUN_0000_446c
 * Linear address: 0x0446C
 * Original GAME.OVR file offset: 17524
 * Body addresses: 185
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far
FUN_0000_446c(undefined2 param_1,char param_2,int param_3,int param_4,undefined4 param_5,
             undefined2 param_6,char param_7,char param_8)

{
  char extraout_AL;
  undefined1 extraout_AH;
  undefined1 uVar3;
  int iVar1;
  undefined2 uVar2;
  undefined1 local_4;
  
  if (param_3 == 0 && param_4 == 0) {
    iVar1 = (int)param_5;
    uVar2 = (undefined2)((ulong)param_5 >> 0x10);
    uVar3 = 0;
    if (param_8 == '\x03') {
      local_4 = *(char *)(iVar1 + 0x34);
    }
    else if (param_8 == '\x06') {
      local_4 = *(char *)(iVar1 + 0x34);
    }
    else if (param_8 == '3') {
      local_4 = *(char *)(iVar1 + 0x33);
    }
    else {
      local_4 = '\0';
    }
  }
  else {
    FUN_0000_0a6e();
    uVar3 = extraout_AH;
    local_4 = extraout_AL;
  }
  local_4 = local_4 + param_2;
  iVar1 = CONCAT11(uVar3,param_7);
  if (param_7 == '\0') {
    iVar1 = (uint)local_4 << 2;
    local_4 = (byte)iVar1;
  }
  else if (param_7 == '\x01') {
    iVar1 = (uint)local_4 << 1;
    local_4 = (byte)iVar1;
  }
  else if (param_7 == '\x03') {
    local_4 = local_4 >> 1;
    iVar1 = 0;
  }
  else if (param_7 == '\x04') {
    local_4 = local_4 >> 2;
    iVar1 = 0;
  }
  uVar2 = FUN_0000_09b5(CONCAT11((char)((uint)iVar1 >> 8),local_4));
  return uVar2;
}


