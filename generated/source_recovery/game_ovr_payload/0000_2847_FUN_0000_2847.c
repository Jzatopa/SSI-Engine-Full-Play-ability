/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:2847
 * Ghidra name: FUN_0000_2847
 * Linear address: 0x02847
 * Original GAME.OVR file offset: 10319
 * Body addresses: 42
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_2847(void)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar1;
  undefined1 local_4 [2];
  
  *(int *)0x4432 = *(int *)0x4432 + 1;
  uVar1 = 6;
  FUN_0000_e6d2(0);
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x1dc0,0xcc0,local_4,unaff_SS,uVar1);
}


