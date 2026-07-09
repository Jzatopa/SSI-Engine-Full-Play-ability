/*
 * Matrix Cubed source recovery corpus
 * Program: GAME.OVR payload
 * Ghidra entry: 0000:1eb0
 * Ghidra name: FUN_0000_1eb0
 * Linear address: 0x01EB0
 * Original GAME.OVR file offset: 7864
 * Body addresses: 121
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as raw overlay payload. Original GAME.OVR file offset is Ghidra linear + 8; relocation and overlay-manager context are not recovered.
 */

void __stdcall16far FUN_0000_1eb0(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 uVar4;
  undefined2 uVar5;
  
  uVar5 = *(undefined2 *)((undefined *)&DAT_0000_ffed + param_1);
  uVar2 = (uint)*(byte *)(param_1 + -0x11);
  uVar4 = 0;
  uVar3 = (uint)*(byte *)0x76d8;
  FUN_0000_06fd();
  FUN_0000_06fd(0x6b,*(undefined1 *)0x76d9,*(undefined1 *)(param_1 + -0x10),0,
                *(undefined2 *)((undefined *)&DAT_0000_ffeb + param_1),uVar3,uVar2,uVar4,uVar5);
  FUN_0000_06fd(0x6b,*(undefined1 *)0x76da,*(undefined1 *)(param_1 + -0xf),0,
                *(undefined2 *)((undefined *)&DAT_0000_ffe9 + param_1));
  cVar1 = ((undefined *)&DAT_0000_fff6)[param_1];
  FUN_0000_06fd(0x6b,CONCAT11(cVar1 >> 7,*(undefined1 *)0x76db),(int)cVar1,(int)cVar1 >> 0xf,
                *(undefined2 *)(param_1 + -0x19));
  return;
}


