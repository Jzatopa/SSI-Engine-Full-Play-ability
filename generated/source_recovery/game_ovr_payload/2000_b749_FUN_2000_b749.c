/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:b749
 * Ghidra name: FUN_2000_b749
 * Linear address: 0x2B749
 * Original GAME.OVR file offset: 178001
 * Body addresses: 169
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - ship_stats (ship), previous candidate, distance 170 byte(s), source offset 178171
 */

char __stdcall16far FUN_2000_b749(undefined4 param_1)

{
  char cVar1;
  undefined2 unaff_DS;
  char local_4;
  
  cVar1 = FUN_2000_b713((int)param_1,param_1._2_2_);
  if (cVar1 == '\0') {
    local_4 = '\0';
  }
  else {
    if ((param_1._2_2_ == *(int *)0x534c) && ((int)param_1 == *(int *)0x534a)) {
      local_4 = *(char *)0x535c;
    }
    else {
      local_4 = *(char *)0x535d;
    }
    local_4 = *(char *)((int)param_1 + 0x36) + local_4;
    if (*(int *)((int)param_1 + 0x16) < (int)(*(uint *)((int)param_1 + 0x22) >> 1)) {
      local_4 = (char)((uint)(int)local_4 >> 1);
    }
    if (*(int *)((int)param_1 + 0x20) < (int)(*(uint *)((int)param_1 + 0x2c) >> 2)) {
      local_4 = local_4 + -3;
    }
    else if (*(int *)((int)param_1 + 0x20) < (int)(*(uint *)((int)param_1 + 0x2c) >> 1)) {
      local_4 = local_4 + -1;
    }
    if (local_4 < '\x01') {
      local_4 = '\x01';
    }
  }
  return local_4;
}


