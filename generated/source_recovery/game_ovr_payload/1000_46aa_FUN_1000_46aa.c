/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:46aa
 * Ghidra name: FUN_1000_46aa
 * Linear address: 0x146AA
 * Original GAME.OVR file offset: 83634
 * Body addresses: 74
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined1 __stdcall16far FUN_1000_46aa(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_15 [19];
  
  cVar1 = func_0x00000a14();
  uVar2 = (undefined2)((ulong)param_3 >> 0x10);
  if ((cVar1 != *(char *)((int)param_3 + 0xd6)) && (*(char *)((int)param_3 + 0xd7) == '\0')) {
    *(undefined1 *)0x747f = 0xe;
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x2e0e,0x99,local_15,unaff_SS,param_1);
  }
  return 1;
}


