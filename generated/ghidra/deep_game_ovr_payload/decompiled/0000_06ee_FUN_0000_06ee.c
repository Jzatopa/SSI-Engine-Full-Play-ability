
void FUN_0000_06ee(void)

{
  byte *pbVar1;
  byte bVar2;
  byte in_DL;
  byte bVar3;
  int in_BX;
  undefined4 in_ESI;
  undefined2 unaff_DI;
  undefined2 unaff_CS;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar4;
  undefined1 in_XMM0 [16];
  
  bVar4 = CARRY1(in_DL,((undefined *)&DAT_0000_ffb0)[in_BX + (int)in_ESI]);
  bVar3 = in_DL + ((undefined *)&DAT_0000_ffb0)[in_BX + (int)in_ESI];
  do {
    bVar3 = bVar3 + ((undefined *)&DAT_0000_ffb0)[in_BX + (int)in_ESI] + bVar4;
    in_ESI = movmskps(in_ESI,in_XMM0);
    pbVar1 = (undefined *)&DAT_0000_ff8d + in_BX + (int)in_ESI;
    bVar4 = CARRY1(*pbVar1,bVar3);
    bVar2 = *pbVar1;
    *pbVar1 = *pbVar1 + bVar3;
  } while (*pbVar1 == 0 || SCARRY1(bVar2,bVar3) != (char)*pbVar1 < '\0');
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x212,unaff_CS,unaff_DI,unaff_SS);
}


