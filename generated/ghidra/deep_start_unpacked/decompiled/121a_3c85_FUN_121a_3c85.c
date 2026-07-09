
undefined4 FUN_121a_3c85(undefined1 param_1,byte param_2,uint param_3,uint param_4)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  
  uVar5 = param_3;
  if ((int)param_3 < (int)param_4) {
    LOCK();
    param_3 = param_4;
    UNLOCK();
    param_4 = uVar5;
  }
  out(0x3ce,5);
  out(0x3cf,0);
  out(0x3ce,1);
  out(0x3cf,0xf);
  out(0x3ce,0);
  out(0x3cf,param_1);
  out(0x3ce,3);
  out(0x3cf,0);
  out(0x3c4,2);
  out(0x3c5,0xf);
  puVar3 = (undefined1 *)((uint)param_2 * 0x28 + (param_4 >> 3));
  if ((param_4 & 7) != 0) {
    bVar7 = (byte)(0xff >> (sbyte)(param_4 & 7));
    param_4 = (param_4 & 0xfff8) + 8;
    if (param_3 < param_4) {
      bVar7 = bVar7 & (byte)(0xff << (((char)param_4 - (char)param_3) - 1U & 0x1f));
    }
    out(0x3ce,8);
    out(0x3cf,bVar7);
    puVar1 = puVar3;
    puVar2 = puVar3;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar1;
  }
  iVar4 = param_3 - param_4;
  if (-1 < iVar4) {
    uVar5 = iVar4 + 1;
    uVar6 = uVar5 >> 3;
    bVar7 = (byte)(uVar5 >> 0xb);
    out(0x3ce,8);
    iVar4 = CONCAT11(bVar7,0xff);
    out(0x3cf,0xff);
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      puVar1 = puVar3;
      puVar3 = puVar3 + 1;
      *puVar1 = 0xff;
    }
    if ((uVar5 & 7) != 0) {
      out(0x3ce,8);
      out(0x3cf,(char)(0xff00 >> ((byte)uVar5 & 7)));
      iVar4 = CONCAT11(bVar7,*puVar3);
      *puVar3 = *puVar3;
    }
  }
  out(0x3ce,1);
  out(0x3cf,0);
  out(0x3ce,8);
  out(0x3cf,0xff);
  return CONCAT22(0x3cf,CONCAT11((char)((uint)iVar4 >> 8),0xff));
}


