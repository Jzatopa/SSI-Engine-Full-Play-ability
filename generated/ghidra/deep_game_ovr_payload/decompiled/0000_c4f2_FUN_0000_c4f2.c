
undefined2 __stdcall16far FUN_0000_c4f2(void)

{
  uint uVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_BP;
  undefined2 unaff_SS;
  
  uVar1 = FUN_0000_09ba();
  *(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) = (uVar1 & 0xff) + 1;
  uVar2 = func_0x0000d612(0x99);
  *(undefined2 *)((undefined *)&DAT_0000_ffcb + unaff_BP) = uVar2;
  if (*(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) < 0x81) {
    iVar3 = CONCAT11((char)((uint)uVar2 >> 8),((undefined *)&DAT_0000_ffcb)[unaff_BP]);
    *(undefined *)*(undefined4 *)(unaff_BP + 6) = ((undefined *)&DAT_0000_ffcb)[unaff_BP];
  }
  else {
    iVar3 = (*(uint *)((undefined *)&DAT_0000_ffcb + unaff_BP) >> 4) + 0x78;
    *(char *)*(undefined4 *)(unaff_BP + 6) = (char)iVar3;
  }
  return CONCAT11((char)((uint)iVar3 >> 8),*(undefined1 *)(unaff_BP + -1));
}


