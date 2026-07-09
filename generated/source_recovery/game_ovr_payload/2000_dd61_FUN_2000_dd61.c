/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:dd61
 * Ghidra name: FUN_2000_dd61
 * Linear address: 0x2DD61
 * Original GAME.OVR file offset: 187753
 * Body addresses: 146
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_2000_dd61(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  iVar2 = *(int *)*(undefined4 *)(param_1 + 10);
  iVar1 = *(int *)0x7455;
  if (param_2 == '\0') {
    *(int *)0x7455 = *(int *)0x7455 - *(int *)((undefined *)&DAT_0000_ffa7 + param_1);
    if (*(int *)0x7455 < 0) {
      *(undefined2 *)0x7455 = 0;
    }
  }
  else {
    *(int *)0x7455 = *(int *)0x7455 + *(int *)((undefined *)&DAT_0000_ffa7 + param_1);
    if (*(int *)((undefined *)&DAT_0000_ffa9 + param_1) -
        *(int *)((undefined *)&DAT_0000_ffa7 + param_1) < *(int *)0x7455) {
      *(int *)0x7455 =
           *(int *)((undefined *)&DAT_0000_ffa9 + param_1) -
           *(int *)((undefined *)&DAT_0000_ffa7 + param_1);
    }
  }
  iVar2 = *(int *)0x7455 + (iVar2 - iVar1);
  *(int *)*(undefined4 *)(param_1 + 10) = iVar2;
  FUN_2000_dc31(param_1,CONCAT11((char)((uint)iVar2 >> 8),param_2));
  FUN_2000_d898(param_1,*(undefined2 *)0x7455);
  return;
}


