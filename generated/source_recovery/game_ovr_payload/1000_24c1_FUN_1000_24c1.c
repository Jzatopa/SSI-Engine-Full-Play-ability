/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:24c1
 * Ghidra name: FUN_1000_24c1
 * Linear address: 0x124C1
 * Original GAME.OVR file offset: 74953
 * Body addresses: 779
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_24c1(char *param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  byte bVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  byte extraout_AH_01;
  int iVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_1e [11];
  undefined1 local_13;
  char local_12;
  byte local_11;
  byte local_10;
  char local_f;
  char local_e;
  char local_d;
  char local_c;
  
  local_e = param_2;
  *param_1 = '\0';
  *(undefined1 *)0x72d2 = 0;
  *(undefined1 *)0x72d3 = 0;
  *(undefined1 *)0x7503 = 0;
  *(undefined1 *)0x7504 = 0;
  local_c = '\0';
  local_d = '\0';
  *(undefined1 *)0x72c6 = 0;
  uVar2 = *(undefined4 *)((int)param_4 + 0xf3);
  *(undefined1 *)((int)uVar2 + 6) = 1;
  FUN_0000_0a05();
  uVar9 = 0x92;
  FUN_0000_0981(0x99,&param_3);
  local_12 = '\0';
  *(undefined1 *)0x7511 = 0;
  cVar4 = FUN_1000_5a95((undefined2)param_3,param_3._2_2_,(int)param_4,param_4._2_2_);
  if (cVar4 != '\0') {
    local_e = '\x01';
    local_12 = '\x01';
    cVar4 = FUN_1000_59e5((undefined2)param_3,param_3._2_2_,(int)param_4,param_4._2_2_);
    if (cVar4 == '\0') {
      *(undefined1 *)0x7511 = 1;
    }
    else {
      *(undefined1 *)0x7511 = 2;
    }
  }
  uVar8 = (undefined2)((ulong)param_3 >> 0x10);
  local_f = *(char *)((int)param_3 + (int)local_12 + 0xd9);
  if ((local_e != '\0') && (*(char *)((int)param_4 + 0x28) == '\x05')) {
    local_f = local_f + '\x02';
  }
  FUN_1000_3e5a(&local_f,unaff_SS,(int)param_3,uVar8,(int)param_4,param_4._2_2_);
  uVar2 = *(undefined4 *)((int)param_4 + 0xf3);
  local_11 = *(byte *)((int)uVar2 + 2);
  bVar3 = local_11;
  if (local_11 != 0) {
LAB_1000_25ba:
    while( true ) {
      local_10 = bVar3;
      uVar8 = (undefined2)((ulong)param_4 >> 0x10);
      iVar7 = (int)param_4;
      if ((*(char *)(iVar7 + (uint)local_10 + 0xda) != '\0') && (local_d == '\0')) {
        pcVar1 = (char *)(iVar7 + (uint)local_10 + 0xda);
        *pcVar1 = *pcVar1 + -1;
        *(byte *)((int)*(undefined4 *)(iVar7 + 0xf3) + 2) = local_10;
        ((undefined *)&DAT_0000_7502)[local_10] = ((undefined *)&DAT_0000_7502)[local_10] + '\x01';
        cVar4 = FUN_0000_095e(uVar9,local_f,(undefined2)param_3,param_3._2_2_,iVar7,uVar8);
        uVar8 = 0x92;
        if (cVar4 == '\0') goto code_r0x0001261a;
        goto LAB_1000_262c;
      }
      if (local_10 == 1) break;
      bVar3 = local_10 - 1;
    }
  }
  uVar8 = uVar9;
  if (local_c == '\0') {
    uVar8 = 0x784;
    FUN_0000_7840(uVar9,*(undefined2 *)0x233c);
    FUN_1000_1c44(0x784,(uint)extraout_AH_01 << 8,(uint)extraout_AH_01 << 8,
                  (uint)extraout_AH_01 << 8,(undefined2)param_3,param_3._2_2_,(int)param_4,
                  param_4._2_2_);
  }
  *param_1 = '\x01';
  local_10 = 1;
  while( true ) {
    uVar9 = (undefined2)((ulong)param_4 >> 0x10);
    iVar7 = (int)param_4;
    if (*(char *)(iVar7 + (uint)local_10 + 0xda) != '\0') {
      *param_1 = '\0';
    }
    if (local_10 == 2) break;
    local_10 = local_10 + 1;
  }
  if (*(char *)(iVar7 + 0xd5) == '\0') {
    *param_1 = '\x01';
  }
  if (*param_1 != '\0') {
    cVar4 = FUN_0000_0a28(uVar8,iVar7,uVar9);
    *param_1 = cVar4;
  }
  return;
code_r0x0001261a:
  uVar9 = 0x99;
  cVar4 = func_0x000009ce(0x92,(undefined2)param_3,param_3._2_2_);
  uVar8 = uVar9;
  bVar3 = local_10;
  if (cVar4 != '\0') {
LAB_1000_262c:
    uVar9 = (undefined2)((ulong)param_4 >> 0x10);
    iVar7 = (int)param_4;
    uVar5 = *(uint *)(iVar7 + 0xeb) | *(uint *)(iVar7 + 0xed);
    uVar6 = uVar5 >> 8;
    if ((uVar5 != 0) && (*(char *)((int)*(undefined4 *)(iVar7 + 0xeb) + 0x2e) == '\x0f')) {
      local_13 = FUN_0000_0963(uVar8,uVar6 << 8,uVar6 << 8,(undefined2)param_3,param_3._2_2_);
      uVar6 = FUN_0000_09ba(0x92,4,1,0xe,(undefined2)param_3,param_3._2_2_);
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0xc28,0x99,local_1e,unaff_SS,CONCAT11((char)((uVar6 & 0xff) + 4 >> 8),local_13))
      ;
    }
    ((undefined *)&DAT_0000_72d1)[local_10] = ((undefined *)&DAT_0000_72d1)[local_10] + '\x01';
    uVar9 = 0x784;
    FUN_0000_7840(uVar8,*(undefined2 *)0x2338);
    local_c = '\x01';
    FUN_1000_19b3(CONCAT11(extraout_AH,local_10),(undefined2)param_3,param_3._2_2_,(int)param_4,
                  param_4._2_2_);
    uVar8 = (undefined2)((ulong)param_3 >> 0x10);
    if (*(char *)((int)param_3 + 0xd5) != '\0') {
      FUN_1000_1c44(0x784,CONCAT11(extraout_AH_00,1),CONCAT11(extraout_AH_00,*(undefined1 *)0x72c6),
                    CONCAT11(extraout_AH_00,*(undefined1 *)0x72c6),(int)param_3,uVar8,(int)param_4,
                    param_4._2_2_);
    }
    if ((*(char *)((int)param_3 + 0xd5) != '\0') && (*(char *)0x72c6 != '\0')) {
      uVar9 = 0x92;
      FUN_0000_0981(0x784,&param_4);
    }
    if (*(char *)((int)param_3 + 0xd5) == '\0') {
      local_d = '\x01';
    }
    uVar8 = (undefined2)((ulong)param_4 >> 0x10);
    bVar3 = local_10;
    if (*(char *)((int)param_4 + 0xd5) == '\0') {
      local_11 = 0;
      *(undefined1 *)((int)param_4 + (uint)local_10 + 0xda) = 0;
    }
  }
  goto LAB_1000_25ba;
}


