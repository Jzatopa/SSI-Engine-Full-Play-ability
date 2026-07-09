
/* WARNING: Instruction at (ram,0x00005140) overlaps instruction at (ram,0x0000513f)
    */

void __stdcall16far FUN_0000_5138(void)

{
  int *piVar1;
  char cVar2;
  undefined2 in_AX;
  undefined1 uVar4;
  uint uVar3;
  int unaff_BP;
  int unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  char in_CF;
  bool in_ZF;
  char in_SF;
  char in_OF;
  
  uVar4 = (undefined1)((uint)in_AX >> 8);
  if (in_ZF || in_OF != in_SF) {
    uVar3 = CONCAT11(uVar4,((char)in_AX + 'P') - in_CF);
  }
  else {
    if (((undefined *)&DAT_0000_ffb7)[unaff_DI] != '\0') {
      if (((*(char *)(unaff_BP + 10) == '\x01') && (*(int *)(unaff_BP + 0xe) == *(int *)0x534c)) &&
         (*(int *)(unaff_BP + 0xc) == *(int *)0x534a)) {
        func_0x00000a55();
      }
      goto LAB_0000_517a;
    }
    uVar3 = CONCAT11(uVar4,100);
  }
  FUN_0000_4a92(*(undefined2 *)(unaff_BP + 6),uVar3 & 0xff00,uVar3);
  *(undefined2 *)(unaff_BP + 8) = 0;
  ((undefined *)&DAT_0000_ffb7)[*(int *)(unaff_BP + 6)] = 1;
LAB_0000_517a:
  if (*(char *)(unaff_BP + -8) != '\0') {
    FUN_0000_4a92(*(undefined2 *)(unaff_BP + 6),1,100);
  }
  cVar2 = FUN_0000_09b5(*(uint *)(unaff_BP + 8) >> 1);
  if ((cVar2 != '\0') && (*(int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30) != 0)) {
    piVar1 = (int *)((int)*(undefined4 *)(unaff_BP + 0xc) + 0x30);
    *piVar1 = *piVar1 + -1;
  }
  return;
}


