
void __stdcall16far FUN_121a_2b9f(byte param_1,uint param_2,byte param_3,byte param_4)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined2 unaff_DS;
  undefined4 local_d;
  byte local_9;
  byte local_4;
  byte local_3;
  
  bVar2 = param_4;
  cVar1 = *(char *)0x44c8;
  if (cVar1 == '\0') {
    if (param_3 < param_4) {
      param_4 = param_3;
      param_3 = bVar2;
    }
    bVar3 = (byte)(0xc0 >> (sbyte)((param_2 & 3) << 1));
    bVar2 = *(byte *)((uint)*(byte *)((param_1 & 0xf) + 0xfc6) * 2 + 0x22c3);
    uVar5 = param_4 + 1 >> 1;
    local_9 = (byte)uVar5;
    uVar6 = param_2 >> 2 & 0xff;
    uVar5 = uVar5 * 0x50;
    local_d = (byte *)CONCAT22(CARRY2(uVar5,uVar6) + 0xb800,(byte *)(uVar5 + uVar6));
    if (local_9 <= param_3 >> 1) {
      while( true ) {
        *local_d = *local_d & (bVar3 ^ 0xff) | bVar2 & bVar3;
        local_d = (byte *)CONCAT22(local_d._2_2_ + (uint)((byte *)0xffaf < (byte *)local_d),
                                   (byte *)local_d + 0x50);
        if (local_9 == param_3 >> 1) break;
        local_9 = local_9 + 1;
      }
    }
    if (param_4 != param_3) {
      local_9 = param_4 >> 1;
      bVar4 = (byte)(param_3 - 1 >> 1);
      uVar5 = param_2 >> 2 & 0xff;
      local_d = (byte *)CONCAT22(CARRY2((uint)local_9 * 0x50,uVar5) + 0xba00,
                                 (byte *)((uint)local_9 * 0x50 + uVar5));
      if (local_9 <= bVar4) {
        while( true ) {
          *local_d = *local_d & (bVar3 ^ 0xff) | bVar2 & bVar3;
          local_d = (byte *)CONCAT22(local_d._2_2_ + (uint)((byte *)0xffaf < (byte *)local_d),
                                     (byte *)local_d + 0x50);
          if (local_9 == bVar4) break;
          local_9 = local_9 + 1;
        }
      }
    }
  }
  else if (cVar1 == '\x01') {
    FUN_121a_3d72(param_1,param_2,param_3,param_4);
  }
  else if (cVar1 == '\x02') {
    if ((param_2 & 1) == 0) {
      local_3 = 0xf;
      local_4 = 0xf0;
    }
    else {
      local_3 = 0xf0;
      local_4 = 0xf;
    }
    for (; param_4 <= param_3; param_4 = param_4 + 1) {
      *(byte *)(param_2 >> 1 & 0xff) =
           *(byte *)(param_2 >> 1 & 0xff) & local_3 | local_4 & (param_1 | param_1 << 4);
    }
  }
  else if (cVar1 == '\x03') {
    FUN_121a_3e43(param_1,param_2,param_3,param_4);
  }
  return;
}


