
void __stdcall16far FUN_0000_49de(void)

{
  undefined2 uVar1;
  int unaff_BP;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  FUN_0000_2e9a(*(undefined2 *)0x44ca,*(undefined2 *)0x44cc,*(undefined2 *)0x44ce);
  FUN_0000_453c(0x44ce);
  if (*(char *)0x7817 != '\0') {
    FUN_0000_4913();
    return;
  }
  FUN_0000_39b7();
  uVar1 = *(undefined2 *)(unaff_BP + -9);
  *(undefined2 *)0x44ce = *(undefined2 *)((undefined *)&DAT_0000_fff5 + unaff_BP);
  *(undefined2 *)0x44d0 = uVar1;
  return;
}


