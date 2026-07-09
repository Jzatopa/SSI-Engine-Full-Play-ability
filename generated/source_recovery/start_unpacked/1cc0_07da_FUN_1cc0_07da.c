/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:07da
 * Ghidra name: FUN_1cc0_07da
 * Linear address: 0x1D3DA
 * Body addresses: 15
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined4 __cdecl16near FUN_1cc0_07da(undefined4 param_1)

{
  undefined2 in_AX;
  int iVar1;
  int in_DX;
  int in_BX;
  int unaff_DI;
  int iVar2;
  undefined2 unaff_ES;
  undefined2 uVar3;
  
  *(undefined1 *)(in_BX + unaff_DI) = (char)in_AX;
  if (in_BX + 1 != in_DX) {
    return CONCAT22(in_DX,in_AX);
  }
  uVar3 = (undefined2)((ulong)param_1 >> 0x10);
  iVar2 = (int)param_1;
  *(int *)(iVar2 + 8) = in_BX + 1;
  iVar1 = (*(code *)*(undefined2 *)(iVar2 + 0x14))(0x1cc0,iVar2,uVar3,iVar2,uVar3);
  if (iVar1 != 0) {
    DAT_1e87_3dce = iVar1;
  }
  return CONCAT22(*(undefined2 *)(iVar2 + 4),*(undefined2 *)(iVar2 + 10));
}


