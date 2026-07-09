/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4e58
 * Ghidra name: FUN_0000_4e58
 * Linear address: 0x04E58
 * Original GAME.OVR file offset: 20064
 * Body addresses: 102
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

/* WARNING: Removing unreachable block (ram,0x00004fcd) */
/* WARNING: Removing unreachable block (ram,0x00005180) */
/* WARNING: Removing unreachable block (ram,0x0000518d) */
/* WARNING: Removing unreachable block (ram,0x0000519c) */
/* WARNING: Removing unreachable block (ram,0x000051a6) */

void FUN_0000_4e58(undefined2 param_1,undefined2 param_2,undefined2 param_3,char param_4,
                  undefined4 param_5)

{
  uint uVar1;
  byte extraout_AH;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 auStack_10e [256];
  int local_e;
  int local_c;
  undefined1 local_a;
  byte local_9;
  char local_4;
  
  local_a = 0;
  iVar4 = (int)((ulong)param_5 >> 0x10);
  iVar3 = (int)param_5;
  local_e = iVar3;
  local_c = iVar4;
  if (param_4 != '\x06') {
    FUN_0000_4fd0();
    return;
  }
  local_9 = 0;
  for (local_4 = '\0'; local_9 = local_9 + *(char *)(iVar3 + local_4 * 6 + 0x3e), local_4 != '\a';
      local_4 = local_4 + '\x01') {
  }
  if ('\0' < (char)local_9) {
    uVar2 = 1;
    uVar1 = (uint)local_9;
    local_9 = FUN_0000_09ba();
    local_4 = '\0';
    if (('\0' < (char)local_9) &&
       (local_9 = local_9 - *(char *)(iVar3 + 0x3e), (char)local_9 < '\x01')) {
      if ((iVar4 == *(int *)0x534c) && (iVar3 == *(int *)0x534a)) {
        FUN_0000_4cde(param_2);
        func_0x00000a5f(0x99,CONCAT11(extraout_AH,local_4),(uint)extraout_AH << 8,iVar3,iVar4,uVar1,
                        uVar2);
      }
      uVar2 = FUN_0000_4339(param_2,iVar3,iVar4);
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2((uint)(*(byte *)(iVar3 + local_4 * 6 + 0x3c) & 0x7f) * 0x22 + 0x2411,unaff_DS,
                    auStack_10e,unaff_SS,uVar2);
    }
    FUN_0000_4ebe();
    return;
  }
  return;
}


