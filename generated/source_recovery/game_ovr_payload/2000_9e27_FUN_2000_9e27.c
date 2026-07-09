/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:9e27
 * Ghidra name: FUN_2000_9e27
 * Linear address: 0x29E27
 * Original GAME.OVR file offset: 171567
 * Body addresses: 112
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_2000_9e27(uint *param_1,char param_2,undefined4 param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  char local_4;
  
  local_4 = '\0';
  uVar4 = (undefined2)((ulong)param_3 >> 0x10);
  uVar1 = *(uint *)((int)param_3 + 0xfd);
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  puVar2 = (uint *)param_1;
  *param_1 = *(uint *)((int)param_3 + 0xfb);
  puVar2[1] = uVar1;
  while (((*param_1 | puVar2[1]) != 0 && (local_4 == '\0'))) {
    if (**(char **)param_1 == param_2) {
      local_4 = '\x01';
    }
    else {
      uVar4 = (undefined2)((ulong)*(undefined4 *)param_1 >> 0x10);
      iVar3 = (int)*(undefined4 *)param_1;
      uVar1 = *(uint *)(iVar3 + 7);
      *param_1 = *(uint *)(iVar3 + 5);
      puVar2[1] = uVar1;
    }
  }
  return CONCAT11((char)((*param_1 | puVar2[1]) >> 8),local_4);
}


