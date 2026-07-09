/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:23a8
 * Ghidra name: FUN_0000_23a8
 * Linear address: 0x023A8
 * Original GAME.OVR file offset: 9136
 * Body addresses: 171
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_23a8(int param_1,char param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_CS;
  undefined2 uVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  
  uVar4 = *(undefined2 *)0x5801;
  *(undefined2 *)(param_1 + -8) = *(undefined2 *)0x57ff;
  *(undefined2 *)((undefined *)&DAT_0000_fffa + param_1) = uVar4;
  while (*(int *)(param_1 + -8) != 0 || *(int *)((undefined *)&DAT_0000_fffa + param_1) != 0) {
    uVar4 = unaff_CS;
    if ((*(char *)((int)*(undefined4 *)(param_1 + -8) + 0xd6) == '\0') &&
       ((*(int *)((undefined *)&DAT_0000_fffa + param_1) != *(int *)0x57fd ||
        (*(int *)(param_1 + -8) != *(int *)0x57fb)))) {
      bVar5 = param_2 == '\0';
      if (bVar5) {
        uVar4 = 0xcc0;
        FUN_0000_d977(unaff_CS,0x1902,unaff_CS,
                      CONCAT11((char)((uint)*(int *)(param_1 + -8) >> 8),
                               *(undefined1 *)((int)*(undefined4 *)(param_1 + -8) + 0xd4)));
        *(bool *)((int)*(undefined4 *)(param_1 + -8) + 0xd5) = !bVar5;
      }
      else {
        *(undefined1 *)((int)*(undefined4 *)(param_1 + -8) + 0xd5) = 0;
      }
    }
    uVar3 = (undefined2)((ulong)*(undefined4 *)(param_1 + -8) >> 0x10);
    iVar2 = (int)*(undefined4 *)(param_1 + -8);
    uVar1 = *(undefined2 *)(iVar2 + 0x101);
    *(undefined2 *)(param_1 + -8) = *(undefined2 *)(iVar2 + 0xff);
    *(undefined2 *)((undefined *)&DAT_0000_fffa + param_1) = uVar1;
    unaff_CS = uVar4;
  }
  return;
}


