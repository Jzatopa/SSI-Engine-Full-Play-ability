/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1c6a:0130
 * Ghidra name: FUN_1c6a_0130
 * Linear address: 0x1C7D0
 * Body addresses: 88
 * Calling convention: __cdecl16near
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

void __cdecl16near FUN_1c6a_0130(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  undefined2 uVar5;
  byte bVar6;
  int iVar7;
  int unaff_BP;
  byte *pbVar8;
  byte *pbVar9;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  
  uVar5 = *(undefined2 *)0x2c;
  pbVar8 = (byte *)0x0;
  bVar10 = true;
  do {
    pbVar9 = (byte *)0xd;
    iVar7 = 5;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      pbVar4 = pbVar9;
      pbVar9 = pbVar9 + 1;
      pbVar1 = pbVar8;
      pbVar8 = pbVar8 + 1;
      bVar10 = *pbVar1 == *pbVar4;
    } while (bVar10);
    if (bVar10) {
      do {
        if (*pbVar8 == 0) {
          return;
        }
        pbVar9 = (byte *)(unaff_BP + -0x82);
        bVar6 = 0;
        while( true ) {
          pbVar2 = pbVar8 + 1;
          bVar3 = *pbVar8;
          if ((bVar3 == 0) || (pbVar8 = pbVar2, bVar3 == 0x3b)) break;
          pbVar1 = pbVar9;
          pbVar9 = pbVar9 + 1;
          *pbVar1 = bVar3;
          bVar6 = bVar3;
        }
        bVar10 = bVar6 < 0x3a;
        if ((bVar6 != 0x3a) && (bVar10 = bVar6 < 0x5c, bVar6 != 0x5c)) {
          *pbVar9 = 0x5c;
        }
        FUN_1c6a_0188();
      } while (bVar10);
      return;
    }
    pbVar8 = pbVar8 + -1;
    do {
      pbVar1 = pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (*pbVar1 != 0);
    bVar10 = false;
    if (*pbVar8 == 0) {
      return;
    }
  } while( true );
}


