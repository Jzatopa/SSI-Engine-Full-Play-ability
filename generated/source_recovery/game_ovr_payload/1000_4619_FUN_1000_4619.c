/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:4619
 * Ghidra name: FUN_1000_4619
 * Linear address: 0x14619
 * Original GAME.OVR file offset: 83489
 * Body addresses: 131
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

byte __stdcall16far FUN_1000_4619(undefined2 param_1,undefined2 param_2)

{
  int *piVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined2 local_9;
  undefined2 uStack_7;
  undefined1 local_4;
  
  local_4 = 0;
  uStack_7 = *(int *)0x5801;
  local_9 = *(int *)0x57ff;
  while (local_9 != 0 || uStack_7 != 0) {
    cVar2 = func_0x00000a14(unaff_CS,param_1,param_2);
    if ((cVar2 == *(char *)(local_9 + 0xd6)) && (*(char *)(local_9 + 0xd5) != '\0')) {
      uVar4 = func_0x00000a50(0x99,local_9,uStack_7);
      bVar3 = (byte)((uVar4 & 0xff) >> 1);
      if (local_4 < bVar3) {
        local_4 = bVar3;
      }
    }
    unaff_CS = 0x99;
    piVar1 = (int *)(local_9 + 0xff);
    uStack_7 = *(int *)(local_9 + 0x101);
    local_9 = *piVar1;
  }
  return local_4;
}


