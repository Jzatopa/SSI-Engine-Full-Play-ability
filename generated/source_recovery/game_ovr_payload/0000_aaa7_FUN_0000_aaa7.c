/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:aaa7
 * Ghidra name: FUN_0000_aaa7
 * Linear address: 0x0AAA7
 * Original GAME.OVR file offset: 43695
 * Body addresses: 390
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_aaa7(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined2 unaff_DS;
  byte local_13;
  byte local_12;
  char local_11;
  int local_b;
  int local_9;
  int local_7;
  int iStack_5;
  
  local_7 = *(int *)0x57ff;
  iStack_5 = *(int *)0x5801;
  FUN_0000_e6d2(0x100);
  while (local_7 != 0 || iStack_5 != 0) {
    local_12 = 1;
    bVar6 = true;
    cVar2 = *(char *)((int)*(undefined4 *)(local_7 + 0xf3) + 1);
    while ((local_12 < 0x41 && (bVar6))) {
      if (*(int *)((undefined *)&DAT_0000_7513 + (uint)local_12 * 4) == 0 &&
          *(int *)((undefined *)&DAT_0000_7515 + (uint)local_12 * 4) == 0) {
        local_11 = -1;
      }
      else {
        uVar5 = *(undefined4 *)
                 ((int)*(undefined4 *)((undefined *)&DAT_0000_7513 + (uint)local_12 * 4) + 0xf3);
        local_11 = *(char *)((int)uVar5 + 1);
      }
      if ((local_11 < cVar2) ||
         ((cVar2 == local_11 &&
          (uVar5 = *(undefined4 *)
                    ((int)*(undefined4 *)((undefined *)&DAT_0000_7513 + (uint)local_12 * 4) + 0xf3),
          *(byte *)((int)uVar5 + 5) < *(byte *)((int)*(undefined4 *)(local_7 + 0xf3) + 5))))) {
        bVar6 = false;
      }
      else {
        local_12 = local_12 + 1;
      }
    }
    local_b = *(int *)((undefined *)&DAT_0000_7513 + (uint)local_12 * 4);
    local_9 = *(int *)((undefined *)&DAT_0000_7515 + (uint)local_12 * 4);
    *(int *)((undefined *)&DAT_0000_7513 + (uint)local_12 * 4) = local_7;
    *(int *)((undefined *)&DAT_0000_7515 + (uint)local_12 * 4) = iStack_5;
    if (local_b != 0 || local_9 != 0) {
      local_13 = local_12;
      bVar6 = true;
      while ((local_13 < 0x48 && (bVar6))) {
        local_13 = local_13 + 1;
        iVar3 = *(int *)((undefined *)&DAT_0000_7513 + (uint)local_13 * 4);
        iVar4 = *(int *)((undefined *)&DAT_0000_7515 + (uint)local_13 * 4);
        *(int *)((undefined *)&DAT_0000_7513 + (uint)local_13 * 4) = local_b;
        *(int *)((undefined *)&DAT_0000_7515 + (uint)local_13 * 4) = local_9;
        local_b = iVar3;
        local_9 = iVar4;
        if (iVar3 == 0 && iVar4 == 0) {
          bVar6 = false;
        }
      }
    }
    piVar1 = (int *)(local_7 + 0xff);
    iStack_5 = *(int *)(local_7 + 0x101);
    local_7 = *piVar1;
  }
  return;
}


