/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:f67d
 * Ghidra name: FUN_1000_f67d
 * Linear address: 0x1F67D
 * Original GAME.OVR file offset: 128645
 * Body addresses: 380
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - save_character (save_load), previous candidate, distance 902 byte(s), source offset 129547
 */

undefined2 __cdecl16far FUN_1000_f67d(void)

{
  byte bVar1;
  byte extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 uVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  byte *pbVar8;
  undefined1 local_531 [512];
  undefined1 local_331 [256];
  undefined1 local_231 [256];
  byte local_131;
  byte local_130;
  undefined1 local_30 [43];
  int local_5;
  undefined1 local_3;
  
  local_3 = 0;
  uVar3 = *(char *)0x74ae == '\0';
  if ((bool)uVar3) {
    pbVar8 = &local_131;
    uVar7 = 0xff;
    func_0x0000d6dc();
  }
  else {
    pbVar8 = &local_131;
    uVar7 = 0xff;
    func_0x0000d6dc();
  }
  do {
    FUN_0000_d7f2(local_130,local_231,unaff_SS,local_331,unaff_SS);
    FUN_0000_7b00(0xcc0,uVar7,pbVar8);
    uVar6 = 0x78b;
    uVar5 = 0x460;
    FUN_0000_d7c7(0x78b,0x460,0x78b);
    if (((bool)uVar3) && (local_130 < 0x43)) {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2(0x3276,unaff_DS,local_531,unaff_SS,(uint)extraout_AH << 8);
    }
    do {
      uVar4 = unaff_SS;
      FUN_0000_d70e(local_131 - 1,1,&local_131,unaff_SS,local_231);
      uVar2 = 0xc3e;
      FUN_0000_c4f2(local_30,unaff_SS,0x10,uVar4,uVar5);
      local_5 = *(int *)0x9f48;
      if (local_5 == 0) {
        uVar5 = 0;
        uVar3 = 1;
      }
      else {
        uVar3 = (undefined1)((uint)local_5 >> 8);
        if ((local_5 != 2) && (local_5 != 0x12)) {
          uVar7 = FUN_0000_e854(CONCAT11(uVar3,local_130),uVar6);
          bVar1 = (byte)((uint)uVar7 >> 8);
          if (0x42 < (byte)uVar7) {
                    /* WARNING: Subroutine does not return */
            FUN_0000_d6c2(0x487,0xcc0,local_331,unaff_SS,(uint)bVar1 << 8);
          }
                    /* WARNING: Subroutine does not return */
          FUN_0000_d6c2(0x3276,unaff_DS,local_331,unaff_SS,(uint)bVar1 << 8);
        }
        bVar1 = FUN_0000_e854(CONCAT11(uVar3,local_130),uVar6);
        if (bVar1 < 0x43) {
                    /* WARNING: Subroutine does not return */
          FUN_0000_d6c2(0x467,0xcc0,local_331,unaff_SS,uVar7);
        }
        uVar3 = local_131 - 1 == 0;
        uVar6 = unaff_SS;
        FUN_0000_d70e(local_131 - 1,1,&local_131,unaff_SS,local_231);
        uVar2 = 0xcc0;
        func_0x0000e800(0xcc0);
        uVar5 = *(undefined2 *)0x9f48;
      }
      local_5 = uVar5;
      FUN_0000_d977(uVar2,0x4a6,uVar2);
    } while ((bool)uVar3);
    FUN_0000_d977(0xcc0,0x4a6,0xcc0,CONCAT11(extraout_AH_00,(undefined1)local_5));
    if (!(bool)uVar3) {
      return 1;
    }
  } while( true );
}


