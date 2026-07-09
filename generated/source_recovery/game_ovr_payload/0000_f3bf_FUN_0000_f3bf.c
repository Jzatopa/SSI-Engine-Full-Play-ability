/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:f3bf
 * Ghidra name: FUN_0000_f3bf
 * Linear address: 0x0F3BF
 * Original GAME.OVR file offset: 62407
 * Body addresses: 387
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far
FUN_0000_f3bf(byte param_1,char param_2,char param_3,char param_4,char param_5,byte param_6)

{
  int in_AX;
  undefined1 uVar2;
  uint uVar1;
  undefined2 unaff_DS;
  byte local_5;
  char local_4;
  undefined1 local_3;
  
  if ((((param_5 < '\0') || (param_4 < '\0')) || ('\n' < param_5)) ||
     (('\x05' < param_4 ||
      (in_AX = (int)param_5,
      *(char *)(*(char *)0x400a * 0x108 + (uint)param_1 * 0x42 + param_4 * 0xb + in_AX + 0x3dec) ==
      '\0')))) {
    uVar2 = (undefined1)((uint)in_AX >> 8);
    local_3 = 0;
  }
  else {
    ((undefined *)&DAT_0000_69ed)[(uint)param_6 * 4] =
         param_5 + param_3 * '\x06' + param_2 * '\x05' + '\x16';
    ((undefined *)&DAT_0000_69ee)[(uint)param_6 * 4] = param_4 + param_2 * '\x05' + '\n';
    uVar1 = func_0x00000e34();
    if ((local_4 == '\0') &&
       ((local_5 != 0 && (uVar1 = (uint)local_5, ((undefined *)&DAT_0000_26d8)[uVar1 * 4] != -1))))
    {
      local_3 = 1;
      if ((*(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_707f + (uint)param_6 * 4) + 0xd5)
           != '\0') ||
         ((uVar1 = (uint)param_6,
          *(char *)((int)*(undefined4 *)((undefined *)&DAT_0000_707f + uVar1 * 4) + 0xd5) == '\0' &&
          (*(char *)0x8c26 == '\0')))) {
        uVar1 = (uint)param_5;
        *(undefined1 *)
         (*(char *)0x400a * 0x108 + (uint)param_1 * 0x42 + param_4 * 0xb + uVar1 + 0x3dec) = 0;
      }
      uVar2 = (undefined1)(uVar1 >> 8);
    }
    else {
      uVar2 = (undefined1)(uVar1 >> 8);
      local_3 = 0;
    }
  }
  return CONCAT11(uVar2,local_3);
}


