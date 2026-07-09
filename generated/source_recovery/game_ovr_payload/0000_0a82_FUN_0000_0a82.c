/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0a82
 * Ghidra name: FUN_0000_0a82
 * Linear address: 0x00A82
 * Original GAME.OVR file offset: 2698
 * Body addresses: 138
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_0a82(void)

{
  undefined2 uVar1;
  undefined2 in_DX;
  int unaff_SI;
  int unaff_DI;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  
  ((undefined *)&DAT_0000_ff89)[unaff_DI] = ((undefined *)&DAT_0000_ff89)[unaff_DI] | (byte)in_DX;
  in(0x80);
  *(char *)(unaff_SI + 0x13) = *(char *)(unaff_SI + 0x13) + (char)((uint)in_DX >> 8);
  uVar4 = *(undefined2 *)0x536c;
  *(undefined2 *)0x57fb = *(undefined2 *)0x536a;
  *(undefined2 *)0x57fd = uVar4;
  *(undefined1 *)0x3dde = 0;
  uVar5 = 0x8c18;
  uVar4 = 2;
  FUN_0000_e6d2(0);
  *(undefined1 *)0x8c33 = 0;
  *(undefined1 *)0x3ddc = 1;
  *(int *)0x4432 = *(int *)0x4432 + 1;
  while (*(int *)0x7640 != 0 || *(int *)0x7642 != 0) {
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x7640 >> 0x10);
    iVar2 = (int)*(undefined4 *)0x7640;
    uVar1 = *(undefined2 *)(iVar2 + 4);
    *(undefined2 *)0x7644 = *(undefined2 *)(iVar2 + 2);
    *(undefined2 *)0x7646 = uVar1;
    FUN_0000_ce54(0xcc0,6,*(undefined2 *)0x7640,*(undefined2 *)0x7642,uVar4,uVar5);
    uVar1 = *(undefined2 *)0x7646;
    *(undefined2 *)0x7640 = *(undefined2 *)0x7644;
    *(undefined2 *)0x7642 = uVar1;
  }
  *(undefined1 *)0x6879 = 0x11;
  *(undefined1 *)0x6878 = 1;
  *(undefined1 *)0x8c32 = 0;
  return;
}


