/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:e2ad
 * Ghidra name: FUN_1000_e2ad
 * Linear address: 0x1E2AD
 * Original GAME.OVR file offset: 123573
 * Body addresses: 312
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_e2ad(int param_1,byte param_2)

{
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_104 [256];
  undefined1 local_4;
  char local_3;
  
  local_3 = FUN_1000_d6c3(param_1);
  ((undefined *)&DAT_0000_7718)[(uint)param_2 * 0x100] = 0;
  local_4 = 0;
  if (local_3 == '\0') {
    if (((undefined *)&DAT_0000_b500)[(int)*(undefined4 *)0x4418 + param_1] != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2((undefined *)&DAT_0000_7718 + (uint)param_2 * 0x100,unaff_DS,local_104,unaff_SS)
      ;
    }
  }
  else if (local_3 == '\x01') {
    if (param_1 == 0x7c00) {
      func_0x0000d6dc();
      return;
    }
    if (*(char *)((int)*(undefined4 *)0x441c + param_1 + -0x7c00) != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2((undefined *)&DAT_0000_7718 + (uint)param_2 * 0x100,unaff_DS,local_104,unaff_SS)
      ;
    }
  }
  else if (local_3 == '\x02') {
    if (*(char *)((int)*(undefined4 *)0x4420 + param_1 + -0x7a00) != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0000_d6c2((undefined *)&DAT_0000_7718 + (uint)param_2 * 0x100,unaff_DS,local_104,unaff_SS)
      ;
    }
  }
  else if ((local_3 == '\x03') &&
          (*(char *)((int)*(undefined4 *)0x4424 + param_1 + -0x8000) != '\0')) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2((undefined *)&DAT_0000_7718 + (uint)param_2 * 0x100,unaff_DS,local_104,unaff_SS);
  }
  return;
}


