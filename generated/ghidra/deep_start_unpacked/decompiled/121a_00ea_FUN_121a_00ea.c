
void __stdcall16far
FUN_121a_00ea(undefined4 *param_1,undefined2 param_2,char param_3,undefined1 param_4,
             undefined1 param_5,undefined4 *param_6)

{
  undefined1 extraout_AH;
  undefined4 *puVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int local_19;
  undefined1 local_17 [8];
  undefined2 local_f;
  byte local_d;
  uint local_c;
  undefined2 local_a;
  undefined2 local_8;
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  undefined2 uVar4;
  
  FUN_1cc0_1aaf(1,&local_5,unaff_SS,(int)*param_6,(int)((ulong)*param_6 >> 0x10));
  FUN_1cc0_1aaf(1,&local_6,unaff_SS,(int)*param_6 + 1,(int)((ulong)*param_6 >> 0x10));
  FUN_1cc0_1aaf(2,&local_8,unaff_SS,(int)*param_6 + 2,(int)((ulong)*param_6 >> 0x10));
  FUN_1cc0_1aaf(2,&local_a,unaff_SS,(int)*param_6 + 4,(int)((ulong)*param_6 >> 0x10));
  FUN_1cc0_1aaf(2,&local_f,unaff_SS,(int)*param_6 + 6,(int)((ulong)*param_6 >> 0x10));
  FUN_1cc0_1aaf(1,&local_d,unaff_SS,(int)*param_6 + 8,(int)((ulong)*param_6 >> 0x10));
  local_c = *(byte *)((int)*param_6 + 9) + 1;
  FUN_1cc0_1aaf(local_c * 3,(uint)local_d * 3 + -0x6639,unaff_DS,(int)*param_6 + 10,
                (int)((ulong)*param_6 >> 0x10));
  local_19 = local_c * 3 + 10;
  local_3 = 0;
  while( true ) {
    *(byte *)((uint)local_d + (uint)local_3 * 2 + -0x6339) =
         *(byte *)((int)*param_6 + local_19) >> 4;
    *(byte *)((uint)local_d + (uint)local_3 * 2 + -0x6338) =
         *(byte *)((int)*param_6 + local_19) & 0xf;
    local_19 = local_19 + 1;
    if (local_3 == (byte)((char)(local_c >> 1) - 1U)) break;
    local_3 = local_3 + 1;
  }
  if ((local_d == 0x20) && (local_c == 0x70)) {
    local_3 = 0;
    while( true ) {
      for (local_4 = 0;
          *(byte *)((uint)local_3 * 4 + (uint)local_4 + -0x6229) =
               *(byte *)((int)*param_6 + local_19) >> (local_4 * -2 + 6 & 0x1f) & 3, local_4 != 3;
          local_4 = local_4 + 1) {
      }
      local_19 = local_19 + 1;
      if (local_3 == 3) break;
      local_3 = local_3 + 1;
    }
    local_3 = 0;
    while( true ) {
      for (local_4 = 0;
          *(byte *)((uint)local_3 * 4 + (uint)local_4 + -0x6209) =
               *(byte *)((int)*param_6 + local_19) >> (local_4 * -2 + 6 & 0x1f) & 3, local_4 != 3;
          local_4 = local_4 + 1) {
      }
      local_19 = local_19 + 1;
      if (local_3 == 0x1b) break;
      local_3 = local_3 + 1;
    }
    *(undefined1 *)0x8dc6 = 1;
  }
  else {
    local_3 = 0;
    while( true ) {
      for (local_4 = 0;
          *(byte *)((uint)local_3 * 4 + (uint)local_4 + -0x6239) =
               *(byte *)((int)*param_6 + local_19) >> (local_4 * -2 + 6 & 0x1f) & 3, local_4 != 3;
          local_4 = local_4 + 1) {
      }
      local_19 = local_19 + 1;
      if (local_3 == 3) break;
      local_3 = local_3 + 1;
    }
    *(undefined1 *)0x8dc6 = 0;
  }
  puVar1 = (undefined4 *)param_1;
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  uVar4 = (undefined2)((ulong)param_6 >> 0x10);
  if (param_3 == '\0') {
    uVar5 = *(undefined2 *)((int)(undefined4 *)param_6 + 2);
    *(undefined2 *)param_1 = *(undefined2 *)param_6;
    *(undefined2 *)((int)puVar1 + 2) = uVar5;
    *(uint *)*param_1 = (uint)local_5;
    *(uint *)((int)*param_1 + 2) = (uint)local_6;
    *(int *)((int)*param_1 + 0x12) = (uint)local_5 * (uint)local_6 * 8;
    *(undefined2 *)((int)*param_1 + 8) = local_f;
    uVar5 = (undefined2)((ulong)*param_1 >> 0x10);
    iVar2 = (int)*param_1;
    *(undefined2 *)(iVar2 + 0x17) = 0;
    *(undefined2 *)(iVar2 + 0x19) = 0;
    *(undefined2 *)((int)*param_1 + 0x14) = param_2;
  }
  else {
    FUN_121a_22ad(puVar1,uVar3,param_5,local_f,local_6,local_5);
  }
  uVar5 = (undefined2)((ulong)*param_1 >> 0x10);
  iVar2 = (int)*param_1;
  *(undefined2 *)(iVar2 + 4) = local_8;
  *(undefined2 *)(iVar2 + 6) = local_a;
  *(undefined1 *)(iVar2 + 0x16) = param_4;
  FUN_1cc0_09f6(8,iVar2 + 10,uVar5,local_17,unaff_SS);
  FUN_121a_057d(*(undefined2 *)param_1,*(undefined2 *)((int)puVar1 + 2),
                CONCAT11(extraout_AH,param_4),CONCAT11(extraout_AH,param_5),&local_19,unaff_SS,
                *(undefined2 *)param_6,*(undefined2 *)((int)(undefined4 *)param_6 + 2));
  return;
}


