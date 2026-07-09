/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:25e3
 * Ghidra name: FUN_3000_25e3
 * Linear address: 0x325E3
 * Original GAME.OVR file offset: 206315
 * Body addresses: 90
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_3000_25e3(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  undefined2 unaff_DS;
  byte local_5;
  byte local_3;
  
  bVar1 = false;
  local_3 = 0;
  local_5 = 0;
  do {
    local_5 = local_5 + 1;
    iVar2 = *(int *)((undefined *)&DAT_0000_707f + (uint)local_5 * 4);
    if ((*(int *)((undefined *)&DAT_0000_7081 + (uint)local_5 * 4) == param_2) && (iVar2 == param_1)
       ) {
      bVar1 = true;
    }
  } while ((!bVar1) &&
          (iVar2 = CONCAT11((char)((uint)iVar2 >> 8),local_5), local_5 != *(byte *)&DAT_0000_69f0));
  if (bVar1) {
    local_3 = local_5;
  }
  return CONCAT11((char)((uint)iVar2 >> 8),local_3);
}


