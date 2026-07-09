/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:4a43
 * Ghidra name: FUN_1000_4a43
 * Linear address: 0x14A43
 * Original GAME.OVR file offset: 84555
 * Body addresses: 235
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far
FUN_1000_4a43(undefined2 *param_1,char *param_2,char param_3,undefined2 param_4,undefined2 param_5,
             undefined2 param_6,undefined2 param_7)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  byte extraout_AH;
  undefined2 *puVar4;
  undefined2 uVar5;
  undefined2 unaff_DS;
  undefined2 uVar6;
  undefined2 uVar7;
  
  *param_2 = '\x01';
  if ((param_3 == '\x01') && (cVar1 = FUN_1000_46aa(param_4,param_5,param_6,param_7), cVar1 == '\0')
     ) {
    *param_2 = '\0';
  }
  puVar4 = (undefined2 *)param_1;
  uVar5 = (undefined2)((ulong)param_1 >> 0x10);
  if (*param_2 == '\0') {
    FUN_0000_e6d2(0);
  }
  else {
    *param_1 = param_4;
    puVar4[1] = param_5;
    uVar6 = param_4;
    uVar7 = param_5;
    uVar2 = FUN_0000_0e20();
    *(undefined1 *)(puVar4 + 2) = uVar2;
    uVar2 = FUN_0000_0e25(param_4,param_5,uVar6,uVar7);
    *(undefined1 *)((int)puVar4 + 5) = uVar2;
    *(undefined1 *)((int)*(undefined4 *)0x71dc + 4) = 0;
    iVar3 = *(char *)((int)*(undefined4 *)0x71dc + 3) + 3;
    uVar2 = (undefined1)((uint)iVar3 >> 8);
    FUN_0000_0e16(0xdb,CONCAT11(uVar2,8),CONCAT11(uVar2,3),iVar3,
                  *(char *)((int)*(undefined4 *)0x71dc + 2) + 3);
    if (param_3 == '\x01') {
      FUN_1000_27d4(param_4,param_5,param_6,param_7);
      FUN_1000_3b01((char *)param_2,(int)((ulong)param_2 >> 0x10),(uint)extraout_AH << 8,param_4,
                    param_5,param_6,param_7);
    }
  }
  return;
}


