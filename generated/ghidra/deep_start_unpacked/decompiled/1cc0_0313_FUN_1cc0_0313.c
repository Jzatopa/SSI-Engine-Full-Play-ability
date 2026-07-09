
uint * __cdecl16near FUN_1cc0_0313(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  undefined1 in_AL;
  byte bVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint in_DX;
  uint uVar7;
  uint uVar8;
  uint *unaff_DI;
  int iVar9;
  int iVar10;
  int unaff_DS;
  bool bVar11;
  uint *puVar12;
  
  uVar6 = CONCAT11(0x3d,in_AL);
  iVar10 = unaff_DS;
  while( true ) {
    iVar9 = iVar10;
    puVar12 = unaff_DI;
    puVar3 = *(uint **)puVar12;
    iVar10 = (int)((ulong)puVar3 >> 0x10);
    unaff_DI = (uint *)puVar3;
    if (iVar10 == *(int *)0x3dae) break;
    uVar8 = unaff_DI[3];
    bVar11 = in_DX == uVar8;
    if ((in_DX <= uVar8) &&
       ((in_DX < uVar8 || (bVar11 = uVar6 == unaff_DI[2], uVar6 <= unaff_DI[2])))) {
      uVar8 = unaff_DI[1];
      puVar5 = (undefined2 *)*puVar3;
      uVar7 = uVar8;
      if (!bVar11) {
        uVar1 = unaff_DI[2];
        uVar2 = unaff_DI[3];
        bVar4 = (byte)(uVar6 + (int)unaff_DI);
        uVar7 = in_DX + iVar10 + (uint)(0xf < bVar4);
        puVar5 = (undefined2 *)(CONCAT11((char)(uVar6 + (int)unaff_DI >> 8),bVar4 - 0x10) & 0xff0f);
        *puVar5 = (undefined2 *)*puVar3;
        puVar5[1] = uVar8;
        puVar5[2] = uVar1 - uVar6 & 0xf;
        puVar5[3] = (uVar2 - in_DX) - (uint)(uVar1 < uVar6);
      }
      *puVar12 = (uint)puVar5;
      puVar12[1] = uVar7;
      return unaff_DI;
    }
  }
  bVar4 = (byte)(uVar6 + (int)unaff_DI);
  uVar8 = in_DX + iVar10 + (uint)(0xf < bVar4);
  uVar6 = CONCAT11((char)(uVar6 + (int)unaff_DI >> 8),bVar4 - 0x10) & 0xff0f;
  if ((uVar8 < *(uint *)0x3db2) || ((uVar8 <= *(uint *)0x3db2 && (uVar6 <= *(uint *)0x3db0)))) {
    *(uint *)0x3dac = uVar6;
    *(uint *)0x3dae = uVar8;
    *puVar12 = uVar6;
    puVar12[1] = uVar8;
    puVar12 = (uint *)0x0;
    (*(code *)*(undefined2 *)0x3dbc)(0x1cc0,0,unaff_DI,iVar10);
    return puVar12;
  }
  puVar12 = (uint *)(*(code *)*(undefined2 *)0x3dbc)(0x1cc0,*(undefined2 *)0xa19a);
  if ((char)puVar12 == '\0') {
    return puVar12;
  }
  if ((char)puVar12 == '\x01') {
    return (uint *)0x0;
  }
  puVar12 = (uint *)FUN_1cc0_030f();
  return puVar12;
}


