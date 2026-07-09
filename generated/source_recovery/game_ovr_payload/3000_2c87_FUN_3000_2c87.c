/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:2c87
 * Ghidra name: FUN_3000_2c87
 * Linear address: 0x32C87
 * Original GAME.OVR file offset: 208015
 * Body addresses: 106
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_3000_2c87(undefined1 param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 4) = param_1;
  uVar1 = FUN_3000_25e3(param_3,param_4);
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 5) =
       ((undefined *)&DAT_0000_69f0)[(uVar1 & 0xff) * 4];
  if (*(char *)0x7516 != '\0') {
    uVar2 = FUN_3000_256b(param_3,param_4);
    uVar3 = FUN_3000_2593(param_3,param_4);
    FUN_3000_2316(8,param_2,uVar3,uVar2);
  }
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 4) = 0;
  *(undefined1 *)((int)*(undefined4 *)0x71dc + 5) = 1;
  return;
}


