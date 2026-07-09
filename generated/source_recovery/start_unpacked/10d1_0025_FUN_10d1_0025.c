/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 10d1:0025
 * Ghidra name: FUN_10d1_0025
 * Linear address: 0x10D35
 * Body addresses: 30
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

uint __stdcall16far FUN_10d1_0025(void)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  undefined2 uVar4;
  int in_BX;
  int unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  byte in_AF;
  undefined2 in_stack_0000000a;
  
  pcVar1 = (code *)swi(0x3f);
  iVar3 = (*pcVar1)();
  *(int *)(in_BX + unaff_SI) = *(int *)(in_BX + unaff_SI) + iVar3;
  pcVar1 = (code *)swi(0x3f);
  uVar4 = (*pcVar1)();
  in_AF = 9 < ((byte)uVar4 & 0xf) | in_AF;
  *unaff_DI = CONCAT11((char)((uint)uVar4 >> 8) - in_AF,(byte)uVar4 + in_AF * -6) & 0xff0f;
  pcVar1 = (code *)swi(0x3f);
  bVar2 = (*pcVar1)();
  bVar2 = 9 < ((byte)in_stack_0000000a & 0xf) | 9 < (bVar2 & 0xf) | in_AF;
  return CONCAT11((char)((uint)in_stack_0000000a >> 8) - bVar2,(byte)in_stack_0000000a + bVar2 * -6)
         & 0xff0f;
}


