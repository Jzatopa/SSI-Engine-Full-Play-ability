/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:0ddf
 * Ghidra name: FUN_0000_0ddf
 * Linear address: 0x00DDF
 * Original GAME.OVR file offset: 3559
 * Body addresses: 7
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_0ddf(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int unaff_BP;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_ZF;
  
  while (!(bool)in_ZF) {
    uVar5 = (undefined2)((ulong)*(undefined4 *)(unaff_BP + -4) >> 0x10);
    iVar4 = (int)*(undefined4 *)(unaff_BP + -4);
    uVar3 = *(undefined2 *)(iVar4 + 0x101);
    *(undefined2 *)(unaff_BP + -4) = *(undefined2 *)(iVar4 + 0xff);
    *(undefined2 *)(unaff_BP + -2) = uVar3;
    *(char *)(unaff_BP + -7) = *(char *)(unaff_BP + -7) + '\x01';
    if ((byte)((undefined *)&DAT_0000_fffa)[unaff_BP] <= *(byte *)(unaff_BP + -7)) break;
    in_ZF = *(int *)(unaff_BP + -4) == 0 && *(int *)(unaff_BP + -2) == 0;
  }
  if (*(int *)(unaff_BP + -4) == 0 && *(int *)(unaff_BP + -2) == 0) {
    *(undefined1 *)0x8c3c = 1;
  }
  else {
    uVar3 = *(undefined2 *)(unaff_BP + -2);
    *(undefined2 *)0x57fb = *(undefined2 *)(unaff_BP + -4);
    *(undefined2 *)0x57fd = uVar3;
    *(undefined1 *)0x8c3c = 0;
  }
  if (((*(char *)(unaff_BP + -8) != '\0') && (*(char *)0x8c22 != '\0')) && (*(char *)0x8c23 != '\0')
     ) {
    uVar1 = *(uint *)0x536a;
    if ((*(int *)0x536c == *(int *)0x57fd) && (uVar1 == *(uint *)0x57fb)) {
      *(undefined1 *)0x3dde = 0;
    }
    uVar2 = uVar1 & 0xff00;
    uVar3 = CONCAT11((char)(uVar1 >> 8),1);
    FUN_0000_065a();
    FUN_0000_0b1a(99,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar3,uVar2);
    *(undefined1 *)0x8c22 = 0;
    *(undefined1 *)0x8c23 = 0;
  }
  return;
}


