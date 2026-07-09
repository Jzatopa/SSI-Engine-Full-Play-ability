/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:20af
 * Ghidra name: FUN_1000_20af
 * Linear address: 0x120AF
 * Original GAME.OVR file offset: 73911
 * Body addresses: 524
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_20af(byte param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  char extraout_AL;
  char cVar6;
  int iVar7;
  byte bVar8;
  byte extraout_AH;
  byte extraout_AH_00;
  undefined1 extraout_AH_01;
  undefined2 unaff_DS;
  int iVar9;
  undefined2 uVar10;
  byte local_3;
  
  iVar9 = (int)param_2;
  uVar10 = param_2._2_2_;
  bVar3 = func_0x00000e2f();
  cVar6 = ((undefined *)&DAT_0000_69ed)[(uint)bVar3 * 4];
  cVar2 = ((undefined *)&DAT_0000_69ee)[(uint)bVar3 * 4];
  cVar4 = cVar6 + ((undefined *)&DAT_0000_26ca)[param_1];
  cVar5 = cVar2 + ((undefined *)&DAT_0000_26d3)[param_1];
  if ((bool)(param_1 & 1)) {
    iVar7 = (uint)(byte)((undefined *)&DAT_0000_26d8)
                        [(uint)*(byte *)((int)*(undefined4 *)0x71dc + cVar5 * 0x32 + (int)cVar4 + 7)
                         * 4] * 3;
    local_3 = (byte)iVar7;
  }
  else {
    iVar7 = (uint)(byte)((undefined *)&DAT_0000_26d8)
                        [(uint)*(byte *)((int)*(undefined4 *)0x71dc + cVar5 * 0x32 + (int)cVar4 + 7)
                         * 4] << 1;
    local_3 = (byte)iVar7;
  }
  bVar8 = (byte)((uint)iVar7 >> 8);
  if (*(byte *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 3) < local_3) {
    *(undefined1 *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 3) = 0;
  }
  else {
    pcVar1 = (char *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 3);
    *pcVar1 = *pcVar1 - local_3;
  }
  local_3 = 1;
  if (*(char *)((int)param_2 + 0xd7) != '\0') {
    local_3 = 3;
    func_0x00000e0c(0xdb,(int)cVar5 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3),
                    (int)cVar4 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2),iVar9,uVar10);
    bVar8 = extraout_AH;
    if ((extraout_AL == '\0') && (*(char *)0x7516 != '\0')) {
      FUN_0000_0e16(0xdb,CONCAT11(extraout_AH,8),CONCAT11(extraout_AH,2),CONCAT11(extraout_AH,cVar2)
                    ,CONCAT11(extraout_AH,cVar6));
      bVar8 = extraout_AH_00;
    }
  }
  if (*(char *)0x7516 != '\0') {
    FUN_0000_0e07(0xdb,CONCAT11(bVar8,bVar3),(uint)bVar8 << 8,(uint)bVar8 << 8);
  }
  ((undefined *)&DAT_0000_69ed)[(uint)bVar3 * 4] = cVar4;
  ((undefined *)&DAT_0000_69ee)[(uint)bVar3 * 4] = cVar5;
  func_0x00000dfd(0xdb);
  if (*(char *)0x7516 != '\0') {
    FUN_0000_0e16(0xdb,CONCAT11(extraout_AH_01,8),CONCAT11(extraout_AH_01,local_3),
                  CONCAT11(extraout_AH_01,cVar5),CONCAT11(extraout_AH_01,cVar4));
  }
  *(undefined1 *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 0xd) = 0;
  *(undefined1 *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 0xe) = 0;
  FUN_0000_7840(0xdb,*(undefined2 *)0x233e);
  FUN_1000_1f36((int)param_2,param_2._2_2_);
  if ((*(char *)((int)param_2 + 0xd5) != '\0') &&
     (cVar6 = func_0x000009ce(0x784,(int)param_2,param_2._2_2_), cVar6 == '\0')) {
    return;
  }
  *(undefined1 *)((int)*(undefined4 *)((int)param_2 + 0xf3) + 3) = 0;
  return;
}


