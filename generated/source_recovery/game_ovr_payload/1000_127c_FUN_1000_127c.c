/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:127c
 * Ghidra name: FUN_1000_127c
 * Linear address: 0x1127C
 * Original GAME.OVR file offset: 70276
 * Body addresses: 80
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_127c(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  
  uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
  iVar3 = (int)*(undefined4 *)0x57fb;
  iVar1 = *(int *)(iVar3 + 0xeb);
  iVar3 = *(int *)(iVar3 + 0xed);
  if ((iVar1 != 0 || iVar3 != 0) &&
     (iVar1 = (uint)*(byte *)(iVar1 + 0x2e) * 9, ((undefined *)&DAT_0000_5370)[iVar1] == '\0')) {
    cVar2 = FUN_0000_09b5(CONCAT11((char)((uint)iVar1 >> 8),0x32));
    if (cVar2 != '\0') {
      *(undefined1 *)0x72c6 = 0;
    }
  }
  return;
}


