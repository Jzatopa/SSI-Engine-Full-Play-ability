/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 1000:6651
 * Ghidra name: FUN_1000_6651
 * Linear address: 0x16651
 * Original GAME.OVR file offset: 91737
 * Body addresses: 193
 * Calling convention: __cdecl16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __cdecl16far FUN_1000_6651(void)

{
  undefined1 uVar1;
  undefined1 extraout_AH;
  uint uVar2;
  undefined2 unaff_BP;
  undefined2 unaff_DS;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar3 = *(undefined2 *)0x233e;
  FUN_0000_7840();
  FUN_0000_c05c(0x32,uVar3,unaff_BP);
  *"s\x15 at sensor operation!\x0eShip Character\x01" =
       *"s\x15 at sensor operation!\x0eShip Character\x01" +
       ((undefined *)&DAT_0000_26ca)[*(byte *)0x736b];
  *"\x15 at sensor operation!\x0eShip Character\x01" =
       *"\x15 at sensor operation!\x0eShip Character\x01" +
       ((undefined *)&DAT_0000_26d3)[*(byte *)0x736b];
  if (*"s\x15 at sensor operation!\x0eShip Character\x01" < '\0') {
    *(undefined1 *)0x7369 = 0xf;
  }
  if ('\x0f' < *"s\x15 at sensor operation!\x0eShip Character\x01") {
    *(undefined1 *)0x7369 = 0;
  }
  if (*"\x15 at sensor operation!\x0eShip Character\x01" < '\0') {
    *(undefined1 *)0x736a = 0xf;
  }
  if ('\x0f' < *"\x15 at sensor operation!\x0eShip Character\x01") {
    *(undefined1 *)0x736a = 0;
  }
  uVar1 = FUN_0000_0d3a(0xbdc,*(undefined1 *)0x736b);
  *(undefined1 *)0x736c = uVar1;
  uVar4 = 0x74b4;
  uVar3 = 3;
  FUN_0000_e6d2(1);
  uVar3 = func_0x00000d44(0xcc0,CONCAT11(extraout_AH,*(undefined1 *)0x736a),
                          CONCAT11(extraout_AH,*(undefined1 *)0x7369),uVar3,uVar4);
  *(undefined1 *)0x736d = (char)uVar3;
  uVar2 = CONCAT11((char)((uint)uVar3 >> 8),*(undefined1 *)((int)*(undefined4 *)0x441c + 0x2ca)) &
          0xff01;
  uVar1 = (undefined1)(uVar2 >> 8);
  if ((char)uVar2 == '\0') {
    FUN_0000_08c5(0xd1,CONCAT11(uVar1,1),CONCAT11(uVar1,1));
  }
  else {
    FUN_0000_08c5(0xd1,CONCAT11(uVar1,2),CONCAT11(uVar1,1));
  }
  return;
}


