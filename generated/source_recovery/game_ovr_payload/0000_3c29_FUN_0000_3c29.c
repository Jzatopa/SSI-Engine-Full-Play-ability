/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:3c29
 * Ghidra name: FUN_0000_3c29
 * Linear address: 0x03C29
 * Original GAME.OVR file offset: 15409
 * Body addresses: 242
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_3c29(void)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 extraout_AH;
  undefined2 unaff_CS;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  do {
    func_0x00000baf(unaff_CS);
    *(undefined1 *)0x743f = 0;
    *(undefined1 *)0x7449 = 0xff;
    *(undefined1 *)0x3ddd = 0;
    uVar2 = func_0x00000d44(0xb8,CONCAT11(extraout_AH,*(undefined1 *)0x736a),
                            CONCAT11(extraout_AH,*(undefined1 *)0x7369));
    *(undefined1 *)0x736d = uVar2;
    uVar3 = 0xd1;
    uVar2 = FUN_0000_0d3a(0xd1,*(undefined1 *)0x736b,*(undefined1 *)0x736a,*(undefined1 *)0x7369);
    *(undefined1 *)0x736c = uVar2;
    *(undefined1 *)0x8c38 = 1;
    *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2d5) = 0;
    uVar1 = *(undefined2 *)0x57fd;
    *(undefined2 *)0x536a = *(undefined2 *)0x57fb;
    *(undefined2 *)0x536c = uVar1;
    FUN_0000_3bdd(*(undefined2 *)0x4430);
    if (*(char *)0x3ddd == '\0') {
      *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf2) = *(undefined1 *)0x8c30;
    }
    unaff_CS = uVar3;
    if (*(char *)0x3ddd == '\0') {
      if ((((*(char *)0x4439 != '\x04') || (*(char *)0x4438 == '\x04')) && (*(char *)0x3ddf != '\0')
          ) || ((*(char *)0x4439 == '\x04' && (*(char *)0x4438 == '\x04')))) {
        uVar3 = 0xb5;
        FUN_0000_0b75(0xd1);
      }
      *(undefined1 *)0x3ddd = 0;
      FUN_0000_3bdd(*(undefined2 *)0x4428);
      unaff_CS = uVar3;
      if ((*(char *)0x3ddd == '\0') &&
         (FUN_0000_3bdd(*(undefined2 *)0x442a), *(char *)0x3ddd == '\0')) {
        uVar1 = *(undefined2 *)0x536c;
        *(undefined2 *)0x57fb = *(undefined2 *)0x536a;
        *(undefined2 *)0x57fd = uVar1;
        unaff_CS = 0xaf;
        FUN_0000_0b1a(uVar3,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
      }
    }
  } while (*(char *)0x3ddd != '\0');
  *(undefined1 *)0x4439 = *(undefined1 *)0x4438;
  return;
}


