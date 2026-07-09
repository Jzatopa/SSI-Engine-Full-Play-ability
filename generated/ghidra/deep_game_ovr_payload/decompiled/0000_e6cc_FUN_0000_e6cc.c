
void FUN_0000_e6cc(undefined2 param_1,byte param_2)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined2 uVar4;
  byte bVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  
  FUN_0000_db00(*(undefined1 *)0x8c30,0);
  if ((param_2 == 0x88) || (param_2 == 0x82)) {
    FUN_0000_e6d2(0x407);
  }
  else {
    FUN_0000_e6d2(0x42d);
  }
  uVar4 = 0xcc0;
  if ((param_2 & 0x40) != 0) {
    FUN_0000_e660(&stack0xfffe);
  }
  *(undefined1 *)0x4005 = 0xfe;
  while( true ) {
    *(undefined1 *)0x4004 = 0xfa;
    uVar6 = uVar4;
    while( true ) {
      cVar1 = *"s\x15 at sensor operation!\x0eShip Character\x01" + *(char *)0x4004;
      uVar3 = (int)*"\x15 at sensor operation!\x0eShip Character\x01" + (int)*(char *)0x4005;
      uVar2 = (undefined1)(uVar3 >> 8);
      uVar4 = FUN_0000_e281(CONCAT11(uVar2,6),uVar3,CONCAT11(uVar2,cVar1));
      *(undefined1 *)0x4007 = (char)uVar4;
      bVar5 = (byte)((uint)uVar4 >> 8);
      uVar2 = FUN_0000_e281((uint)bVar5 << 8,CONCAT11(bVar5,(char)uVar3),CONCAT11(bVar5,cVar1));
      *(undefined1 *)0x4006 = uVar2;
      uVar2 = FUN_0000_e281(2,uVar3 & 0xff,cVar1);
      *(undefined1 *)0x4008 = uVar2;
      uVar2 = FUN_0000_e281(4,uVar3 & 0xff,cVar1);
      *(undefined1 *)0x4009 = uVar2;
      FUN_0000_e2f5(&stack0xfffe);
      FUN_0000_e3ab(&stack0xfffe);
      FUN_0000_e3ed(&stack0xfffe);
      uVar4 = 0xd1;
      uVar3 = func_0x00000d44(uVar6,uVar3 & 0xff,cVar1);
      *(undefined1 *)0x400d = (char)(uVar3 & 0xff40);
      FUN_0000_dc7e(0xd1,CONCAT11((char)((uVar3 & 0xff40) >> 8),param_2));
      if (*(char *)0x4004 == '\x06') break;
      *(char *)0x4004 = *(char *)0x4004 + '\x01';
      uVar6 = uVar4;
    }
    if (*(char *)0x4005 == '\x02') break;
    *(char *)0x4005 = *(char *)0x4005 + '\x01';
  }
  FUN_0000_db22();
  return;
}


