/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 121a:3d72
 * Ghidra name: FUN_121a_3d72
 * Linear address: 0x15F12
 * Body addresses: 165
 * Calling convention: __stdcall16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined4 FUN_121a_3d72(undefined1 param_1,uint param_2,byte param_3,byte param_4)

{
  uint uVar1;
  byte bVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  bVar2 = param_3;
  if (param_3 < param_4) {
    LOCK();
    param_3 = param_4;
    UNLOCK();
    param_4 = bVar2;
  }
  out(0x3ce,5);
  out(0x3cf,0);
  out(0x3ce,1);
  out(0x3cf,0xf);
  out(0x3ce,0);
  out(0x3cf,param_1);
  out(0x3ce,3);
  out(0x3cf,0);
  out(0x3c4,2);
  out(0x3c5,0xf);
  puVar3 = (undefined1 *)((uint)param_4 * 0x28 + (param_2 >> 3));
  uVar1 = (uint)puVar3 >> 8;
  out(0x3ce,8);
  out(0x3cf,(char)(0x80 >> ((byte)param_2 & 7)));
  uVar4 = (uint)(byte)((param_3 - param_4) + 1);
  do {
    *puVar3 = *puVar3;
    puVar3 = puVar3 + 0x28;
    uVar4 = uVar4 - 1;
  } while (uVar4 != 0);
  out(0x3ce,1);
  out(0x3cf,0);
  out(0x3ce,8);
  out(0x3cf,0xff);
  return CONCAT22(0x3cf,CONCAT11((char)uVar1,0xff));
}


