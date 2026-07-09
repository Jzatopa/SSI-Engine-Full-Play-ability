/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:c90d
 * Ghidra name: FUN_2000_c90d
 * Linear address: 0x2C90D
 * Original GAME.OVR file offset: 182549
 * Body addresses: 417
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_c90d(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char local_3;
  
  iVar1 = *(int *)0x57fb;
  iVar3 = *(int *)0x57fd;
  *(char *)(param_1 + -0x211) = (char)*(undefined2 *)(param_1 + -0x210) - *(char *)0x747b;
  uVar4 = *(undefined2 *)0x5801;
  *(undefined2 *)(param_1 + -0x242) = *(undefined2 *)0x57ff;
  *(undefined2 *)(param_1 + -0x240) = uVar4;
  cVar2 = *(char *)(param_1 + -0x211);
  if (cVar2 != '\0') {
    local_3 = '\x01';
    while( true ) {
      if (*(int *)(param_1 + -0x242) != 0 || *(int *)(param_1 + -0x240) != 0) {
        uVar6 = (undefined2)((ulong)*(undefined4 *)(param_1 + -0x242) >> 0x10);
        iVar5 = (int)*(undefined4 *)(param_1 + -0x242);
        uVar4 = *(undefined2 *)(iVar5 + 0x101);
        *(undefined2 *)(param_1 + -0x242) = *(undefined2 *)(iVar5 + 0xff);
        *(undefined2 *)(param_1 + -0x240) = uVar4;
      }
      if (local_3 == cVar2) break;
      local_3 = local_3 + '\x01';
    }
  }
  if (*(int *)(param_1 + -0x242) != 0 || *(int *)(param_1 + -0x240) != 0) {
    *(undefined1 *)0x7483 = 0x48;
    *(undefined1 *)0x7458 = 1;
    *(undefined1 *)(param_1 + -0x212) = 1;
    if (*(char *)0x7450 == '\0') {
      if ((*(int *)0x57fd == *(int *)(param_1 + -0x240)) &&
         (*(int *)0x57fb == *(int *)(param_1 + -0x242))) {
        *(undefined1 *)0x7458 = 0;
        *(undefined1 *)0x7483 =
             *(undefined1 *)
              (param_1 + (uint)*(byte *)(param_1 + (uint)*(byte *)0x7457 * 2 + -0x23e) + -0x200);
        if (*(char *)0x7483 == '\0') {
          *(undefined1 *)0x7483 = 0xd;
        }
      }
      else {
        uVar4 = *(undefined2 *)0x57fd;
        *(undefined2 *)0x57f7 = *(undefined2 *)0x57fb;
        *(undefined2 *)0x57f9 = uVar4;
        uVar4 = *(undefined2 *)(param_1 + -0x240);
        *(undefined2 *)0x57fb = *(undefined2 *)(param_1 + -0x242);
        *(undefined2 *)0x57fd = uVar4;
      }
    }
    else {
      uVar4 = *(undefined2 *)(param_1 + -0x240);
      *(undefined2 *)0x7451 = *(undefined2 *)(param_1 + -0x242);
      *(undefined2 *)0x7453 = uVar4;
    }
    FUN_2000_e4dd(*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
    if ((*(char *)0x4438 == '\0') && (*(char *)0x7485 != '\0')) {
      *(undefined1 *)0x7483 = 0xd;
      *(undefined1 *)0x7458 = 0;
      *(undefined1 *)(param_1 + -0x212) = 0;
      FUN_2000_c83b(param_1);
      if ((*(int *)(param_1 + -0x240) == iVar3) && (*(int *)(param_1 + -0x242) == iVar1)) {
        *(undefined1 *)0x7486 = 1;
        FUN_2000_c7fa(param_1);
        *(undefined1 *)0x8d71 = 0;
      }
    }
  }
  return;
}


