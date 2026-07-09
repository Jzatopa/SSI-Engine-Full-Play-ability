/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:3e5a
 * Ghidra name: FUN_1000_3e5a
 * Linear address: 0x13E5A
 * Original GAME.OVR file offset: 81506
 * Body addresses: 192
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_1000_3e5a(char *param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  char cVar1;
  undefined2 uVar2;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  undefined2 uVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 local_7;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  iVar4 = (int)param_4;
  uVar5 = param_4._2_2_;
  local_3 = func_0x00000a23();
  cVar1 = func_0x00000a3c(0x99,(int)param_4,param_4._2_2_,uVar2,uVar3,iVar4,uVar5);
  if ((cVar1 == '\0') || (*(char *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 4) == '\0')) {
    local_4 = FUN_0000_0e20(0x99,param_2,param_3);
    local_5 = FUN_0000_0e25(param_2,param_3);
    local_7 = 0xff;
    uVar2 = FUN_0000_0e20(0xdb,(int)param_4,param_4._2_2_);
    FUN_0000_0e25((int)param_4,param_4._2_2_,uVar2);
    FUN_0000_0da4(0xdb,&local_7);
    if (*(char *)0x4136 != '\0') {
      *param_1 = *param_1 + '\x02';
    }
    uVar2 = func_0x00000814(0xd7,(int)param_4,param_4._2_2_,CONCAT11(extraout_AH,local_3));
    cVar1 = FUN_1000_3e02(uVar2,(int)param_4);
    *param_1 = *param_1 + cVar1;
  }
  else {
    *param_1 = *param_1 + '\x05';
  }
  return;
}


