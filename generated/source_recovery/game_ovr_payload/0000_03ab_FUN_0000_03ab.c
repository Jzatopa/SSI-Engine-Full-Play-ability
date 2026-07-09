/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:03ab
 * Ghidra name: FUN_0000_03ab
 * Linear address: 0x003AB
 * Original GAME.OVR file offset: 947
 * Body addresses: 60
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void FUN_0000_03ab(void)

{
  byte extraout_AH;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar1;
  undefined2 uVar2;
  undefined1 local_27 [37];
  
  uVar2 = 0x10;
  uVar1 = 0x10;
  FUN_0000_49de(0x96c7,unaff_DS);
  FUN_0000_6d0d(0x21a,uVar1,uVar2);
  FUN_0000_0fdb(0x602);
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0xaf,0xec,local_27,unaff_SS,(uint)extraout_AH << 8);
}


