/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:a680
 * Ghidra name: FUN_2000_a680
 * Linear address: 0x2A680
 * Original GAME.OVR file offset: 173704
 * Body addresses: 391
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_a680(int param_1,int param_2)

{
  byte extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_1a [18];
  byte local_8;
  byte local_7;
  char local_6;
  int local_5;
  char local_3;
  
  if ((param_2 == *(int *)0x534c) && (param_1 == *(int *)0x534a)) {
    local_7 = '\x01';
    local_8 = 0x11;
    local_6 = '\0';
    while( true ) {
      func_0x00006e59(unaff_CS,8,local_7,0x26,local_7,0x1d);
      local_7 = local_7 + 1;
      func_0x00006e59(0x602,(uint)extraout_AH << 8,CONCAT11(extraout_AH,local_7),
                      CONCAT11(extraout_AH,0x26),CONCAT11(extraout_AH,local_7),
                      CONCAT11(extraout_AH,0x1d));
      func_0x0000b5d1(0x602);
      local_5 = 0;
      uVar1 = 0xb58;
      while( true ) {
        iVar3 = local_5 * 8 + 0xe8;
        FUN_0000_4d3f(uVar1,CONCAT11((char)((uint)iVar3 >> 8),8),iVar3,(uint)local_7 * 8 + 7,
                      (uint)local_7 << 3);
        if (local_5 == 9) break;
        local_5 = local_5 + 1;
        uVar1 = 0x21a;
      }
      unaff_CS = 0xb58;
      FUN_0000_b5b0(0x21a);
      local_7 = local_7 + 1;
      if (local_6 == '\x05') break;
      local_6 = local_6 + '\x01';
    }
  }
  else {
    if (*(int *)((int)*(undefined4 *)0x534a + 0x18) == 0) {
      func_0x00006e59();
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0x2157,0x602,local_1a,unaff_SS,CONCAT11(extraout_AH_00,8));
    }
    local_8 = 0x17;
  }
  func_0x0000b5d1(unaff_CS);
  *(undefined1 *)0x7817 = 0;
  uVar1 = 0xb58;
  while( true ) {
    iVar3 = ((int)*(char *)0x7817 + (uint)local_8) * 4;
    FUN_0000_3721(uVar1,*(undefined2 *)(iVar3 + 0x52d6),*(undefined2 *)(iVar3 + 0x52d8),
                  (int)*(char *)(((int)*(char *)0x7817 + (uint)local_8) * 6 + 0x253f),
                  (int)*(char *)(((int)*(char *)0x7817 + (uint)local_8) * 6 + 0x253e));
    if (*(char *)0x7817 == '\x05') break;
    *(char *)0x7817 = *(char *)0x7817 + '\x01';
    uVar1 = 0x21a;
  }
  uVar1 = FUN_0000_b5b0(0x21a);
  local_3 = '\0';
  while (bVar2 = (byte)((uint)uVar1 >> 8),
        uVar1 = FUN_2000_a396((uint)bVar2 << 8,CONCAT11(bVar2,local_3),param_1,param_2),
        local_3 != '\x05') {
    local_3 = local_3 + '\x01';
  }
  return;
}


