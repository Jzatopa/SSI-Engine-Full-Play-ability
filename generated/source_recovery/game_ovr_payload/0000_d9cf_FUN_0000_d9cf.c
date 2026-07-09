/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:d9cf
 * Ghidra name: FUN_0000_d9cf
 * Linear address: 0x0D9CF
 * Original GAME.OVR file offset: 55767
 * Body addresses: 54
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_d9cf(void)

{
  undefined2 in_AX;
  undefined1 uVar1;
  undefined1 extraout_AH;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar1 = (undefined1)((uint)in_AX >> 8);
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 6) = 0;
  if ((((undefined *)&DAT_0000_fffa)[unaff_BP] != '\0') && (*(char *)(unaff_BP + 10) != '\0')) {
    FUN_0000_d3bf();
    uVar1 = extraout_AH;
  }
  *(undefined1 *)(unaff_BP + -1) = ((undefined *)&DAT_0000_fffa)[unaff_BP];
  return CONCAT11(uVar1,*(undefined1 *)(unaff_BP + -1));
}


