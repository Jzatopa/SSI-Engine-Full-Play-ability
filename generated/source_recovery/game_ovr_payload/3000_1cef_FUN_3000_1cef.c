/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:1cef
 * Ghidra name: FUN_3000_1cef
 * Linear address: 0x31CEF
 * Original GAME.OVR file offset: 204023
 * Body addresses: 203
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_1cef(char param_1,char param_2)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  undefined1 extraout_AH;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_6;
  byte local_5;
  undefined1 local_4;
  char local_3;
  
  local_3 = param_2 - *(char *)((int)*(undefined4 *)0x71dc + 2);
  iVar2 = (int)param_1 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3);
  local_4 = (undefined1)iVar2;
  bVar3 = (byte)((uint)iVar2 >> 8);
  FUN_3000_1f45((uint)bVar3 << 8,iVar2,CONCAT11(bVar3,local_3));
  FUN_3000_1ed8(&local_6,unaff_SS,&local_5,unaff_SS,CONCAT11(extraout_AH,param_1),
                CONCAT11(extraout_AH,param_2));
  if (local_5 != 0) {
    cVar1 = FUN_3000_20ce(0,*(undefined2 *)((undefined *)&DAT_0000_707f + (uint)local_5 * 4),
                          *(undefined2 *)((undefined *)&DAT_0000_7081 + (uint)local_5 * 4));
    if (cVar1 != '\0') {
      func_0x00000e84();
    }
  }
  return;
}


