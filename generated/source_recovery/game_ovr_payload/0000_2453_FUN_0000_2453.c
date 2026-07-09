/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2453
 * Ghidra name: FUN_0000_2453
 * Linear address: 0x02453
 * Original GAME.OVR file offset: 9307
 * Body addresses: 290
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_2453(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 unaff_DS;
  undefined2 uVar7;
  undefined2 uVar8;
  
  if (*(char *)0x8c39 == '\0') {
    uVar2 = FUN_0000_232e(&stack0xfffe);
    *(undefined1 *)0x8c39 = uVar2;
  }
  *(undefined1 *)0x4439 = *(undefined1 *)0x4438;
  *(undefined1 *)0x443d = 0;
  uVar2 = *(undefined1 *)0x8c3f;
  *(undefined1 *)0x8c3f = 0;
  *(int *)0x4432 = *(int *)0x4432 + 1;
  if ((*(char *)0x8c39 == '\0') && (*(char *)0x8c26 == '\0')) {
    *(undefined1 *)0x9ed7 = 1;
    func_0x000003e5();
  }
  else {
    uVar4 = (uint)*(byte *)0x7369;
    uVar5 = (uint)*(byte *)0x736a;
    uVar6 = (uint)*(byte *)0x736b;
    bVar3 = FUN_0000_06ee();
    if (bVar3 < *(byte *)((int)*(undefined4 *)0x441c + 0x2c1)) {
      *(byte *)((int)*(undefined4 *)0x441c + 0x2c1) = bVar3;
    }
    if (*(char *)0x8c26 != '\0') {
      FUN_0000_23a8(&stack0xfffe,1);
    }
    FUN_0000_0415(0x6b,uVar6,uVar5,uVar4);
    *(undefined1 *)0x9ed7 = 1;
    if (*(char *)0x8c26 != '\0') {
      FUN_0000_23a8(&stack0xfffe,(uint)extraout_AH << 8);
    }
    func_0x000003e5(0x3f);
    *(undefined1 *)0x8c26 = 0;
  }
  *(undefined1 *)0x4438 = *(undefined1 *)0x4439;
  *(byte *)((int)*(undefined4 *)0x441c + 0x2ca) = *(byte *)((int)*(undefined4 *)0x441c + 0x2ca) & 1;
  uVar8 = 0x8c18;
  uVar7 = 2;
  FUN_0000_e6d2(0);
  *(undefined1 *)0x8c33 = 0;
  if (*(char *)0x4438 == '\x03') {
    uVar1 = *(undefined1 *)0x744e;
    *(undefined1 *)0x744e = 0xff;
    FUN_0000_0bb9(CONCAT11(extraout_AH_00,uVar1));
    func_0x00000bbe(0xb8);
    FUN_0000_0775(0xb8);
  }
  else {
    *(undefined1 *)0x744e = 0xff;
    FUN_0000_0a2d(0xcc0,uVar7,uVar8);
  }
  *(undefined1 *)0x8c3f = uVar2;
  return;
}


