/*
 * Matrix Cubed source recovery corpus
 * Program: START.unpacked.exe
 * Ghidra entry: 1139:0020
 * Ghidra name: FUN_1139_0020
 * Linear address: 0x113B0
 * Body addresses: 15
 * Calling convention: unknown
 * Evidence limit: Imported as unpacked MZ executable. Pseudocode is call-graph/control-flow evidence, not original source text.
 */

/* WARNING: Instruction at (ram,0x000113f6) overlaps instruction at (ram,0x000113f5)
    */

undefined2 FUN_1139_0020(void)

{
  uint *puVar1;
  code *pcVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  byte in_AF;
  undefined1 uVar8;
  
  pcVar2 = (code *)swi(0x3f);
  bVar3 = (*pcVar2)();
  *(char *)(in_BX + unaff_SI) =
       *(char *)(in_BX + unaff_SI) + (bVar3 + (9 < (bVar3 & 0xf) | in_AF) * -6 & 0xf);
  pcVar2 = (code *)swi(0x3f);
  iVar6 = (*pcVar2)();
  puVar1 = (uint *)(in_BX + unaff_SI);
  *puVar1 = *puVar1 + iVar6;
  bVar7 = (POPCOUNT(*puVar1 & 0xff) & 1U) == 0;
  pcVar2 = (code *)swi(0x3f);
  cVar4 = (*pcVar2)();
  if (!bVar7) {
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
    *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  }
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  *(char *)(in_BX + unaff_SI) = *(char *)(in_BX + unaff_SI) + cVar4;
  iVar6 = CONCAT11((char)((uint)in_BX >> 8) * '\x02',(byte)in_BX);
  cVar4 = cVar4 + (char)*(undefined2 *)(iVar6 + unaff_SI);
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(iVar6 + unaff_SI) = *(char *)(iVar6 + unaff_SI) + cVar4;
  *(char *)(unaff_DI + -0x78) = *(char *)(unaff_DI + -0x78) + (char)extraout_DX;
  in(0x83);
  uVar5 = in(extraout_DX);
  uVar8 = ((byte)in_BX & *(byte *)(unaff_BP + unaff_SI + 0x30d)) == 0;
  do {
    *(undefined1 *)0x413c = uVar5;
    FUN_1cc0_0d77();
    if (!(bool)uVar8) {
      uVar8 = *(char *)0x413c == '0';
      FUN_1cc0_0cf3();
      FUN_1cc0_0d23();
      FUN_1cc0_0d77();
      if (!(bool)uVar8) {
        FUN_1cc0_08b5();
        FUN_1cc0_086c();
        bVar3 = *(byte *)0x413c;
        *(undefined1 *)(unaff_BP + -1) = (char)(bVar3 - 0x30);
        return CONCAT11((char)(bVar3 - 0x30 >> 8),*(undefined1 *)(unaff_BP + -1));
      }
    }
    uVar5 = FUN_1bdc_030d();
  } while( true );
}


