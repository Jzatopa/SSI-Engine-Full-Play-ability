/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:9802
 * Ghidra name: FUN_2000_9802
 * Linear address: 0x29802
 * Original GAME.OVR file offset: 169994
 * Body addresses: 188
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_9802(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  char *local_8;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar3 = (int)param_1;
  iVar2 = (uint)*(byte *)(iVar3 + 0x2e) * 9;
  _local_8 = (char *)CONCAT22(unaff_DS,(undefined *)&DAT_0000_536e + iVar2);
  cVar1 = *_local_8;
  iVar4 = (int)param_2;
  uVar6 = (undefined2)((ulong)param_2 >> 0x10);
  if (cVar1 == '\x01') {
    *(char *)(iVar4 + 0xd9) =
         *(char *)(iVar4 + 0xd9) +
         ((undefined *)&DAT_0000_5370)[iVar2] + -0x32 + *(char *)(iVar3 + 0x32);
    *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 0xc0;
    if (*(char *)(iVar3 + 0x2e) == '\x18') {
      *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 0x20;
    }
  }
  else if (cVar1 == '\x03') {
    *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 8;
  }
  else if (cVar1 == '\x04') {
    *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 0x80;
  }
  else if (cVar1 == '\a') {
    *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 0x10;
  }
  return;
}


