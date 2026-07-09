/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:2863
 * Ghidra name: FUN_1000_2863
 * Linear address: 0x12863
 * Original GAME.OVR file offset: 75883
 * Body addresses: 140
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_2863(undefined2 param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint uVar5;
  
  uVar3 = 1;
  uVar4 = 4;
  uVar5 = FUN_0000_09ba();
  cVar1 = (char)((uVar5 & 0xff) >> 1);
  cVar2 = FUN_0000_09ba(0x99,2,1,uVar4,uVar3);
  cVar2 = cVar2 * '\x02' + -3;
  if ((*param_2 < -8) || ('\b' < *param_2)) {
    *param_2 = *param_2 + cVar1 * cVar2;
  }
  else if (*param_2 < '\0') {
    *param_2 = *param_2 - cVar1;
  }
  else if (*param_2 < '\x01') {
    *param_2 = *param_2 + cVar2;
  }
  else {
    *param_2 = *param_2 + cVar1;
  }
  return;
}


