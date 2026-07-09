
void __stdcall16far FUN_1c3e_018d(byte *param_1,char *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  code *pcVar3;
  char cVar4;
  byte bVar5;
  undefined2 uVar6;
  byte *pbVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  byte *pbVar12;
  undefined2 uVar13;
  undefined2 uVar14;
  bool bVar15;
  
  uVar14 = (undefined2)((ulong)param_1 >> 0x10);
  pbVar9 = (byte *)param_1;
  pbVar7 = pbVar9 + 1 + *param_1;
  uVar13 = (undefined2)((ulong)param_2 >> 0x10);
  pcVar11 = (char *)param_2;
  pbVar10 = pbVar9 + 3;
  uVar6 = *(undefined2 *)(pbVar9 + 1);
  if ((pbVar7 < pbVar10) || ((char)((uint)uVar6 >> 8) != ':')) {
    pbVar10 = pbVar9 + 1;
    pcVar3 = (code *)swi(0x21);
    cVar4 = (*pcVar3)();
    uVar6 = CONCAT11(0x3a,cVar4 + 'A');
  }
  else {
    bVar5 = (byte)uVar6;
    if ((0x60 < bVar5) && (bVar5 < 0x7b)) {
      uVar6 = CONCAT11(0x3a,bVar5 - 0x20);
    }
  }
  pbVar9 = (byte *)(pcVar11 + 3);
  *(undefined2 *)(pcVar11 + 1) = uVar6;
  if ((pbVar10 == pbVar7) || (*pbVar10 != 0x5c)) {
    bVar15 = (byte)uVar6 < 0x40;
    pbVar1 = pbVar9;
    pbVar9 = (byte *)(pcVar11 + 4);
    *pbVar1 = 0x5c;
    pcVar3 = (code *)swi(0x21);
    (*pcVar3)();
    if ((!bVar15) && (*pbVar9 != 0)) {
      iVar8 = -1;
      do {
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pbVar1 = pbVar9;
        pbVar9 = pbVar9 + 1;
      } while (*pbVar1 != 0);
      pbVar9[-1] = 0x5c;
    }
  }
  for (iVar8 = (int)pbVar7 - (int)pbVar10; iVar8 != 0; iVar8 = iVar8 + -1) {
    pbVar2 = pbVar9;
    pbVar9 = pbVar9 + 1;
    pbVar1 = pbVar10;
    pbVar10 = pbVar10 + 1;
    *pbVar2 = *pbVar1;
  }
  *pbVar9 = 0;
  pbVar9 = (byte *)(pcVar11 + 1);
  pbVar10 = pbVar9;
  pbVar7 = pbVar9;
  do {
    pbVar1 = pbVar10;
    pbVar10 = pbVar10 + 1;
    bVar5 = *pbVar1;
    pbVar12 = pbVar7;
    if ((bVar5 == 0) || (bVar5 == 0x5c)) {
      if (*(int *)(pbVar7 + -2) == 0x2e5c) {
        pbVar12 = pbVar7 + -2;
      }
      else if (((*(int *)(pbVar7 + -2) == 0x2e2e) && (pbVar7[-3] == 0x5c)) &&
              (pbVar12 = pbVar7 + -3, pbVar7[-4] != 0x3a)) {
        do {
          pbVar12 = pbVar12 + -1;
        } while (*pbVar12 != 0x5c);
      }
      if (bVar5 == 0) {
        if (pbVar12[-1] == 0x3a) {
          pbVar1 = pbVar12;
          pbVar12 = pbVar12 + 1;
          *pbVar1 = 0x5c;
        }
        *param_2 = (char)pbVar12 - (char)pbVar9;
        return;
      }
    }
    else if ((0x60 < bVar5) && (bVar5 < 0x7b)) {
      bVar5 = bVar5 - 0x20;
    }
    pbVar7 = pbVar12 + 1;
    *pbVar12 = bVar5;
  } while( true );
}


