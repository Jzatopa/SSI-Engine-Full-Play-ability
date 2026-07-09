/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:0308
 * Ghidra name: FUN_1cc0_0308
 * Linear address: 0x1CF08
 * Body addresses: 7
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

uint * __cdecl16near FUN_1cc0_0308(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int in_AX;
  undefined2 *puVar5;
  uint uVar6;
  int in_DX;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int unaff_DS;
  bool bVar11;
  undefined4 uVar12;
  uint *puVar13;
  uint *puVar14;
  
  puVar9 = (uint *)0x0;
  if (in_AX != 0) {
    *(int *)0xa19a = in_AX;
    uVar12 = FUN_1cc0_0491();
    uVar8 = (uint)((ulong)uVar12 >> 0x10);
    uVar6 = (uint)uVar12;
    puVar9 = (uint *)0x3db4;
    in_DX = unaff_DS;
    do {
      iVar10 = in_DX;
      puVar14 = puVar9;
      puVar13 = *(uint **)puVar14;
      in_DX = (int)((ulong)puVar13 >> 0x10);
      puVar9 = (uint *)puVar13;
      if (in_DX == *(int *)0x3dae) {
        bVar4 = (byte)(uVar6 + (int)puVar9);
        uVar8 = uVar8 + in_DX + (uint)(0xf < bVar4);
        uVar6 = CONCAT11((char)(uVar6 + (int)puVar9 >> 8),bVar4 - 0x10) & 0xff0f;
        if ((uVar8 < *(uint *)0x3db2) || ((uVar8 <= *(uint *)0x3db2 && (uVar6 <= *(uint *)0x3db0))))
        {
          *(uint *)0x3dac = uVar6;
          *(uint *)0x3dae = uVar8;
          *puVar14 = uVar6;
          puVar14[1] = uVar8;
          puVar14 = (uint *)0x0;
          (*(code *)*(undefined2 *)0x3dbc)(0x1cc0,0,puVar9,in_DX);
          return (uint *)CONCAT22(puVar9,puVar14);
        }
        puVar13 = (uint *)(*(code *)*(undefined2 *)0x3dbc)(0x1cc0,*(undefined2 *)0xa19a);
        in_DX = (int)((ulong)puVar13 >> 0x10);
        puVar9 = (uint *)puVar13;
        if ((char)puVar13 != '\0') {
          if ((char)puVar13 != '\x01') {
            puVar13 = (uint *)FUN_1cc0_030f();
            return puVar13;
          }
          return (uint *)0x0;
        }
        goto LAB_1cc0_0382;
      }
      uVar1 = puVar9[3];
      bVar11 = uVar8 == uVar1;
    } while ((uVar1 < uVar8) ||
            ((uVar1 <= uVar8 && (bVar11 = uVar6 == puVar9[2], puVar9[2] < uVar6))));
    uVar1 = puVar9[1];
    puVar5 = (undefined2 *)*puVar13;
    uVar7 = uVar1;
    if (!bVar11) {
      uVar2 = puVar9[2];
      uVar3 = puVar9[3];
      bVar4 = (byte)(uVar6 + (int)puVar9);
      uVar7 = uVar8 + in_DX + (uint)(0xf < bVar4);
      puVar5 = (undefined2 *)(CONCAT11((char)(uVar6 + (int)puVar9 >> 8),bVar4 - 0x10) & 0xff0f);
      *puVar5 = (undefined2 *)*puVar13;
      puVar5[1] = uVar1;
      puVar5[2] = uVar2 - uVar6 & 0xf;
      puVar5[3] = (uVar3 - uVar8) - (uint)(uVar2 < uVar6);
    }
    *puVar14 = (uint)puVar5;
    puVar14[1] = uVar7;
  }
LAB_1cc0_0382:
  return (uint *)CONCAT22(in_DX,puVar9);
}


