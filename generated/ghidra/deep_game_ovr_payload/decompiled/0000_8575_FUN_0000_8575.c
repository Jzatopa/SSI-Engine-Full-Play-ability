
void __stdcall16far FUN_0000_8575(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined4 uVar3;
  
  if (*(char *)0x8c26 == '\0') {
    ((undefined *)&DAT_0000_ffee)[unaff_BP] =
         *(char *)((int)*(undefined4 *)0x441c + 0x33e) - *(char *)0x8c27;
    if (((undefined *)&DAT_0000_ffee)[unaff_BP] != '\0') {
      uVar3 = FUN_0000_d62d();
      puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + 6);
      *puVar2 = (int)uVar3;
      ((undefined2 *)puVar2)[1] = (int)((ulong)uVar3 >> 0x10);
    }
  }
  else {
    uVar1 = *(undefined2 *)((undefined *)&DAT_0000_fffa + unaff_BP);
    puVar2 = (undefined2 *)*(undefined4 *)(unaff_BP + 6);
    *puVar2 = *(undefined2 *)(unaff_BP + -8);
    ((undefined2 *)puVar2)[1] = uVar1;
  }
  return;
}


