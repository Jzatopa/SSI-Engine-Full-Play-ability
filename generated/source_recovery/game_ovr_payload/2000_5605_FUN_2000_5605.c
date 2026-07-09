/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:5605
 * Ghidra name: FUN_2000_5605
 * Linear address: 0x25605
 * Original GAME.OVR file offset: 153101
 * Body addresses: 556
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_2000_5605(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  char local_5;
  char local_4;
  char local_3;
  
  FUN_0000_e6d2(0);
  FUN_0000_e6d2(0);
  uVar5 = 0x44a5;
  uVar4 = 7;
  FUN_0000_e6d2(0);
  *(undefined1 *)0x449e = 1;
  *(undefined1 *)0x44a5 = 8;
  for (local_3 = '\x01';
      *(undefined1 *)(local_3 + 0x4449) =
           *(undefined1 *)(*(char *)((int)*(undefined4 *)0x57fb + 0x28) * 8 + (int)local_3 + 0xfdb),
      local_3 != '\b'; local_3 = local_3 + '\x01') {
  }
  local_5 = *(char *)0x1558;
  *(undefined1 *)(local_5 + 0x449e) = 9;
  local_4 = '\b';
  *(undefined1 *)0x40e9 = 0;
  local_3 = '\x01';
  uVar3 = 0xcc0;
  do {
    if (((((((int)local_3 == (uint)*(byte *)0x444a) || ((int)local_3 == (uint)*(byte *)0x444b)) ||
          ((int)local_3 == (uint)*(byte *)0x444c)) ||
         (((int)local_3 == (uint)(byte)*(code *)FUN_0000_444d ||
          ((int)local_3 == (uint)*(byte *)0x444e)))) ||
        (((int)local_3 == (uint)*(byte *)0x444f ||
         (((int)local_3 == (uint)*(byte *)0x4450 || ((int)local_3 == (uint)*(byte *)0x4451)))))) ||
       (('\x0f' < local_3 && (local_3 < '\x18')))) {
LAB_2000_57f5:
      local_4 = local_4 + -1;
      uVar2 = uVar3;
    }
    else {
      uVar2 = uVar3;
      if (*(char *)0x40ea != '\0') {
        uVar2 = 0x99;
        cVar1 = FUN_0000_0a6e(uVar3,(int)local_3,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd,uVar4,
                              uVar5);
        uVar3 = uVar2;
        if (cVar1 == '\0') goto LAB_2000_57f5;
      }
      uVar3 = uVar2;
      if (*(char *)(local_3 * 0x1b + 0x153c) == '\0') goto LAB_2000_57f5;
      if (*(char *)((int)*(undefined4 *)0x57fb + (int)local_3 + 0x4c) != '\0') {
        *(char *)0x40e9 = *(char *)0x40e9 + '\x01';
      }
      *(char *)((int)local_3 + (int)local_4 + 0x4449) = local_3;
      if (*(char *)(local_3 * 0x1b + 0x153d) != local_5) {
        *(char *)(local_5 + 0x44a5) = local_3 + local_4 + -1;
        local_5 = *(char *)(local_3 * 0x1b + 0x153d);
        *(char *)(local_5 + 0x449e) = local_3 + local_4;
      }
    }
    if (local_3 == 'T') {
      *(char *)(local_5 + 0x44a5) = local_4 + 'T';
      *(undefined1 *)0x44a0 = 9;
      *(char *)0x44a7 = local_4 + 'T';
      return;
    }
    local_3 = local_3 + '\x01';
    uVar3 = uVar2;
  } while( true );
}


