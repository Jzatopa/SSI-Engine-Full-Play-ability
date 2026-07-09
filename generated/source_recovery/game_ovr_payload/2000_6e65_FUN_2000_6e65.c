/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:6e65
 * Ghidra name: FUN_2000_6e65
 * Linear address: 0x26E65
 * Original GAME.OVR file offset: 159341
 * Body addresses: 203
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_6e65(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  int local_7;
  int iStack_5;
  char local_3;
  
  local_3 = '\0';
  while( true ) {
    uVar3 = (undefined2)((ulong)param_1 >> 0x10);
    iVar2 = (int)param_1;
    if (*(uint *)((undefined *)&DAT_0000_3252 + local_3 * 2) <= *(uint *)(iVar2 + local_3 * 2)) {
      if (local_3 == '\x06') {
        iStack_5 = *(int *)0x5801;
        local_7 = *(int *)0x57ff;
        while (local_7 != 0 || iStack_5 != 0) {
          *(char *)(local_7 + 0x38) = *(char *)(local_7 + 0x38) + '\x01';
          piVar1 = (int *)(local_7 + 0xff);
          iStack_5 = *(int *)(local_7 + 0x101);
          local_7 = *piVar1;
        }
        *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) - *(int *)0x325e;
        *(undefined1 *)0x67e9 = 1;
      }
      else {
        piVar1 = (int *)(iVar2 + (char)(local_3 + '\x01') * 2);
        *piVar1 = *piVar1 + 1;
        *(int *)(iVar2 + local_3 * 2) =
             *(int *)(iVar2 + local_3 * 2) - *(int *)((undefined *)&DAT_0000_3252 + local_3 * 2);
      }
    }
    if (local_3 == '\x06') break;
    local_3 = local_3 + '\x01';
  }
  return;
}


