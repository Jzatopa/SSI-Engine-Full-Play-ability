/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:a396
 * Ghidra name: FUN_2000_a396
 * Linear address: 0x2A396
 * Original GAME.OVR file offset: 172958
 * Body addresses: 713
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_a396(char param_1,char param_2,undefined4 param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_111 [254];
  uint local_13;
  byte local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  uint local_c;
  int local_a;
  int local_8;
  int local_6;
  uint local_4;
  
  if (((param_3._2_2_ != *(int *)0x5350) || ((int)param_3 != *(int *)0x534e)) ||
     (*(int *)((int)*(undefined4 *)0x534a + 0x18) != 0)) {
    if ((param_3._2_2_ == *(int *)0x534c) && ((int)param_3 == *(int *)0x534a)) {
      local_4 = 0x1d;
      local_6 = param_2 * 2 + 1;
      local_8 = 5;
      local_10 = 8;
    }
    else {
      local_4 = 3;
      local_6 = param_2 + 0xc;
      local_8 = 7;
      local_10 = 0;
    }
    local_a = 0x50;
    if (*(int *)((int)param_3 + param_2 * 2 + 0x16) == 0) {
      local_d = 0xc;
      local_e = 0;
    }
    else {
      local_e = 0xc;
      if ((param_3._2_2_ == *(int *)0x534c) && ((int)param_3 == *(int *)0x534a)) {
        local_d = 0xb;
      }
      else {
        local_d = 10;
      }
    }
    if ((param_3._2_2_ == *(int *)0x534c) && ((int)param_3 == *(int *)0x534a)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(param_2 * 5 + 0x11bf,unaff_DS,local_111,unaff_SS,local_10);
    }
    if (param_1 == '\0') {
      local_11 = 0;
    }
    else {
      local_11 = 10;
    }
    do {
      if ((local_11 & 1) == 0) {
        local_f = local_d;
      }
      else {
        local_f = local_e;
      }
      FUN_2000_a22f();
      FUN_2000_a35c(&local_11,unaff_SS);
    } while (-1 < (char)local_11);
    if (*(int *)((int)param_3 + param_2 * 2 + 0x22) < 100) {
      local_c = (*(int *)((int)param_3 + param_2 * 2 + 0x16) * local_a) /
                *(int *)((int)param_3 + param_2 * 2 + 0x22);
    }
    else {
      local_c = (int)((*(int *)((int)param_3 + param_2 * 2 + 0x16) + 0xfU >> 4) * local_a) /
                (int)(*(uint *)((int)param_3 + param_2 * 2 + 0x22) >> 4);
    }
    if ((int)local_c < 0) {
      local_c = 0;
    }
    else if (local_a <= (int)local_c) {
      local_c = local_a - 1;
    }
    if ((param_3._2_2_ == *(int *)0x534c) && ((int)param_3 == *(int *)0x534a)) {
      local_6 = param_2 * 0x10 + 0x10;
      local_8 = 0xe8;
    }
    else {
      local_6 = param_2 * 8 + 0x60;
      local_8 = 0x78;
    }
    uVar1 = 0xb58;
    func_0x0000b5d1();
    local_4 = (local_8 + local_c) - 1;
    if (0 < (int)local_c) {
      FUN_0000_4a49(CONCAT11(param_2 >> 7,*(undefined1 *)(param_2 + 0xe5e)),local_6 + 3,local_4);
      uVar1 = 0x21a;
      FUN_0000_4a49(CONCAT11(param_2 >> 7,*(undefined1 *)(param_2 + 0xe64)),local_6 + 4,local_4);
    }
    local_13 = local_a - 1;
    if ((int)local_c <= (int)local_13) {
      local_4 = local_c;
      uVar2 = uVar1;
      while( true ) {
        if ((local_4 & 7) == 0) {
          local_d = 8;
        }
        else {
          local_d = 0;
        }
        uVar1 = 0x21a;
        FUN_0000_4d3f(uVar2,CONCAT11((char)(local_4 + local_8 >> 8),local_d),local_4 + local_8,
                      local_6 + 4,local_6 + 3);
        if (local_4 == local_13) break;
        local_4 = local_4 + 1;
        uVar2 = uVar1;
      }
    }
    FUN_0000_b5b0(uVar1);
  }
  return;
}


