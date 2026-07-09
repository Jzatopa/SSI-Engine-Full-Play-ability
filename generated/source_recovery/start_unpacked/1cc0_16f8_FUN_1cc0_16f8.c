/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1cc0:16f8
 * Ghidra name: FUN_1cc0_16f8
 * Linear address: 0x1E2F8
 * Body addresses: 152
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

undefined4 __cdecl16near FUN_1cc0_16f8(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int in_CX;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  byte bVar10;
  char cVar11;
  byte *unaff_DI;
  undefined2 unaff_ES;
  bool bVar12;
  bool bVar13;
  
  uVar2 = 0;
  uVar7 = 0;
  bVar1 = false;
  if (in_CX == 0) goto LAB_1cc0_1759;
  if (*unaff_DI == 0x2b) {
LAB_1cc0_170d:
    unaff_DI = unaff_DI + 1;
    in_CX = in_CX + -1;
    if (in_CX == 0) goto LAB_1cc0_1759;
  }
  else if (*unaff_DI == 0x2d) {
    bVar1 = true;
    goto LAB_1cc0_170d;
  }
  if (*unaff_DI == 0x24) {
    iVar4 = in_CX + -1;
    if (iVar4 == 0) {
LAB_1cc0_1759:
      return CONCAT22(uVar7,uVar2);
    }
    do {
      unaff_DI = unaff_DI + 1;
      bVar9 = *unaff_DI;
      if (0x60 < bVar9) {
        bVar9 = bVar9 - 0x20;
      }
      bVar10 = bVar9 - 0x30;
      if ((byte)(bVar9 - 0x3a) < 0xf6) {
        if ((byte)(bVar9 + 0xb9) < 0xfa) break;
        bVar10 = bVar9 - 0x37;
      }
      cVar11 = '\x04';
      do {
        bVar12 = (int)uVar2 < 0;
        uVar2 = uVar2 << 1;
        bVar13 = (int)uVar7 < 0;
        uVar7 = uVar7 << 1 | (uint)bVar12;
        if (bVar13) goto LAB_1cc0_1759;
        cVar11 = cVar11 + -1;
      } while (cVar11 != '\0');
      uVar2 = CONCAT11((char)(uVar2 >> 8),(byte)uVar2 | bVar10);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    do {
      uVar6 = (uint)(byte)(*unaff_DI - 0x30);
      if ((byte)(*unaff_DI - 0x3a) < 0xf6) break;
      if ((uVar7 & 0xf000) != 0) goto LAB_1cc0_1759;
      uVar3 = uVar2 * 2;
      uVar8 = uVar7 << 1 | (uint)((int)uVar2 < 0);
      iVar4 = uVar2 << 2;
      uVar5 = uVar2 * 8;
      uVar7 = uVar2 * 10;
      uVar2 = uVar7 + uVar6;
      uVar7 = ((uVar8 << 1 | (uint)((int)uVar3 < 0)) << 1 | (uint)(iVar4 < 0)) + uVar8 +
              (uint)CARRY2(uVar5,uVar3) + (uint)CARRY2(uVar7,uVar6);
      if ((int)uVar7 < 0) goto LAB_1cc0_1759;
      unaff_DI = unaff_DI + 1;
      in_CX = in_CX + -1;
    } while (in_CX != 0);
  }
  if (bVar1) {
    uVar6 = ~uVar2;
    uVar2 = uVar6 + 1;
    uVar7 = ~uVar7 + (uint)(0xfffe < uVar6);
  }
  return CONCAT22(uVar7,uVar2);
}


