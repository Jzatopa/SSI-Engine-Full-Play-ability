/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:8db7
 * Ghidra name: FUN_0000_8db7
 * Linear address: 0x08DB7
 * Original GAME.OVR file offset: 36287
 * Body addresses: 290
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_8db7(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  undefined2 uVar5;
  char local_13;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  char local_c;
  char local_b;
  int local_a;
  int iStack_8;
  undefined4 local_6;
  
  local_6 = 0;
  local_10 = *(undefined2 *)0x72be;
  local_e = *(undefined2 *)0x72c0;
  local_12 = 0;
  uVar5 = 1;
  FUN_0000_0f94();
  uVar3 = 0xec;
  do {
    FUN_0000_8cef(uVar3,&local_12);
    if ((local_b == 'T') || (local_b == '\r')) {
      local_c = '\0';
      uVar4 = 0x67;
      FUN_0000_069a(uVar3,&local_13);
      if (local_13 == '\0') {
        _local_a = CONCAT22(*(int *)0x72c0,*(int *)0x72be);
        if ((*(int *)0x72c0 == local_6._2_2_) && (*(int *)0x72be == (int)local_6)) {
          uVar3 = *(undefined2 *)((int)local_6 + 0x2c);
          *(undefined2 *)0x72be = *(undefined2 *)((int)local_6 + 0x2a);
          *(undefined2 *)0x72c0 = uVar3;
        }
        else {
          while( true ) {
            uVar3 = (undefined2)((ulong)_local_a >> 0x10);
            iVar2 = (int)_local_a;
            if ((*(int *)(iVar2 + 0x2c) == local_6._2_2_) &&
               (*(int *)(iVar2 + 0x2a) == (int)local_6)) break;
            _local_a = CONCAT22(*(undefined2 *)(iVar2 + 0x2c),*(undefined2 *)(iVar2 + 0x2a));
          }
          uVar1 = *(undefined2 *)((int)local_6 + 0x2c);
          *(undefined2 *)(iVar2 + 0x2a) = *(undefined2 *)((int)local_6 + 0x2a);
          *(undefined2 *)(iVar2 + 0x2c) = uVar1;
        }
        if ((int)local_6 != 0 || local_6._2_2_ != 0) {
          *(undefined2 *)((int)local_6 + 0x2a) = 0;
          *(undefined2 *)((int)local_6 + 0x2c) = 0;
          uVar4 = 0xcc0;
          FUN_0000_ce54(0x67,0x3e,(int)local_6,local_6._2_2_,uVar5);
        }
        if (*(int *)0x72be == 0 && *(int *)0x72c0 == 0) {
          local_c = '\x01';
        }
      }
    }
    else {
      local_c = '\x01';
      uVar4 = uVar3;
    }
    uVar3 = uVar4;
  } while (local_c == '\0');
  FUN_0000_0a2d(uVar4);
  return;
}


