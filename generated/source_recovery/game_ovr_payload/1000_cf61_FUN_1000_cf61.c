/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:cf61
 * Ghidra name: FUN_1000_cf61
 * Linear address: 0x1CF61
 * Original GAME.OVR file offset: 118633
 * Body addresses: 407
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_cf61(byte param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  byte local_4;
  byte local_3;
  
  local_4 = 0;
  if (param_1 != 0) {
    local_3 = 1;
    while( true ) {
      *(undefined1 *)(local_3 + 0x76d5) =
           *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x7fff);
      ((undefined *)&DAT_0000_7755)[local_3] =
           *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x7ffe);
      *(int *)0x4432 = *(int *)0x4432 + 2;
      cVar1 = *(char *)(local_3 + 0x76d5);
      if ((((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) || (cVar1 == '\x05')) {
        *(int *)0x4432 = *(int *)0x4432 + 1;
        ((undefined *)&DAT_0000_7715)[local_3] =
             *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x8000);
      }
      else if (cVar1 == '\x04') {
        ((undefined *)&DAT_0000_7715)[local_3] =
             *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x7fff);
        ((undefined *)&DAT_0000_77d5)[local_3] =
             *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x7ffe);
        ((undefined *)&DAT_0000_7795)[local_3] =
             *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x7ffd);
        *(int *)0x4432 = *(int *)0x4432 + 3;
      }
      else if (cVar1 == -0x80) {
        local_4 = local_4 + 1;
        if (((undefined *)&DAT_0000_7755)[local_3] == '\0') {
          ((undefined *)&DAT_0000_7718)[(uint)local_4 * 0x100] = 0;
        }
        else {
          FUN_1000_e105(local_4,((undefined *)&DAT_0000_7755)[local_3]);
        }
      }
      else if (cVar1 == -0x7f) {
        local_4 = local_4 + 1;
        *(int *)0x4432 = *(int *)0x4432 + 1;
        ((undefined *)&DAT_0000_7715)[local_3] =
             *(undefined1 *)((int)*(undefined4 *)0x4424 + *(int *)0x4432 + -0x8000);
        uVar2 = FUN_1000_d677(((undefined *)&DAT_0000_7715)[local_3],
                              ((undefined *)&DAT_0000_7755)[local_3]);
        FUN_1000_e2ad(uVar2,local_4);
      }
      if (local_3 == param_1) break;
      local_3 = local_3 + 1;
    }
  }
  *(int *)0x4432 = *(int *)0x4432 + 1;
  return;
}


