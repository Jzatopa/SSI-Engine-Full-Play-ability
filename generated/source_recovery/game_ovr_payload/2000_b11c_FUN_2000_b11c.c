/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b11c
 * Ghidra name: FUN_2000_b11c
 * Linear address: 0x2B11C
 * Original GAME.OVR file offset: 176420
 * Body addresses: 97
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined4 __stdcall16far FUN_2000_b11c(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined1 local_8;
  
  local_8 = 0;
  uVar4 = (undefined2)((ulong)param_2 >> 0x10);
  iVar1 = *(int *)((int)param_2 + 0xeb);
  iVar2 = *(int *)((int)param_2 + 0xed);
  lVar3 = CONCAT22(iVar2,iVar1);
  if ((*(char *)(iVar1 + 0x38) != '\0') &&
     (lVar3 = (ulong)*(byte *)(iVar1 + 0x2e) * 9, ((undefined *)&DAT_0000_5370)[(int)lVar3] != '\0')
     ) {
    lVar3 = CONCAT22(iVar2,iVar1);
    *param_1 = iVar1;
    ((int *)param_1)[1] = iVar2;
    local_8 = 1;
  }
  return CONCAT22((int)((ulong)lVar3 >> 0x10),CONCAT11((char)((ulong)lVar3 >> 8),local_8));
}


