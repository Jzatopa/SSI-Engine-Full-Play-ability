/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c03d
 * Ghidra name: FUN_2000_c03d
 * Linear address: 0x2C03D
 * Original GAME.OVR file offset: 180293
 * Body addresses: 91
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_c03d(void)

{
  undefined1 uVar1;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  
  if (*(char *)0x535e == '\0') {
    FUN_2000_c000();
    FUN_0000_72a2();
    *(undefined1 *)0x535e = 1;
    uVar1 = *(undefined1 *)0x50d2;
    *(undefined1 *)0x50d2 = 0;
    FUN_0000_13b5(0x602,CONCAT11(extraout_AH,5),CONCAT11(extraout_AH,1));
    *(undefined1 *)0x50d2 = uVar1;
    FUN_0000_444d(0x139,0x5364);
    FUN_0000_7329(0x21a);
  }
  return;
}


