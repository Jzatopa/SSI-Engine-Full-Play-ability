/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0a32
 * Ghidra name: FUN_0000_0a32
 * Linear address: 0x00A32
 * Original GAME.OVR file offset: 2618
 * Body addresses: 53
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Instruction at (ram,0x00000a86) overlaps instruction at (ram,0x00000a85)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0000_0a32(void)

{
  byte *pbVar1;
  undefined2 uVar2;
  byte bVar3;
  uint in_AX;
  undefined1 *puVar4;
  int in_DX;
  byte *in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  int iVar5;
  undefined2 unaff_ES;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uStack0002;
  
  puVar4 = (undefined1 *)(in_AX + 0x614);
  *(int *)0x634 = (*(int *)0x634 - (int)puVar4) - (uint)(0xf9eb < in_AX);
  if ((undefined1 *)*(uint *)0x654 == puVar4) {
LAB_0000_0a48:
    puVar4 = (undefined1 *)((uint)puVar4 & 0xff);
  }
  else if ((int)*(uint *)0x654 - (int)puVar4 < 0) {
    *(undefined2 *)(in_AX + 0x612) = unaff_ES;
    in_DX = (int)&stack0x0000 >> 0xf;
    puVar4 = (undefined1 *)register0x00000010;
    goto LAB_0000_0a48;
  }
  bVar3 = (byte)puVar4 | *in_BX;
  *in_BX = bVar3;
  *(byte *)0xaf07 = bVar3;
  out(7,bVar3);
  pbVar1 = (byte *)(unaff_BP + -1 + unaff_SI + 8);
  *pbVar1 = *pbVar1 | (byte)in_DX;
  pbVar1 = (byte *)(unaff_BP + -1 + unaff_SI + 8);
  *pbVar1 = *pbVar1 | 0xd3;
  if (*pbVar1 == 0) {
    if (*(char *)0x3dde == '\0') goto code_r0x00000aa3;
  }
  else {
    *(uint *)(in_BX + unaff_SI) = *(uint *)(in_BX + unaff_SI) | 0xff96;
    in_BX[unaff_DI + -0x4cf8] = in_BX[unaff_DI + -0x4cf8] | 0xd3;
    ((undefined *)&DAT_0000_ff89)[unaff_DI] = ((undefined *)&DAT_0000_ff89)[unaff_DI] | (byte)in_DX;
    in(0x80);
    *(char *)(unaff_SI + 0x13) = *(char *)(unaff_SI + 0x13) + (char)((uint)in_DX >> 8);
  }
  uVar2 = *(undefined2 *)0x536c;
  *(undefined2 *)0x57fb = *(undefined2 *)0x536a;
  *(undefined2 *)0x57fd = uVar2;
  *(undefined1 *)0x3dde = 0;
code_r0x00000aa3:
  uStack0002 = 0x8c18;
  FUN_0000_e6d2(0);
  *(undefined1 *)0x8c33 = 0;
  *(undefined1 *)0x3ddc = 1;
  *(int *)0x4432 = *(int *)0x4432 + 1;
  while (*(int *)0x7640 != 0 || *(int *)0x7642 != 0) {
    uVar6 = (undefined2)((ulong)*(undefined4 *)0x7640 >> 0x10);
    iVar5 = (int)*(undefined4 *)0x7640;
    uVar2 = *(undefined2 *)(iVar5 + 4);
    *(undefined2 *)0x7644 = *(undefined2 *)(iVar5 + 2);
    *(undefined2 *)0x7646 = uVar2;
    FUN_0000_ce54(0xcc0,6,*(undefined2 *)0x7640,*(undefined2 *)0x7642);
    uVar2 = *(undefined2 *)0x7646;
    *(undefined2 *)0x7640 = *(undefined2 *)0x7644;
    *(undefined2 *)0x7642 = uVar2;
  }
  *(undefined1 *)0x6879 = 0x11;
  *(undefined1 *)0x6878 = 1;
  *(undefined1 *)0x8c32 = 0;
  return;
}


