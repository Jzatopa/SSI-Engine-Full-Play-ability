/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:19b3
 * Ghidra name: FUN_1000_19b3
 * Linear address: 0x119B3
 * Original GAME.OVR file offset: 72123
 * Body addresses: 471
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_1000_19b3(byte param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined1 local_10;
  undefined2 local_e;
  char local_c [2];
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  int local_7;
  int iStack_5;
  char local_3;
  
  uVar2 = func_0x00000968();
  uVar5 = (undefined2)((ulong)param_3 >> 0x10);
  iVar4 = (int)param_3;
  iVar3 = (int)*(char *)(iVar4 + (uint)param_1 + 0xe0) + (uVar2 & 0xff);
  if (iVar3 < 1) {
    *(undefined1 *)0x72c6 = 0;
  }
  else {
    local_10 = (undefined1)iVar3;
    *(undefined1 *)0x72c6 = local_10;
  }
  if (*(char *)0x7511 == '\x02') {
    if (*(char *)(iVar4 + 0x28) == '\x05') {
      *(char *)0x72c6 = *(char *)0x72c6 * (char)((int)*(char *)(iVar4 + 0x29) + 7U >> 2);
    }
    else {
      *(char *)0x72c6 = *(char *)0x72c6 << 1;
    }
  }
  FUN_0000_0981(0x92,&param_3);
  FUN_0000_0981(0x92,&param_2);
  uVar5 = (undefined2)((ulong)param_3 >> 0x10);
  iVar3 = (int)param_3;
  local_7 = *(int *)(iVar3 + 0xeb);
  iStack_5 = *(int *)(iVar3 + 0xed);
  if (local_7 != 0 || iStack_5 != 0) {
    local_9 = FUN_0000_0e20(0x92,iVar3,uVar5);
    local_a = FUN_0000_0e25((undefined2)param_3,param_3._2_2_);
    local_e = 0xff;
    uVar5 = FUN_0000_0e20(0xdb,(undefined2)param_2,param_2._2_2_);
    FUN_0000_0e25((undefined2)param_2,param_2._2_2_,uVar5);
    local_8 = FUN_0000_0da4(0xdb,&local_e);
    func_0x00000e02(0xd7,local_c);
    if (local_c[0] == '\x01') {
      *(undefined1 *)0x4134 = 1;
    }
    else if (local_c[0] == '\x04') {
      *(undefined1 *)0x4135 = 1;
    }
    iVar3 = (uint)*(byte *)(local_7 + 0x2e) * 9;
    local_3 = ((undefined *)&DAT_0000_5370)[iVar3];
    uVar5 = (undefined2)((ulong)param_2 >> 0x10);
    if (local_3 == '\x02') {
      if (*(char *)0x4134 == '\0') {
        uVar2 = CONCAT11((char)((uint)iVar3 >> 8),*(undefined1 *)((int)param_2 + 0x48)) & 0xff10;
        if ((((char)uVar2 == '\0') ||
            (uVar2 = FUN_0000_09b5(CONCAT11((char)(uVar2 >> 8),0x32)), (char)uVar2 == '\0')) &&
           ((uVar2 = CONCAT11((char)(uVar2 >> 8),*(undefined1 *)((int)param_2 + 0x48)) & 0xff20,
            (char)uVar2 == '\0' ||
            (cVar1 = FUN_0000_09b5(CONCAT11((char)(uVar2 >> 8),0x4b)), cVar1 == '\0'))))
        goto LAB_1000_1b7f;
      }
      *(undefined1 *)0x72c6 = 0;
    }
    else if (local_3 == '\x03') {
      if (*(char *)0x4135 != '\0') {
        *(undefined1 *)0x72c6 = 0;
      }
    }
    else if ((local_3 == '\x04') && ((*(byte *)((int)param_2 + 0x48) & 0x40) != 0)) {
      *(undefined1 *)0x72c6 = 0;
    }
  }
LAB_1000_1b7f:
  *(undefined1 *)0x72c7 = 0;
  return;
}


