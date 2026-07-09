/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:1b72
 * Ghidra name: FUN_3000_1b72
 * Linear address: 0x31B72
 * Original GAME.OVR file offset: 203642
 * Body addresses: 381
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_1b72(char param_1,char param_2)

{
  undefined4 uVar1;
  char cVar2;
  uint uVar3;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_9;
  byte local_8;
  char local_7;
  char local_6;
  char local_5;
  char local_4;
  char local_3;
  
  local_3 = param_2 - *(char *)((int)*(undefined4 *)0x71dc + 2);
  local_4 = param_1 - *(char *)((int)*(undefined4 *)0x71dc + 3);
  local_7 = '\0';
  while( true ) {
    cVar2 = FUN_3000_181b(&local_6,unaff_SS,&local_5,unaff_SS,local_7,
                          *(undefined1 *)((int)*(undefined4 *)0x71dc + 5));
    if (((cVar2 != '\0') &&
        (cVar2 = FUN_3000_209d((int)local_4 + (int)local_6,(int)local_3 + (int)local_5),
        cVar2 != '\0')) &&
       (FUN_3000_1908((int)param_1 + (int)local_6,(int)param_2 + (int)local_5,
                      (int)local_4 + (int)local_6,(int)local_3 + (int)local_5),
       *(char *)((int)*(undefined4 *)0x71dc + 4) != '\0')) {
      uVar3 = (int)local_4 + (int)local_6;
      func_0x00000e84(unaff_CS,CONCAT11((char)(uVar3 >> 8),0x20),(uVar3 >> 8) << 8,(uVar3 >> 8) << 8
                      ,uVar3,(int)local_3 + (int)local_5);
      unaff_CS = 0xe5;
    }
    if (local_7 == '\x03') break;
    local_7 = local_7 + '\x01';
  }
  FUN_3000_1ed8(&local_9,unaff_SS,&local_8,unaff_SS,param_1,param_2);
  if ((local_8 != 0) &&
     (cVar2 = FUN_3000_20ce(0,*(undefined2 *)((undefined *)&DAT_0000_707f + (uint)local_8 * 4),
                            *(undefined2 *)((undefined *)&DAT_0000_7081 + (uint)local_8 * 4)),
     cVar2 != '\0')) {
    uVar1 = *(undefined4 *)
             ((int)*(undefined4 *)((undefined *)&DAT_0000_707f + (uint)local_8 * 4) + 0xf3);
    func_0x00000e84(unaff_CS,*(undefined1 *)
                              ((int)*(undefined4 *)((undefined *)&DAT_0000_707f + (uint)local_8 * 4)
                              + 0xb9),0,*(undefined1 *)((int)uVar1 + 7),
                    ((undefined *)&DAT_0000_6b58)[local_8],((undefined *)&DAT_0000_6b10)[local_8]);
  }
  return;
}


