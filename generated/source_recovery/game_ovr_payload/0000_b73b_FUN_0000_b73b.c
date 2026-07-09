/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:b73b
 * Ghidra name: FUN_0000_b73b
 * Linear address: 0x0B73B
 * Original GAME.OVR file offset: 46915
 * Body addresses: 262
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_b73b(char *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 unaff_DS;
  int iVar3;
  undefined2 uVar4;
  undefined1 local_1b [15];
  char local_c;
  undefined1 local_9;
  undefined1 local_6;
  undefined1 local_5;
  undefined1 local_4;
  undefined1 local_3;
  
  *(undefined *)&DAT_0000_7513 = 1;
  uVar2 = (undefined2)((ulong)param_3 >> 0x10);
  iVar1 = (int)param_3;
  local_3 = *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 3);
  local_4 = *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 7);
  iVar3 = iVar1;
  uVar4 = uVar2;
  local_5 = FUN_0000_0e20();
  local_6 = FUN_0000_0e25(iVar1,uVar2,iVar3,uVar4);
  local_c = param_2;
  *param_1 = '\0';
  local_9 = 8;
  while ((((param_2 == '\0' || (param_2 == '\r')) || (param_2 == 'D')) || (*param_1 != '\0'))) {
    if ((param_2 != ' ') || (*param_1 != '\0')) {
      if (*(byte *)((int)*(undefined4 *)(iVar1 + 0xf3) + 3) < 2) {
        *(undefined1 *)((int)*(undefined4 *)(iVar1 + 0xf3) + 3) = 0;
      }
      *(undefined1 *)&DAT_0000_7513 = 0;
      return;
    }
  }
  if (*(char *)(iVar1 + 0xd4) == '\v') {
    func_0x0000d6dc(0xdb,0xc,local_1b);
    return;
  }
  if (*(char *)(iVar1 + 0xd4) != '\n') {
    func_0x0000d6dc(0xdb,0xc,local_1b);
    return;
  }
  func_0x0000d6dc(0xdb,0xc,local_1b);
  return;
}


