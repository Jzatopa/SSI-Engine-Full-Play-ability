/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2e9a
 * Ghidra name: FUN_0000_2e9a
 * Linear address: 0x02E9A
 * Original GAME.OVR file offset: 11938
 * Body addresses: 55
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_2e9a(void)

{
  char *pcVar1;
  uint uVar2;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  pcVar1 = (char *)(in_BX + unaff_SI + 0xb);
  *pcVar1 = *pcVar1 + (char)in_BX;
  uVar5 = 3;
  uVar4 = 3;
  uVar3 = 1;
  uVar2 = (uint)*(byte *)0x739d;
  FUN_0000_0ba5();
  FUN_0000_b5b0(0xb8,uVar2,uVar3,uVar4,uVar5);
  *(char *)0x73eb = *(char *)0x73eb + '\x01';
  if (*(byte *)0x73ea < *(byte *)0x73eb) {
    *(undefined1 *)0x73eb = 1;
  }
  FUN_0000_6e3e(0xb58);
  return;
}


