/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:7c66
 * Ghidra name: FUN_2000_7c66
 * Linear address: 0x27C66
 * Original GAME.OVR file offset: 162926
 * Body addresses: 130
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_2000_7c66(char param_1,char param_2,undefined4 param_3)

{
  byte bVar1;
  undefined2 uVar2;
  char cVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)0x72da = 1;
  uVar2 = FUN_0000_09ba();
  *(undefined1 *)0x72c4 = (char)uVar2;
  cVar3 = (char)((uint)uVar2 >> 8);
  if (*(char *)0x72c4 == '\x01') {
    *(undefined1 *)0x72da = 0;
  }
  else if (*(char *)0x72c4 == '\x14') {
    *(undefined1 *)0x72da = 1;
  }
  else {
    bVar1 = *(byte *)0x72c4;
    *(undefined1 *)0x72c4 = (char)((uint)bVar1 + (int)param_1);
    *(char *)&DAT_0000_72d9 = param_2;
    FUN_2000_780a(&param_3,unaff_SS,CONCAT11((char)((uint)bVar1 + (int)param_1 >> 8),0xc));
    cVar3 = param_2 >> 7;
    if (*(byte *)0x72c4 < *(byte *)((int)param_3 + (int)param_2 + 0x1e)) {
      *(undefined1 *)0x72da = 0;
    }
    else {
      *(undefined1 *)0x72da = 1;
    }
  }
  return CONCAT11(cVar3,*(undefined1 *)0x72da);
}


