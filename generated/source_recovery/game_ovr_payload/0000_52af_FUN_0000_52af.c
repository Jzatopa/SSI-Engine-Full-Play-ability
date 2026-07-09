/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:52af
 * Ghidra name: FUN_0000_52af
 * Linear address: 0x052AF
 * Original GAME.OVR file offset: 21175
 * Body addresses: 164
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_0000_52af(undefined2 param_1,char param_2,byte param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  char local_5;
  char local_4;
  
  uVar1 = *(undefined1 *)((uint)param_3 * 0x22 + 0x240b);
  if ((param_5 == *(int *)0x5350) && (param_4 == *(int *)0x534e)) {
    FUN_0000_47f6();
  }
  if (param_2 == '\a') {
    uVar2 = 1;
    uVar3 = 100;
    local_5 = FUN_0000_09ba();
    local_4 = '\0';
    while (local_5 = local_5 - *(char *)(local_4 + 0xba), '\0' < local_5) {
      if (local_4 == '\x06') {
        return;
      }
      local_4 = local_4 + '\x01';
    }
    FUN_0000_4e58(0x99,param_1,uVar1,(int)local_4,param_4,param_5,uVar3,uVar2);
  }
  else {
    FUN_0000_4e58();
  }
  return;
}


