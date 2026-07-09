/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4525
 * Ghidra name: FUN_0000_4525
 * Linear address: 0x04525
 * Original GAME.OVR file offset: 17709
 * Body addresses: 23
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_4525(int param_1)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_3;
  
  uVar4 = (undefined2)((ulong)*(undefined4 *)0x534a >> 0x10);
  iVar3 = (int)*(undefined4 *)0x534a;
  local_3 = '\0';
  while( true ) {
    if (*(int *)((undefined *)&DAT_0000_ffdb + param_1 + local_3 * 2) <
        *(int *)(iVar3 + local_3 * 2 + 0x16)) {
      piVar1 = (int *)(iVar3 + local_3 * 2 + 0x16);
      *piVar1 = *piVar1 - *(int *)((undefined *)&DAT_0000_ffdb + param_1 + local_3 * 2);
    }
    if (local_3 == '\x05') break;
    local_3 = local_3 + '\x01';
  }
  *(undefined1 *)0x7817 = 0;
  while( true ) {
    if (*(byte *)(iVar3 + *(char *)0x7817 * 6 + 0x3e) <
        (byte)((undefined *)&DAT_0000_ffcb)[param_1 + *(char *)0x7817]) {
      *(undefined1 *)(iVar3 + *(char *)0x7817 * 6 + 0x3e) = 0;
    }
    else {
      pcVar2 = (char *)(iVar3 + *(char *)0x7817 * 6 + 0x3e);
      *pcVar2 = *pcVar2 - ((undefined *)&DAT_0000_ffcb)[param_1 + *(char *)0x7817];
    }
    if (*(char *)0x7817 == '\a') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
  }
  return;
}


