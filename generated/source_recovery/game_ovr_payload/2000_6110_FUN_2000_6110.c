/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:6110
 * Ghidra name: FUN_2000_6110
 * Linear address: 0x26110
 * Original GAME.OVR file offset: 155928
 * Body addresses: 218
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_6110(int param_1,char param_2)

{
  char cVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  if (param_2 == '\0') {
    cVar1 = *(char *)0x40e8;
    if (cVar1 == '\0') {
      return;
    }
    if (cVar1 == '\x06') {
      *(undefined1 *)0x40e8 = 4;
    }
    else if (cVar1 == '\x03') {
      *(undefined1 *)0x40e8 = 6;
    }
    else if (cVar1 == '\x01') {
      *(undefined1 *)0x40e8 = 3;
    }
    else if (cVar1 == '\x05') {
      *(undefined1 *)0x40e8 = 1;
    }
    else if (cVar1 == '\x04') {
      *(undefined1 *)0x40e8 = 5;
    }
  }
  else {
    cVar1 = *(char *)0x40e8;
    if (cVar1 == '\0') {
      *(undefined1 *)0x40e8 = 6;
      *(undefined2 *)(param_1 + -9) = *(undefined2 *)(param_1 + 10);
    }
    else if (cVar1 == '\x06') {
      *(undefined1 *)0x40e8 = 3;
    }
    else if (cVar1 == '\x03') {
      *(undefined1 *)0x40e8 = 1;
    }
    else if (cVar1 == '\x01') {
      *(undefined1 *)0x40e8 = 5;
    }
    else if (cVar1 == '\x05') {
      *(undefined1 *)0x40e8 = 4;
    }
    else if (cVar1 == '\x04') {
      *(undefined1 *)0x40e8 = 6;
    }
  }
  ((undefined *)&DAT_0000_fffa)[param_1] =
       (*(char *)(*(char *)0x40e8 + 0x44a5) - *(char *)(*(char *)0x40e8 + 0x449e)) + '\x01';
  *(undefined1 *)(param_1 + -2) = 1;
  *(undefined1 *)(param_1 + -5) = 1;
  *(undefined1 *)(param_1 + -4) = 1;
  return;
}


