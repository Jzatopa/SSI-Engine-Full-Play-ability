/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:5742
 * Ghidra name: FUN_0000_5742
 * Linear address: 0x05742
 * Original GAME.OVR file offset: 22346
 * Body addresses: 130
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_5742(int param_1)

{
  undefined1 uVar2;
  int iVar1;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  local_3 = 0;
  *(undefined1 *)0x7817 = 0;
  while( true ) {
    uVar4 = (undefined2)((ulong)*(undefined4 *)(param_1 + 0xc) >> 0x10);
    iVar3 = (int)*(undefined4 *)(param_1 + 0xc) + *(char *)0x7817 * 6;
    uVar2 = (undefined1)((uint)(*(char *)0x7817 * 6) >> 8);
    if ((*(byte *)(iVar3 + 0x3e) < *(byte *)(iVar3 + 0x3d)) &&
       (iVar1 = *(char *)(param_1 + -0xd) * 8, uVar2 = (undefined1)((uint)iVar1 >> 8),
       (byte)((undefined *)&DAT_0000_ffcb)[*(int *)(param_1 + 6) + iVar1 + (int)*(char *)0x7817] <
       *(byte *)(iVar3 + 0x3d))) {
      local_3 = 1;
    }
    if (*(char *)0x7817 == '\a') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
  }
  return CONCAT11(uVar2,local_3);
}


