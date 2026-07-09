
ulong __stdcall16far FUN_1000_d0f8(char param_1)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  undefined2 unaff_DS;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined2 local_6;
  undefined2 local_4;
  
  uVar5 = CONCAT22(local_4,local_6);
  bVar1 = ((undefined *)&DAT_0000_7755)[param_1];
  cVar2 = ((undefined *)&DAT_0000_7715)[param_1];
  cVar3 = *(char *)(param_1 + 0x76d5);
  if (cVar3 == '\0') {
    uVar5 = (ulong)bVar1;
  }
  else if (cVar3 == '\x01') {
    uVar5 = FUN_1000_dd22(CONCAT11(cVar2,1),CONCAT11(cVar2,bVar1));
  }
  else if ((cVar3 == '\x02') || (cVar3 == -0x7f)) {
    uVar4 = FUN_1000_d677(CONCAT11(param_1 >> 7,cVar2),CONCAT11(param_1 >> 7,bVar1));
    uVar5 = (ulong)uVar4;
  }
  else if ((cVar3 == '\x03') || (cVar3 == -0x80)) {
    uVar5 = FUN_1000_dd22(CONCAT11(cVar2,2),CONCAT11(cVar2,bVar1));
  }
  else if (cVar3 == '\x04') {
    lVar6 = func_0x0000d612();
    lVar7 = func_0x0000d612(0xcc0);
    uVar5 = lVar6 + lVar7 + CONCAT22((int)cVar2 >> 7,CONCAT11(cVar2,bVar1));
  }
  else if (cVar3 == '\x05') {
    uVar5 = FUN_1000_dd22(CONCAT11(cVar2,4),CONCAT11(cVar2,bVar1));
  }
  return uVar5;
}


