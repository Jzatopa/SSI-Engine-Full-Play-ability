/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:42f6
 * Ghidra name: FUN_2000_42f6
 * Linear address: 0x242F6
 * Original GAME.OVR file offset: 148222
 * Body addresses: 484
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_42f6(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  byte local_f;
  int local_e;
  int iStack_c;
  int local_6;
  int iStack_4;
  
  iStack_c = (int)((ulong)param_1 >> 0x10);
  local_e = (int)param_1;
  if ((*(byte *)(local_e + 0x34) & 0x20) == 0) {
    if (*(char *)(local_e + 0x38) == '\0') {
      *(undefined1 *)(local_e + 0x38) = 1;
    }
    local_f = *(byte *)(local_e + 0x38);
    uVar3 = (undefined2)((ulong)*(undefined4 *)0x57fb >> 0x10);
    iVar2 = (int)*(undefined4 *)0x57fb;
    iVar1 = *(int *)(iVar2 + 0xf7);
    iVar2 = *(int *)(iVar2 + 0xf9);
    while (iStack_4 = iVar2, local_6 = iVar1, local_6 != 0 || iStack_4 != 0) {
      iVar1 = *(int *)(local_6 + 0x2a);
      iVar2 = *(int *)(local_6 + 0x2c);
      if (((((iStack_4 != iStack_c) || (local_6 != local_e)) &&
           (*(char *)(local_6 + 0x2f) == *(char *)(local_e + 0x2f))) &&
          ((((*(char *)(local_6 + 0x30) == *(char *)(local_e + 0x30) &&
             (*(char *)(local_6 + 0x31) == *(char *)(local_e + 0x31))) &&
            ((*(char *)(local_6 + 0x2e) == *(char *)(local_e + 0x2e) &&
             ((*(char *)(local_6 + 0x32) == *(char *)(local_e + 0x32) &&
              (*(char *)(local_6 + 0x33) == *(char *)(local_e + 0x33))))))) &&
           (*(int *)(local_6 + 0x36) == *(int *)(local_e + 0x36))))) &&
         (((*(char *)(local_6 + 0x3b) == *(char *)(local_e + 0x3b) &&
           (*(char *)(local_6 + 0x3c) == *(char *)(local_e + 0x3c))) &&
          (*(char *)(local_6 + 0x3d) == *(char *)(local_e + 0x3d))))) {
        if (*(char *)(local_6 + 0x38) == '\0') {
          *(undefined1 *)(local_6 + 0x38) = 1;
        }
        if ((uint)local_f + (uint)*(byte *)(local_6 + 0x38) < 0x65) {
          local_f = local_f + *(char *)(local_6 + 0x38);
          func_0x000009e7(unaff_CS,local_6,iStack_4,*(undefined2 *)0x57fb,*(undefined2 *)0x57fd);
          unaff_CS = 0x99;
        }
        else {
          *(undefined1 *)(local_e + 0x38) = 100;
          *(char *)(local_6 + 0x38) = *(char *)(local_6 + 0x38) - ('d' - local_f);
          local_f = *(byte *)(local_6 + 0x38);
          local_e = local_6;
          iStack_c = iStack_4;
        }
      }
    }
    *(byte *)(local_e + 0x38) = local_f;
  }
  return;
}


