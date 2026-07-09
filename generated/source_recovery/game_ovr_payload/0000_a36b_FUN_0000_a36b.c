/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:a36b
 * Ghidra name: FUN_0000_a36b
 * Linear address: 0x0A36B
 * Original GAME.OVR file offset: 41843
 * Body addresses: 307
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_0000_a36b(void)

{
  int *piVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined2 unaff_CS;
  undefined2 uVar6;
  undefined2 unaff_DS;
  uint local_6;
  int iStack_4;
  
  *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c8) = 0;
  local_6 = *(uint *)0x57ff;
  iStack_4 = *(int *)0x5801;
  while (local_6 != 0 || iStack_4 != 0) {
    if ((*(char *)((int)*(undefined4 *)(local_6 + 0xf3) + 0xf) == '\x01') ||
       ((*(char *)(local_6 + 0xd6) == '\x01' &&
        (*(char *)((int)*(undefined4 *)0x4418 + 0xaa) == '\0')))) {
      *(undefined1 *)0x3de4 = 1;
      if (*(char *)(local_6 + 0xd5) != '\x01') {
        pcVar2 = (char *)((int)*(undefined4 *)0x441c + 0x2c8);
        *pcVar2 = *pcVar2 + '\x01';
      }
      if ((*(char *)(local_6 + 0xd4) == '\x06') &&
         (*(char *)((int)*(undefined4 *)0x441c + 0x2c7) == '\0')) {
        *(undefined1 *)((int)*(undefined4 *)0x441c + 0x2c7) = 1;
      }
      uVar3 = *(uint *)(local_6 + 0xff);
      iVar4 = *(int *)(local_6 + 0x101);
      *(uint *)0x57fb = local_6;
      *(int *)0x57fd = iStack_4;
      uVar5 = local_6 & 0xff00;
      if (*(char *)((int)*(undefined4 *)(local_6 + 0xf3) + 0xf) == '\x01') {
        uVar5 = uVar5 + 1;
      }
      FUN_0000_065a(unaff_CS,CONCAT11((char)(uVar5 >> 8),1),uVar5);
      unaff_CS = 99;
      local_6 = uVar3;
      iStack_4 = iVar4;
    }
    else {
      uVar6 = unaff_CS;
      if (*(int *)(local_6 + 0xf3) != 0 || *(int *)(local_6 + 0xf5) != 0) {
        uVar6 = 0xcc0;
        FUN_0000_ce54(unaff_CS,0x12,*(undefined2 *)(local_6 + 0xf3),*(undefined2 *)(local_6 + 0xf5))
        ;
        *(undefined2 *)(local_6 + 0xf3) = 0;
        *(undefined2 *)(local_6 + 0xf5) = 0;
      }
      piVar1 = (int *)(local_6 + 0x101);
      unaff_CS = uVar6;
      local_6 = *(uint *)(local_6 + 0xff);
      iStack_4 = *piVar1;
    }
  }
  uVar6 = *(undefined2 *)0x5801;
  *(undefined2 *)0x57fb = *(undefined2 *)0x57ff;
  *(undefined2 *)0x57fd = uVar6;
  return;
}


