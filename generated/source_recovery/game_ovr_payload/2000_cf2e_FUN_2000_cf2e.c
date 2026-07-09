/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:cf2e
 * Ghidra name: FUN_2000_cf2e
 * Linear address: 0x2CF2E
 * Original GAME.OVR file offset: 184118
 * Body addresses: 154
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_cf2e(int param_1)

{
  int iVar1;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  *(undefined1 *)(param_1 + -0x212) = 1;
  iVar1 = *(int *)(param_1 + -0x210);
  if (iVar1 == 1) {
    if ((*(int *)(param_1 + -0x20e) < 8) || (0x18 < *(int *)(param_1 + -0x20e))) {
      if ((0x1e < *(int *)(param_1 + -0x20e)) && (*(int *)(param_1 + -0x20e) < 0x27)) {
        *(undefined1 *)0x747d = 8;
      }
    }
    else {
      *(undefined1 *)0x747d = 7;
    }
  }
  else if ((iVar1 < 0xf) || (0x15 < iVar1)) {
    *(undefined1 *)(param_1 + -0x212) = 0;
  }
  else if ((4 < *(int *)(param_1 + -0x20e)) && (*(int *)(param_1 + -0x20e) < 0xb)) {
    *(char *)0x747d = (char)*(undefined2 *)(param_1 + -0x210) + -0xf;
  }
  *(undefined1 *)0x8d71 = 0;
  *(undefined1 *)0x7458 = 1;
  return;
}


