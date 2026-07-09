
void __stdcall16far FUN_121a_28a9(byte param_1,byte param_2,uint param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  undefined2 unaff_DS;
  undefined4 local_c;
  char local_6;
  byte local_4;
  
  uVar5 = param_4;
  cVar4 = *(char *)0x44c8;
  if (cVar4 == '\0') {
    if (param_3 < param_4) {
      param_4 = param_3;
      param_3 = uVar5;
    }
    uVar5 = param_4 >> 2;
    bVar1 = *(byte *)((uint)*(byte *)((param_1 & 0xf) + 0xfc6) * 2 + 0x22c3);
    if ((param_2 & 1) == 0) {
      uVar2 = (uint)(param_2 >> 1) * 0x50;
      local_c = (byte *)CONCAT22(CARRY2(uVar2,uVar5 & 0xff) + 0xb800,
                                 (byte *)(uVar2 + (uVar5 & 0xff)));
    }
    else {
      uVar2 = (uint)(param_2 >> 1) * 0x50;
      local_c = (byte *)CONCAT22(CARRY2(uVar2,uVar5 & 0xff) + 0xba00,
                                 (byte *)(uVar2 + (uVar5 & 0xff)));
    }
    if ((param_4 & 3) != 0) {
      local_4 = (byte)(0xff >> (sbyte)((param_4 & 3) << 1));
      param_4 = ((uVar5 & 0xff) + 1) * 4;
      if (param_3 < param_4) {
        local_4 = local_4 & (byte)(0xff << (('\x03' - ((byte)param_3 & 3)) * '\x02' & 0x1f));
      }
      *local_c = (local_4 ^ 0xff) & *local_c | local_4 & bVar1;
      local_c = (byte *)CONCAT22(local_c._2_2_ + (uint)((byte *)0xfffe < (byte *)local_c),
                                 (byte *)local_c + 1);
    }
    cVar4 = (char)((param_3 + 1) - param_4 >> 2);
    if (-1 < cVar4) {
      iVar7 = (int)((ulong)local_c >> 0x10);
      pbVar6 = (byte *)local_c;
      FUN_1cc0_1ad2(CONCAT11(cVar4 >> 7,bVar1),(int)cVar4,pbVar6,iVar7);
      if ((param_3 & 3) != 3) {
        uVar5 = (uint)cVar4;
        local_c = (byte *)CONCAT22(((int)uVar5 >> 0xf) + iVar7 + (uint)CARRY2(uVar5,(uint)pbVar6),
                                   pbVar6 + uVar5);
        bVar3 = (byte)(0xff << (('\x03' - ((byte)param_3 & 3)) * '\x02' & 0x1f));
        *local_c = (bVar3 ^ 0xff) & *local_c | bVar3 & bVar1;
      }
    }
  }
  else if (cVar4 == '\x01') {
    FUN_121a_3c85(param_1,param_2,param_3,param_4);
  }
  else if (cVar4 == '\x02') {
    uVar5 = param_4 >> 1;
    local_6 = (char)uVar5;
    if ((param_4 & 1) != 0) {
      *(byte *)(uVar5 & 0xff) = *(byte *)(uVar5 & 0xff) & 0xf0 | param_1 & 0xf;
      local_6 = local_6 + '\x01';
    }
    cVar4 = (char)((param_3 - param_4) + 1 >> 1);
    if ('\0' < cVar4) {
      FUN_1cc0_1ad2(CONCAT11(cVar4 >> 7,param_1 | param_1 << 4),(int)cVar4,local_6,
                    *(undefined2 *)((uint)param_2 * 2 + 0x4f3a));
    }
    if ((param_3 & 1) == 0) {
      *(byte *)(uint)(byte)(local_6 + cVar4) =
           *(byte *)(uint)(byte)(local_6 + cVar4) & 0xf | param_1 & 0xf0 | param_1 << 4;
    }
  }
  else if (cVar4 == '\x03') {
    FUN_121a_3e17(param_1,param_2,param_3,param_4);
  }
  return;
}


