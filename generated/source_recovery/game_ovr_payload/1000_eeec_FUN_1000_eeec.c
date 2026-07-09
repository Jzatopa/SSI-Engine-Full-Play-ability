/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:eeec
 * Ghidra name: FUN_1000_eeec
 * Linear address: 0x1EEEC
 * Original GAME.OVR file offset: 126708
 * Body addresses: 133
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 * Nearby project anchors:
 *   - item0_loader (items), next candidate, distance 246 byte(s), source offset 126462
 */

void __cdecl16far FUN_1000_eeec(void)

{
  undefined1 uVar1;
  undefined1 extraout_AH;
  undefined2 unaff_DS;
  undefined2 uVar2;
  undefined2 uVar3;
  
  uVar1 = func_0x00000d44();
  *(undefined1 *)0x736d = uVar1;
  if ((((*(char *)0x8c33 != '\0') || (*(char *)0x8c35 != '\0')) || (*(char *)0x8c37 != '\0')) ||
     ((*(char *)0x8c38 != '\0' || (*(char *)0x8c3a != '\0')))) {
    uVar3 = 0x8c18;
    uVar2 = 2;
    FUN_0000_e6d2(0);
    *(undefined1 *)0x74aa = 1;
    FUN_0000_0b75(0xcc0,uVar2,uVar3);
    FUN_0000_0a32(0xb5);
    *(undefined1 *)0x8c3a = 0;
    *(undefined1 *)0x8c37 = 0;
    *(undefined1 *)0x8c38 = 0;
    *(undefined1 *)0x8c33 = 0;
    *(undefined1 *)0x8c35 = 0;
    uVar1 = FUN_0000_0d3a(0x99,CONCAT11(extraout_AH,*(undefined1 *)0x736b),
                          CONCAT11(extraout_AH,*(undefined1 *)0x736a),
                          CONCAT11(extraout_AH,*(undefined1 *)0x7369));
    *(undefined1 *)0x736c = uVar1;
  }
  return;
}


