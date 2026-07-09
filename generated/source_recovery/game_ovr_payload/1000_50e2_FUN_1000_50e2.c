/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:50e2
 * Ghidra name: FUN_1000_50e2
 * Linear address: 0x150E2
 * Original GAME.OVR file offset: 86250
 * Body addresses: 585
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined4 __stdcall16far FUN_1000_50e2(int param_1,char param_2)

{
  int iVar1;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 local_20 [18];
  int local_e;
  int local_c;
  int local_a;
  int local_8;
  int local_6;
  int local_4;
  
  iVar1 = (uint)*(byte *)(param_1 + (uint)*(byte *)(param_1 + -0xdb) * 3 + -0xdb) * 4;
  local_a = *(int *)((undefined *)&DAT_0000_707f + iVar1);
  local_8 = *(int *)((undefined *)&DAT_0000_7081 + iVar1);
  if (local_a == 0 && local_8 == 0) {
    local_a = *(int *)(param_1 + 0x16);
    local_8 = *(int *)(param_1 + 0x18);
  }
  if (*(char *)(param_1 + -0xda) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x3842,unaff_CS,local_20,unaff_SS);
  }
  *(undefined1 *)(param_1 + -0xdd) =
       ((undefined *)&DAT_0000_69ed)
       [(uint)*(byte *)(param_1 + (uint)*(byte *)(param_1 + -0xdb) * 3 + -0xdb) * 4];
  *(undefined1 *)(param_1 + -0xde) =
       ((undefined *)&DAT_0000_69ee)
       [(uint)*(byte *)(param_1 + (uint)*(byte *)(param_1 + -0xdb) * 3 + -0xdb) * 4];
  *(char *)(param_1 + -0xdb) = *(char *)(param_1 + -0xdb) + param_2;
  if (*(char *)(param_1 + -0xdb) == '\0') {
    *(undefined1 *)(param_1 + -0xdb) = *(undefined1 *)(param_1 + -0xda);
  }
  if (*(byte *)(param_1 + -0xda) < *(byte *)(param_1 + -0xdb)) {
    *(undefined1 *)(param_1 + -0xdb) = 1;
  }
  iVar1 = (uint)*(byte *)(param_1 + (uint)*(byte *)(param_1 + -0xdb) * 3 + -0xdb) * 4;
  local_e = *(int *)((undefined *)&DAT_0000_707f + iVar1);
  local_c = *(int *)((undefined *)&DAT_0000_7081 + iVar1);
  *(undefined1 *)(param_1 + -0xdf) =
       ((undefined *)&DAT_0000_69ed)
       [(uint)*(byte *)(param_1 + (uint)*(byte *)(param_1 + -0xdb) * 3 + -0xdb) * 4];
  *(undefined1 *)(param_1 + -0xe0) =
       ((undefined *)&DAT_0000_69ee)
       [(uint)*(byte *)(param_1 + (uint)*(byte *)(param_1 + -0xdb) * 3 + -0xdb) * 4];
  if (((local_e == 0 && local_c == 0) || (*(char *)(param_1 + -0xdf) < '\0')) ||
     (*(char *)(param_1 + -0xe0) < '\0')) {
    local_6 = local_a;
    local_4 = local_8;
    *(undefined1 *)(param_1 + -0xdf) = *(undefined1 *)(param_1 + -0xdd);
    *(undefined1 *)(param_1 + -0xe0) = *(undefined1 *)(param_1 + -0xde);
  }
  else {
    local_6 = local_e;
    local_4 = local_c;
    func_0x00000a00();
    *(undefined1 *)(param_1 + -0xdd) = *(undefined1 *)(param_1 + -0xdf);
    *(undefined1 *)(param_1 + -0xde) = *(undefined1 *)(param_1 + -0xe0);
  }
  return CONCAT22(local_4,local_6);
}


