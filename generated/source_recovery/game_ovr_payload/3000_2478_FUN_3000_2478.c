/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:2478
 * Ghidra name: FUN_3000_2478
 * Linear address: 0x32478
 * Original GAME.OVR file offset: 205952
 * Body addresses: 243
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_2478(char param_1,byte param_2,byte param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined2 unaff_DS;
  
  bVar1 = FUN_3000_25e3((int)param_4,param_4._2_2_);
  cVar2 = FUN_3000_20ce(1,(int)param_4,param_4._2_2_);
  if ((cVar2 == '\0') && (*(char *)0x7516 != '\0')) {
    uVar3 = FUN_3000_256b((int)param_4,param_4._2_2_);
    uVar4 = FUN_3000_2593((int)param_4,param_4._2_2_);
    FUN_3000_2316(8,3,uVar4,uVar3);
  }
  uVar5 = (uint)(*(byte *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 7) >> 2);
  if ((((uVar5 != param_3 >> 2) || (param_2 != 0)) || (param_1 != '\0')) &&
     (*(char *)0x7516 != '\0')) {
    uVar5 = FUN_3000_1f45(bVar1,0,0);
  }
  *(byte *)((int)*(undefined4 *)((int)param_4 + 0xf3) + 7) = param_3;
  if (param_1 == '\0') {
    cVar2 = FUN_3000_20ce(uVar5 & 0xff00,(int)param_4,param_4._2_2_);
    if ((cVar2 != '\0') && (*(char *)0x7516 != '\0')) {
      uVar5 = (uint)(byte)((undefined *)&DAT_0000_6b10)[bVar1];
      uVar6 = (uint)(byte)((undefined *)&DAT_0000_6b58)[bVar1];
      uVar7 = (uint)param_3;
      uVar8 = (uint)param_2;
      uVar9 = (uint)*(byte *)((int)param_4 + 0xb9);
      func_0x00000e84();
      FUN_0000_39b7(uVar9,uVar8,uVar7,uVar6,uVar5);
    }
  }
  return;
}


