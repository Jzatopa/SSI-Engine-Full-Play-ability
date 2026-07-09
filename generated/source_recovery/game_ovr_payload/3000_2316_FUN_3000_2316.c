/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:2316
 * Ghidra name: FUN_3000_2316
 * Linear address: 0x32316
 * Original GAME.OVR file offset: 205598
 * Body addresses: 354
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_3000_2316(byte param_1,undefined1 param_2,char param_3,char param_4)

{
  byte bVar1;
  uint uVar2;
  undefined2 uVar3;
  char extraout_AL;
  char cVar4;
  int iVar5;
  undefined1 uVar7;
  undefined1 extraout_AH;
  uint uVar6;
  undefined2 unaff_CS;
  undefined2 uVar8;
  undefined2 unaff_DS;
  char local_9;
  char local_8;
  byte local_7;
  
  local_8 = param_4 + ((undefined *)&DAT_0000_26ca)[param_1];
  iVar5 = (int)param_3 + (int)(char)((undefined *)&DAT_0000_26d3)[param_1];
  local_9 = (char)iVar5;
  uVar7 = (undefined1)((uint)iVar5 >> 8);
  FUN_3000_2188(CONCAT11(uVar7,param_2),iVar5,CONCAT11(uVar7,local_8));
  uVar7 = extraout_AH;
  if ((extraout_AL != '\0') && (bVar1 = *(byte *)&DAT_0000_69f0, bVar1 != 0)) {
    local_7 = 1;
    while( true ) {
      uVar2 = *(uint *)((undefined *)&DAT_0000_707f + (uint)local_7 * 4);
      uVar3 = *(undefined2 *)((undefined *)&DAT_0000_7081 + (uint)local_7 * 4);
      uVar6 = uVar2;
      uVar8 = unaff_CS;
      if (((*(char *)(uVar2 + 0xd5) != '\0') &&
          (uVar6 = (uint)local_7, ((undefined *)&DAT_0000_69f0)[uVar6 * 4] != '\0')) &&
         (uVar6 = FUN_3000_20ce(0,uVar2,uVar3), (char)uVar6 != '\0')) {
        uVar8 = 0xe5;
        uVar6 = func_0x00000e84(unaff_CS,*(undefined1 *)(uVar2 + 0xb9),0,
                                *(undefined1 *)((int)*(undefined4 *)(uVar2 + 0xf3) + 7),
                                ((undefined *)&DAT_0000_6b58)[local_7],
                                ((undefined *)&DAT_0000_6b10)[local_7]);
      }
      uVar7 = (undefined1)(uVar6 >> 8);
      if (local_7 == bVar1) break;
      local_7 = local_7 + 1;
      unaff_CS = uVar8;
    }
  }
  FUN_3000_1cef(CONCAT11(uVar7,param_3),CONCAT11(uVar7,param_4));
  cVar4 = FUN_3000_209d((int)local_9 - (int)*(char *)((int)*(undefined4 *)0x71dc + 3),
                        (int)local_8 - (int)*(char *)((int)*(undefined4 *)0x71dc + 2));
  if (cVar4 == '\0') {
    if ('1' < local_8) {
      local_8 = '1';
    }
    if (local_8 < '\0') {
      local_8 = '\0';
    }
    if ('\x18' < local_9) {
      local_9 = '\x18';
    }
    if (local_9 < '\0') {
      local_9 = '\0';
    }
  }
  FUN_3000_1b72(local_9,local_8);
  FUN_0000_39b7();
  return;
}


