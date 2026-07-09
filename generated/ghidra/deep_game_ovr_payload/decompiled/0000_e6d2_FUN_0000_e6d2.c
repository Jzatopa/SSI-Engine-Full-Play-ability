
void __stdcall16far FUN_0000_e6d2(void)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  byte bVar6;
  undefined1 extraout_AH;
  uint uVar5;
  int unaff_BP;
  undefined2 uVar7;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_0000_db00(*(undefined1 *)0x8c30,0);
  if ((*(char *)(unaff_BP + 6) == -0x78) || (*(char *)(unaff_BP + 6) == -0x7e)) {
    FUN_0000_e6d2(0x407);
  }
  else {
    FUN_0000_e6d2(0x42d);
  }
  uVar4 = 0xcc0;
  if ((*(byte *)(unaff_BP + 6) & 0x40) != 0) {
    FUN_0000_e660(unaff_BP);
  }
  *(undefined1 *)0x4005 = 0xfe;
  while( true ) {
    *(undefined1 *)0x4004 = 0xfa;
    uVar7 = uVar4;
    while( true ) {
      *(char *)(unaff_BP + -1) =
           *"s\x15 at sensor operation!\x0eShip Character\x01" + *(char *)0x4004;
      cVar1 = *(char *)0x4005;
      cVar2 = *"\x15 at sensor operation!\x0eShip Character\x01";
      *(undefined1 *)(unaff_BP + -2) = (char)((int)cVar2 + (int)cVar1);
      uVar3 = (undefined1)((uint)((int)cVar2 + (int)cVar1) >> 8);
      uVar4 = FUN_0000_e281(CONCAT11(uVar3,6),CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -2)),
                            CONCAT11(uVar3,*(undefined1 *)(unaff_BP + -1)));
      *(undefined1 *)0x4007 = (char)uVar4;
      bVar6 = (byte)((uint)uVar4 >> 8);
      uVar3 = FUN_0000_e281((uint)bVar6 << 8,CONCAT11(bVar6,*(undefined1 *)(unaff_BP + -2)),
                            CONCAT11(bVar6,*(undefined1 *)(unaff_BP + -1)));
      *(undefined1 *)0x4006 = uVar3;
      uVar3 = FUN_0000_e281(2,*(undefined1 *)(unaff_BP + -2),*(undefined1 *)(unaff_BP + -1));
      *(undefined1 *)0x4008 = uVar3;
      uVar3 = FUN_0000_e281(4,*(undefined1 *)(unaff_BP + -2),*(undefined1 *)(unaff_BP + -1));
      *(undefined1 *)0x4009 = uVar3;
      FUN_0000_e2f5(unaff_BP);
      FUN_0000_e3ab(unaff_BP);
      FUN_0000_e3ed(unaff_BP);
      uVar4 = 0xd1;
      uVar5 = func_0x00000d44(uVar7,CONCAT11(extraout_AH,*(undefined1 *)(unaff_BP + -2)),
                              CONCAT11(extraout_AH,*(undefined1 *)(unaff_BP + -1)));
      *(undefined1 *)0x400d = (char)(uVar5 & 0xff40);
      FUN_0000_dc7e(0xd1,CONCAT11((char)((uVar5 & 0xff40) >> 8),*(undefined1 *)(unaff_BP + 6)));
      if (*(char *)0x4004 == '\x06') break;
      *(char *)0x4004 = *(char *)0x4004 + '\x01';
      uVar7 = uVar4;
    }
    if (*(char *)0x4005 == '\x02') break;
    *(char *)0x4005 = *(char *)0x4005 + '\x01';
  }
  FUN_0000_db22();
  return;
}


