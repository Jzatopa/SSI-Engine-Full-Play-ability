/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b876
 * Ghidra name: FUN_2000_b876
 * Linear address: 0x2B876
 * Original GAME.OVR file offset: 178302
 * Body addresses: 108
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - ship_stats (ship), next candidate, distance 131 byte(s), source offset 178171
 */

void FUN_2000_b876(undefined2 param_1,char param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_9 [6];
  undefined1 local_3;
  
  if ((param_2 == '\0') || (*(int *)((int)*(undefined4 *)0x534a + 0x18) < 1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined1 *)0x535b = uVar1;
  func_0x00006e59();
  if ((param_4 == *(int *)0x534c) && (param_3 == *(int *)0x534a)) {
    local_3 = 0xb;
  }
  else {
    local_3 = 0xe;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x32db,0x602,local_9,unaff_SS,8);
}


