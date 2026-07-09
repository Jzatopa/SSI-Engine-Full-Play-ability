
/* WARNING: Removing unreachable block (ram,0x0001d7bb) */

undefined4 __stdcall16far FUN_1000_d71e(undefined1 *param_1,undefined1 param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  undefined2 unaff_DS;
  bool bVar3;
  uint local_c8;
  uint local_c6;
  int local_c4;
  int iStack_c2;
  
  *param_1 = 1;
  uVar2 = param_3 + 0x8400;
  local_c8 = 0;
  local_c6 = 0;
  if (uVar2 < 0x10) {
    FUN_0000_e6af(param_2);
  }
  else if ((uVar2 < 0x10) || (0xb9 < uVar2)) {
    if ((uVar2 < 0xc4) || (0xcd < uVar2)) {
      if (uVar2 == 0x100) {
        if (*(char *)0x8c3c == '\0') {
          local_c8 = (uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xd4);
        }
        else {
          local_c8 = 0;
        }
        local_c6 = 0;
      }
      else if (uVar2 == 0x10c) {
        local_c8 = (uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xd6);
        local_c6 = 0;
        if (*(char *)((int)*(undefined4 *)0x57fb + 0x4c) != '\0') {
          bVar3 = 0xffbf < local_c8;
          local_c8 = local_c8 + 0x40;
          local_c6 = (uint)bVar3;
        }
        if (*(char *)((int)*(undefined4 *)0x57fb + 0xd7) != '\0') {
          bVar3 = 0xff7f < local_c8;
          local_c8 = local_c8 + 0x80;
          local_c6 = local_c6 + bVar3;
        }
      }
      else if (uVar2 == 0x10e) {
        local_c8 = (uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xd8);
        local_c6 = 0;
      }
      else if ((uVar2 < 0x10f) || (0x110 < uVar2)) {
        if (uVar2 == 0x119) {
          local_c8 = (uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xe3);
          local_c6 = 0;
        }
        else if (uVar2 == 0x11b) {
          local_c8 = (uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xe5);
          local_c6 = 0;
        }
        else if (uVar2 == 0x2b1) {
          local_c8 = 0;
          local_c6 = 0;
          iStack_c2 = *(int *)0x5801;
          local_c4 = *(int *)0x57ff;
          while ((local_c4 != 0 || iStack_c2 != 0 &&
                 ((iStack_c2 != *(int *)0x57fd || (local_c4 != *(int *)0x57fb))))) {
            piVar1 = (int *)(local_c4 + 0xff);
            iStack_c2 = *(int *)(local_c4 + 0x101);
            bVar3 = 0xfffe < local_c8;
            local_c8 = local_c8 + 1;
            local_c6 = local_c6 + bVar3;
            local_c4 = *piVar1;
          }
        }
        else if (uVar2 == 0x312) {
          local_c8 = (uint)*(byte *)0x50d2;
          local_c6 = 0;
        }
        else {
          *param_1 = 0;
        }
      }
      else {
        local_c8 = (uint)*(byte *)((int)*(undefined4 *)0x57fb + (int)(char)((char)uVar2 + -0xf) +
                                  0xd9);
        local_c6 = 0;
      }
    }
    else {
      FUN_0000_e6af(param_2);
    }
  }
  else {
    FUN_0000_e6af(0xba);
    FUN_0000_e6af(param_2);
    local_c6 = 0;
  }
  return CONCAT22(local_c6,local_c8);
}


