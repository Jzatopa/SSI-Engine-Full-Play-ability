
void FUN_1000_fb92(void)

{
  undefined2 uVar1;
  int unaff_BP;
  int unaff_DI;
  int iVar2;
  undefined2 unaff_ES;
  undefined2 uVar3;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  ulong uVar4;
  
  uVar1 = *(undefined2 *)(unaff_DI + 0xfd);
  *(undefined2 *)((undefined *)&DAT_0000_ff3e + unaff_BP) = *(undefined2 *)(unaff_DI + 0xfb);
  *(undefined2 *)((undefined *)&DAT_0000_ff40 + unaff_BP) = uVar1;
  while (*(int *)((undefined *)&DAT_0000_ff3e + unaff_BP) != 0 ||
         *(int *)((undefined *)&DAT_0000_ff40 + unaff_BP) != 0) {
    *(int *)(unaff_BP + -0xde) = *(int *)(unaff_BP + -0xde) + 9;
    uVar3 = (undefined2)((ulong)*(undefined4 *)((undefined *)&DAT_0000_ff3e + unaff_BP) >> 0x10);
    iVar2 = (int)*(undefined4 *)((undefined *)&DAT_0000_ff3e + unaff_BP);
    uVar1 = *(undefined2 *)(iVar2 + 7);
    *(undefined2 *)((undefined *)&DAT_0000_ff3e + unaff_BP) = *(undefined2 *)(iVar2 + 5);
    *(undefined2 *)((undefined *)&DAT_0000_ff40 + unaff_BP) = uVar1;
  }
  ((undefined *)&DAT_0000_ff47)[unaff_BP] = 0x4f;
  FUN_0000_e854(*(undefined1 *)0x50d5);
  uVar4 = func_0x0000c4be(0xcc0);
  if ((0x7fffffff < uVar4) ||
     (((long)uVar4 < 0x10000 && ((uint)uVar4 < *(uint *)(unaff_BP + -0xde))))) {
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x828,0xc3e,unaff_BP + -0x101,unaff_SS,*(uint *)(unaff_BP + -0xde) & 0xff00);
  }
  if (((undefined *)&DAT_0000_ff47)[unaff_BP] != 'O') {
    FUN_1000_fad0();
    return;
  }
  if (((undefined *)&DAT_0000_fff6)[unaff_BP] == '\0') {
    func_0x0000d6dc(0xc3e,4,unaff_BP + -0xb8);
                    /* WARNING: Subroutine does not return */
    FUN_0000_d6c2(0x876,0xcc0,unaff_BP + -0xe0,unaff_SS,(int)*(undefined4 *)(unaff_BP + 10));
  }
  func_0x0000d6dc(0xc3e,4,unaff_BP + -0xb8);
  func_0x0000d6dc(0xcc0,0x28,unaff_BP + -0xb3);
                    /* WARNING: Subroutine does not return */
  FUN_0000_d6c2(0x50d4,unaff_DS,unaff_BP + -0x1de,unaff_SS,unaff_BP + -0x8a);
}


