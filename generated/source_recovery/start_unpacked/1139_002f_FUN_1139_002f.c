/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1139:002f
 * Ghidra name: FUN_1139_002f
 * Linear address: 0x113BF
 * Body addresses: 159
 * Calling convention: __stdcall16far
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x000113f6) overlaps instruction at (ram,0x000113f5)
    */

undefined2 __stdcall16far FUN_1139_002f(void)

{
  byte bVar1;
  code *pcVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 extraout_DX;
  int in_BX;
  int iVar5;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_PF;
  undefined1 uVar6;
  
  pcVar2 = (code *)swi(0x3f);
  cVar3 = (*pcVar2)();
  if (!(bool)in_PF) {
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  }
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar3;
  iVar5 = CONCAT11((char)((uint)in_BX >> 8) * '\x02',(byte)in_BX);
  cVar3 = cVar3 + (char)*(undefined2 *)(iVar5 + unaff_SI);
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(iVar5 + unaff_SI) = *(char *)(iVar5 + unaff_SI) + cVar3;
  *(char *)(unaff_DI + -0x77) = *(char *)(unaff_DI + -0x77) + (char)extraout_DX;
  in(0x83);
  uVar4 = in(extraout_DX);
  uVar6 = ((byte)in_BX & *(byte *)(unaff_BP + unaff_SI + 0x30d)) == 0;
  do {
    *(undefined1 *)0x413c = uVar4;
    FUN_1cc0_0d77(0);
    if (!(bool)uVar6) {
      uVar6 = *(char *)0x413c == '0';
      iVar5 = unaff_BP + -0x21;
      FUN_1cc0_0cf3(iVar5);
      FUN_1cc0_0d23(CONCAT11(extraout_AH,*(undefined1 *)(unaff_BP + 6)),
                    CONCAT11(extraout_AH,*(undefined1 *)(unaff_BP + 8)));
      FUN_1cc0_0d77(iVar5);
      if (!(bool)uVar6) {
        FUN_1cc0_08b5(0,CONCAT11(extraout_AH_00,*(undefined1 *)0x413c));
        FUN_1cc0_086c();
        bVar1 = *(byte *)0x413c;
        *(undefined1 *)(unaff_BP + -1) = (char)(bVar1 - 0x30);
        return CONCAT11((char)(bVar1 - 0x30 >> 8),*(undefined1 *)(unaff_BP + -1));
      }
    }
    uVar4 = FUN_1bdc_030d();
  } while( true );
}


