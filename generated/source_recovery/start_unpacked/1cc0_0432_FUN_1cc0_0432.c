/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0432
 * Ghidra name: FUN_1cc0_0432
 * Linear address: 0x1D032
 * Body addresses: 95
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1cc0_0432(void)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined2 *in_CX;
  int in_BX;
  undefined2 *unaff_DI;
  int unaff_ES;
  undefined2 unaff_DS;
  
  bVar3 = (byte)((int)in_CX + in_CX[2]);
  if ((in_BX + in_CX[3] + (uint)(0xf < bVar3) != unaff_ES) ||
     ((undefined2 *)(CONCAT11((char)((uint)((int)in_CX + in_CX[2]) >> 8),bVar3 - 0x10) & 0xff0f) !=
      unaff_DI)) {
    *in_CX = unaff_DI;
    in_CX[1] = unaff_ES;
    return;
  }
  if ((unaff_ES == *(int *)0x3dae) && (unaff_DI == (undefined2 *)*(undefined2 *)0x3dac)) {
    *(undefined2 *)0x3dac = in_CX;
    *(int *)0x3dae = in_BX;
    return;
  }
  *in_CX = *unaff_DI;
  in_CX[1] = unaff_DI[1];
  iVar1 = unaff_DI[3];
  iVar4 = unaff_DI[2] + in_CX[2];
  iVar2 = in_CX[3];
  bVar3 = (byte)iVar4;
  in_CX[2] = CONCAT11((char)((uint)iVar4 >> 8),bVar3 - 0x10) & 0xff0f;
  in_CX[3] = iVar1 + iVar2 + (uint)(0xf < bVar3);
  return;
}


