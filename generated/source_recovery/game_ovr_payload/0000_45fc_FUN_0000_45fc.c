/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:45fc
 * Ghidra name: FUN_0000_45fc
 * Linear address: 0x045FC
 * Original GAME.OVR file offset: 17924
 * Body addresses: 86
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

undefined2 __stdcall16far FUN_0000_45fc(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 unaff_DS;
  int iVar5;
  
  uVar2 = 1;
  uVar3 = 10;
  uVar1 = FUN_0000_09ba();
  iVar5 = 10;
  uVar4 = FUN_0000_09ba(0x99,10,1,uVar1,uVar3,uVar2);
  iVar5 = (uVar4 & 0xff) - iVar5;
  return CONCAT11((char)((uint)iVar5 >> 8),
                  '\0' < (char)(((char)iVar5 + *(char *)((int)*(undefined4 *)0x534a + 0x37)) -
                               *(char *)((int)*(undefined4 *)0x534e + 0x37)));
}


