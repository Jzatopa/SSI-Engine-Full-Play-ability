/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:a2b3
 * Ghidra name: FUN_1000_a2b3
 * Linear address: 0x1A2B3
 * Original GAME.OVR file offset: 107195
 * Body addresses: 363
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_a2b3(undefined2 param_1,char param_2,char param_3,char param_4)

{
  char cVar1;
  byte bVar2;
  undefined2 unaff_DS;
  undefined1 local_3;
  
  if (param_2 == '\0') {
    cVar1 = (char)((ulong)(long)(int)(uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xb8) % 6);
    bVar2 = *(byte *)((int)*(undefined4 *)0x57fb + 0xb8) / 6;
    FUN_1000_a0fa(param_1,0,0,0xfe,*(undefined1 *)((int)*(undefined4 *)0x57fb + 0xb8),
                  (char)bVar2 + 1,cVar1 + 6);
    param_4 = param_4 + cVar1;
    if (param_4 < '\0') {
      param_4 = '\x05';
    }
    else if ('\x05' < param_4) {
      param_4 = '\0';
    }
    param_3 = param_3 + bVar2;
    if (param_3 < '\0') {
      param_3 = '\x05';
    }
    else if ('\x05' < param_3) {
      param_3 = '\0';
    }
    *(char *)((int)*(undefined4 *)0x57fb + 0xb8) = param_3 * '\x06' + param_4;
    bVar2 = (byte)((uint)(param_3 + 1) >> 8);
    FUN_1000_a0fa(param_1,CONCAT11(bVar2,1),(uint)bVar2 << 8,CONCAT11(bVar2,0xfe),
                  CONCAT11(bVar2,*(undefined1 *)((int)*(undefined4 *)0x57fb + 0xb8)),param_3 + 1,
                  param_4 + 6);
  }
  else {
    local_3 = '\0';
    param_3 = '\0';
    while( true ) {
      param_4 = '\0';
      while( true ) {
        if ((int)local_3 == (uint)*(byte *)((int)*(undefined4 *)0x57fb + 0xb8)) {
          bVar2 = (byte)((uint)(param_3 + 1) >> 8);
          FUN_1000_a0fa(param_1,CONCAT11(bVar2,1),(uint)bVar2 << 8,CONCAT11(bVar2,0xfe),
                        CONCAT11(bVar2,local_3),param_3 + 1,param_4 + 6);
        }
        else {
          bVar2 = (byte)((uint)(param_3 + 1) >> 8);
          FUN_1000_a0fa(param_1,(uint)bVar2 << 8,(uint)bVar2 << 8,CONCAT11(bVar2,0xfe),
                        CONCAT11(bVar2,local_3),param_3 + 1,param_4 + 6);
        }
        local_3 = local_3 + '\x01';
        if (param_4 == '\x05') break;
        param_4 = param_4 + '\x01';
      }
      if (param_3 == '\x05') break;
      param_3 = param_3 + '\x01';
    }
  }
  FUN_0000_39b7();
  return;
}


