/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:4a92
 * Ghidra name: FUN_0000_4a92
 * Linear address: 0x04A92
 * Original GAME.OVR file offset: 19098
 * Body addresses: 247
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_4a92(undefined2 param_1,char param_2,byte param_3)

{
  uint *puVar1;
  char cVar2;
  undefined2 uVar3;
  byte bVar4;
  undefined1 extraout_AH;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 *puVar5;
  undefined1 local_10d [257];
  undefined1 local_c [5];
  char local_7;
  uint local_6;
  uint uStack_4;
  
  uStack_4 = *(uint *)0x5801;
  local_6 = *(uint *)0x57ff;
  do {
    if ((local_6 | uStack_4) == 0) {
      return;
    }
    if (*(char *)(local_6 + 0xd4) == '\x01') {
      uVar3 = FUN_0000_09b5(CONCAT11((char)((local_6 | uStack_4) >> 8),param_3));
      bVar4 = (byte)((uint)uVar3 >> 8);
      if (((char)uVar3 != '\0') || (param_2 != '\0')) {
        cVar2 = FUN_0000_0963(0x99,(uint)bVar4 << 8,CONCAT11(bVar4,2),local_6,uStack_4);
        if ((cVar2 != '\0') && ((param_2 == '\0' && (param_3 < 100)))) {
                    /* WARNING: Subroutine does not return */
          FUN_0000_d6c2(local_6,uStack_4,local_10d,unaff_SS,0xb);
        }
        if (param_2 == '\0') {
          local_7 = FUN_0000_09ba(0x92,9,1);
          local_7 = local_7 + '\x01';
        }
        else {
          local_7 = (char)*(undefined2 *)(local_6 + 0x45) + '\x1e';
        }
        puVar5 = local_c;
        FUN_0000_e390(4);
        FUN_0000_0a0f(0xcc0,local_7,local_6,uStack_4,puVar5);
                    /* WARNING: Subroutine does not return */
        FUN_0000_d6c2(local_6,uStack_4,local_10d,unaff_SS,CONCAT11(extraout_AH,0xb));
      }
    }
    puVar1 = (uint *)(local_6 + 0xff);
    uStack_4 = *(uint *)(local_6 + 0x101);
    local_6 = *puVar1;
  } while( true );
}


