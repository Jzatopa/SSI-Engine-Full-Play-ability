/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:0b9d
 * Ghidra name: FUN_1000_0b9d
 * Linear address: 0x10B9D
 * Original GAME.OVR file offset: 68517
 * Body addresses: 580
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_1000_0b9d(void)

{
  undefined2 unaff_DS;
  undefined2 uVar1;
  undefined2 uVar2;
  
  *(undefined1 *)0x4417 = 1;
  FUN_0000_e6d2(0);
  FUN_0000_e6d2(0x100);
  FUN_0000_e6d2(0x1ff);
  FUN_0000_e6d2(0x100);
  FUN_0000_e6d2(0x400);
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xb6) = 2;
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xe6) = 1;
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xf2) = 0;
  FUN_0000_e6d2(0x400);
  FUN_0000_e6d2(0x200);
  FUN_0000_e6d2(0x2400);
  FUN_0000_e6d2(0);
  *(undefined1 *)0x7369 = 7;
  *(undefined1 *)0x736a = 0xd;
  *(undefined1 *)0x736b = 2;
  uVar2 = 0x74b4;
  uVar1 = 3;
  FUN_0000_e6d2(1);
  *(undefined1 *)0x8d6f = 1;
  *(undefined2 *)0x7372 = 0;
  *(undefined2 *)0x7374 = 1;
  *(undefined1 *)0x401c = 2;
  while( true ) {
    *(undefined2 *)((uint)*(byte *)0x401c * 4 + 0x736e) = 0xffff;
    *(undefined2 *)((uint)*(byte *)0x401c * 4 + 0x7370) = 0xffff;
    if (*(char *)0x401c == '\x03') break;
    *(char *)0x401c = *(char *)0x401c + '\x01';
  }
  *(undefined1 *)0x4440 = 0;
  *(undefined1 *)0x4448 = 1;
  *(undefined1 *)0x4441 = 0;
  *(undefined2 *)0x4442 = 0;
  *(undefined2 *)0x57ff = 0;
  *(undefined2 *)0x5801 = 0;
  *(undefined2 *)0x57fb = 0;
  *(undefined2 *)0x57fd = 0;
  *(undefined2 *)0x57f7 = 0;
  *(undefined2 *)0x57f9 = 0;
  *(undefined2 *)0x4432 = 0x8000;
  *(undefined1 *)((int)*(undefined4 *)0x4418 + 0xfc) = 4;
  *(undefined1 *)0x50d2 = 1;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x312) = *(undefined1 *)0x50d2;
  *(undefined1 *)0x50d3 = 1;
  *(undefined1 *)0x7368 = 0;
  *(undefined2 *)0x9f38 = 1;
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x33e) = 0;
  *(undefined2 *)0x7455 = 1;
  *(undefined1 *)0x8c26 = 0;
  *(undefined1 *)0x74a8 = 0;
  *(undefined1 *)0x8c31 = 0;
  *(undefined1 *)0x8c32 = 0;
  *(undefined1 *)0x8c33 = 0;
  *(undefined1 *)0x4446 = 0;
  *(undefined1 *)0x50ca = 1;
  *(undefined1 *)0x8c35 = 0;
  *(undefined1 *)0x52d4 = 0;
  *(undefined1 *)0x7436 = 0;
  *(undefined1 *)0x743f = 0;
  *(undefined1 *)0x7448 = 0xff;
  *(undefined1 *)0x7449 = 0xff;
  *(undefined1 *)0x52d5 = 0;
  *(undefined1 *)0x7639 = 0xe8;
  *(code *)FUN_0000_7638 = (code)0xdb;
  *(undefined1 *)0x8c3b = 0;
  *(undefined1 *)0x7516 = 1;
  *(undefined1 *)0x744e = 0xff;
  *(undefined1 *)0x4447 = 0;
  FUN_0000_7329(0xcc0,uVar1,uVar2);
  *(undefined1 *)0x7457 = 1;
  *(undefined1 *)0x4438 = 4;
  *(undefined1 *)0x4439 = 0;
  *(undefined1 *)0x74ac = 0;
  *(undefined1 *)0x8c3e = 0;
  *(undefined1 *)&DAT_0000_7513 = 0;
  *(undefined1 *)0x750e = 0;
  *(undefined1 *)0x8c3f = 0;
  *(undefined1 *)0x8d71 = 0;
  *(undefined1 *)0x7450 = 0;
  *(undefined1 *)0x74b3 = 0;
  *(undefined1 *)0x443d = 0;
  *(undefined1 *)0x67e9 = 0;
  FUN_1000_0202();
  return;
}


