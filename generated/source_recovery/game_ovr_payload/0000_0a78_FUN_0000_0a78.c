/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0a78
 * Ghidra name: FUN_0000_0a78
 * Linear address: 0x00A78
 * Original GAME.OVR file offset: 2688
 * Body addresses: 9
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x00000a86) overlaps instruction at (ram,0x00000a85)
    */

void __cdecl16far FUN_0000_0a78(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  byte in_CH;
  undefined2 in_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar5;
  undefined2 uVar6;
  
  pbVar1 = (byte *)(unaff_BP + unaff_SI + 8);
  *pbVar1 = *pbVar1 | in_CH;
  if (*pbVar1 == 0) {
    if (*(char *)0x3dde == '\0') goto code_r0x00000aa3;
  }
  else {
    *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) | 0xff96;
    pbVar1 = (byte *)(in_BX + unaff_DI + -0x4cf8);
    *pbVar1 = *pbVar1 | in_CH;
    ((undefined *)&DAT_0000_ff89)[unaff_DI] = ((undefined *)&DAT_0000_ff89)[unaff_DI] | (byte)in_DX;
    in(0x80);
    *(char *)(unaff_SI + 0x13) = *(char *)(unaff_SI + 0x13) + (char)((uint)in_DX >> 8);
  }
  uVar5 = *(undefined2 *)0x536c;
  *(undefined2 *)0x57fb = *(undefined2 *)0x536a;
  *(undefined2 *)0x57fd = uVar5;
  *(undefined1 *)0x3dde = 0;
code_r0x00000aa3:
  uVar6 = 0x8c18;
  uVar5 = 2;
  FUN_0000_e6d2(0);
  *(undefined1 *)0x8c33 = 0;
  *(undefined1 *)0x3ddc = 1;
  *(int *)0x4432 = *(int *)0x4432 + 1;
  while (*(int *)0x7640 != 0 || *(int *)0x7642 != 0) {
    uVar4 = (undefined2)((ulong)*(undefined4 *)0x7640 >> 0x10);
    iVar3 = (int)*(undefined4 *)0x7640;
    uVar2 = *(undefined2 *)(iVar3 + 4);
    *(undefined2 *)0x7644 = *(undefined2 *)(iVar3 + 2);
    *(undefined2 *)0x7646 = uVar2;
    FUN_0000_ce54(0xcc0,6,*(undefined2 *)0x7640,*(undefined2 *)0x7642,uVar5,uVar6);
    uVar2 = *(undefined2 *)0x7646;
    *(undefined2 *)0x7640 = *(undefined2 *)0x7644;
    *(undefined2 *)0x7642 = uVar2;
  }
  *(undefined1 *)0x6879 = 0x11;
  *(undefined1 *)0x6878 = 1;
  *(undefined1 *)0x8c32 = 0;
  return;
}


