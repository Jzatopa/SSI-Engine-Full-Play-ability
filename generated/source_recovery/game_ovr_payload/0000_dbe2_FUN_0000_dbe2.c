/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:dbe2
 * Ghidra name: FUN_0000_dbe2
 * Linear address: 0x0DBE2
 * Original GAME.OVR file offset: 56298
 * Body addresses: 156
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_dbe2(undefined2 param_1,undefined1 param_2,byte param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  bool bVar3;
  
  iVar1 = *(char *)0x4004 * 6 + *(char *)0x4005 * 5 + 0x15 + (uint)param_4;
  iVar2 = *(char *)0x4005 * 5 + 10 + (uint)param_3;
  if ((((-1 < iVar1) && (iVar2 < 0x32)) && (-1 < iVar2)) && (iVar2 < 0x19)) {
    bVar3 = (int)*(undefined4 *)0x71dc + iVar2 * 0x32 + iVar1 == 0;
    FUN_0000_d977();
    if (!bVar3) {
      FUN_0000_db35(CONCAT11(extraout_AH,param_2),CONCAT11(extraout_AH,param_3),
                    CONCAT11(extraout_AH,param_4));
    }
  }
  return;
}


