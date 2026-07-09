
void __cdecl16far FUN_1000_7afc(void)

{
  char cVar1;
  undefined2 in_AX;
  byte bVar5;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  
  cVar1 = *(char *)0x4438;
  bVar5 = (byte)((uint)in_AX >> 8);
  if (cVar1 == '\x04') {
    if (*(char *)((int)*(undefined4 *)0x441c + 0x2c9) == -1) {
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c9) = 0;
    }
    else {
      *(undefined1 *)0x74aa = 1;
      uVar2 = CONCAT11(bVar5,*(undefined1 *)0x7369);
      uVar3 = CONCAT11(bVar5,*(undefined1 *)0x736a);
      uVar4 = CONCAT11(bVar5,*(undefined1 *)0x736b);
      cVar1 = func_0x00000d3f();
      if (cVar1 == '\x01') {
        FUN_1000_6651(uVar4,uVar3,uVar2);
      }
      unaff_CS = 0x99;
      FUN_0000_0a32(0xd1);
    }
    func_0x00000baf(unaff_CS);
    FUN_0000_453c(0x742d);
    FUN_0000_453c(0x7432);
    *(undefined1 *)0x742c = 0xff;
    *(undefined1 *)0x7431 = 0xff;
  }
  else if (cVar1 == '\x03') {
    if (*(char *)((int)*(undefined4 *)0x441c + 0x2c9) == -1) {
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c9) = 0;
    }
    else {
      FUN_1000_6712();
      FUN_0000_0a32();
    }
  }
  else if (cVar1 == '\t') {
    if (*(char *)((int)*(undefined4 *)0x441c + 0x2c9) == -1) {
      *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c9) = 0;
    }
    else {
      FUN_1000_7263((uint)bVar5 << 8);
    }
  }
  return;
}


