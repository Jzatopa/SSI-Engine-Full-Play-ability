/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:6b7f
 * Ghidra name: FUN_2000_6b7f
 * Linear address: 0x26B7F
 * Original GAME.OVR file offset: 158599
 * Body addresses: 742
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_6b7f(char param_1,byte param_2)

{
  undefined2 *puVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined2 uVar4;
  bool bVar5;
  undefined2 unaff_CS;
  undefined2 uVar6;
  undefined2 unaff_DS;
  undefined4 local_1d;
  undefined1 *local_15;
  int iStack_13;
  undefined1 *local_11;
  int iStack_f;
  int local_b;
  int iStack_9;
  undefined *local_7;
  byte local_5;
  byte local_4;
  char local_3;
  
  if (*(char *)0x4438 == '\x02') {
    bVar5 = false;
    local_4 = 1;
    do {
      if (*(char *)(local_4 + 0x40eb) != '\0') {
        bVar5 = true;
      }
      local_4 = local_4 + 1;
    } while ((!bVar5) && (local_4 <= *(byte *)((int)*(undefined4 *)0x441c + 0x33e)));
    if (!bVar5) {
      return;
    }
  }
  else {
    unaff_CS = 0xcc0;
    FUN_0000_e6d2(1);
  }
  local_7 = (undefined *)(uint)param_2;
  for (local_3 = param_1; '\x01' < local_3; local_3 = local_3 + -1) {
    local_7 = (undefined *)
              (*(int *)((undefined *)&DAT_0000_3252 + (char)(local_3 + -1) * 2) * (int)local_7);
  }
  do {
    if (local_7 == (undefined *)0x0) {
      return;
    }
    if (local_7 < (undefined *)0xb) {
      local_5 = (byte)local_7;
    }
    else {
      local_5 = 10;
    }
    local_4 = 1;
    iStack_9 = *(int *)0x5801;
    local_b = *(int *)0x57ff;
LAB_2000_6c37:
    if (local_b != 0 || iStack_9 != 0) {
      if (*(char *)(local_4 + 0x40eb) != '\0') {
        *(undefined1 *)(local_4 + 0x40eb) = 0;
        local_1d = (undefined1 *)
                   CONCAT22(*(undefined2 *)(local_b + 0xfd),
                            (undefined1 *)*(undefined2 *)(local_b + 0xfb));
        local_11 = (undefined1 *)*(undefined2 *)(local_b + 0xfb);
        iStack_f = *(int *)(local_b + 0xfd);
        local_15 = (undefined1 *)*(undefined2 *)(local_b + 0xfb);
        iStack_13 = *(int *)(local_b + 0xfd);
        puVar3 = *(undefined1 **)(local_15 + 5);
        uVar4 = *(undefined2 *)(local_15 + 7);
        if (*(int *)(local_b + 0xfb) != 0 || *(int *)(local_b + 0xfd) != 0) {
          while (*(int *)(local_11 + 5) != 0 || *(int *)(local_11 + 7) != 0) {
            puVar1 = (undefined2 *)(local_11 + 5);
            iStack_f = *(int *)(local_11 + 7);
            local_11 = (undefined1 *)*puVar1;
          }
        }
        bVar5 = false;
        do {
          if (((undefined1 *)local_1d == (undefined1 *)0x0 && local_1d._2_2_ == 0) || (bVar5))
          goto LAB_2000_6e01;
          if ((local_1d._2_2_ == iStack_f) && ((undefined1 *)local_1d == local_11)) {
            bVar5 = true;
          }
          uVar6 = unaff_CS;
          if (*(int *)((undefined1 *)local_1d + 1) == 0) {
            local_1d = (undefined1 *)
                       CONCAT22(*(undefined2 *)((undefined1 *)local_1d + 7),
                                *(undefined1 **)((undefined1 *)local_1d + 5));
          }
          else if ((uint)local_5 < *(uint *)((undefined1 *)local_1d + 1)) {
            *(uint *)((undefined1 *)local_1d + 1) =
                 *(int *)((undefined1 *)local_1d + 1) - (uint)local_5;
            *(undefined1 *)(local_4 + 0x40eb) = 1;
            local_1d = (undefined1 *)
                       CONCAT22(*(undefined2 *)((undefined1 *)local_1d + 7),
                                *(undefined1 **)((undefined1 *)local_1d + 5));
          }
          else {
            uVar6 = 0x92;
            func_0x0000094f(unaff_CS,(undefined1 *)local_1d,local_1d._2_2_,*local_1d,local_b,
                            iStack_9);
            if ((iStack_13 == *(int *)(local_b + 0xfd)) &&
               (local_15 == (undefined1 *)*(undefined2 *)(local_b + 0xfb))) {
              local_1d = (undefined1 *)
                         CONCAT22(*(undefined2 *)(local_b + 0xfd),
                                  (undefined1 *)*(undefined2 *)(local_b + 0xfb));
            }
            else {
              local_1d = (undefined1 *)CONCAT22(uVar4,puVar3);
            }
          }
          iStack_13 = *(int *)(local_b + 0xfd);
          local_15 = (undefined1 *)*(undefined2 *)(local_b + 0xfb);
          while (unaff_CS = uVar6, local_15 != (undefined1 *)0x0 || iStack_13 != 0) {
            if (((iStack_13 == local_1d._2_2_) && (local_15 == (undefined1 *)local_1d)) ||
               ((*(int *)(local_15 + 7) == local_1d._2_2_ &&
                (*(undefined1 **)(local_15 + 5) == (undefined1 *)local_1d)))) break;
            puVar1 = (undefined2 *)(local_15 + 5);
            iStack_13 = *(int *)(local_15 + 7);
            local_15 = (undefined1 *)*puVar1;
          }
        } while( true );
      }
      goto LAB_2000_6e32;
    }
    if (local_7 < (undefined *)0xb) {
      local_7 = (undefined *)0x0;
    }
    else {
      local_7 = (undefined *)&DAT_0000_fff6 + (int)local_7;
    }
  } while( true );
LAB_2000_6e01:
  while( true ) {
    if ((undefined1 *)local_1d == (undefined1 *)0x0 && local_1d._2_2_ == 0) break;
    if (*(int *)((undefined1 *)local_1d + 1) != 0) {
      *(undefined1 *)(local_4 + 0x40eb) = 1;
    }
    local_1d = (undefined1 *)
               CONCAT22(*(undefined2 *)((undefined1 *)local_1d + 7),
                        *(undefined1 **)((undefined1 *)local_1d + 5));
  }
LAB_2000_6e32:
  local_4 = local_4 + 1;
  piVar2 = (int *)(local_b + 0xff);
  iStack_9 = *(int *)(local_b + 0x101);
  local_b = *piVar2;
  goto LAB_2000_6c37;
}


