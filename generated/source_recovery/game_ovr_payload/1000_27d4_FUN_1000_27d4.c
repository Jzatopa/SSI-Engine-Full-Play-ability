/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:27d4
 * Ghidra name: FUN_1000_27d4
 * Linear address: 0x127D4
 * Original GAME.OVR file offset: 75740
 * Body addresses: 143
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_27d4(undefined4 param_1)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined2 uVar4;
  undefined1 local_3;
  
  uVar4 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  pcVar1 = (char *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xd);
  *pcVar1 = *pcVar1 + '\x01';
  bVar2 = func_0x00000dd5();
  local_3 = (byte)((ulong)(long)(int)(((uint)bVar2 -
                                      (uint)*(byte *)((int)*(undefined4 *)(iVar3 + 0xf3) + 7)) + 8)
                  % 8);
  if (4 < local_3) {
    local_3 = 8 - local_3;
  }
  *(undefined1 *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xe) =
       (char)((ulong)(long)(int)((uint)*(byte *)((int)*(undefined4 *)(iVar3 + 0xf3) + 0xe) +
                                (uint)local_3) % 8);
  return;
}


