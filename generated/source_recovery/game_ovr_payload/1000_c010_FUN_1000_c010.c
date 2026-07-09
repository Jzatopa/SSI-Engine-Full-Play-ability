/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:c010
 * Ghidra name: FUN_1000_c010
 * Linear address: 0x1C010
 * Original GAME.OVR file offset: 114712
 * Body addresses: 178
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - shop_menu (shop), previous candidate, distance 2658 byte(s), source offset 117370
 */

void __cdecl16far FUN_1000_c010(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  undefined1 local_7;
  
  local_7 = 1;
  while( true ) {
    iVar1 = FUN_0000_ce3f(unaff_CS,0x3e);
    *(undefined1 *)0x7817 = *(undefined1 *)(local_7 + 0xd81);
    iVar2 = *(char *)0x7817 * 0x10;
    iVar3 = iVar2 + 0x57f3;
    unaff_CS = 0xcc0;
    FUN_0000_e6af(0x10);
    local_7 = (byte)((uint)(iVar1 + 0x2e) >> 8);
    *(undefined1 *)(iVar2 + 0x582b) = *(undefined1 *)(local_7 + 0xd83);
    uVar4 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar1 = (int)*(undefined4 *)0x57fb;
    uVar5 = *(undefined2 *)(iVar1 + 0xf9);
    *(undefined2 *)(iVar2 + 0x581d) = *(undefined2 *)(iVar1 + 0xf7);
    *(undefined2 *)(iVar2 + 0x581f) = uVar5;
    *(undefined1 *)(iVar2 + 0x581c) = 0;
    uVar5 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar1 = (int)*(undefined4 *)0x57fb;
    *(int *)(iVar1 + 0xf7) = iVar3;
    *(int *)(iVar1 + 0xf9) = iVar3;
    *(byte *)(iVar2 + 0x5827) = *(byte *)(iVar2 + 0x5827) | 0x80;
    if (local_7 == 2) break;
    local_7 = local_7 + 1;
  }
  return;
}


