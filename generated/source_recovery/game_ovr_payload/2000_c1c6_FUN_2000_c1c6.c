/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c1c6
 * Ghidra name: FUN_2000_c1c6
 * Linear address: 0x2C1C6
 * Original GAME.OVR file offset: 180686
 * Body addresses: 456
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_c1c6(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 unaff_DS;
  byte *local_a;
  byte local_6;
  
  func_0x0000b5d1();
  FUN_0000_3721(0xb58,*(undefined2 *)0x744a,*(undefined2 *)0x744c,1,0x11);
  FUN_0000_13ba(0x101);
  local_6 = 0;
  while( true ) {
    iVar1 = (((uint)(byte)((undefined *)&DAT_0000_26a8)[local_6] +
             (uint)*(byte *)((int)*(undefined4 *)0x5360 + 0x36)) %
             (uint)(byte)((undefined *)&DAT_0000_269b)[local_6] +
            (uint)(byte)((undefined *)&DAT_0000_2696)[local_6]) * 3;
    _local_a = (byte *)CONCAT22(unaff_DS,(undefined1 *)(iVar1 + 0x25e8));
    *(undefined1 *)((int)*(undefined4 *)0x5360 + (uint)local_6 * 2) = *_local_a;
    *(undefined1 *)((int)*(undefined4 *)0x5360 + (uint)local_6 * 2 + 1) =
         *(undefined1 *)(iVar1 + 0x25e9);
    FUN_0000_13ba(CONCAT11((char)(*(byte *)(iVar1 + 0x25ea) + 0x128 >> 8),1));
    if (local_6 == 4) break;
    local_6 = local_6 + 1;
  }
  local_6 = 0;
  while( true ) {
    iVar1 = ((uint)*(byte *)0x269a +
            ((uint)*(byte *)0x26ac + (uint)(byte)((undefined *)&DAT_0000_26a0)[local_6] +
            (uint)*(byte *)((int)*(undefined4 *)0x5360 + 0x36)) % (uint)*(byte *)0x269f) * 3;
    _local_a = (byte *)CONCAT22(unaff_DS,(byte *)(iVar1 + 0x25e8));
    *(byte *)((int)*(undefined4 *)0x5360 + (local_6 + 5) * 2) = *_local_a;
    *(undefined1 *)((int)*(undefined4 *)0x5360 + (local_6 + 5) * 2 + 1) =
         *(undefined1 *)(iVar1 + 0x25e9);
    iVar2 = *_local_a + 0x11;
    iVar3 = *(byte *)(iVar1 + 0x25e9) + 1;
    uVar4 = *(byte *)(iVar1 + 0x25ea) + 0x10c;
    uVar5 = uVar4 & 0xff00;
    FUN_0000_13ba(CONCAT11((char)(uVar4 >> 8),1));
    if (local_6 == 7) break;
    local_6 = local_6 + 1;
  }
  *(undefined1 *)0x5368 = 0xff;
  FUN_2000_bf38(uVar5,uVar4,iVar3,iVar2);
  FUN_0000_b5b0(0x139);
  return;
}


