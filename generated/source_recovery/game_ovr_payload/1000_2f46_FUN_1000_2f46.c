/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:2f46
 * Ghidra name: FUN_1000_2f46
 * Linear address: 0x12F46
 * Original GAME.OVR file offset: 77646
 * Body addresses: 358
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_1000_2f46(undefined2 param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined1 uVar5;
  undefined2 uVar3;
  uint uVar4;
  undefined2 uVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  undefined2 unaff_DS;
  long lVar10;
  bool local_3a;
  undefined1 local_2a [28];
  undefined *local_e;
  
  *(undefined1 *)0x72cd = 1;
  uVar8 = (undefined2)((ulong)param_3 >> 0x10);
  iVar7 = (int)param_3;
  iVar1 = *(int *)(iVar7 + 0xeb);
  uVar6 = *(undefined2 *)(iVar7 + 0xed);
  iVar2 = (uint)*(byte *)(iVar1 + 0x2e) * 9;
  local_e = (undefined *)&DAT_0000_536e + iVar2;
  uVar5 = (undefined1)((uint)local_e >> 8);
  uVar9 = CONCAT11(uVar5,((undefined *)&DAT_0000_5372)[iVar2]);
  uVar3 = CONCAT11(uVar5,((undefined *)&DAT_0000_5373)[iVar2]);
  FUN_0000_09ba();
  *(undefined1 *)0x72c7 = 0xf;
  uVar5 = 0;
  if (param_2 == '\x05') {
    uVar4 = FUN_0000_09ba(0x99,6,1,uVar3,uVar9);
    uVar5 = (undefined1)((uVar4 & 0xff) + 1 >> 8);
    *(undefined1 *)0x72c7 = 0x17;
  }
  else if ((param_2 == '\a') || (param_2 == '\f')) {
    uVar5 = 0;
    *(undefined1 *)0x72c7 = 0x11;
  }
  else if (param_2 == '\n') {
    *(undefined1 *)0x72c7 = 0x10;
  }
  uVar9 = 0x99;
  if ((local_e[2] == '\a') || (local_e[2] == '\t')) {
    *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) & 0x7f;
  }
  else if (local_e[2] == '\b') {
    uVar9 = 0x7e;
    lVar10 = func_0x00000846(0x99,CONCAT11(uVar5,6),iVar7,uVar8);
    uVar6 = (undefined2)((ulong)lVar10 >> 0x10);
    if (lVar10 != 0) {
      *(byte *)((int)lVar10 + 0x34) = *(byte *)((int)lVar10 + 0x34) & 0x7f;
    }
    local_3a = lVar10 != 0;
  }
  else {
    local_3a = true;
  }
  if (local_3a == false) {
    func_0x0000d6dc(uVar9,0x14,local_2a);
    return;
  }
  func_0x0000d6dc(uVar9,0x14,local_2a);
  return;
}


