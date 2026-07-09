/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:d977
 * Ghidra name: FUN_0000_d977
 * Linear address: 0x0D977
 * Original GAME.OVR file offset: 55679
 * Body addresses: 75
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_d977(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint in_AX;
  int unaff_BP;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  ((undefined *)&DAT_0000_74ba)[in_AX & 0xff] = 0;
  *(undefined1 *)(unaff_BP + -0x10) = *(undefined1 *)(unaff_BP + -2);
  if (*(char *)(unaff_BP + -0x10) != '\0') {
    *(undefined1 *)(unaff_BP + -4) = 1;
    while( true ) {
      if (((undefined *)&DAT_0000_74ba)[*(byte *)(unaff_BP + -4)] != '\0') {
        ((undefined *)&DAT_0000_fffa)[unaff_BP] = 1;
      }
      if (*(char *)(unaff_BP + -4) == *(char *)(unaff_BP + -0x10)) break;
      *(char *)(unaff_BP + -4) = *(char *)(unaff_BP + -4) + '\x01';
    }
  }
  uVar4 = 0;
  if (((undefined *)&DAT_0000_fffa)[unaff_BP] == '\0') {
    *(undefined1 *)(unaff_BP + -2) = 0;
  }
  else {
    ((undefined *)&DAT_0000_fffa)[unaff_BP] = 0;
  }
  while( true ) {
    if (*(char *)(unaff_BP + -3) == '\0') {
      FUN_0000_d9c2();
      return;
    }
    if (((undefined *)&DAT_0000_fffa)[unaff_BP] != '\0') break;
    if (*(char *)(unaff_BP + -2) == '\0') {
      FUN_0000_d9c2();
      return;
    }
    *(char *)(unaff_BP + -3) = *(char *)(unaff_BP + -3) + -1;
    uVar3 = (undefined1)(uVar4 >> 8);
    uVar3 = FUN_0000_09ba(unaff_CS,CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),CONCAT11(uVar3,1))
    ;
    *(undefined1 *)(unaff_BP + -4) = uVar3;
    uVar4 = (uint)*(byte *)(unaff_BP + -4);
    unaff_CS = 0x99;
    if (((undefined *)&DAT_0000_74ba)[uVar4] != '\0') {
      iVar5 = (uint)(byte)((undefined *)&DAT_0000_74ba)[*(byte *)(unaff_BP + -4)] * 4;
      uVar1 = *(undefined2 *)((undefined *)&DAT_0000_7081 + iVar5);
      *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP) =
           *(undefined2 *)((undefined *)&DAT_0000_707f + iVar5);
      *(undefined2 *)(unaff_BP + -9) = uVar1;
      if ((*(char *)(unaff_BP + 10) == '\0') || (*(char *)((int)*(undefined4 *)0x71dc + 6) == '\0'))
      {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_0000_643a(0x99,*(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP),
                            *(undefined2 *)(unaff_BP + -9),*(undefined2 *)(unaff_BP + 0xc),
                            *(undefined2 *)(unaff_BP + 0xe));
      }
      ((undefined *)&DAT_0000_fffa)[unaff_BP] = 1;
      uVar4 = *(uint *)((undefined *)&DAT_0000_fff5 + unaff_BP);
      uVar1 = *(undefined2 *)(unaff_BP + -9);
      uVar2 = *(undefined4 *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0xf3);
      uVar6 = (undefined2)((ulong)uVar2 >> 0x10);
      iVar5 = (int)uVar2;
      *(uint *)(iVar5 + 8) = uVar4;
      *(undefined2 *)(iVar5 + 10) = uVar1;
    }
  }
  FUN_0000_d9c2();
  return;
}


