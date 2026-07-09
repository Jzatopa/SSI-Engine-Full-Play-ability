/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 3000:1542
 * Ghidra name: FUN_3000_1542
 * Linear address: 0x31542
 * Original GAME.OVR file offset: 202058
 * Body addresses: 714
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_3000_1542(undefined2 param_1,byte param_2,uint param_3,char param_4,char param_5)

{
  byte bVar1;
  char cVar2;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  uint local_21;
  uint local_1f;
  char acStack_1d [4];
  char acStack_19 [4];
  char acStack_15 [4];
  char acStack_11 [4];
  char local_d;
  char local_c;
  char local_b;
  char local_a;
  char local_9;
  byte local_8;
  byte local_7;
  byte local_6;
  byte local_5;
  byte local_4;
  byte local_3;
  
  local_5 = 0;
  while( true ) {
    cVar2 = FUN_0000_0de9(unaff_CS,&local_d);
    if (cVar2 == '\0') {
      acStack_11[local_5] = -1;
    }
    else {
      acStack_11[local_5] = param_5 + local_c;
      acStack_15[local_5] = param_4 + local_d;
    }
    if (local_5 == 3) break;
    local_5 = local_5 + 1;
    unaff_CS = 0xdb;
  }
  *(undefined1 *)0x71e0 = 0;
  bVar1 = *(byte *)&DAT_0000_69f0;
  if (bVar1 != 0) {
    local_3 = 1;
    while( true ) {
      if (((undefined *)&DAT_0000_69f0)[(uint)local_3 * 4] != '\0') {
        local_9 = '\0';
        local_21 = 0xff;
        local_6 = 0;
        while( true ) {
          cVar2 = FUN_0000_0de9(0xdb,&local_d);
          if (cVar2 == '\0') {
            acStack_19[local_6] = -1;
          }
          else {
            acStack_19[local_6] = ((undefined *)&DAT_0000_69ed)[(uint)local_3 * 4] + local_c;
            acStack_1d[local_6] = ((undefined *)&DAT_0000_69ee)[(uint)local_3 * 4] + local_d;
          }
          if (local_6 == 3) break;
          local_6 = local_6 + 1;
        }
        local_6 = 0;
        while( true ) {
          if (-1 < acStack_19[local_6]) {
            local_5 = 0;
            while( true ) {
              if ((-1 < acStack_11[local_5]) &&
                 (cVar2 = FUN_3000_11b4(param_2,acStack_1d[local_6],acStack_19[local_6],
                                        acStack_15[local_5],acStack_11[local_5]), cVar2 != '\0')) {
                local_a = acStack_19[local_6];
                local_b = acStack_1d[local_6];
                local_1f = param_3;
                cVar2 = FUN_3000_105d(&local_1f,unaff_SS,&local_b,unaff_SS,&local_a,unaff_SS,
                                      acStack_15[local_5],acStack_11[local_5]);
                if ((cVar2 != '\0') && (local_9 = '\x01', local_1f < local_21)) {
                  local_21 = local_1f;
                  local_7 = local_5;
                  local_8 = local_6;
                }
              }
              if (local_5 == 3) break;
              local_5 = local_5 + 1;
            }
          }
          if (local_6 == 3) break;
          local_6 = local_6 + 1;
        }
        if (local_9 != '\0') {
          *(char *)0x71e0 = *(char *)0x71e0 + '\x01';
          *(byte *)((uint)*(byte *)0x71e0 * 3 + 0x71de) = local_3;
          *(undefined1 *)((uint)*(byte *)0x71e0 * 3 + 0x71df) = (undefined1)local_21;
          local_4 = 0;
          if (param_2 < 8) {
            local_4 = param_2;
          }
          else {
            while (cVar2 = FUN_3000_11b4(local_4,acStack_1d[local_8],acStack_19[local_8],
                                         acStack_15[local_7],acStack_11[local_7]), cVar2 == '\0') {
              local_4 = local_4 + 1;
            }
          }
          *(byte *)((uint)*(byte *)0x71e0 * 3 + 0x71e0) = local_4;
        }
      }
      if (local_3 == bVar1) break;
      local_3 = local_3 + 1;
    }
  }
  FUN_3000_0c9f();
  return;
}


