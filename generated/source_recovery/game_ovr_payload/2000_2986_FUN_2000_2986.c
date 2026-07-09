/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 2000:2986
 * Ghidra name: FUN_2000_2986
 * Linear address: 0x22986
 * Original GAME.OVR file offset: 141710
 * Body addresses: 90
 * Calling convention: unknown
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - item_debug_fields (items), previous candidate, distance 2138 byte(s), source offset 143848
 *   - gear_menu (inventory), previous candidate, distance 3877 byte(s), source offset 145587
 */

void FUN_2000_2986(undefined2 param_1,char param_2,char param_3)

{
  undefined2 unaff_DS;
  undefined1 local_107 [256];
  undefined1 local_7;
  undefined1 local_6 [4];
  
  if (param_2 == '\0') {
    local_7 = 0xf;
  }
  else {
    local_7 = 0xd;
  }
  func_0x00001140();
  FUN_0000_733e(0xec,CONCAT11(param_3 >> 7,
                              *(undefined1 *)((int)*(undefined4 *)0x57fb + (int)param_3 + 0x10)),
                local_107);
  func_0x0000d6dc(0x602,3,local_6);
  return;
}


