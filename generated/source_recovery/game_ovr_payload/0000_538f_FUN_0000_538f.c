/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:538f
 * Ghidra name: FUN_0000_538f
 * Linear address: 0x0538F
 * Original GAME.OVR file offset: 21399
 * Body addresses: 231
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_538f(undefined2 param_1,int param_2,char param_3,undefined2 param_4,undefined2 param_5
                  ,byte param_6,undefined2 param_7,undefined2 param_8,undefined4 param_9)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 unaff_CS;
  undefined2 uVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar6;
  undefined1 local_13d [256];
  byte local_3d;
  undefined1 local_3c [4];
  undefined1 local_38 [51];
  undefined1 local_5;
  undefined1 local_4;
  
  uVar4 = (undefined2)((ulong)param_9 >> 0x10);
  local_3d = *(byte *)((int)param_9 + (uint)param_6 * 6 + 0x3c) & 0x7f;
  if (*(char *)(param_2 + -0xd) != '\0') {
    uVar5 = unaff_CS;
    if (*(char *)0x5358 != '\0') {
      uVar5 = 0x602;
      func_0x00007263();
    }
    unaff_CS = 0x602;
    FUN_0000_7105(uVar5);
  }
  local_4 = 0xb;
  *(undefined1 *)(param_2 + -8) = 1;
  if (param_3 != '\a') {
    unaff_CS = 0x99;
    cVar1 = FUN_0000_09b5(0x32);
    if (cVar1 == '\0') goto LAB_0000_548f;
  }
  cVar1 = FUN_0000_51b3(param_2,param_4,param_5,param_6,param_7,param_8,(int)param_9,uVar4);
  iVar2 = CONCAT11(cVar1 >> 7,1);
  uVar3 = FUN_0000_09ba(unaff_CS,CONCAT11(cVar1 >> 7,0x14),iVar2,(int)cVar1);
  if (iVar2 <= (int)(uVar3 & 0xff)) {
    local_5 = 1;
    *(undefined1 *)0x72c6 = *(undefined1 *)((uint)local_3d * 0x22 + 0x240b);
    puVar6 = local_3c;
    FUN_0000_e390(3);
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x101a,0xcc0,local_13d,unaff_SS,puVar6);
  }
LAB_0000_548f:
  local_5 = 0;
  func_0x0000d6dc(0x99,0x32,local_38);
  return;
}


