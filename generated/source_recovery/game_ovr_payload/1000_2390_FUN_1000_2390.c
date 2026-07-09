/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:2390
 * Ghidra name: FUN_1000_2390
 * Linear address: 0x12390
 * Original GAME.OVR file offset: 74648
 * Body addresses: 219
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_2390(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  iVar4 = (int)param_1;
  bVar1 = *(byte *)(iVar4 + 0xdb);
  iVar2 = *(int *)(iVar4 + 0xeb);
  iVar3 = *(int *)(iVar4 + 0xed);
  if (iVar2 == 0 && iVar3 == 0) {
    *(undefined1 *)0x72c8 = *(undefined1 *)(iVar4 + 0x3b);
  }
  else {
    *(undefined1 *)0x72c8 = ((undefined *)&DAT_0000_536f)[(uint)*(byte *)(iVar2 + 0x2e) * 9];
  }
  FUN_0000_0981();
  *(undefined1 *)0x72c8 = (char)((uint)*(byte *)0x72c8 + (uint)(*(byte *)0x74b9 & 1) >> 1);
  if (((iVar2 != 0 || iVar3 != 0) &&
      (((undefined *)&DAT_0000_5370)[(uint)*(byte *)(iVar2 + 0x2e) * 9] != '\0')) &&
     (*(byte *)(iVar2 + 0x38) < *(byte *)0x72c8)) {
    *(undefined1 *)0x72c8 = *(undefined1 *)(iVar2 + 0x38);
  }
  if ((*(char *)((int)*(undefined4 *)(iVar4 + 0xf3) + 6) == '\0') || (*(byte *)0x72c8 < bVar1)) {
    *(undefined1 *)(iVar4 + 0xdb) = *(undefined1 *)0x72c8;
  }
  else {
    *(byte *)(iVar4 + 0xdb) = bVar1;
  }
  return;
}


