/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:e480
 * Ghidra name: FUN_2000_e480
 * Linear address: 0x2E480
 * Original GAME.OVR file offset: 189576
 * Body addresses: 82
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_e480(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_CS;
  int local_6;
  int iStack_4;
  
  local_6 = *param_1;
  iStack_4 = ((int *)param_1)[1];
  while (local_6 != 0 || iStack_4 != 0) {
    iVar1 = *(int *)(local_6 + 0x2a);
    iVar2 = *(int *)(local_6 + 0x2c);
    FUN_0000_ce54(unaff_CS,0x2e,local_6,iStack_4);
    unaff_CS = 0xcc0;
    local_6 = iVar1;
    iStack_4 = iVar2;
  }
  return;
}


