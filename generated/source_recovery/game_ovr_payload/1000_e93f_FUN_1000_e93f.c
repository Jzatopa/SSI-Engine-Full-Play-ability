/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:e93f
 * Ghidra name: FUN_1000_e93f
 * Linear address: 0x1E93F
 * Original GAME.OVR file offset: 125255
 * Body addresses: 138
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_e93f(byte param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  if (*(int *)0x7640 == 0 && *(int *)0x7642 == 0) {
    uVar4 = FUN_0000_ce3f();
    *(undefined2 *)0x7640 = (int)uVar4;
    *(undefined2 *)0x7642 = (int)((ulong)uVar4 >> 0x10);
    uVar2 = (undefined2)((ulong)*(undefined4 *)0x7640 >> 0x10);
    iVar1 = (int)*(undefined4 *)0x7640;
    *(undefined2 *)(iVar1 + 2) = 0;
    *(undefined2 *)(iVar1 + 4) = 0;
  }
  else {
    uVar2 = *(undefined2 *)0x7642;
    *(undefined2 *)0x7644 = *(undefined2 *)0x7640;
    *(undefined2 *)0x7646 = uVar2;
    uVar4 = FUN_0000_ce3f();
    *(undefined2 *)0x7640 = (int)uVar4;
    *(undefined2 *)0x7642 = (int)((ulong)uVar4 >> 0x10);
    uVar2 = *(undefined2 *)0x7646;
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x7640 >> 0x10);
    iVar1 = (int)*(undefined4 *)0x7640;
    *(undefined2 *)(iVar1 + 2) = *(undefined2 *)0x7644;
    *(undefined2 *)(iVar1 + 4) = uVar2;
  }
  *(undefined2 *)*(undefined4 *)0x7640 = *(undefined2 *)0x4432;
  uVar2 = FUN_1000_d677(((undefined *)&DAT_0000_7715)[param_1],
                        ((undefined *)&DAT_0000_7755)[param_1]);
  *(undefined2 *)0x4432 = uVar2;
  return;
}


